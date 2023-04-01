/*
----------TIME COMPLEXITY----------
O(nlogn)
T(n) = 2T(n/2) + O(n)
----------ALGORITHM----------
1. Make a utility function, which returns the max of two numbers
2. Make a crossum function which calculates the max value of left and right subarrays, starting at the middle and returns
   their sum
3. Finally a maxsum recursive function which calculates the left and right subarray sum by calling itself and find out the max of the
   left,right and crossum and then returns that.
*/
#include <bits/stdc++.h>
using namespace std;

int max(int a, int b)
{
    return a > b ? a : b;
}
int crossum(int a[], int l, int h, int m) // l and h make the function more general so that it can be used recursively
{
    // first for the left subarray
    int s = 0;
    int left = INT_MIN;
    for (int i = m; i >= l; i--)
    {
        s += a[i];
        if (s > left)
        {
            left = s; // if the current sum becomes greater than the previous max it becomes the new max
        }
    }
    s = 0; // we reset the sum
    int right = INT_MIN;
    for (int i = m + 1; i <= h; i++)
    {
        s += a[i];
        if (s > right)
        {
            right = s; // if the current sum becomes greater than the previous max it becomes the new max
        }
    }
    return (left + right);
}

int max_sum(int a[], int l, int h)
{
    if (l == h)
    {
        return a[l];
    }
    int m = (l + h) / 2;
    int temp = max(max_sum(a, l, m), max_sum(a, m + 1, h));
    return max(temp, crossum(a, l, h, m)); // max only takes two parameters at once,the final ans would be the max of left max, right max and crossum
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
    // int a[] = {-2, -5, 6, -2, -3, 1, 5, -6};
    cout << max_sum(arr, 0, n - 1) << endl;
    return 0;
}