    vector<vector<int>>ans;
    //set<vector<int>>ans;
    void help(vector<int>&cand, int i, vector<int>& tmp, int target)
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
            help(cand,i+1,tmp,target-cand[i]);
            tmp.pop_back();
            help(cand,i+1,tmp,target);
        }
        return;
    }
    
    vector<vector<int>> combinationSum2(vector<int>& cand, int target) {
        sort(cand.begin(),cand.end());
        vector<int>tmp;
        help(cand,0,tmp,target);
        
        //for(auto& x:ans)
            //ans2.push_back(x);
        
        return ans;
    }
