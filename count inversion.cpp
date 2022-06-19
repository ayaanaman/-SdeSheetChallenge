    vector<int>ans;
    
    void count(vector<pair<int,int>> &arr,int l,int r,int mid)
    {
        int sz1=mid-l+1;
        int sz2=r-mid;
        vector<pair<int,int>>tmp1(sz1);
        vector<pair<int,int>>tmp2(sz2);
        
        for(int i=l;i<=mid;i++)
            tmp1[i-l]=arr[i];
        
        for(int i=mid+1;i<=r;i++)
            tmp2[i-(mid+1)]=arr[i];
        
        int i=0,j=0;
        
        while(i<sz1)
        {
            if(j<sz2 && tmp1[i].first>tmp2[j].first)
            {
                
                j++;
            }
            else
            {
                ans[tmp1[i].second]+=j;
                i++;
            }
        }
        
        i=0,j=0;
        int k=l;
        
        while(i<sz1 && j<sz2)
        {
            if(tmp1[i].first<tmp2[j].first)
                arr[k++]=tmp1[i++];
            else
                arr[k++]=tmp2[j++];
        }
        while(i<sz1)arr[k++]=tmp1[i++];
        while(j<sz2)arr[k++]=tmp2[j++];
    }
    
    void mergesort(vector<pair<int,int>> &arr, int l,int r)
    {
        if(l>=r)return;
        int mid=(l+r)/2;
        mergesort(arr,l,mid);
        mergesort(arr,mid+1,r);
        count(arr,l,r,mid);
    }
    
    vector<int> countSmaller(vector<int>& nums) {
        int n=nums.size();
        ans.resize(n,0);
        vector<pair<int,int>>arr(n);
        
        for(int i=0;i<n;i++)
        {
            arr[i]={nums[i],i};
        }
        mergesort(arr,0,n-1);
        return ans;
    }
