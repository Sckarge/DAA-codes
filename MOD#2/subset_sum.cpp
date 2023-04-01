#include <bits/stdc++.h>
using namespace std;
int b[100], c = 0;
void print_subset()
{
    for (int i = 0; i < c; i++)
    {
        cout << b[i] << " ";
    }
    cout << endl;
}

bool subset_sum(int set[], int curr_pos, int curr_sum, int req_sum, int size, bool &found)
{
    if (curr_sum == req_sum)
    {
        found = true;
        print_subset();
    }
    for (int i = curr_pos; i < size; i++)
    {
        if (curr_sum + set[i] <= req_sum)
        {
            curr_sum += set[i];
            b[c++] = set[i]; // store the current element in our subset array
            subset_sum(set, curr_pos + 1, curr_sum, req_sum, size, found);
            curr_sum -= set[i];
            c--;
        }
    }
    return found;
}

int main()
{
    int i, n, sum;
    cout << "Enter the number of elements in the set" << endl;
    cin >> n;
    int a[n];
    cout << "Enter the values" << endl;
    for (i = 0; i < n; i++)
        cin >> a[i];
    cout << "Enter the value of sum" << endl;
    cin >> sum;
    bool f = false;
    f = subset_sum(a, 0, 0, sum, n, f);
    if (f)
    {
        cout << "Subset(s) with the given sum found: " << endl;
    }
    else
        cout << "No required subset found" << endl;
    return 0;
}