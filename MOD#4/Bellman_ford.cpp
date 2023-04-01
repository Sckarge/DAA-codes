#include <bits/stdc++.h>
using namespace std;

typedef struct edge
{
	int source, dest;
	float wt;
} edge;

int main()
{
	int vert, e;
	cout << "Number of edges: ";
	cin >> e;
	cout << "No of vertices: ";
	cin >> vert;
	edge edges[e]; // This is an array of edges which will represent the graph
	for (int i = 0; i < e; i++)
	{
		cout << "Source of edge " << i << ": ";
		cin >> edges[i].source;
		cout << "Destination of edge " << i << ": ";
		cin >> edges[i].dest;
		cout << "Weight of edge " << i << ": ";
		cin >> edges[i].wt;
	}
	float dist[vert]; // distance array for all vertices, which will be updated
	int start;
	cout << "Initial node: ";
	cin >> start;
	// First off we will set all distances except the source node as infinity
	for (int i = 0; i < vert; i++)
	{
		dist[i] = INT_MAX;
	}
	dist[start] = 0;
	// The outer loop here is to keep track of the no of times the distances can be updated
	// No more than vert-1 unless there is a negative cycle and in that case the algorithm will not give optimum soln
	for (int i = 0; i < vert - 1; i++)
	{
		for (int j = 0; j < e; j++)
		{
			int u = edges[j].source; // source of the curr edges
			int v = edges[j].dest;	 // dest of the curr edge
			float wt = edges[j].wt;	 // weight of the curr edge
			if (dist[u] + wt < dist[v])
			{
				dist[v] = dist[u] + wt;
			}
		}
	}

	for (int i = 0; i < e; i++)//We check for 1 last iteration, whether there is a change, if a change is made
	//there is a negative cycle in the graph and optimal soln cannot be found
	{
		int u = edges[i].source;
		int v = edges[i].dest;
		int w = edges[i].wt;
		if (dist[u] + w < dist[v])
		{
			cout << "Negative weight cycle found" << endl;
			exit(0);
		}
	}
	cout << "The final min distances are " << endl;
	for (int i = 0; i < vert; i++)
	{
		cout << "Node " << i << ": " << dist[i] << endl;
	}
	return 0;
}
