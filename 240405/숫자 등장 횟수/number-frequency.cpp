#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    unordered_map<int, int> map;
    int elem, query;
    
    // Input sequence
    cin >> elem >> query;
    for (int i = 0; i < elem; i++) {
        int v;
        cin >> v;
        map[v]++;
    }

    // Queries
    // cin >> query;
    for (int j = 0; j < query; j++) {
        int num;
        cin >> num;
        cout << map[num] << ' ';
    }
    
    return 0;
}