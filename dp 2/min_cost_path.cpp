#include<iostream>
using namespace std;

//recursion.
int min_cost2(int **input, int m, int n)
{
	int **dp = new int*[m];
	for(int i=0; i<m; i++)
	{
		dp[i] = new int[n];
	}
	dp[m-1][n-1] = input[m-1][n-1];
	// last column
	for(int i=m-2; i>=0; i--)
	{
		dp[i][n-1] = input[i][n-1] + dp[i+1][n-1];
	}
	// last row
	for(int i=n-2; i>=0; i--)
	{
		dp[m-1][i] = input[m-1][i] + dp[m-1][i+1];
	}
	// fill up the table.
	for(int i=m-2; i>=0; i--)
	{
		for(int j=n-2; j>=0; j--)
		{
			dp[i][j] = input[i][j] + min(dp[i+1][j], min(dp[i+1][j+1], dp[i][j+1]));
		}
	}
	//delete the dp array after stroing answer.
	//pending deletion
	return dp[0][0];
}

//memoization
int min_cost1(int **input, int si, int sj, int ei, int ej, int **output)
{
	// base cases.
	if(si==ei && sj==ej)
	{
		return input[si][sj];
	}
	// check boundary condition.
	if(si>ei || sj>ej)
	{
		return INT_MAX;
	}
	// check memoized value.
	if(output[si][sj] != -1)
	{
		return output[si][sj];
	}
	//normal case.
	long long option1 = min_cost1(input, si+1, sj, ei, ej, output);
	long long option2 = min_cost1(input, si+1, sj+1, ei, ej, output);
	long long option3 = min_cost1(input, si, sj+1, ei, ej, output);
	output[si][sj]= input[si][sj]+min(option1, min(option2, option3));
	return input[si][sj]+min(option1, min(option2, option3));
}

int min_cost(int **input, int si, int sj, int ei, int ej)
{
	// base cases.
	if(si==ei && sj==ej)
	{
		return input[si][sj];
	}
	// check boundary condition.
	if(si>ei || sj>ej)
	{
		return INT_MAX;
	}
	//normal case.
	long long option1 = min_cost(input, si+1, sj, ei, ej);
	long long option2 = min_cost(input, si+1, sj+1, ei, ej);
	long long option3 = min_cost(input, si, sj+1, ei, ej);
	return input[si][sj]+min(option1, min(option2, option3));
}

int main(){
	int m = 3;
	int n = 3;
	int **input = new int*[m];
	// m X n array.
	for(int i=0; i<m; i++)
	{
		input[i] = new int[n];
	}
	input[0][0] = 1;
	input[0][1] = 2;
	input[0][2] = 3;
	input[1][0] = 1;
	input[1][1] = 4;
	input[1][2] = 9;
	input[2][0] = 1;
	input[2][1] = 2;
	input[2][2] = 8;

	cout<<min_cost(input, 0, 0, 2, 2)<<endl;

	// creating output array for memoization.
	int **output = new int*[m];
	for(int i=0; i<m; i++)
	{
		output[i] = new int[n];
		for(int j=0; j<n; j++)
		{
			output[i][j] = -1;
		}
	}
	cout<<min_cost1(input, 0, 0, 2, 2, output)<<endl;
	cout<<min_cost2(input, m, n)<<endl;
}