#include <iostream>
using namespace std;

void Modify(int x[]){
    for(int i=0;i<sizeof(x); i++){
        if(*(x+i)%2==0)
            *(x+i)=*(x+i)/2;
    }
}

int main() {
    int idx;
    cin >> idx;
    int arr[idx];

    for(int i =0;i < idx;i++)
        cin>>*(arr+i);
    Modify(arr);
    for(int i =0;i<idx;i++)
        cout<<*(arr+i)<<" ";
    return 0;
}