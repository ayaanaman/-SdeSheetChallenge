    vector<vector<string>>ans;
    bool ischeck(vector<string> &grid, int r, int c,int dim)
    {
        for(int i=0;i<=r;i++)
            if(grid[i][c]=='Q') return false;
        int i=r-1;
        int j=c+1;
        while(i>=0 && j<dim)
        {
            if(grid[i][j]=='Q')
                return false;
            i--;
            j++;
        }
        
        i=r-1;
        j=c-1;
        while(i>=0 && j>=0)
        {
            if(grid[i][j]=='Q')
                return false;
            i--;
            j--;
        }
        return true;
    }
    
    bool help(vector<string> &grid, int n, int dim, int r)
    {
        if(n==0)
        {
            //ans.push_back(grid);
            return true;
        }
        
        for(int i=0;i<dim;i++)
        {
            if(ischeck(grid,r,i,dim))
            {
                grid[r][i]='Q';
                if(help(grid,n-1,dim,r+1))
                    return true;
            }
            grid[r][i]='.';
        }
        return false;
    }
    
    vector<vector<string>> solveNQueens(int n){
        string str="";
        for(int i=0;i<n;i++)
            str+='.';
        vector<string>grid(n,str);
        help(grid,n,n,0);
        for(int i=0;i<grid.size();i++)
            cout<<grid[i]<<endl;
        return ans;
    }
