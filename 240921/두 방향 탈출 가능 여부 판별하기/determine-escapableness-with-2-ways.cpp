#include <iostream>
#include <vector>

using namespace std;


int dx[] = {1,0};
int dy[] = {0,1};

vector<vector<bool>> marked;

bool isValid(vector<vector<int>>& grid, int x, int y, int n, int m){
    return (x>=0 && x<n && y>=0 && y<m && grid[x][y]==1 && !marked[x][y]);
}

void dfs(vector<vector<int>>& grid, int x, int y, int n, int m){
    marked[x][y] == true;

    for(int i =0; i<2;i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(isValid(grid, nx,ny,n,m)){
            dfs(grid,nx,ny,n,m);
        }
    }
}

int main(){
    int n, m;
    cin >> n >> m;

    vector<vector<int>>grid(n, vector<int>(m));
    marked = vector<vector<bool>> (n, vector<bool>(m, false));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> grid[i][j];
        }
    }

    if(grid[0][0]==0 || grid[n-1][m-1]==0){
        cout << 0 << endl;
        return 0;
    }

    dfs(grid,0,0,n,m);

    if(marked[n-1][m-1]){
        cout<< 1 << endl;
    }else{
        cout << 0 << endl;
    }

    return 0;
}