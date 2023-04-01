#include <bits/stdc++.h>
using namespace std;

void rk_match(string ms, string p, int d) // d here is the decimal no on which the system is based
{
    int slen = ms.length();
    int plen = p.length();
    int q = slen + plen;
    int h = (int)pow(d, plen - 1) % q; // h is just convinient to calculate once as it is used many times later

    int ms_hash = 0, p_hash = 0; // we  initiate hash values of mainstring and pattern
    for (int i = 0; i < plen; i++)
    {
        ms_hash = (ms_hash * d + ms[i]) % q; // multiply by 10(if decimal) and add ones place then modulus
        p_hash = (p_hash * d + p[i]) % q;
    }
    for (int i = 0; i <= slen - plen; i++)
    {
        if (ms_hash == p_hash) // if the hash values for the current window match,we check otherwise we move on.
        {
            int j;
            for (j = 0; j < plen; j++) // implementation of naive pattern matching
            {
                if (ms[i + j] != p[j])
                {
                    break;
                }
            }
            //***Personal Note: Place this if statement outside loop
            if (j == plen)
            {
                cout << "Match found at " << i << endl;
            }
        }
        ms_hash = (((ms_hash - ms[i] * h) * d) + ms[i + plen]) % q; // we calculate hash value for next window from the value of the last
        // subtract most significant digit and add ones place digit then modulus of q
        if (ms_hash < 0)
        { // case where hash value is less than 0
            ms_hash += q;
        }
    }
}

int main()
{
    string txt, pat;
    cout << "Main text: ";
    cin >> txt;
    cout << "Pattern: ";
    cin >> pat;
    // char txt[] = "GEEKS FOR GEEKS";
    // char pat[] = "GEEK";
    rk_match(txt, pat, 256);
    return 0;
}