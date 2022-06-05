
void rotateMatrix(vector<vector<int>> &mat, int n, int m)
{
	int row=0,col=0,last_row=n,last_col=m,prev,curr;
	while(row<last_row && col<last_col)
	{
		 if(row+1==last_row || col+1==last_col)
           break;
		prev=mat[row+1][col];
		for(int i=col;i<last_col;i++)
		{
			curr=mat[row][i];
			mat[row][i]=prev;
			prev=curr;
		}
		row++;
		for(int i=row;i<last_row;i++)
		{
			curr=mat[i][last_col-1];
			mat[i][last_col-1]=prev;
			prev=curr;
		}
		last_col--;
		if(row<last_row)
		{
			for(int i=last_col-1;i>=col;i--)
			{
				curr=mat[last_row-1][i];
				mat[last_row-1][i]=prev;
				prev=curr;
			}
		}
		last_row--;
		if(col<last_col)
		{
			for(int i=last_row-1;i>=row;i--)
			{
				curr=mat[i][col];
				mat[i][col]=prev;
				prev=curr;
			}
		}
		col++;
	}

}
