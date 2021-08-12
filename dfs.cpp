#include <iostream>
#include <bits/stdc++.h>

using namespace std;

//vector<int> visited(N+1,0);
    

void dfs(int i,vector<int> adj_list[],vector<int> &visited)
{
    visited[i]=1;
    cout<<i<<" ";
    for(auto x:adj_list[i])
    {
        if(!visited[x])
        {
            dfs(x,adj_list,visited);
        }
    }
    return;
}

int main()
{
    int N,M;
    cin>>N>>M;
    vector<int> adj_list[N+1];
    for(int i=0;i<M;i++)
    {
        int u,v;
        cin>>u>>v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
        
    }
    vector<int> visited(N+1,0);
    
    for(int i=1;i<=N;i++)
    {
        if(!visited[i])
        {
            dfs(i,adj_list,visited);
        }
    }

    return 0;
}
