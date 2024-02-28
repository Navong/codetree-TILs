#include <iostream>
#include <vector>
#include <utility>

using namespace std;

const int MAX_N = 100000;

vector<pair<int, int>> graph[MAX_N + 1];

int furthestNode, maxDist;

void dfs(int node, int parent, int dist) {
  if (dist > maxDist) {
    maxDist = dist;
    furthestNode = node;
  }

  for (auto neighbor : graph[node]) {
    if (neighbor.first != parent) {
      dfs(neighbor.first, node, dist + neighbor.second);
    }
  }
}

int findDiameter() {
  // Perform DFS from any vertex
  dfs(1, 0, 0);

  // Perform DFS from the farthest node found in the first DFS
  maxDist = 0;
  dfs(furthestNode, 0, 0);

  return maxDist;
}

int main() {
  int n;
  cin >> n;

  int u, v, dist;
  for (int i = 0; i < n - 1; ++i) {
    cin >> u >> v >> dist;
    graph[u].push_back({v, dist});
    graph[v].push_back({u, dist});
  }

  int diameter = findDiameter();
  cout << diameter << endl;

  return 0;
}