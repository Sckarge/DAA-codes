/*
We move the window that we are looking in by one element to the right and then iterate through that window 
one by one.
If we find that one of chars don't match, we will move on to the next window
*/
#include <bits/stdc++.h>
using namespace std;

bool Naive_str(string s, string p)
{
    int slen = s.length();//Main string's length
    int plen = p.length();//pattern's length
    bool flag = false;

    for (int i = 0; i <= slen - plen; i++)//we need only move the window until slen-plen
    {
        int j;//Essential to do this
        for (j = 0; j < plen; j++)//we will now check all letters in the window with our main string
        {
            if (s[i + j] != p[j])//If any char is not matching we break out of the loop
            {
                break;
            }
        }
        if (j == plen)//If we reach the end of the window, we have a match
        {
            flag = true;
            cout << "Pattern found at " << i << endl;
        }
    }
    return flag;
}
int main()
{
    string s;
    string p;
    cout<<"Enter Main string: "<<endl;
    cin>>s;
    cout<<"Enter pattern to be found: "<<endl;
    cin>>p;
    if (!Naive_str(s, p))
        cout << "Pattern not found" << endl;
    return 0;
}