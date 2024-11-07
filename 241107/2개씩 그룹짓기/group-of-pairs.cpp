#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    //variable
    int N;
    cin >> N;

    //get 2N from input use vector
    vector<int> elem (2*N);

    for (int i = 0; i < 2*N; i++){
        cin >> elem[i];
    }


    sort(elem.begin(), elem.end());

    int maxSum =0;

    for(int i =0; i < N; i++){
        int sum = elem[i] + elem[2*N -1 -i];
        maxSum = max(maxSum, sum);
    }

    cout << maxSum << endl;

    


    return 0;
}