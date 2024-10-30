#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <string>
#include <cassert>
#include <cstdlib>
#include <chrono>
#include <cmath>

using namespace std::chrono;

using namespace std;

const long M = 1000000007;

using namespace std;

const double SMALL = 1.0E-30; // used to stop divide-by-zero
const double NEARZERO = 1.0e-10; // helps in printing

using vec = vector<double>; // vector
using matrix = vector<vec>; // matrix

// https://cplusplus.com/forum/beginner/276798/

void print( const string &title, const matrix &A )
{
    if ( title != "" ) cout << title << '\n';

    for ( auto &row : A )
    {
        for ( auto x : row ) cout << setw( 15 ) << ( abs( x ) < NEARZERO ? 0.0 : x );
        cout << '\n';
    }
}

// Function prototypes
matrix matmul(const matrix &A, const matrix &B);

matrix subtract(const matrix &A, const matrix &B);

matrix oppsign(matrix A);

matrix subMatrix(const matrix &A, int i1, int i2, int j1, int j2);

matrix assembly(const matrix &A11, const matrix &A12, const matrix &A21, const matrix &A22);

matrix inverse(const matrix &A);

//======================================================================
matrix matmul(const matrix &A, const matrix &B) // Matrix times matrix
{
    int rowsA = A.size(), colsA = A[0].size();
    int rowsB = B.size(), colsB = B[0].size();
    assert(colsA == rowsB);

    matrix C(rowsA, vec(colsB, 0.0));
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            for (int k = 0; k < colsA; k++) {
                C[i][j] += A[i][k] * B[k][j];
                while (C[i][j] > M) {
                    C[i][j] -= M;
                }
            }
        }
    }
    return C;
}

//======================================================================

matrix subtract(const matrix &A, const matrix &B) // Subtract matrices
{
    int rows = A.size(), cols = A[0].size();
    assert(rows == B.size() && cols == B[0].size());

    matrix result(rows, vec(cols));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = A[i][j] - B[i][j];
            while (result[i][j] > M) {
                result[i][j] -= M;
            }
        }
    }
    return result;
}

//======================================================================

matrix oppsign(matrix A) // Minus matrix
{
    for (auto &row: A) {
        for (auto &e: row) e = -e;
    }
    return A;
}

//======================================================================

matrix subMatrix(const matrix &A, int i1, int i2, int j1, int j2) {
    int rows = i2 - i1 + 1, cols = j2 - j1 + 1;
    matrix result(rows, vec(cols));
    for (int i = i1, r = 0; i <= i2; i++, r++) {
        auto it1 = A[i].begin() + j1, it2 = A[i].begin() + j2 + 1;
        copy(it1, it2, result[r].begin());
    }
    return result;
}

//======================================================================

matrix assembly(const matrix &A11, const matrix &A12, const matrix &A21, const matrix &A22) {
    int k = A11.size();
    int n = k + A22.size();
    matrix result(n, vec(n));

    for (int i = 0; i < k; i++) {
        copy(A11[i].begin(), A11[i].end(), result[i].begin());
        copy(A12[i].begin(), A12[i].end(), result[i].begin() + k);
    }

    for (int i = k; i < n; i++) {
        copy(A21[i - k].begin(), A21[i - k].end(), result[i].begin());
        copy(A22[i - k].begin(), A22[i - k].end(), result[i].begin() + k);
    }

    return result;
}

//======================================================================

matrix inverse(const matrix &A) {
    int n = A.size();
    if (n == 1) {
        double value = A[0][0];
        if (abs(value) < SMALL) {
            cerr << "Non-invertible. Giving up.\n";
            exit(0);
        }
        return matrix(1, vec(1, 1.0 / value));
    }

    // Partition into four
    int k = n / 2;
    matrix A11 = subMatrix(A, 0, k - 1, 0, k - 1);
    matrix A12 = subMatrix(A, 0, k - 1, k, n - 1);
    matrix A21 = subMatrix(A, k, n - 1, 0, k - 1);
    matrix A22 = subMatrix(A, k, n - 1, k, n - 1);

    // Strassen steps
    matrix R1 = inverse(A11);
    matrix R2 = matmul(A21, R1);
    matrix R3 = matmul(R1, A12);
    matrix R4 = matmul(A21, R3);
    matrix R5 = subtract(R4, A22);
    matrix R6 = inverse(R5);
    matrix X12 = matmul(R3, R6);
    matrix X21 = matmul(R6, R2);
    matrix R7 = matmul(R3, X21);
    matrix X11 = subtract(R1, R7);
    matrix X22 = oppsign(R6);

    return assembly(X11, X12, X21, X22);
}

#pragma region string ends_with https://stackoverflow.com/a/42844629/2316926
static bool ends_with(std::string_view str, std::string_view suffix) {
    return str.size() >= suffix.size() && str.compare(str.size() - suffix.size(), suffix.size(), suffix) == 0;
}

#pragma endregion

double get_result(const std::vector<std::vector<double> > &vect) {
    double total = 0;
    for (auto value: vect[0]) {
        total += value;
        while (total >= M) {
            total -= M;
        }
    }
    return ceil(total);
}

vector<std::vector<double> > construct_markov_chain() {
    int alphabet_size;
    string input = "";

    cin >> alphabet_size;
    cin >> input;

    double part = 1.0 / alphabet_size;

    // states from E_0 to E_n. E0 = empty text En full text
    vector<string> states(input.length() + 1);
    for (int i = 0; i <= input.length(); i++) {
        string t = input.substr(0, i);
        states[i] = t;
    }

    // matrix
    vector matrix(input.length(), vector(input.length(), 0.0));

    for (int i = 0; i < input.length(); i++) {
        // som v stave E0 = !!!vyplnam nulty riadok!!! matrix[i][...]
        // zatial mam k dispozicii text "" teda substring {0, 0}
        string text_in_state = input.substr(0, i);

        for (int j = 0; j < alphabet_size; j++) {
            char character = 'a' + j;
            string new_text = text_in_state + character;
            // do akeho stavu ma dostane new_text? najlhsieho mozneho

            for (int k = states.size() - 1; k >= 0; k--) {
                string state = states[k];
                if (ends_with(new_text, state)) {
                    if (k < states.size() - 1) {
                        matrix[i][k] += part;
                    }
                    break;
                }
            }
        }
    }

    return matrix;
}

vector<std::vector<double> > I_Q(vector<vector<double> > input) {
    vector matrix(input.size(), vector(input.size(), 0.0));

    for (int x = 0; x < input.size(); x++) {
        for (int y = 0; y < input.size(); y++) {
            if (x == y) {
                matrix[y][x] = 1 - input[y][x];
            } else {
                matrix[y][x] = -input[y][x];
            }
        }
    }

    // matrix

    return matrix;
}


int main() {
    auto markov_matrix = construct_markov_chain();
    // print("Hello", markov_matrix);
    auto i_q = I_Q(markov_matrix);
     print("Hello", i_q);
   auto result = inverse(i_q);
    // print("Result", result);
    cout << fixed << get_result(result) << endl;
    return 0;
}

// pri vstupe:
// 10
// aaaaaaaaaa

// nespravne vysledky
// 111100385.951076
// 111100386.000000 zaokruhlenie ani zaokruhlenie hore nefunguje