    /*GRAPH COLORING
    This problem entails coloring a graph such that no two adjacent nodes have the same color
    ***In this case, we have set colors as {red}
    */
    #include <bits/stdc++.h>
    using namespace std;
    #define V 4 // No of vertices
    string c[] = {"red", "green", "blue", "yellow"};
    void print_colors(int color[V]);
    bool is_Safe(bool graph[V][V], int color[V])
    {
        /*
        graph[V][V] ---> An adjacency matrix for the given graph
        color[V] = indicates which color has been filled in each vertex
        */
        // We are running through the whole matrix to find a case where the
        // vertices are adjacent and have the same color
        for (int i = 0; i < V; i++)
        {
            for (int j = i + 1; j < V; j++)
            {
                if (graph[i][j] && color[i] == color[j])
                    return false;
            }
        }
        return true;
    }

    bool graph_color(bool graph[V][V], int color[V], int m, int i)
    {
        /*
        graph ---> List of all edges
        color ---> Stores colors of all edges
        m -------> Number of edges
        i -------> current edge
        */
        // base case
        if (i == V)
        {
            if (is_Safe(graph, color))
            { // if at the end we have a graph which follows our rules we return true
                print_colors(color);
                // Print the solution
                return true;
            }
            return false;
        }
        for (int j = 0; j < m; j++)
        {
            color[i] = j; // we check by setting each node every possible color
            if (graph_color(graph, color, m, i + 1))
            { // if it fits the rules return true
                return true;
            }
            color[i] = 0; // backtracking the color(will be changed again next round)
        }
        return false;
    }

    void print_colors(int color[V])
    {
        for (int i = 0; i < V; i++)
        {
            cout << "Node " << i + 1 << ": Color " << c[color[i]] << endl;
        }
    }
    int main()
    {
        bool graph[V][V] = {
            {0, 1, 1, 1},
            {1, 0, 1, 0},
            {1, 1, 0, 1},
            {1, 0, 1, 0},
        };
        int m = 3; // Number of colors

        // Initialize all color values as 0.
        // This initialization is needed
        // correct functioning of isSafe()
        int color[V];
        for (int i = 0; i < V; i++)
            color[i] = 0;

        // Function call
        if (!graph_color(graph, color, m, 0))
            cout << "Solution does not exist";

        return 0;
    }