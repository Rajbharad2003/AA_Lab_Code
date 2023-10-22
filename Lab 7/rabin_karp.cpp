#include <bits/stdc++.h>
using namespace std;

int main()
{
    string text, pattern;
    cout << "Enter Text" << endl;
    cin >> text;
    cout << "Enter pattern" << endl;
    cin >> pattern;
    cout << text << pattern << endl;
    int n = text.length();
    int m = pattern.length();
    int d = 10;
    int q = 13;
    int h = pow(d, m - 1);
    h = h % q;
    int p = 0;
    int t = 0;
    for (int i = 0; i <= m - 1; i++)
    {
        p = (d * p + pattern[i]) % q;
        t = (d * t + text[i]) % q;
    }

    for (int i = 0; i <= (n - m); i++)
    {
        if (p = t && pattern == text.substr(i, m))
        {
            cout << "Pattern occurs with shift " << i << endl;
        }
        if (i < (n - m))
        {
            t = (d * (t - text[i + 1] * h) + text[i + m + 1]) % q;
        }
        if (t < 0)
        {
            t = t + q;
        }
    }

    return 0;
}