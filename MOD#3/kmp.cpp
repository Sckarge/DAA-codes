#include <bits/stdc++.h>
using namespace std;
/*
LPS array
This basically stores the no of characters in the current suffix that match with the prefix i.e. if I were to have a mismatch right now, how much of the pattern is still matching

eg -
text -----> ABABC
pattern --> ABC
Here, when we are at A at index 2 in the main string, we get a mismatch, but, we can say that A matches thefirst letter of the pattern so we would start at j = 1.

---Time complexity---
[
n---> no of elements in mainstring
m---> no of elements in pattern
]
Time complexity of Naive algorithm is O(n*m) because we backtrack in both the mainstring and pattern
but, as we do not backtrack in mainstring in kmp, the time complexity includes the parsing of the mainstring and pattern seperately i.e. O(n+m)
*/
void calc_lps(string p, int LPS[])
{
    LPS[0] = 0;       // we always start with 0 in LPS table
    int i = 0, j = 1; // Here i is checking prefix and j the suffix
    while (j < p.length())
    {
        if (p[i] == p[j])
        {
            LPS[j] = i + 1; // we store the index for the pattern that
            // is being matched so far
            i++;
            j++; // both can move to check the next char    
        }

        else
        {
            if (i == 0)
            {
                LPS[j] = 0; // no chars are matching
                j++;        // check the next char for a match
            }
            else
            {
                i = LPS[i - 1]; // if this is not a match, we will  i to wherever there was a match previously
            }
        }
    }
}
int main()
{
    string txt, pat;
    cout << "Enter main text ";
    cin >> txt;
    cout << "Enter pattern to be found ";
    cin >> pat;
    int slen = txt.length();
    int plen = pat.length();
    int LPS[plen];
    calc_lps(pat, LPS);
    int i = 0, j = 0;
    while (i < slen) // we only move through the main text once
    {
        if (txt[i] == pat[j])
        {
            i++;
            j++;
        }
        if (j == plen)
        {
            cout << "Pattern found at index " << i - plen << endl;
            j = LPS[j - 1]; // we check how many of the chars at the end match the begining
        }
        else if (i < slen && pat[j] != txt[i])
        {
            if (j == 0)
            {
                i++; // if we are checking the beggining of the pattern, simply move to the next letter
            }
            else
            {
                j = LPS[j - 1]; // if there is a mismatch after a few letters, we check how much of the prefix and suffix matches
            }
        }
    }
}
