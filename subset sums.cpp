vector<int>ans;
    void help(vector<int> &arr,int i,int &sum)
    {
        if(i==arr.size())
        {
            ans.push_back(sum);
            return;
        }
        
        sum+=arr[i];
        help(arr,i+1,sum);
        sum-=arr[i];
        help(arr,i+1,sum);
        
    }
    
    vector<int> subsetSums(vector<int> arr, int N)
    {
        int sum=0;
        help(arr,0,sum);
        return ans;
    }
