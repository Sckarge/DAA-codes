// Fractional Knapsack
/*
----------TIME COMPLEXITY----------
O(nlogn)
----------ALGORITHM----------
We use a Greedy approach to get the optimum solution for the fractional knapsack problem
Steps for solving:-
    -> Calculate the ratio(v/w)
    -> Sort the items based on this ratio
    -> Take the item with the highest ratio and add them until we can't add the
       next item as a whole
    -> At the end add the next item as much as we can(fraction)
*/
/*
SAMPLE INPUT
n = 3
W = 50
items = {60, 10}, {100, 20}, {120, 30}
*/
#include <bits/stdc++.h>
using namespace std;

// Structure for an item which stores weight and
// corresponding value of Item
typedef struct Item
{
    int value, weight;

    Item()
    {
        this->value = 0;
        this->weight = 0;
    }
    // Constructor
    Item(int value, int weight)
    {
        this->value = value;
        this->weight = weight;
    }
} Item;
// Comparison function to sort Item
// according to val/weight ratio
static bool cmp(Item a, Item b)
{
    double r1 = (double)a.value / (double)a.weight;
    double r2 = (double)b.value / (double)b.weight;
    return r1 > r2;
}

// Main greedy function to solve problem
double fractionalKnapsack(int W, struct Item arr[], int N)
{
    /*
    ----Inputs----
    W -----> Max capacity of the knapsack
    arr ---> Array of items
    N -----> No of items
    */
    // Sorting Item on basis of ratio
    sort(arr, arr + N, cmp);

    double finalvalue = 0.0;

    // Looping through all items
    for (int i = 0; i < N; i++)
    {

        // If adding Item won't overflow,
        // add it completely
        if (W >= arr[i].weight)
        {
            W -= arr[i].weight;
            finalvalue += arr[i].value;
        }

        // If we can't add current Item,
        // add fractional part of it
        else
        {
            finalvalue += arr[i].value * ((double)W / (double)arr[i].weight);
            break;
        }
    }

    // Returning final value
    return finalvalue;
}

// Driver code
int main()
{
    int W, n;
    cout << "Number of items ";
    cin >> n;
    cout << "Max capacity: ";
    cin >> W;
    Item *arr = new Item[n];
    for (int i = 0; i < n; i++)
    {
        int val, wt;
        cout << "Item " << i + 1 << endl;
        cout << "Value: ";
        cin >> val;
        cout << "Weight: ";
        cin >> wt;
        arr[i] = Item(val, wt);
    }
    // Function call
    cout << "The optimal solution is " << fractionalKnapsack(W, arr, n) << endl;
    return 0;
}
