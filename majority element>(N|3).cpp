class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        
        if(nums.size()==1)
            return vector<int>(1,nums[0]);
        
        int i=0,j=nums.size()/3;
        vector<int>result;
        if(nums.size()==2)
        {
            result.push_back(nums[i]);
            if(nums[i]!=nums[i+1])
                result.push_back(nums[i+1]);
            return result;
        }
        
        int pre=INT_MIN;
        while(j<nums.size())
        {
            if(nums[i]==nums[j] && pre!=nums[i])
            {
                pre=nums[i];
                result.push_back(nums[i]);
            }
            i++;
            j++;
        }
        return result;
    }
};
