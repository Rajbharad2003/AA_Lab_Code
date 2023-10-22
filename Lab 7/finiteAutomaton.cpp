
#include <bits/stdc++.h>
using namespace std;

void finite_automaton_matcher(const string &text, const string &pattern, const vector<vector<int>> &transition_table)
{
    int n = text.length();
    int m = pattern.length();
    int q = 0;

    for (int i = 0; i < n; i++)
    {
        char current_char = text[i];
        int char_index = -1;

        for (int j = 0; j < m; j++)
        {
            if (pattern[j] == current_char)
            {
                char_index = j;
                break;
            }
        }

        if (char_index == -1)
        {
            q = 0;
        }
        else
        {
            q = transition_table[q][char_index];
        }

        if (q == m)
        {
            cout << "Pattern found at position " << i - m + 1 << endl;
        }
    }
}

int main()
{
    int s, n;
    cout << "Enter no of states and no of unique char in string" << endl;
    cin >> s >> n;
    string text, pattern;
    cout << "Enter text: " << endl;
    getline(cin >> ws, text);
    cout << "Enter pattern: " << endl;
    getline(cin >> ws, pattern);

    vector<vector<int>> mat(s, vector<int>(n));
    for (int i = 0; i < s; i++)
        for (int j = 0; j < n; j++)
            cin >> mat[i][j];
    finite_automaton_matcher(text, pattern, mat);
}
