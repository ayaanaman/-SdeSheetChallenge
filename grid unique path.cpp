    int uniquePaths(int m, int n) {
        vector<int> pre(n,1);
        vector<int> tmp(n);
        
        for(int i=1;i<m;i++)
        {
            tmp[0]=pre[0];
            for(int j=1;j<n;j++)
            {   
                tmp[j]=pre[j]+tmp[j-1];
            }
            pre=tmp;
        }
        
        return pre[n-1];
    }
