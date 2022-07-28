    #include<bits/stdc++.h>
    using namespace std;
     
    bool isCheck(vector<int>&arr,int dist,int cow)
    {
        int first=arr[0];
        for(int i=1;i<arr.size();i++){
            if(arr[i]-first>=dist){
                first=arr[i];
                cow--;
                if(cow<=1)
                    return true;
            }
        }
        return false;
    }
     
    int main() {
        int t;
        cin>>t;
        
        while(t--){
            int n,c,ans=-1;
            cin>>n>>c;
            vector<int>arr(n);
            for(int i=0;i<n;i++)
                cin>>arr[i];
     
            sort(arr.begin(),arr.end());
            int l=arr[0],h=arr[n-1]-arr[0];
            while(l<=h)
            {
                int m=l+(h-l)/2;
                if(isCheck(arr,m,c)){
                    ans=m;
                    l=m+1;
                }
                else{
                    h=m-1;
                }
            }
            cout<<ans<<"\n";
        }
        return 0;
    } 
