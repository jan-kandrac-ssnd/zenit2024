#include <any>
#include <iostream>
#include <vector>

using namespace std;

struct station {
     string name;
     vector<station *> neighbors;

     // odid z tejto stanice do dalsej, ak taka neexistuje vytvor ju
     bool go_to(const string &station_name, station* &target) {
         for (const auto s: neighbors) {
             if (s->name == station_name) {
                 target = s;
                 return false;
             }
         }
         auto* s = new station;
         s->name = station_name;
         neighbors.push_back(s);
         target = s;
         return true;
     }
};

int main() {
     int n;
     string line;
     cin >> n;

     station mapa;

     int count = 0;
     for (int i = 0; i < n; i++) {
         cin >> line;
         station *current_station = nullptr;
         unsigned long pointer = 1UL;

         while (true) {
             const auto pos = line.find('/', pointer);
             string token = line.substr(pointer, pos == string::npos ? line.length() : pos - pointer);
             if (current_station == nullptr) {
                 if (mapa.go_to(token, current_station)) count++;
             } else {
                 if (current_station->go_to(token, current_station)) count++;
             }
             pointer += token.length() + 1;
             if (pos == string::npos) break;
         }
     }

     cout << count << endl;
     return 0;
}