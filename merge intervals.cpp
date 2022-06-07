class Solution {
public:
    bool static cmp(vector<int>v1,vector<int>v2)
    {
        if(v1[0]!=v2[0])
            return v1[0]<v2[0];
        return v1[1]>v2[1];
    }
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        vector<vector<int>>ans;
        vector<int>temp;
        
        sort(intervals.begin(),intervals.end());
        int l=intervals[0][0],r=intervals[0][1];
        
       for(int i=1;i<intervals.size();i++)
       {
           if(intervals[i][0]>r)
           {
               temp={l,r};
               ans.push_back(temp);
               temp.clear();
               l=intervals[i][0];
               r=intervals[i][1];
           }
           else
           if(intervals[i][0]<=r)
           {
               r=max(r,intervals[i][1]);
           }
       }
        temp={l,r};
        ans.push_back(temp);
        return ans;
      }
};
