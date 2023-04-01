// Here is the top-down approach of
// dynamic programming
#include <bits/stdc++.h>
using namespace std;

// This function recursively calculates the max profit
int knapsackRec(int W, int wt[], int val[], int i, int **dp)
{
    // base case
    if (i == 0)
        return 0;
    // Case 1: This value for current capcaity left and i value is already calculated
    if (dp[i][W] != -1)
    {
        return dp[i][W];
    }
    // Case 2: We cannot include this item in our sack because it would exceed our capacity
    if (W < wt[i])
    {
        dp[i][W] = knapsackRec(W, wt, val, i - 1, dp); // The capacity is not reduced but the object is included
        return dp[i][W];
    }
    // Case 3: We can include the item and check whether that leads to the highest possible profit
    else
    {
        dp[i][W] = max(knapsackRec(W, wt, val, i - 1, dp), knapsackRec(W - wt[i], wt, val, i - 1, dp) + val[i]); // we include the current object and so we add the value reduce capacity
        // we also need to check which case from case 2 or 3 provides a higher profit
        return dp[i][W];
    }
}

int knapsack(int W, int wt[], int val[], int n)
{
    int **dp = new int *[n]; // no of rows equal to the no of items
    for (int i = 0; i < n; i++)
    {
        dp[i] = new int[W + 1]; // W+1 because we can also have 0 capacity
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < W + 1; j++)
        {
            dp[i][j] = -1;
        }
    }
    return knapsackRec(W, wt, val, n - 1, dp);
}
int main()
{
    int W, n;
    cout << "Number of items ";
    cin >> n;
    cout << "Max capacity: ";
    cin >> W;
    int *val, *wt = new int[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Item " << i + 1 << endl;
        cout << "Value: ";
        cin >> val[i];
        cout << "Weight: ";
        cin >> wt[i];
    }
    // int val[] = {60, 100, 120};
    // int wt[] = {10, 20, 30};
    // int W = 50;
    // int n = sizeof(val) / sizeof(val[0]);
    cout << knapsack(W, wt, val, n) << endl;
    return 0;
}
