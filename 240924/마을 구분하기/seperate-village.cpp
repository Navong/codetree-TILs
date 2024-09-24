#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<bool>> marked;

//coordination

int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

bool isValid(vector<vector<int>>& grid, int x, int y, int n){
    return (x>=0&&x<n&&y>=0&&y<n&&grid[x][y]==1&&!marked[x][y]);
}

int dfs(vector<vector<int>>& grid, int x, int y, int n){
    marked[x][y] = true;
    int pInVilliages = 1;

    for(int i =0;i<4;i++){
        x += dx[i];
        y += dy[i];
        if(isValid(grid, x, y, n)){
            pInVilliages += dfs(grid, x, y, n);
        }
    }

    return pInVilliages;
}

int main(){
    int n;
    cin >> n;


    if(n > 25) return 0;

    //grid
    vector<vector<int>> grid(n, vector<int>(n));
    marked = vector<vector<bool>>(n, vector<bool>(n, false));
    vector<int> count;


    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> grid[i][j];
        }
    }

    //perform dfs when encouter '1'
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]==1&&!marked[i][j]){
                // dfs(grid, i,j,n);
                count.push_back(dfs(grid, i,j,n));
            }
        }
    }

    sort(count.begin(), count.end());
    cout << count.size() << endl;
    for(int p : count){
        cout << p << endl;
    }
}