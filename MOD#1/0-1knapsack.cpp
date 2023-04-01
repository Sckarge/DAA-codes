/*
0-1 Knapsack problem(Recursive implementation)

*/
#include <bits/stdc++.h>
using namespace std;

int max(int a, int b)
{
    return a > b ? a : b;
}
// Our algorithm is executed in knapsack function
int knapsack(int cap, int wt[], int val[], int n)
{
    if (n == 0 || cap == 0) // if we have reached the end of the items or the sack is full
        return 0;
    // we will make two cases here, one where the item is included and the other where it is not
    if (wt[n - 1] > cap)
        return knapsack(cap, wt, val, n - 1); // we move one index down but, we don't change the capacity as the current item is not included
    else
    {
        return max(val[n - 1] + knapsack(cap - wt[n - 1], wt, val, n - 1), knapsack(cap, wt, val, n - 1));
        // incase we can include the current item, we still have to check whether it is the optimmal solution,
        // to do this we check the max for included and non included cases.
    }
}

int main()
{
    int val[] = {60, 100, 120};
    int wt[] = {10, 20, 30};
    int cap = 50;
    int n = sizeof(val) / sizeof(val[0]);
    cout << knapsack(cap, wt, val, n) << endl;
    return 0;
}