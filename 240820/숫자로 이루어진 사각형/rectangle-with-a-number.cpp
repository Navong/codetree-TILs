#include <iostream>
using namespace std;

void PrintShape(int n){
    int a=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(a == 10) a = 1;
            cout <<a<<" ";
            a++;
        }
        cout<<endl;
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    int n; cin >> n;
    PrintShape(n);
    return 0;
}