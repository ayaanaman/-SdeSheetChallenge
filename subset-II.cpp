    vector<vector<int>>ans2;
    set<vector<int>>ans;
    void sol(vector<int>& nums,vector<int> tmp,int i)
    {
        if(i>=nums.size()) {
            sort(tmp.begin(),tmp.end());
            ans.insert(tmp); return;}
        tmp.push_back(nums[i]);
        sol(nums,tmp,i+1);
        tmp.pop_back();
        sol(nums,tmp,i+1);
        tmp.pop_back();
        
        return;
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        int i=0;
        vector<int>tmp;
        sol(nums,tmp,i);
        for(auto& x:ans)
            ans2.push_back(x);
        return ans2;
    }
