class Solution {
public:
    int help(vector<int>& nums,int tar,int i)
    {
        reverse(nums.begin()+i,nums.end());
        vector<int>::iterator upper=upper_bound(nums.begin()+i,nums.end(),tar);
        int indx=upper-nums.begin();
        return indx;
    }
    void nextPermutation(vector<int>& nums) {
        bool flag=false;
        for(int i=nums.size()-1;i>0;i--)
        {
            if(nums[i]>nums[i-1])
            {
                flag=true;
                int indx=help(nums,nums[i-1],i);
                swap(nums[i-1],nums[indx]);
                break;
            }
        }
        if(!flag)
            reverse(nums.begin(),nums.end());
    }
};
