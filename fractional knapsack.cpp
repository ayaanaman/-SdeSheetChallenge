    double fractionalKnapsack(int W, Item arr[], int n)
    {
        vector<pair<double,int>>v;
        for(int i=0;i<n;i++)
        {
            v.push_back({double(arr[i].value)/double(arr[i].weight),arr[i].weight});    
        }
        
        sort(v.begin(),v.end(),greater<>());
        int i=0;
        double ans=0;
        
        while(i<n && W>0)
        {
            // while(v[i].second==0)
            //     i++;
                
            //cout<<W<<"-"<<i<<" ";
            if(W<v[i].second)
            {
                ans+=(v[i].first*W);
                break;
            }
            else
            {
                ans+=(v[i].first*v[i].second);
                W-=v[i].second;
                v[i].second=0;
            }
            i++;
        }
        return ans;
    }
