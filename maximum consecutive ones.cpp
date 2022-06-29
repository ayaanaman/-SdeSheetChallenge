        int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxLen = 0;
        int curLen = 0;
        for(int i=0;i<nums.size();++i){
            if(nums[i]==1){
                curLen++;
            }
            else{
                if(curLen>maxLen)
                    maxLen = curLen;
                curLen = 0;
            }
        }
        if(curLen>maxLen)
            maxLen = curLen;
        return maxLen;
    }
