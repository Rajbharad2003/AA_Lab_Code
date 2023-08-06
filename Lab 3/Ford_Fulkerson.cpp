//Lab 3 - Ford Fulkerson Algorithm
#include<bits/stdc++.h>
#include<queue>
using namespace std;

int flow_graph[6][6] = {{0, 16, 13, 0, 0, 0},
                            {0, 0, 10, 12, 0, 0},
                            {0, 4, 0, 0, 14, 0},
                            {0, 0, 9, 0, 0, 20},
                            {0, 0, 0, 7, 0, 4},
                            {0, 0, 0, 0, 0, 0}};

int visited[6];

bool bfs(int rflow_graph[6][6], int source, int sink, int* parent)
{
    for(int i=0 ; i < 6 ; i++)
    {
        visited[i] = 0;
    }

    queue<int> q;
    q.push(source);
    visited[source] = 1;
    parent[source] = -1;
    
    while(!q.empty())
    {
        int u = q.front();
        cout << u << endl;
        q.pop();
        for(int v=0 ; v<6 ; v++)
        {
            if(visited[v] == 0 && rflow_graph[u][v] > 0)
            {
                cout << v << " " << "i m hear" << endl;
                if(v == sink)
                {
                    parent[v] = u;
                    for(int i=0 ; i<6 ; i++)
                        cout << parent[i] << " ";
                    cout << endl;
                    return true;
                }
                q.push(v);
                visited[v] = 1;
                parent[v] = u;
            }
        }
    }
    return false;
}

int ford_fulkerson(int source, int sink)
{
    int rflow_graph[6][6];

    for(int u = 0 ; u < 6 ; u++)
    {
        for(int v = 0 ; v < 6 ; v++)
        {
            rflow_graph[u][v] = flow_graph[u][v];
        }
    }
    int parent[6];
    int max_flow = 0;

    while(bfs(rflow_graph, source, sink, parent))
    {
        int path_flow = INT_MAX;
        
        for(int i=sink ; i != source ; i = parent[i])
        {
            int u = parent[i];
            path_flow = min(path_flow, rflow_graph[u][i]);
        }
        
        for(int i=sink ; i != source ; i = parent[i])
        {
            int u = parent[i];
            rflow_graph[u][i] -= path_flow;
            rflow_graph[i][u] += path_flow;
        }
        
        max_flow += path_flow;
    }
    return max_flow;
}

int main()
{
    int max_flow = ford_fulkerson(0, 5);
    cout << "Maximum flow for given network is : " << max_flow;
    return 0;
}


