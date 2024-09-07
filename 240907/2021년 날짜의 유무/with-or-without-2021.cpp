#include <iostream>
using namespace std;

bool isValidDate(int M, int D){
    int dayInMonth[]={31,28,31,30,31,30,31,31,30,31,30,31};

    if(M < 1 || M > 12){
        return false;
    }

    if(D < 1 || D > dayInMonth[M-1]){
        return false;
    }

    return true;
}

int main() {
    // 여기에 코드를 작성해주세요.
    int M, D;
    cin >> M >> D;
    if(isValidDate(M, D)) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}