#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void bfs(int node,vector<pair<int,int>> graph[],int visited[])
{
    queue<pair<int,int> > q;
    q.push(make_pair(node,0));
    visited[node]=1;
    //auto curr_node;
    while(!q.empty())
    {
       auto curr_node=q.front();
       q.pop();
       cout<<curr_node.first<<"  "<<curr_node.second<<endl;
       for(auto x: graph[curr_node.first])
       {
           if(!visited[x.first])
           {
               q.push(make_pair(x.first,x.second));
               visited[x.first]=1;
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
            bfs(i,graph,visited);
        }
    }
    
    return 0;
}
