#include <iostream>
using namespace std;

// 별을 n줄 출력하고, 다시 n줄을 출력하는 함수
void printPattern(int n, int current) {
    if (current == 0) return;
    
    // 별 출력 (current 줄)
    for (int i = 0; i < current; i++) {
        cout << "* ";
    }
    cout << endl;
    
    // 재귀적으로 줄을 줄여가며 호출
    printPattern(n, current - 1);
    
    // 별 출력 (current 줄)
    if (current <= n) {
        for (int i = 0; i < current; i++) {
            cout << "* ";
        }
        cout << endl;
    }
}

int main() {
    int N;
    cin >> N;

    printPattern(N, N);

    return 0;
}