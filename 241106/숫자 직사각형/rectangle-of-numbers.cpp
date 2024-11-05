#include <iostream>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int row, col;
    int arr[100][100];
    cin >> row >> col;

    int num = 1;

    for(int i = 0; i < row; i++){
        for(int j=0; j < col; j++){
            arr[i][j] = num++;
        }
    }

    for(int i = 0; i < row; i++){
        for(int j=0; j < col; j++){
            cout << arr[i][j] << ' ';
        }

        cout << endl;
    }

    return 0;
}