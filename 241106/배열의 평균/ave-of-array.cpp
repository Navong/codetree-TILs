#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    // 2 row 4 cols
    int grid[2][4];
    float hor_avg;
    float tmp;

    for(int i =0;i<2;i++){
        for(int j=0;j<4;j++){
            cin >> grid[i][j];
        }
    }

    // horizon avg
    for(int i =0;i<2;i++){
        tmp = 0;
        for(int j=0;j<4;j++){
            tmp += grid[i][j];
        }
        cout <<fixed<<setprecision(1) << tmp/4 << " ";
    }

    cout << endl;
    // vertical avg
    for (int j = 0; j < 4; j++) {
        double colSum = 0;
        for (int i = 0; i < 2; i++) {
            colSum += grid[i][j];
        }
        double colAvg = colSum / 2.0;
        std::cout << std::fixed << std::setprecision(1) << colAvg << " ";
    }

    cout << endl;

    double allAvg;
    for (int i=0; i<2;i++){
        for (int j=0; j<4;j++){
            allAvg += grid[i][j];
        }
    }

    cout << fixed << setprecision(1) << allAvg/8.0;


    // all avg


    return 0;
}