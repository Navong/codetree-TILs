#include <iostream>
using namespace std;


void Print5Star(){
    for(int i=0; i<10; i++)
        cout << "*";
    cout << endl;
}


int main() {
    for(int i=0;i<5;i++)
        Print5Star();
    return 0;
}