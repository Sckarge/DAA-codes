#include <bits/stdc++.h>
// #define n 6
// #define n 4
using namespace std;

typedef struct Node
{
   int id;
   int state; // status
   int pred;  // predecessor
} node;

/*
int res[n][n] = {
   {0, 16, 13, 0, 0, 0},
   {0, 0, 10, 12, 0, 0},
   {0, 4, 0, 0, 14, 0},
   {0, 0, 9, 0, 0, 20},
   {0, 0, 0, 7, 0, 4},
   {0, 0, 0, 0, 0, 0}    //maxflow=23
};

int res[n][n]={
{0,3,2,0},{0,0,5,2},{0,0,0,3},{0,0,0,0}
};
*/
int **res;
/* n =6
{0, 10, 0, 10, 0, 0},
    {0, 0, 4, 2, 8, 0},
    {0, 0, 0, 0, 0, 10},
    {0, 0, 0, 0, 9, 0},
    {0, 0, 6, 0, 0, 10},
    {0, 0, 0, 0, 0, 0} // maxflow=19*/
bool bfs(node vert[], node source, node sink, int n)
{
   node u;
   int i, j;
   queue<node> q;

   for (i = 0; i < n; i++)
   { // Initially set the state of all nodes as unvisited
      vert[i].state = 0;
   }

   vert[source.id].state = 1; // source is visited
   vert[source.id].pred = -1; // no parent for source
   q.push(source);            // enqueue source node

   while (!q.empty())
   {
      u = q.front(); // Take out value of front of the queue
      q.pop();
      for (i = 0; i < n; i++)
      {
         if (res[u.id][i] > 0 && vert[i].state == 0)
         { // if this node is unvisited and there is residual flow
            vert[i].pred = u.id;
            vert[i].state = 1;
            q.push(vert[i]); // push node for exploration
         }
      }
   }                                  // end of while
   return (vert[sink.id].state == 1); // this checks if the sink was visited, if yes then BFS was a success
}
int main()
{
   //Input section
   int n;
   cout << "Number of nodes: ";
   cin >> n;
   res = new int *[n];
   for (int i = 0; i < n; i++)
   {
      res[i] = new int[n];
   }
   cout << "Enter residual matrix " << endl;
   for (int i = 0; i < n; i++)
   {
      for (int j = 0; j < n; j++)
      {
         cin >> res[i][j];
      }
   }
   node vert[n];//array of vertices
   node source, sink;
   for (int i = 0; i < n; i++)
   {
      vert[i].id = i;//set all vert id's
   }

   source.id = 0;
   sink.id = n - 1;
   int maxflow = 0;
   int u, v;

   while (bfs(vert, source, sink, n))//Until we keep getting a path
   { // find augmented path using bfs
      int augflow = INT_MAX;//To find the bottleneck we start this value at infinity
      for (v = sink.id; v != source.id; v = vert[v].pred)//going backwards from sink to source
      {
         u = vert[v].pred;
         augflow = augflow < res[u][v] ? augflow : res[u][v];//if this res is smaller it becomes the bottleneck
      }
      for (v = sink.id; v != source.id; v = vert[v].pred)
      {
         u = vert[v].pred;
         res[u][v] -= augflow; // add augflow to forward edge
         res[v][u] += augflow; // subtract augflow from back edge
      }
      /* cout<<"residue graph after each iteration\n";
          for(int i = 0; i<n; i++) {
          for(int j = 0; j<n; j++) {
             cout<< res[i][j]<<" ";}
          cout<<"\n";}*/
      maxflow += augflow;
   } // while
   cout << "Maximum flow is: " << maxflow << endl;
}