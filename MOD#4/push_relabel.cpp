#include <bits/stdc++.h>
using namespace std;

const int N = 1000;
const int INF = 1e9;

int n, m, s, t;
int height[N], excess[N], cap[N][N], flow[N][N], nextEdge[N];

void push(int u, int v)
{
    int d = min(excess[u], cap[u][v] - flow[u][v]);
    flow[u][v] += d;
    flow[v][u] -= d;
    excess[u] -= d;
    excess[v] += d;
}

void relabel(int u)
{
    int d = INF;
    for (int i = 0; i < n; i++)
    {
        if (cap[u][i] - flow[u][i] > 0)
        { // if excess flow is present
            d = min(d, height[i]);
            height[u] = d + 1;
        }
    }
}

void discharge(int u)
{
    while (excess[u] > 0)
    {
        if (nextEdge[u] == n)
        {
            relabel(u);
            nextEdge[u] = 0;
        }
        else
        {
            int v = nextEdge[u];
            if (cap[u][v] - flow[u][v] > 0 && height[u] == height[v] + 1)
            { // if both excess flow and height is present push flow
                push(u, v);
            }
            else
            {
                nextEdge[u]++;
            }
        }
    }
}

int maxFlow()
{
    memset(height, 0, sizeof(height));
    memset(excess, 0, sizeof(excess));
    memset(cap, 0, sizeof(cap));
    memset(flow, 0, sizeof(flow));
    memset(nextEdge, 0, sizeof(nextEdge));
    //Taking input for all edges
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cout << "Edge " << i << ": " << endl;
        cout << "Source: ";
        cin >> u;
        cout << "Destination: ";
        cin >> v;
        cout << "Weight: ";
        cin >> w;
        cap[u][v] += w;
    }
    height[s] = n;
    excess[s] = INF;
    //setting up initial heights and excess flows
    for (int i = 0; i < n; i++)
    {
        if (i != s && i != t)
        {
            excess[i] = 0;//all excess flows and heights except the source are initially 0
            height[i] = 0;
        }
        if (cap[s][i] > 0)
        {
            push(s, i);//push from source to all nodes who have capacity
        }
    }
    while (true)
    {
        bool done = true;
        for (int i = 0; i < n; i++)
        {
            if (i != s && i != t && excess[i] > 0)
            {
                discharge(i);
                if (excess[i] > 0)
                {
                    done = false;
                }
            }
        }
        if (done)//if we don't find any nodes with excess flow, the algo is complete
        {
            break;
        }
    }
    return excess[t];
}

int main()
{
    cin >> n >> m >> s >> t;
    cout << maxFlow() << endl;
    return 0;
}
