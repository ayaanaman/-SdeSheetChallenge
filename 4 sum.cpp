#define ll long long
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) 
    {
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        //if(n<4) return -1;
        
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int k=j+1,m=n-1;
                while(k<m)
                {
                    ll sum=(ll)nums[i]+(ll)nums[j]+(ll)nums[k]+(ll)nums[m];
                    if(sum==target)
                    {
                        vector<int>temp={nums[i],nums[j],nums[k],nums[m]};
                        ans.push_back(temp);
                        while(k<m && nums[k]==temp[2])k++;
                        while(k<m && nums[m]==temp[3])m--;
                    }
                    else
                    if(sum<target)
                        k++;
                    else
                        m--;
                }
                while(j+1<n && nums[j+1]==nums[j])j++;
            }
            while(i+1<n && nums[i+1]==nums[i])i++;
        }
        return ans;
    }
};
