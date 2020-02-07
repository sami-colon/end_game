#include<bits/stdc++.h>
using namespace std;

// memoization of basic recusrion 2
int getCount2(string s1, string s2, int m, int n, int **dp)
{
	// base case 1
	if(n == 0)
	{
		return m;
	}
	// base case 2
	if(m == 0)
	{
		return n;
	}
	if(dp[m-1][n-1] != -1)
	{
		return dp[m-1][n-1];
	}
	// if character is same.
	if(s1[m-1] == s2[n-1])
	{
		return getCount2(s1, s2, m-1, n-1, dp);
	}
	// for different characters.
	// do insert.
	int option1 = getCount2(s1, s2, m, n-1, dp);
	// do remove.
	int option2 = getCount2(s1, s2, m-1, n, dp);
	// do replace.
	int option3 = getCount2(s1, s2, m-1, n-1, dp);
	dp[m-1][n-1] = 1 + min(option1, min(option2, option3));
	return 1 + min(option1, min(option2, option3));
}

// basic recursion 2.
int getCount1(string s1, string s2, int m, int n)
{
	// base case 1
	if(n == 0)
	{
		return m;
	}
	// base case 2
	if(m == 0)
	{
		return n;
	}
	// if character is same.
	if(s1[m-1] == s2[n-1])
	{
		return getCount1(s1, s2, m-1, n-1);
	}
	// for different characters.
	// do insert.
	int option1 = getCount1(s1, s2, m, n-1);
	// do remove.
	int option2 = getCount1(s1, s2, m-1, n);
	// do replace.
	int option3 = getCount1(s1, s2, m-1, n-1);
	return 1 + min(option1, min(option2, option3));
}

// basic recursion.
int getCount(string s1, string s2)
{
	// base case both string ends.
	if(s1[0]=='\0' && s2[0]=='\0')
	{
		return 0;
	}
	// one string didnt end.
	if((s1[0]=='\0' && s2[0]!='\0') || (s1[0]!='\0' && s2[0]=='\0'))
	{
		return INT_MAX;
	}
	// current character matches.
	if(s1[0] == s2[0])
	{
		return getCount(s1.substr(1), s2.substr(1));
	}
	// cuurent character donot matches.
	if(s1[0] != s2[0])
	{
		// do insert.
		int option1 = getCount(s2[0]+s1, s2);
		// do remove.
		int option2 = getCount(s1.substr(1), s2);
		// do replace.
		s1[0] = s2[0];
		int option3 = getCount(s1, s2);
		return 1 + min(option1, min(option2, option3));
	}
}

int main()
{
	string s1 = "geek";
	string s2 = "saturday";
	cout<<getCount(s1, s2)<<endl;
	cout<<getCount1(s1, s2, s1.size(), s2.size())<<endl;
	int ** dp = new int*[s1.size()];
	for(int i=0;i<s1.size();i++)
	{
		dp[i] = new int[s2.size()];
		for(int j=0;j<s2.size(); j++)
		{
			dp[i][j] = -1;
		}
	}
	cout<<getCount2(s1, s2, s1.size(), s2.size(), dp)<<endl;
}