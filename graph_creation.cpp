#include<bits/stdc++.h>
using namespace std;

void addEdge(int u,int v,vector<int> adj[])
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void dfsHelper(int node, vector<int> adj[],vector<bool> &vis1)
{
    cout<<node<<" ";
    for(auto it:adj[node]){
        if(!vis1[it]){
            vis1[it]=true;
            dfsHelper(it,adj,vis1);
        }
    }
}

void bfsHelper(int node, vector<int> adj[],vector<bool> &vis2)
{
    queue<int> q;
    q.push(node);

    while(!q.empty()){
        int front = q.front();
        q.pop();
        cout<<front<<" ";
        for(auto it: adj[front])
        {
            if(!vis2[it])
            {
                vis2[it]=true;
                q.push(it);
            }
        } 
    }
}




int main() {
    //Graph Creation
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
    //DFS of Graph
    vector<bool> vis1(V,false);
    cout<<"\nDFS of Graph will be: \n";
    for(int i=0;i<V;i++){
        if(!vis1[i])
        {
            vis1[i] = true;
            dfsHelper(i,adj,vis1);
        }
    }

    //BFS of Graph
    vector<bool> vis2(V,false);
    cout<<"\nBFS of Graph will be: \n";
    for(int i=0;i<V;i++){
        if(!vis2[i])
        {
            vis2[i] = true;
            bfsHelper(i,adj,vis2);
        }
    }
    


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