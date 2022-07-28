    int BS(vector<int>& nums, int start, int end, int x)
    {
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            
            if(nums[mid]==x)
                return mid;
            if(nums[mid]<x)
                start=mid+1;
            else
            if(nums[mid]>x)
                end=mid-1;
        }
        return -1;
    }
    
    int pivotIndex(vector<int>& nums,int n)
    {
        int start=0,end=n-1;
         while(start<=end)
         {
             int mid=start+(end-start)/2;
             if(nums[mid]<nums[(mid+n-1)%n] && nums[mid]<=nums[(mid+1)%n])
                 return mid;
             if(nums[mid]<=nums[end])
                 end=mid-1;
             else
             if(nums[start]<=nums[mid])
                 start=mid+1;
         }
        return 0;
    }
    
    int search(vector<int>& nums, int target) 
    {
        int pivt=pivotIndex(nums,nums.size());
        int f=BS(nums,0,(pivt-1+nums.size())%nums.size(),target);
        if(f==-1)
            return BS(nums,pivt,nums.size()-1,target);
        return f;
    }
