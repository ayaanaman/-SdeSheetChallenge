bool ispossible(vector<vector<int> > &A,int num,int thres)
{
    int count=0;
    for(int i=0;i<A.size();i++)
    {
        count+=lower_bound(A[i].begin(),A[i].end(),num)-A[i].begin();
    }
    
    if(count<=thres)
    {
       // cout<<count<<" ";
        return true;
    }
    return false;
}

int Solution::findMedian(vector<vector<int>> &A) {
    int maxi=INT_MIN,mini=INT_MAX;
    int row=A[0].size()-1;
    // for(int i=0;i<A.size();i++)
    for(int j=0;j<A.size();j++)
    {
        mini=min(mini,A[j][0]);
        maxi=max(maxi,A[j][row]);
    }
    
    int l=mini,h=maxi,ans;
    int N=A.size(),M=A[0].size();
    int thres=(N*M)/2;
    //thres+=1;

    while(l<=h)
    {
        int m=l+(h-l)/2;
        if(ispossible(A,m,thres))
        {
            //cout<<m<<",";
            l=m+1;
            ans=m;
        }
        else
            h=m-1;
    }
    
    return ans;
}
