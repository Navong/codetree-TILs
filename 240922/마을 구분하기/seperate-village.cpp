#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<vector<bool>> marked;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

bool isValid(vector<vector<int>>& grid, int x, int y, int n){
    return (x >= 0&&x<n&&y>=0&&y<n&&grid[x][y]&&!marked[x][y]);
}

int dfs(vector<vector<int>>& grid, int x, int y, int n){
    marked[x][y] = true;
    int count=1;

    for(int i=0;i<4;i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(isValid(grid,nx,ny,n)){
            count += dfs(grid,nx,ny,n);
        }
    }
    return count;
}

int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin >> n;

    vector<vector<int>> grid(n, vector<int>(n));
    marked = vector<vector<bool>>(n, vector<bool>(n, false));
    vector<int> number_viliages;

    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            cin >> grid[i][j];
        }
    }

    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            if(grid[i][j]==1&&!marked[i][j]){
                number_viliages.push_back(dfs(grid,i,j,n));
            }
        }
    }

    cout << number_viliages.size() << endl;

    sort(number_viliages.begin(), number_viliages.end());

    for(int size : number_viliages){
        cout << size << endl;
    }


    return 0;
}