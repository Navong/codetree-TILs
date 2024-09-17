#include <iostream>
using namespace std;

string str;
string par_str;

void find_index(){
    size_t index = str.find(par_str);
    if(index != string::npos) cout << index << endl;
    else cout << "-1";
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> str >> par_str;
    find_index();
    return 0;
}