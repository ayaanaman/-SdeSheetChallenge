    int findPlatform(int arr[], int dep[], int n)
    {
    	sort(arr,arr+n);
    	sort(dep,dep+n);
    	
    	int i=1,j=0;
    	int ans=0,cnt=1;
    	
    	while(i<n && j<n)
    	{
    	    if(arr[i]<=dep[j])
    	    {
    	        i++;
    	        cnt++;
    	    }
    	    else
    	    {
    	        j++;
    	        ans=max(ans,cnt);
    	        cnt--;
    	    }
    	}
    	ans=max(ans,cnt);
    	return ans;
    }
