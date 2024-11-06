#include <iostream>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n,m;
    int grid[100][100];

    cin >> n >> m;

    // input grid
    int num = 1;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            grid[i][j] = num++;
        }
    }

    //print grid

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout << grid[i][j] << " ";
        }

        cout << endl;
    }
    return 0;
}