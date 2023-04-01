/*
The indices when checking the letters is subtracted by 1 bec the indexes start at a 0
code procedure:
1. Make the array for dp
2. Nested for loop going through the array in 1 of 3 cases
    Case 1:
        The element is in the first row or column and is to be set to 0
    Case 2:
        The element has matching letters and hence it will be set to the value of its top left diagonal + 1
    Case 3:
        The characters do not match and we set the value to the left or top value(whichever is larger)
3. return the value in index (m,n)
*/
#include <bits/stdc++.h>
using namespace std;
int max(int a, int b) // utility function
{
    return a > b ? a : b;
}
int lcs(char *X, char *Y, int m, int n)
{
    int L[m + 1][n + 1]; // making the dp array
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0) // initiating the first row and column as 0's
                L[i][j] = 0;
            else if (X[i - 1] == Y[j - 1]) // if the letters match we want to add 1 to the
                L[i][j] = L[i - 1][j - 1] + 1;
            else
                L[i][j] = max(L[i - 1][j], L[i][j - 1]); // if the letters do not match then
                                                         // we can check whether the top or left element is larger and give it that value
        }
    }
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
            cout << L[i][j] << " ";
        cout << endl;
    }
    return L[m][n];
}
int main()
{
    char X[20], Y[20];
    cout << "String 1: ";
    cin >> X;
    cout << "String 2: ";
    cin >> Y;
    int m = strlen(X);
    int n = strlen(Y); // make sure to use only strlen and not sizeof here as that will
    // report the size as 20
    printf("Length of LCS is %d\n", lcs(X, Y, m, n));
    return 0;
}