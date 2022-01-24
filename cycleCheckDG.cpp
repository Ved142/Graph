#include<bits/stdc++.h>
using namespace std;

void addEdge(int u,int v,vector<int> adj[])
{
    adj[u].push_back(v);
}

bool checkCycleDG(int node, vector<int> adj[],vector<bool> &vis1,vector<int> &path)
{
    path[node] = 1;
    vis1[node] = true;
    for(auto it:adj[node]){
        if(vis1[it] && path[it]==1)
        {
            
            return true;
        }
        else if(!vis1[it]){
            vis1[it] = true;
            path[it] = node;
            if(checkCycleDG(it,adj,vis1,path)){
                return true;
            }
        }
    }
    path[node]=0;
    return false;
}





int main() {
    //Directed Graph Creation
    int E,V;
    cout<<"Enter the number of vertices and edges: ";
    cin>>V>>E;
    vector<int> adj[V];
    cout<<"Enter the edges:\n";
    for(int i=1;i<=E;i++)
    {
        int u,v;
        cin>>u>>v;
        addEdge(u,v,adj);
    } 
    cout<<"\nAdjacency List of Graph: \n";  
    for(int i=0;i<V;i++){
        cout<<i<<" : ";
        for(int j=0;j<adj[i].size();j++)
        {
            cout<<adj[i][j]<<" ";
        }
        cout<<"\n";
    }
    //Cycle detection using DFS
    vector<bool> vis1(V,false);
    vector<int> path(V,0);
    cout<<"\nCycle detection using DFS\n";
    for(int i=0;i<V;i++){
        if(!vis1[i])
        {
            if(checkCycleDG(i,adj,vis1,path))
            {
                cout<<"Yes, the cycle is present\n";
                return 0;

            }
        }
    }
    
    cout<<"Cycle is not present\n";
return 0;
}

/*Example test case:
6 5
0 1
0 2
1 4
2 4
3 5 
*/