#include <bits/stdc++.h> 
long long ans=0;

void count(long long *arr,int l,int mid,int r)
{
    int sz1=mid-l+1;
    int sz2=r-mid;
    vector<int>tmp1(sz1),tmp2(sz2);
    for(int i=l;i<=mid;i++)
        tmp1[i-l]=arr[i];
    for(int i=mid+1;i<=r;i++)
        tmp2[i-(mid+1)]=arr[i];
    int i=0,j=0,k=l;
    while(i<sz1)
    {
        //cout<<"*";
        if(j<sz2 && tmp1[i]>tmp2[j])
        {
            arr[k++]=tmp2[j++];
        }
        else
        {
            ans+=j;
            arr[k++]=tmp1[i++];
        }
    }
    while(i<sz1)
    {
        arr[k++]=tmp1[i++];
    }
    while(j<sz2)
    {
        arr[k++]=tmp2[j++];
    }
}

void merge(long long *arr,int l, int r)
{
    if(l>=r)return;
    int mid=(l+r)/2;
    merge(arr,l,mid);
    merge(arr,mid+1,r);
    count(arr,l,mid,r);
    return;
}

long long getInversions(long long *arr, int n){
    merge(arr,0,n-1);
    return ans;
}
