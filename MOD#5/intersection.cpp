#include <bits/stdc++.h>
using namespace std;

int m1[2], m2[2];
int mmul(int a[], int b[])
{

    return ((a[0] * b[1]) + (a[1] * b[0]));
}
void msub(int a[], int b[], int n)
{
    if (n == 1)
    {
        m1[0] = a[0] - b[0];
        m1[1] = a[1] - b[1];
    }
    else{
        m2[0] = a[0] - b[0];
        m2[1] = a[1] - b[1];
    }
}

int dir(int P1[], int P2[], int P3[])
{
    msub(P3,P1,1);
    msub(P2,P1,2);
    return (mmul(m1,m2));
}

int main()
{
    int p1[2];
    int p2[2];
    int p3[2];
    int p4[2];
    cout << "Enter coordinates for the two points- " << endl;
    cout << "Line 1 point 1: ";
    for (int i = 0; i < 2; i++)
    {
        cin >> p1[i];
    }
    cout << "Line 1 point 2: ";
    for (int i = 0; i < 2; i++)
    {
        cin >> p2[i];
    }
    cout << "Line 2 point 1: ";
    for (int i = 0; i < 2; i++)
    {
        cin >> p3[i];
    }
    cout << "Line 2 point 2: ";
    for (int i = 0; i < 2; i++)
    {
        cin >> p4[i];
    }
    int d1 = dir(p3, p4, p1);
    int d2 = dir(p3, p4, p2);
    int d3 = dir(p1, p2, p3);
    int d4 = dir(p1, p2, p4);
    if (d1 * d2 > 0 && d3 * d4 > 0)
    {
        cout << "Lines intersect" << endl;
    }
    else
    {
        cout << "Lines do not intersect" << endl;
    }
}