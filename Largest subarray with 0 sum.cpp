
int maxLen(int A[], int n)
{
    unordered_map<int,int>mp;
    int ans=0,sum=0;
    //mp[0]=0;
    for(int i=0;i<n;i++)
    {
        sum+=A[i];
        if(mp[sum] || sum==0)
            ans=max(ans,i+1-mp[sum]);
        else
            mp[sum]=i+1;
    }
return ans;
    
}
