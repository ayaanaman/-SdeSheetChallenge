    vector<int>ans;
    
    void help(vector<int>&arr, int N,int i, int &sum)
    {
        
        if(i==N){ans.push_back(sum); return;}
        
        sum+=arr[i];
        help(arr,N,i+1,sum);
        sum-=arr[i];
        help(arr,N,i+1,sum);
        return;
    }
    vector<int> subsetSums(vector<int> arr, int N)
    {
        int sum=0;
        help(arr,N,0,sum);
        return ans;
    }
