// by using the adjacency matrix the space complexity is much more

/* for the weight we put the wweight insetead of the 1 */

// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     cout << "Enter the number of vertex and the edges: ";
//     int n,m; // n = no of vertex , m = no of edges
//     cin >> n >> m;
//     // take a vector to store the edges

//     vector<vector<int>> adj_mat(n+1,vector<int>(m+1,0));

//     // this portion is only for the notstion of the row and the col of the matrix
//     for(int i = 0;i<=n;i++){
//         adj_mat[0][i] = i;
//         adj_mat[i][0] = i;
//     }

//     // taking the input of the vertex, the edge is present bewteen them
//     cout << "Enter the vertex in which edge is exist : ";
//     for(int i = 0;i<m;i++){
//         int u,v;
//         cin >> u >> v;
//         adj_mat[u][v] = 1;
//         adj_mat[v][u] = 1;
//     }

//     // printing the adjacency matrix of the graph
//     for(int i = 0;i<=m;i++){
//         for(int j = 0;j<=m;j++){
//             cout << adj_mat[i][j] <<" ";
//         }
//         cout << endl;
//     }
// }


// representation of the grsph uding the adjacency list the time complexity is linear here

/* to store the weighted graph just push the pair of node and the weight instead of the node also 
 just take the vector<vector<pair<int,int>>> list(n+1  and push the v and the weight in the 2d vector) 
  the first vector just keep the track of the vertex and in the internl vector is specified for a
  particular nodes and int the pair the neighbour and the weight bewteen the vertex */
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    //  n -> no of vertex
    //  m -> no of edge
    cin >> n >> m;
    vector<vector<int>> list(n+1);
    // m is the number of the edjes so we take the user input m times
    for(int i = 0;i<m;i++){
        int u,v;
        cin >> u >> v;
        list[u].push_back(v);
        // if to store the directed graph just comment out the below line 
        // for directed graph only u -> v not a v -> u is plotted
        list[v].push_back(u);
    }

    for(int i = 0;i<=n;i++){
        cout << i  << " : ["; 
        for(int j = 0;j<list[i].size();j++){
            cout << list[i][j] <<",";
        }
        cout << "]"<<endl;
    }
}
