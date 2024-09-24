#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 방향 벡터
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

vector<vector<bool>> marked;

// 유효한 위치인지 확인
bool isValid(const vector<vector<int>>& grid, int x, int y, int n) {
    return (x >= 0 && x < n && y >= 0 && y < n && grid[x][y] == 1 && !marked[x][y]);
}

// DFS 수행
int dfs(vector<vector<int>>& grid, int x, int y, int n) {
    marked[x][y] = true;
    int peopleInVillage = 1;

    for (int i = 0; i < 4; i++) {
        int nextX = x + dx[i];
        int nextY = y + dy[i];
        if (isValid(grid, nextX, nextY, n)) {
            peopleInVillage += dfs(grid, nextX, nextY, n);
        }
    }

    return peopleInVillage;
}

int main() {
    int n;
    cin >> n;

    if (n > 25) {
        cout << "도시의 크기는 25이 넘을 수 없습니다." << endl;
        return 0;
    }

    // 지도 생성
    vector<vector<int>> grid(n, vector<int>(n));
    marked = vector<vector<bool>>(n, vector<bool>(n, false));
    vector<int> villageSizes;

    // 지도 데이터 입력
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    // DFS 수행
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 1 && !marked[i][j]) {
                villageSizes.push_back(dfs(grid, i, j, n));
            }
        }
    }

    // 마을 크기 정렬 및 출력
    sort(villageSizes.begin(), villageSizes.end());
    cout << villageSizes.size() << endl;
    for (int size : villageSizes) {
        cout << size << endl;
    }

    return 0;
}