#include <iostream>
#include <iomanip>

using namespace std;

int main(){
    // 2 rows, 4 cols
    int grid[100][100];

    //input grid
    for(int i=0; i<2; i++){
        for(int j=0; j<4;j++){
            cin >> grid[i][j];
        }
    }

    //sumOfrow
    for(int i=0; i<2; i++){
        double sumOfrow = 0;
        for(int j=0; j<4;j++){
            sumOfrow += grid[i][j];
        }
        cout << fixed << setprecision(1) << sumOfrow/4.0 << " ";
    }

    cout << endl;

    //sumOfcols
    for(int j=0; j<4; j++){
        double sumOfcols = 0;
        for(int i=0; i<4;i++){
            sumOfcols += grid[i][j];
        }
        cout << fixed << setprecision(1) << sumOfcols/2.0 << " ";
    }

    cout << endl;

    //sumOfall
    double sumOfall = 0;

    for(int i=0; i<2; i++){
        for(int j=0; j<4;j++){
            sumOfall += grid[i][j];
        }
    }
    cout << fixed << setprecision(1) << sumOfall/8.0;

    


    return 0;
}