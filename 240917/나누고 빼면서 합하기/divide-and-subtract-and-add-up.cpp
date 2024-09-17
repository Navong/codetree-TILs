#include <iostream>
#include <vector>
using namespace std;

int calculateSum(const vector<int> &sequence, int m)
{
    int sum = 0;
    while (m > 1)
    {
        sum += sequence[m - 1]; // Add element at position m (0-based index)
        if (m % 2 == 0)
        {
            m /= 2;
        }
        else
        {
            m -= 1;
        }
    }
    sum += sequence[0]; // Add the first element (m = 1)
    return sum;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<int> sequence(n);
    for (int i = 0; i < n; i++)
    {
        cin >> sequence[i];
    }

    int result = calculateSum(sequence, m);
    cout << result << endl;

    return 0;
}