// { Driver Code Starts
// C++ program to find minimum number of swaps
// required to sort an array
#include<bits/stdc++.h>
using namespace std;

int minSwaps(int A[], int N);

// Driver program to test the above function
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int a[n];
	    for(int i=0;i<n;i++)
	    cin>>a[i];
	    cout<<minSwaps(a,n)<<endl;
	}
}

// } Driver Code Ends


/* You are required to complete this method */
int minSwaps(int A[], int N){
    /*Your code here */
    int ans = 0;
    map<int, bool>visited;
    
    int sorted_arr[N];
    for(int i=0; i<N; i++){
        sorted_arr[i] = A[i];
        visited[A[i]] = false;
    }
    sort(sorted_arr, sorted_arr + N);
    
    for(int i=0; i<N; i++)
    {
        if(!visited[A[i]])
        {
            visited[A[i]] = true;
            if(A[i] != sorted_arr[i])
            {
                int cycle = 1;
                int curr = sorted_arr[i];
                while(visited[curr] != true)
                {
                    int j=0;
                    for(j=0; j<N; j++)
                    {
                        if(A[j] == curr)
                        break;
                    }
                    visited[curr] = true;
                    curr = sorted_arr[j];
                    cycle++;
                }
                ans += cycle - 1;
            }
        }
    }
    return ans;
}
