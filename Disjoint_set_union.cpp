#include<bits/stdc++.h>
using namespace std;

// here we make a disjoint 
class DSU{
    vector<int> rank;
    vector<int> parent;
    public:
    DSU(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        for(int i = 0;i<n;i++){ 
            parent[i] = i;
        }
    }
        // function to find the ultimate parent that helps to achieve the constant time complexity
    int find_ultimate_parent(int node){
        if(node == parent[node]){
            return node;
        }
        // this is the path compresion 
        return parent[node] = find_ultimate_parent(parent[node]);
    }

        // rank 

    void union_by_rank(int u, int v){
        int ulp_u = find_ultimate_parent(u);
        int ulp_v = find_ultimate_parent(v);

        if(ulp_u == ulp_v) return;
        // the parent with the high rank is consider as a ultimate parent 
        if(rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        }
        else if(rank[ulp_v] < rank[ulp_u]){
            parent[ulp_v] = ulp_u;
        }
        else{
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
};

int main(){
    // 7 is the number of node
    DSU ds(7);

    ds.union_by_rank(1,2);
    ds.union_by_rank(2,3);
    ds.union_by_rank(4,5);
    ds.union_by_rank(6,7);
    ds.union_by_rank(5,6);

    // if 3 and 7 same or not

    if(ds.find_ultimate_parent(3) == ds.find_ultimate_parent(7)){
        cout << "same\n";
    }
    else cout << "not same\n";

    ds.union_by_rank(3,7);

    if(ds.find_ultimate_parent(3) == ds.find_ultimate_parent(7)){
        cout << "same\n";
    }
    else cout << "not same\n";

    ds.union_by_rank(1,2);
}
