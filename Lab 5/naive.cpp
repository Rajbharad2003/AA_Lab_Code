#include <bits/stdc++.h>
using namespace std;
//Naive String Matching
int main()
{
    string text = "MY NAME IS MAHARSHI";
    string pattern = "IS";
    int n = text.length();
    int m = pattern.length();
    int s = 0;
    for (; s <= n - m; s++)
    {
        int i = 0, j = 0;
        while (j < m && text[s + i] == pattern[j])
        {
            i++;
            j++;
        }
        if (j == m)
        {
            cout << "Pattern matched at index " << s << endl;
        }
    }
    if(s == 0){
        cout << "Pattern not matched" << endl;
    }
    return 0;
}