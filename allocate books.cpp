bool  isCheck(vector<int> &A,int limit, int B)
{
    int student=0;
    int pages=0;
    int i=0;
    while(i<A.size())
    {
        if(A[i]>limit)
            return false;
        if(A[i]+pages>limit)
        {
            B--;
            pages=A[i];
        }
        else
            pages+=A[i];
        i++;
    }
    if(B>=1 && pages<=limit)
        return true;
    return false;
}
int Solution::books(vector<int> &A, int B) {
    int n=A.size();
    if(n<B)
        return -1;
    int sum=0;
    for(auto &x:A)
        sum+=x;
        
    int l=0,h=sum,ans=-1;
    while(l<=h)
    {
        int m=l+(h-l)/2;
        if(isCheck(A,m,B)){
            h=m-1;
            //cout<<h<<","<<m<<" ";
            ans=m;
        }
        else{
            l=m+1;
        }
    }
    return ans;
}
