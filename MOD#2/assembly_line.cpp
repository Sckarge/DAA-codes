/*
a --> processing times for all machines
t --> transfer times between lines(first index is the line the transfer is from)
e -->entry times for lines
x --> exit times for lines
*/
#include <bits/stdc++.h>
using namespace std;
#define NUM_LINE 2    // no of parallel lines
#define NUM_STATION 4 // no of stations in each line

int min(int a, int b)
{
    return a < b ? a : b;
}

int opt_assembly(int a[][NUM_STATION], int t[][NUM_STATION], int *e, int *x)
{
    int O1[NUM_STATION], O2[NUM_STATION]; // arrays to store optimum values for each station
    O1[0] = e[0] + a[0][0];               // we find the optimum time for the zeroth station by adding the entry time and the execution time of the station
    O2[0] = e[1] + a[1][0];
    for (int i = 1; i < NUM_STATION; i++)
    {
        // In case, it comes from its own line, we only add its own execution time and the optimum time of the station before it
        // But, if we are transferring, we consider the optimum time of the previous station in the other assembly line and the transfer time
        O1[i] = min(O1[i - 1] + a[0][i], O2[i - 1] + t[1][i] + a[0][i]);
        O2[i] = min(O2[i - 1] + a[1][i], O1[i - 1] + t[0][i] + a[1][i]);
        // transfer times are indexed as where the transfers are coming from
    }
    return min(O1[NUM_STATION - 1] + x[0], O2[NUM_STATION - 1] + x[1]); // Taking into consideration the exit times of each line.
}

int main()
{
    int a[][NUM_STATION] = {{4, 5, 3, 2},
                            {2, 10, 1, 4}};
    int t[][NUM_STATION] = {{0, 7, 4, 5},
                            {0, 9, 2, 8}};
    int e[] = {10, 12}, x[] = {18, 7};

    cout << opt_assembly(a, t, e, x) << endl;

    return 0;
}