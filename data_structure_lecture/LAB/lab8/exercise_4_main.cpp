#include <iostream>
using namespace std;


int NumPaths(int row, int col, int n)
{
	if ((row == n) || (col == n))
		return 1;
	else
		return NumPaths(row + 1, col, n) + NumPaths(row, col + 1, n);
}


const int MAX_ROWS = 100, MAX_COLS = 100;
int mat[MAX_ROWS][MAX_COLS];

int NumPaths_C(int row, int col, int n)
{
	if (mat[row][col] == -1) 
	{ 
		mat[row][col] = NumPaths(row, col, n);
	}
	return mat[row][col];
}

int main()
{
	for (int i = 0; i < MAX_ROWS; i++)
	{
		for (int j = 0; j < MAX_COLS; j++)
			mat[i][j] = -1;
	}
	cout << NumPaths(2, 2, 3) <<endl;
	cout << NumPaths_C(0, 0, 3) << endl;
	return 0;
}