#include <iostream>
using namespace std;

void PrintNLine(int n){
    for(int j=0;j<n;j++){
        cout << "12345^&*()_";
        cout << endl;
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    int NumOfLine;
    cin >> NumOfLine;
    PrintNLine(NumOfLine);
    return 0;
}