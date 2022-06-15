class Solution {
public:
    int longestConsecutive(vector<int>& arr) 
    {
        int n=arr.size(),ans=0,smallest=INT_MAX,largest=INT_MIN;
        unordered_set<int>st;
        for(auto&x: arr)
            st.insert(x);
        
        
        for(int i=0;i<n;i++)
        {
            if(st.find(arr[i]-1)==st.end())
            {
                int j=arr[i]+1;
                while(st.find(j)!=st.end())
                {
                    j++;
                }
                ans=max(ans,j-arr[i]);
            }
        }
        return ans;
    }
};
