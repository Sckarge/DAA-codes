/*GRAPH COLORING
This problem entails coloring a graph such that no two adjacent nodes have the same color
***In this case, we have set colors as {red}
*/
#include <bits/stdc++.h>
using namespace std;

void print_colors(int color[], int V);
bool is_Safe(int graph[][100], int color[], int V, int v, int c)
{
    for (int i = 0; i < V; i++)
        if (graph[v][i] && c == color[i])
            return false;
    return true;
}

bool graph_color_helper(int graph[][100], int color[], int m, int V, int v)
{
    if (v == V)
        return true;

    for (int c = 1; c <= m; c++)
    {
        if (is_Safe(graph, color, V, v, c))
        {
            color[v] = c;

            if (graph_color_helper(graph, color, m, V, v + 1))
                return true;

            color[v] = 0;
        }
    }

    return false;
}

void graph_color(int graph[][100], int m, int V)
{
    int color[V] = {0};

    if (!graph_color_helper(graph, color, m, V, 0))
    {
        cout << "Solution does not exist\n";
        return;
    }

    print_colors(color, V);
}

void print_colors(int color[], int V)
{
    for (int i = 0; i < V; i++)
        cout << "Vertex " << i + 1 << " ---> Color " << color[i] << endl;
}

int main()
{
    int V, m;
    cout << "Enter the number of vertices: ";
    cin >> V;

    int graph[100][100];
    cout << "Enter the adjacency matrix (in 0/1 format): " << endl;
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            cin >> graph[i][j];

    cout << "Enter the number of colors: ";
    cin >> m;

    graph_color(graph, m, V);

    return 0;
}
