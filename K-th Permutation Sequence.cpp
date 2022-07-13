    int help(string &str,char ch,int i)
    {
        reverse(str.begin()+i,str.end());
        int upper=upper_bound(str.begin()+i,str.end(),ch)-str.begin();
        return upper;
    }
    
    string getPermutation(int n, int k) {
        string str="";
        if(k==1)
        {
            
            for(int i=1;i<=n;i++)
                str+=(i+'0');
            return str;
        }
        str=getPermutation(n,k-1);
        bool flag=false;
        
        for(int i=str.size()-1;i>0;i--)
        {
            if(str[i]>str[i-1])
            {
                flag=true;
                int indx=help(str,str[i-1],i);
                //cout<<indx;
                swap(str[i-1],str[indx]);
                break;
            }
        }
        if(!flag)
            reverse(str.begin(),str.end());
        //cout<<str<<endl;
        return str;
    }
