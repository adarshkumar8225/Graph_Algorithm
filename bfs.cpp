#include <iostream>
#include <bits/stdc++.h>

using namespace std;

//vector<int> visited(N+1,0);
    

void bfs(int i,vector<int> adj_list[],vector<int> &visited)
{
    queue<int> q;
    q.push(i);
    //visited[i]=1;
    while(!q.empty())
    {
        int curr_node=q.front();
        visited[curr_node]=1;
        cout<<curr_node<<" ";
        q.pop();
        int k=0;
        for(auto x : adj_list[curr_node])
        {
            if(!visited[x])
            {
                q.push(x);
                visited[x]=1;
            }
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
            bfs(i,adj_list,visited);
        }
    }

    return 0;
}
