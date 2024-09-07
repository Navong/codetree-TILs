#include <iostream>
#include <unordered_set>
using namespace std;

bool hasMultipleAlphabets(const string& str){
    unordered_set<char> uniqueChars;

    for(char c : str){
        uniqueChars.insert(c);
        if(uniqueChars.size()>1) return true;
    }

    return false;
}

int main() {
    // Please write your code here.
    string str;
    cin >> str;
    if(hasMultipleAlphabets(str)) cout << "Yes" << endl;
    else cout << "No" <<endl;
    return 0;
}