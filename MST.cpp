class Solution
{
	public:
	//Returns minimum vakue ndex among those nodes which are not included till now
	int min_val(int key[],int MST[],int N)
	{
	    int min_index,min_val=INT_MAX;
	    for(int i=0;i<N;i++)
	    {
	        //MST[i] makes sure that this ith node is not included till now in MST
	        if(key[i]<min_val && MST[i]==0 )
	        {
	            min_index=i;
	            min_val=key[i];
	        }
	    }
	    return min_index;
	}
	
	
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        int key[V];
        int MST[V];
        int parent[V];
        for(int i=0;i<V;i++) 
        {
            key[i]=INT_MAX;
            MST[i]=0;
            parent[i]=-1;
        }
        key[0]=0;

        int curr_node,weight,adj_node;
        int vertex=V;
        //Run loop to include every vertex in MST
        while(vertex--)
        {
            //current node is one with minimum key value which is not visited till now
            curr_node=min_val(key,MST,V);
            MST[curr_node]=1;//Include current node in MST by making it to 1
            
            //NOW find the adjacent nodes of current node
            for(auto x: adj[curr_node])
            {
                //store the adjacent node and weight
                 weight=x[1];
                 adj_node=x[0];
                 //Check whether current not is not included in MST
                if(MST[adj_node]==0 )
                {
                    //if weight to include adjacent node is lesser than previous value
                    if(weight<key[adj_node])
                    {
                        key[adj_node]=weight; //update.... this is the least weight to include this adjacent node till now
                        parent[adj_node]=curr_node;//update the current node as the new parent node
                    }
                }
            }
        }
        //USED to Find the total cost of MST
        int sum=0;
        for(int i=0;i<V;i++) sum+=key[i];
        //Print the MST if they ask to print it
        for(int i=1;i<V;i++)
        {
            cout<<parent[i]<<" "<<i<<" "<<key[i]<<endl;
        }
        
        
        return sum;
        
        
        
    }
};
