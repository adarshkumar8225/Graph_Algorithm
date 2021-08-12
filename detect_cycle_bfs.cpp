#include <iostream>
#include <bits/stdc++.h>

using namespace std;

//vector<int> visited(N+1,0);
    

bool detect_cycle(int i,vector<int> adj_list[],vector<int> &visited)
{
    queue<pair<int,int> > q;
    q.push(make_pair(i,-1));
    visited[i]=1;
    while(!q.empty())
    {
        pair<int,int> v=q.front();
        int curr_node=v.first;
        int prev_node=v.second;
        q.pop();
        visited[curr_node]=1;
        for(auto x: adj_list[curr_node])
        {
            if(!visited[x])
            {
                q.push(make_pair(x,curr_node));
                visited[x]=1;
            }
            else 
            {
                if(x!=prev_node) return 1;
            }
        }
    }
    
    return 0;
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
            if(detect_cycle(i,adj_list,visited))
            {
                cout<<"CYCLE IN THE GRAPH";
                return 0;
            }
        }
    }
    cout<<"NO CYCLE PRESENT IN THE GRAPH";
    return 0;
}
