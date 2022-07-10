    vector<vector<string>>ans;
    
    bool ispalindrom(string &str,int i,int j)
    {
        while(i<j)
        {
            if(str[i++]!=str[j--])
                return false;
        }
        return true;
    }
    
    void help(string &s,vector<string>curr,int start,int end)
    {
        if(start>=s.size()) ans.push_back(curr);        
        
        for(int k=start;k<end;k++)
        {
            if(ispalindrom(s,start,k))
            {
                curr.push_back(s.substr(start,k-start+1));
                help(s,curr,k+1,end);
                curr.pop_back();
            }
        }

    }
    
    vector<vector<string>> partition(string s) {
        
        vector<string>curr;
        help(s,curr,0,s.size());
        return ans;
    }
