    int maxMeetings(int start[], int end[], int n)
    {
        vector<pair<int,int>>arr;
        
        for(int i=0;i<n;i++)
            arr.push_back({end[i],start[i]});
            
        sort(arr.begin(),arr.end());
        
        int ans=1;
        int endt=arr[0].first;
        for(int i=1;i<n;i++)
        {
            if(arr[i].second>endt)
            {
                ans++;
                endt=arr[i].first;
            }
        }
        return ans;
    }
