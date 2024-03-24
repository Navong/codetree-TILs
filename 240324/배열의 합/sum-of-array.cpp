#include <iostream>
using namespace std;

int main() {
    // Please write your code here.
    int n = 4;
    int val;

    for(int i =0; i<n;i++){
        int sum_val =0;
        for(int j=0; j<n;j++){
            cin >> val;
            sum_val +=val;
        }
        cout << sum_val << endl;
    }
}