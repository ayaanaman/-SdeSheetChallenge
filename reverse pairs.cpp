class Solution {
public:
    int ans=0;
    
    void count(vector<int>&nums,int l,int mid ,int r)
    {
        int sz1=mid-l+1;
        int sz2=r-mid;
        vector<int>tmp1(sz1),tmp2(sz2);
        
        for(int i=l;i<=mid;i++)
            tmp1[i-l]=nums[i];
        
        for(int i=mid+1;i<=r;i++)
            tmp2[i-(mid+1)]=nums[i];
        
        int i=0,j=0,k=l;
        while(i<sz1)
        {
            if(j<sz2 && double(tmp1[i])/2.0>double(tmp2[j]))
            {
                j++;
            }
            else
            {
                ans+=j;
                i++;
            }
        }
        
        i=0,j=0;
        while(i<sz1 && j<sz2)
        {
            if(tmp1[i]<tmp2[j])
                nums[k++]=tmp1[i++];
            else
                nums[k++]=tmp2[j++];
        }
        while(i<sz1)
            nums[k++]=tmp1[i++];
        while(j<sz2)
            nums[k++]=tmp2[j++];
    }
    
    void merge(vector<int>&nums,int l,int r)
    {
        if(l>=r)return;
        int mid=(l+r)/2;
        merge(nums,l,mid);
        merge(nums,mid+1,r);
        count(nums,l,mid,r);
        return;
    }
    
    int reversePairs(vector<int>& nums) {
        int n=nums.size();
        merge(nums,0,n-1);
        return ans;
    }
};
