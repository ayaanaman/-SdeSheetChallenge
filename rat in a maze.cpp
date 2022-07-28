    vector<string>ans;
    
    void help(vector<vector<int>> &m, int r,int c,int n,string &str)
    {
        if(r==n-1 && c==n-1 && m[r][c]==1)
        {
            ans.push_back(str);
            return;
        }
        if(r<0 || c<0 || r>=n || c>=n || m[r][c]==0) return;
        
        str+='D';
        m[r][c]=0;
        help(m,r+1,c,n,str);
        str.pop_back();
        str+='R';
        help(m,r,c+1,n,str);
        str.pop_back();
        str+='L';
        help(m,r,c-1,n,str);
        str.pop_back();
        str+='U';
        help(m,r-1,c,n,str);
        str.pop_back();
        m[r][c]=1;
        return;
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        string str="";
        help(m,0,0,n,str);
        return ans;
    }
