    vector<vector<int>>ans;
    void help(vector<int>& nums, vector<int>& tmp)
    {
        if(tmp.size()==nums.size())
        {
            ans.push_back(tmp);
            return;
        }
        
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==INT_MAX) continue;
            
            tmp.push_back(nums[i]);
            int n=nums[i];
            nums[i]=INT_MAX;
            
            help(nums,tmp);
            
            tmp.pop_back();
            nums[i]=n;
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int>tmp;
        help(nums,tmp);
        return ans;
    }
