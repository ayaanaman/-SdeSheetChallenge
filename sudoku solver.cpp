    bool isPossible(vector<vector<char>>& board, char &num, int col, int row)
    {        
        for(int i=0;i<9;i++){
            
            if(board[row][i]==num) return false;
            if(board[i][col]==num) return false;
            if(board[3*(row/3)+ i/3][3*(col/3)+i%3]==num) return false;
            
        }
        return true;
    }
    
    bool help(vector<vector<char>>& board)
    {
        for(int i=0;i<9;i++)
        for(int j=0;j<9;j++)
        {
            if(board[i][j]=='.'){
                for(int num=1;num<=9;num++)
                {
                    char ch=num+'0';
                    if(isPossible(board,ch,j,i))
                    {
                        board[i][j]=ch;
                        if(help(board))
                            return true;
                        board[i][j]='.';
                    }
                    
                }
             return false;   
            }
        }
        return true;
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        help(board);
    }
