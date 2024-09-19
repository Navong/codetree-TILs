#include <iostream>
#include <vector>
using namespace std;

vector<bool> marked;
int edgecount = 0;

void dfs(vector<vector<int>> &G, int v){
    marked[v] = true;

    //iterate all neighbors in cur node
    for (int w : G[v]){
        if(!marked[w]){
            edgecount++;
            dfs(G, w);
        }
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    int N,M;
    cin >> N >> M;


    vector<vector<int>> G(N+1); // 1-based graph

    for(int i = 0; i < M; ++i){
        int x, y;
        cin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);

        //undirected graph x are y neighbors, y are also x neighbors.
    }

    marked = vector<bool>(N+1, false);

    // marked = {false, false,}

    dfs(G, 1);

    cout << edgecount << endl;

    return 0;
}