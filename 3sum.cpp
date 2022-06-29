    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>ans;
        
        if(nums.size()<3)return ans;
        
        sort(nums.begin(),nums.end());
        
        int i=0,j=nums.size()-1;
        
        for(int i=0;i<nums.size()-2;i++)
        {
            int k=i+1;
            j=nums.size()-1;
            while(j>k)
            {
                int sum=nums[i]+nums[j]+nums[k];
                if(sum<0) k++;
                else
                if(sum==0)
                {    
                    ans.push_back(vector<int>{nums[i],nums[k],nums[j]});
                    k++;
                    j--;
                    while(j>k && nums[k-1]==nums[k])k++;
                    while(j>k && nums[j]==nums[j+1])j--;
                }
                else
                    j--;
                
                while(i<nums.size()-2 && nums[i]==nums[i+1])i++;
            }
        }
        return ans;
    }
