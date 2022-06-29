    int removeDuplicates(vector<int>& nums) 
    {
        if(nums.size()<=1)
            return nums.size();
    
        int i,j,n=nums.size();
        
        for(i=1,j=1;j<n;j++)
        {
            if(nums[j]!=nums[j-1])
                nums[i++]=nums[j];
        }
        
        return i;
    }
