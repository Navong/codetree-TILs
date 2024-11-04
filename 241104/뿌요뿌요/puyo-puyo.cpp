#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<vector<int>> grid;
vector<vector<bool>> visited;
int largestBlockSize = 0;
int explodeCount = 0;

int dx[] = {-1, 1, 0, 0}; // Directions for row movement (up, down, left, right)
int dy[] = {0, 0, -1, 1}; // Directions for column movement

// DFS to calculate the size of a block
int dfs(int x, int y, int num) {
    visited[x][y] = true;
    int blockSize = 1; // Current cell is part of the block

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && nx < n && ny >= 0 && ny < n && !visited[nx][ny] && grid[nx][ny] == num) {
            blockSize += dfs(nx, ny, num); // Recursively add connected cells
        }
    }
    return blockSize;
}

int main() {
    cin >> n;
    grid.resize(n, vector<int>(n));
    visited.resize(n, vector<bool>(n, false));

    // Input the grid
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    // Traverse the grid to find blocks
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!visited[i][j]) {
                int blockSize = dfs(i, j, grid[i][j]);
                if (blockSize > 4) {
                    explodeCount++;
                    largestBlockSize = max(largestBlockSize, blockSize);
                }
            }
        }
    }

    cout << explodeCount << " " << largestBlockSize << endl;

    return 0;
}