#include<bits/stdc++.h>
using namespace std;
// dp using bottom up appraoch.
int lcs2(string s1, string s2, int n, int m){
	n++;m++;
	int ** dp = new int*[n];
	for(int i=0; i<n; i++){
		dp[i] = new int[m];
	}
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if( i == 0 || j == 0){
				dp[i][j] = 0;
			}
			else{
				dp[i][j] = max(dp[i-1][j-1], max(dp[i-1][j], dp[i][j-1]));
				if(s1[i-1] == s2[j-1]){
					dp[i][j]+=1;
				}
			}
		}
	}
	return dp[n-1][m-1];
}

// memoization.
int lcs1(string s1, string s2, int n, int m, int **dp){
	if(n == 0 || m == 0){
		return 0;
	}
	if(dp[n-1][m-1] != -1){
		return dp[n-1][m-1];
	}
	if(s1[n-1] == s2[m-1]){
		dp[n-1][m-1] = 1 + lcs1(s1, s2, n-1, m-1, dp);
		return dp[n-1][m-1];
	}
	else{
		dp[n-1][m-1] = max(lcs1(s1, s2, n-1, m-1, dp), max(lcs1(s1, s2, n-1, m, dp), lcs1(s1, s2, n, m-1, dp)));
		return dp[n-1][m-1];
	}
}

// basic recusrion.
int lcs(string s1, string s2, int n, int m){
	if(n == 0 || m == 0){
		return 0;
	}
	if(s1[n-1] == s2[m-1]){
		return 1 + lcs(s1, s2, n-1, m-1);
	}
	else{
		return max(lcs(s1, s2, n-1, m-1), max(lcs(s1, s2, n-1, m), lcs(s1, s2, n, m-1)));
	}
}

int main(){
	string s1 = "00a1b2c3defghabcd";
	string s2 = "abcde";
	cout << lcs(s1, s2, s1.size(), s2.size())<< endl;
	// dp array build.
	int **dp = new int *[s1.size()];
	for(int i=0;i<s1.size();i++)
	{
		dp[i] = new int[s2.size()];
		for(int j=0;j<s2.size(); j++)
		{
			dp[i][j] = -1;
		}
	}
	cout<< lcs1(s1, s2, s1.size(), s2.size(), dp) << endl;
	cout << lcs2(s1, s2, s1.size(), s2.size()) << endl;
	return 0;
}