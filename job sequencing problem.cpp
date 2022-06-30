    static bool comprt(Job& a,Job& b)
    {
        return a.profit>b.profit;
    }
    
    vector<int> JobScheduling(Job arr[], int n) 
    {
        sort(arr,arr+n,comprt);
        
        vector<int>job_day;
        int max_day=0;
        
        for(int i=0;i<n;i++)
            max_day=max(max_day,arr[i].dead);
        
        job_day.resize(max_day+1,-1);

        int profit=0;
        
        for(int i=0;i<n;i++)
        {
            //cout<<arr[i].dead<<" "<<t<<"\n";
            int x=arr[i].dead;
            while(job_day[x]!=-1)
                x--;
            if(x>0)
            {
                job_day[x]=1;
                profit+=arr[i].profit;
            }
        }
        
        int job_count=0;
        for(int i=1;i<max_day+1;i++)
            if(job_day[i]==1)
                job_count++;
        
        return vector<int>{job_count,profit};
    } 
