#include <iostream>
#include <vector>
#include <unordered_map>
#include <functional>

using namespace std;

class TreeNode {
public:
    int value;
    vector <int> children;

    TreeNode(int val) : value(val){}
};

class Tree {
public:
    unordered_map<int, TreeNode*> nodes;

    void addEdge(int parent, int child){
        if(nodes.find(parent) == nodes.end()){
            nodes[parent] = new TreeNode(parent);
        }
        if(nodes.find(child) == nodes.end()){
            nodes[child] = new TreeNode(child);
        }

        nodes[parent]-> children.push_back(child);
    }
};


void findParentNodes(Tree& tree, int root){
    unordered_map<int, int> parentMap;

    //perform DFS
    function<void(int, int)> dfs = [&](int node, int parent){
        parentMap[node] = parent;

        for(int child : tree.nodes[node]-> children){
            dfs(child, node);
        }
    };

    dfs(root,-1);

    //print the result
    for (int i = 2; i <= tree.nodes.size(); ++i) {
        cout << parentMap[i] << endl;
    }
}

int main() {
    Tree tree;

    int nodes;
    int par, ch;

    cin >> nodes;

    for (int i = 1; i < nodes; i++){
        cin >> par >> ch;
        tree.addEdge(par,ch);
    }

    int root = 1;
    findParentNodes(tree, root);

    

    return 0;
}