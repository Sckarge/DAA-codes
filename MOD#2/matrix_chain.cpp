/*
p--> Dimensions of the matrices
dp -->array for memoization
*/
#include <bits/stdc++.h>
using namespace std;
int dp[100][100];

int mc_memoiz(int p[], int i, int j)
{
    // First of all lets see if we are trying a multiplication of just one number
    if (i == j)
    {
        dp[i][j] = 0;
        return 0; // no cost of multiplication
    }
    // Also when using memoization if we have already solved for the case then we simply use that value
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    // Now we move on to the case for which we need to calculate
    dp[i][j] = INT_MAX; // current min in the loop
    for (int k = i; k < j; k++)
    {                                                                                    // the iterable k here is the place where the matrix is split or multiplied
        int temp = mc_memoiz(p, i, k) + mc_memoiz(p, k + 1, j) + p[i - 1] * p[k] * p[j]; // i-1 here because we want the
        // first dimension of the matrix we are starting at
        dp[i][j] = min(dp[i][j], temp);
    }
    return dp[i][j]; // return the now optimum value
}

int exec(int *p, int n)
{
    int i = 1, j = n - 1; // because the indexing ends at n-1
    return mc_memoiz(p, i, j);
}

int main()
{
    int n;
    cout << "Size of array: ";
    cin >> n;
    int *arr = new int[n];
    cout << "Enter array: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    //int arr[] = {1, 2, 3, 4};
    //int n = sizeof(arr) / sizeof(arr[0]);
    memset(dp, -1, sizeof dp);
    cout << "Minimum number of multiplications is "
         << exec(arr, n) << endl;
}