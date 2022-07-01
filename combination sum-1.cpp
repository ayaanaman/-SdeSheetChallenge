    vector<vector<int>>ans;
    
    void help(vector<int>&cand, int i, vector<int>tmp, int target)
    {
        if(target==0)
        {
            ans.push_back(tmp);
            return;
        }
        if(i==cand.size()) return;
        
        if(cand[i]<=target)
        {
            tmp.push_back(cand[i]);
            help(cand,i,tmp,target-cand[i]);
            tmp.pop_back();
            help(cand,i+1,tmp,target);
        }
        else
            help(cand,i+1,tmp,target);
        return;
    }
    
    vector<vector<int>> combinationSum(vector<int>& cand, int target) {
        vector<int>tmp;
        help(cand,0,tmp,target);
        return ans;
    }
