class Solution {
public:
    void help(vector<vector<int>>& matrix,int r, int c)
    {
        for(int i=0;i<matrix.size();i++)
            if(matrix[i][c]!=0)
                 matrix[i][c]=-1e9;
        for(int i=0;i<matrix[0].size();i++)
            if(matrix[r][i]!=0)
                matrix[r][i]=-1e9;
    }
    
    void setZeroes(vector<vector<int>>& matrix) {
        for(int i=0;i<matrix.size();i++)
            for(int j=0;j<matrix[0].size();j++)
            {
                if(matrix[i][j]==0)
                    help(matrix,i,j);
            }
        
        for(int i=0;i<matrix.size();i++)
            for(int j=0;j<matrix[0].size();j++)
            {
                if(matrix[i][j]==-1e9)
                    matrix[i][j]=0;
            }
    }
};
