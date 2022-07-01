	int minCoins(int coins[], int M, int V) 
	{
	    //vector<vector<int>>dp;
	    vector<int>prev(V+1,0),curr(V+1,0);
	    //dp.resize(M+1,vector<int>(V+1));
	    
	    for(int j=0;j<V+1;j++)
	    {

	        if(j%coins[0]==0)
	            prev[j]=j/coins[0];
	        else
	            prev[j]=1e9;
	    }
	    
	    for(int i=1;i<M;i++)
        {
            for(int j=0;j<V+1;j++)
    	    {
    	        if(coins[i]<=j)
    	            curr[j]=min(1+curr[j-coins[i]],prev[j]);
    	        else
    	            curr[j]=prev[j];
    	    }
    	    prev=curr;
        }
	   // for(auto &x:curr)
	   //     cout<<x<<" ";
	    return prev[V]!=1e9?prev[V]:-1;
	}
