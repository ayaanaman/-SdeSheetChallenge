class Solution {
public:
    bool check(vector<vector<int>>& matrix,int target, int row ,int n)
    {
        int m,f=0,l=n-1;
        while(f<=l)
        {
             m=(f+l)/2;
            if(target==matrix[row][m])
                return true;
            else
            if(target>matrix[row][m])
                f=m+1;
            else
            if(target<matrix[row][m])
                l=m-1;
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
       
        int n=matrix[0].size();
        int f=0,l=matrix.size()-1,m;
        while(f<=l)
        {
            m=(f+l)/2;
            if(matrix[m][0]<=target && matrix[m][n-1]>=target)
                return check(matrix,target,m,n);
            else
            if(matrix[m][n-1]<target)
                f=m+1;
            else
            if(matrix[m][0]>target)
                l=m-1;
        }
        return false;
    }
};
