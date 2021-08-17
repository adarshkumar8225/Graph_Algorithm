#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void dfs(int node,vector<pair<int,int>> graph[],int visited[])
{
    int curr_node=node;
    
    if(visited[curr_node]==1) return;
    else
    {
        auto p=graph[curr_node];
        //cout<<curr_node<<" "<<endl;
        visited[curr_node]=1;
        for(auto x : graph[curr_node])
        {
            if(!visited[x.first])
            {
                cout<<curr_node<<"-"<<x.first<<" "<<"weight="<<x.second<<endl;
                dfs(x.first,graph,visited);
            }
        }
        
    }
    
}


int main()
{
    //N no. of nodes and M no. of edges.
    int N,M;
    cin>>N>>M;
    
    vector<pair<int,int> > graph[N+1];
    int u,v,w;
    for(int i=0;i<M;i++)
    {
        cin>>u>>v>>w;
        graph[u].push_back(make_pair(v,w));
        graph[v].push_back(make_pair(u,w));
    }
    int visited[N+1]={0};
    
    for(int i=1;i<=N;i++)
    {
        if(!visited[i])
        {
            dfs(i,graph,visited);
        }
    }
    
    return 0;
}
