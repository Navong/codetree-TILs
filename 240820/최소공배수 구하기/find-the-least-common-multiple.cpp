#include <iostream>
using namespace std;

int gcd(int n, int m){
    if(n<m) swap(n,m);
    while(m!=0){
        int tmp = m;
        m = n%m;
        n = tmp;
    }
    return n;
}

int lcm(int a, int b){
    return (a / gcd(a,b)) * b;
}

int main() {
    // 여기에 코드를 작성해주세요.
    int n,m;
    cin>>n>>m;
    cout<<lcm(n,m);
    return 0;
}