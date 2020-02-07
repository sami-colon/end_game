#include<bits/stdc++.h>
using namespace std;

// memoization
int f1(int *a, int s, int e, int **dp){
    // base case
    // single element i.e no matrix; or single matrix.
    int ans = INT_MAX;
    if(s == e || s+1 == e){
        return 0;
    }
    if(dp[s][e] != -1){
        return dp[s][e];
    }
    else{
        for(int k=s+1; k<=e-1; k++){
            int option = f1(a, s, k, dp) + f1(a, k, e, dp) + (a[s]*a[k]*a[e]);
            ans = min(ans, option);
        }
        dp[s][e] = ans;
        return ans;
    }
}

// basic recusrion.
int f(int * a, int s, int e){
    // base case
    // single element i.e no matrix; or single matrix.
    int ans = INT_MAX;
    if(s == e || s+1 == e){
        return 0;
    }
    else{
        for(int k=s+1; k<=e-1; k++){
            int option = f(a, s, k) + f(a, k, e) + (a[s]*a[k]*a[e]);
            ans = min(ans, option);
        }
        return ans;
    }
    
}
int mcm(int* p, int n){

  /* Don't write main().
   *  Don't read input, it is passed as function argument.
   *  Return output and don't print it.
   *  Taking input and printing output is handled automatically.
  */
    // return f(p, 0, n);
    int ** dp = new int*[n+1];
    for(int i=0; i<n+1; i++){
        dp[i] = new int[n+1];
        for(int j=0; j<n+1; j++){
            dp[i][j] = -1;
        }
    }
    return f1(p, 0, n, dp);
}
