/*
------TIME COMPLEXITY------
------ALGORITHM------
1. Make a utility function that calculates the number of digits in the int
2. Karatsuba
    1) Base case - If one or both of the numbers are of 1 digit i.e <10, multiply directly
    2) n = find the max no of digits out of the 2 numbers given(take ceiling of n/2)
    3) m = calculate and store 10 to the power of the number stored in the previous step.
    4) When we do an integer division on given numbers by m we get a & c and a modulus would give us b & d respectively
    5)get karatsuba of ac, bd and a+b and put it in the formula to get the answer
*/
#include <bits/stdc++.h>
using namespace std;

int getsize(long n)
{
    int count = 0;
    while (n > 0)
    {
        n /= 10;
        count++;
    }
    return count;
}

long long karatsuba(long long x, long long y)
{
    if (x < 10 && y < 10)
        return x * y;
    int n = max(getsize(x), getsize(y));
    int m = (int)ceil(n / 2.0);
    long p = (long)pow(10, m);
    long a = x / p;
    long b = x % p;
    long c = y / p;
    long d = y % p;
    long ac = karatsuba(a, c);
    long bd = karatsuba(b, d);
    long e = karatsuba(a + b, c + d) - ac - bd;
    long long ans = (pow(10 * 1L, 2 * m) * ac + pow(10 * 1L, m) * e + bd);
    return ans;
}
int main()
{
    long long a, b;
    cout << "Number 1: ";
    cin >> a;
    cout << "Number 2: ";
    cin >> b;
    long long c = karatsuba(a, b);
    cout << a << " * " << b << " = " << c << endl;
    return 0;
}