#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;

class graph{

public:
    unordered_map<int, list<int> > adj;

    void addEdge(int u, int v, bool direction){
        // direction = 0 -> undirectional
        // direction = 1 -> directional

        adj[u].push_back(v);
        if (direction == 0){
            adj[v].push_back(u);
        }
    }

    void printADJlist(){
        for (auto i : adj){
            cout << i.first << " -> ";
            for (auto j : i.second){
                cout << j << ", ";
            }
            cout << endl;
        }
    }
};

int main() {
    int nodes, edges;
    cout << "Enter the Number of nodes: ";
    cin >> nodes;
    cout << "Enter the number of edges: ";
    cin >> edges;

    graph g1;

    for (int i=0; i <= nodes; i++){
        int u, v;
        cin >> u >> v;
        // creating edges of graph
        g1.addEdge(u, v, 0);    // direction = 0 -> undirectional graph

    }
    g1.printADJlist();
    return 0;
}