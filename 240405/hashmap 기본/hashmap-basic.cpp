#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    // Please write your code here.
    //create map
    unordered_map<int, int> map;

    //add
    int k,v, lop;
    cin >> lop;
    string query;

    for(int i=0;i<lop;i++){
        cin >> query;
        if(query == "add"){
            cin >> k >> v;
            //k exist or not
            if(map.find(k)!=map.end()) map[k] = v;
            else map.insert({k,v});
        }else if(query == "find"){
            cin >> k;
            if(map.find(k)!=map.end()) cout << map[k] << endl;
            else cout << "None" << endl;
        }else if(query == "remove"){
            cin >> k;
            map.erase(k);
        }
    }

    //remove
    //find
    return 0;
}