bool isValid(int row,int col,int c,int board[9][9] )
    {
        for(int i=0;i<9;i++)
        {
            if(board[row][i]==c)
            {
                return false;
            }
            if(board[i][col]==c)
            {
                return false;
            }
            if(board[3 * (row/3) + i/3][3 * (col/3) + i%3]==c)
            {
                return false;
            }
            
        }
        return true;
    }
bool solve(int board[9][9])
    {
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                if(board[i][j]==0)
                {
                    for(int c=1;c<=9;c++)
                    {
                        if(isValid(i,j,c,board))
                        {
                            board[i][j]=c;
                            if(solve(board)==true)
                            {
                                return true;
                            }
                            else
                            {
                                board[i][j]=0;
                            }
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    
bool isItSudoku(int matrix[9][9]) 
{
    return solve(matrix);
    // Write your code here.
}
