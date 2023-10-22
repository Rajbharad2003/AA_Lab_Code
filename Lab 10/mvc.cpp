#include <bits/stdc++.h>
using namespace std;

class mvc
{
    unordered_map<int, vector<int>> adj;
    int n, e;
    vector<pair<int, int>> edges;
 
public:
    void randomizeRun()
    {
        vector<pair<int, int>> temp = edges;
        set<int> ans;
        while (temp.size() != 0)
        {
            int index = rand() % temp.size();
            auto selected = temp[index];
            ans.insert(selected.first);
            ans.insert(selected.second);
            for (int i = 0; i < temp.size(); i++)
            {
                if (temp[i].first == selected.first || temp[i].first == selected.second || temp[i].second == selected.first || temp[i].second == selected.second)
                {
                    temp.erase(temp.begin() + i);
                    i--;
                }
            }
        }
        cout << "MVC using Randomize Approximation" << endl;
        for (auto i : ans)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    int findMax(unordered_map<int, vector<int>> &temp)
    {
        int index = 0;
        for (auto a : temp)
        {
            if (temp[index].size() < a.second.size())
            {
                index = a.first;
            }
        }
        for (int a : temp[index])
        {
            for (int i = 0; i < temp[a].size(); i++)
            {
                if (temp[a][i] == index)
                {
                    temp[a].erase(temp[a].begin() + i);
                    break;
                }
            }
        }
        temp[index].clear();
        return index;
    }
    void greedyRun()
    {
        unordered_map<int, vector<int>> temp = adj;
        vector<pair<int, int>> tempe = edges;
        vector<int> ans;
        while (tempe.size() != 0)
        {
            int index = findMax(temp);
            ans.push_back(index);
            for (int i = 0; i < tempe.size(); i++)
            {
                if (index == tempe[i].first)
                {
                    tempe.erase(tempe.begin() + i);
                    i--;
                }
                else if (index == tempe[i].second)
                {
                    tempe.erase(tempe.begin() + i);
                    i--;
                }
            }
        }
        cout << "MVC using Greedy Approximation : ";
        for (auto a : ans)
        {
            cout << a << " ";
        }
        cout << endl;
    }

    void takeInput()
    {
        cout << "Enter no. of vertices" << endl;
        cin >> n;
        cout << "Enter no. of edges" << endl;
        cin >> e;
        cout << "Enter edges" << endl;
        for (int i = 0; i < e; i++)
        {
            int u, v;
            cin >> u >> v;
            edges.push_back({u, v});
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }
};

int main()
{
    srand(time(0));
    mvc m;
    m.takeInput();
    m.randomizeRun();
    m.greedyRun();

    return 0;
}
