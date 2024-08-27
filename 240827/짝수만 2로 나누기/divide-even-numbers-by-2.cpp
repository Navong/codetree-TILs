#include <iostream>
using namespace std;

void Modify(int x[], int size){
    for(int i=0;i<size; i++){
        if(*(x+i)%2==0){
            *(x+i)=*(x+i)/2;
        }
    }
}

int main() {
    int idx;
    cin >> idx;
    int arr[idx];

    for(int i =0;i<idx;i++)
        cin>>*(arr+i);
    Modify(arr, idx);
    for(int i=0;i<idx;i++)
        cout<<*(arr+i)<<" ";
    return 0;
}