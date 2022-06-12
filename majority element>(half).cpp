    int majorityElement(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end());
        
        int i=0,j=nums.size()/2;
        
        while(j<nums.size())
        {
            if(nums[i]==nums[j])
                return nums[i];
            j++;
            i++;    
        }
        return -1;
    }
    
