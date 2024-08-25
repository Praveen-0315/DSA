#include<iostream>
#include<vector>
using namespace std;

class DisjointSet{
    vector<int> rank, parent, size_;
public:
    // Constructor
    DisjointSet(int n){
        rank.resize(n+1, 0);        // n+1 for 1 based indexing as well as 0 based
        size_.resize(n+1, 1);
        parent.resize(n+1);
        for(int i=0; i<n; i++)
            parent[i] = i; 
    }

    //finding ultimate parent of node
    int findPar(int node){
        if(node == parent[node])
            return node;
        return parent[node] = findPar(parent[node]);
    }

    // Union by rank of two nodes
    void unionByRank(int u, int v){
        // p_u, p_v are the ultimate parent of u and v respectively
        int p_u = findPar(u);
        int p_v = findPar(v);

        if(p_u == p_v) return ;     // both belongs to same component

        if(rank[p_u] < rank[p_v])
            parent[p_u] = p_v;
        else if(rank[p_u] > rank[p_v])
            parent[p_v] = p_u;
        else{
            parent[p_v] = p_u;
            rank[p_u]++;
        }
    }

    // Union by size of two nodes
    void unionBySize(int u, int v){
        // p_u, p_v are the ultimate parent of u and v respectively
        int p_u = findPar(u);
        int p_v = findPar(v);

        if(p_u == p_v) return ;     // both belongs to same component

        if(size_[p_u] < size_[p_v]){
            parent[p_u] = p_v;
            size_[p_v] += size_[p_u];
        }
        else {
            parent[p_v] = p_u;
            size_[p_u] += size_[p_v];
        }
    }

};

int main(){
    DisjointSet ds(7);
    // ds.unionByRank(1,2);
    // ds.unionByRank(2,3);
    // ds.unionByRank(4,5);
    // ds.unionByRank(6,7);
    // ds.unionByRank(5,6);

    // if(ds.findPar(1) == ds.findPar(7)) cout<<"same Components "<<endl;
    // else cout<<"Different Components "<<endl;

    // ds.unionByRank(3,7);

    // if(ds.findPar(1) == ds.findPar(7)) cout<<"same Components "<<endl;
    // else cout<<"Different Components "<<endl;


    ds.unionBySize(1,2);
    ds.unionBySize(2,3);
    ds.unionBySize(4,5);
    ds.unionBySize(6,7);
    ds.unionBySize(5,6);

    if(ds.findPar(1) == ds.findPar(7)) cout<<"same Components "<<endl;
    else cout<<"Different Components "<<endl;

    ds.unionBySize(3,7);

    if(ds.findPar(1) == ds.findPar(7)) cout<<"same Components "<<endl;
    else cout<<"Different Components "<<endl;


    return 0;
}