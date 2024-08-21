#include <iostream>
using namespace std;

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b =temp;
    cout << a << " " << b<<endl;
}

int main() {
    // 여기에 코드를 작성해주세요.
    int n,m;
    cin >> n>>m;
    swap(n,m);
    return 0;
}