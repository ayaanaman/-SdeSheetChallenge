    string getPermutation(int n, int k) {
        string str="";
        if(k==1)
        {
            
            for(int i=1;i<=n;i++)
                str+=(i+'0');
            return str;
        }
        str=getPermutation(n,k-1);
        
        return next_permutation(str.begin(),str.end());
    }
