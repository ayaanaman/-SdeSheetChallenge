class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i=0,j=0;
        unordered_map<char,int>mp;
        int ans=0;
        
        while(j<s.size())
        {
            mp[s[j]]++;
            while(mp[s[j]]>1)
            {
                ans=max(ans,j-i);
                mp[s[i]]--;
                i++;
            }
            j++;
        }
        ans=max(ans,j-i);
        return ans;
    }
};
