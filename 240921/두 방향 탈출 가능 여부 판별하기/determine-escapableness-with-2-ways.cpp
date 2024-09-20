#include <iostream>
#include <vector>

using namespace std;

// Directions to move: down, up, right, left
int dx[] = {1, 0};
int dy[] = {0, 1};

// Global variables for marking visited cells and edge count
vector<vector<bool>> marked;
int edgeCount = 0;

// Function to check if a cell is within grid bounds and valid
bool isValid(int x, int y, int n, int m,const vector<vector<int>>& grid) {
    return (x >= 0 && x < n && y >= 0 && y < m && grid[x][y] == 1 && !marked[x][y]);
}

// DFS function to explore the grid
void dfs(const vector<vector<int>>& grid, int x, int y, int n, int m) {
    marked[x][y] = true;  // Mark the current cell as visited

    // Iterate over all 4 possible directions
    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        // Check if moving to (nx, ny) is valid and has not been visited
        if (isValid(nx, ny, n, m, grid)) {
            edgeCount++;  // Increment edge count as we traverse to an unvisited node
            dfs(grid, nx, ny, n, m);  // Recursively visit the neighbor
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    // Input grid (n rows, m columns)
    vector<vector<int>> grid(n, vector<int>(m));
    marked = vector<vector<bool>>(n, vector<bool>(m, false));
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j];  // 0 represents snake, 1 represents safe spot
        }
    }

    // Check if the start or end points are blocked
    if (grid[0][0] == 0 || grid[n-1][m-1] == 0) {
        cout << 0 << endl;
        return 0;
    }

    // Perform DFS from top-left corner (0, 0)
    dfs(grid, 0, 0, n, m);

    // Check if we have visited the bottom-right corner (n-1, m-1)
    if (marked[n-1][m-1]) {
        cout << 1 << endl;  // Escape possible
    } else {
        cout << 0 << endl;  // Escape not possible
    }

    return 0;
}