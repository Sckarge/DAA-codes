#include <bits/stdc++.h>
#define MAX 20
using namespace std;
int cost[MAX][MAX];
int n;

int main()
{
  int i, j, k, c, x, y;
  int max_edges, origin, destin;
  cout << "Enter number of nodes : ";
  cin >> n;
  for (i = 1; i <= n; i++)
  {
    for (j = 1; j <= n; j++)
    {
      cost[i][j] = INT_MAX; // cost/distance of all nodes is initially set to infinity
    }
  }
  max_edges = n * (n - 1); // Permuation of n nodes can create atmost n*(n-1) edges
  for (i = 1; i <= max_edges; i++)
  {
    cout << "Enter edge ( 0 0 to quit ) : " << i;
    cin >> origin >> destin;
    if ((origin == 0) && (destin == 0))
      break;
    if (origin > n || destin > n || origin <= 0 || destin <= 0)
    {
      cout << "Invalid edge!\n";
      i--;
    }
    else
    {
      cout << "\n enter the cost\n";
      cin >> c;                 // only for a valid edge, read its cost 'c' and store it in the appropriate
      cost[origin][destin] = c; // index of cost[ ][ ]
    }
  }
  // display
  cout << "\nInitial Cost Matrix\n";
  for (i = 1; i <= n; i++)
  {
    for (j = 1; j <= n; j++)
      cout << cost[i][j] << " ";
    cout << "\n";
  }
  for (i = 1; i <= n; i++) // This loop runs the no of times the we update the whole matrix
  {
    for (j = 1; j <= n; j++) // row iterations
    {
      for (k = 1; k <= n; k++) // Columns in each row
      {
        if (cost[j][k] > cost[j][i] + cost[i][k]) // i is the middle transition point here
          cost[j][k] = cost[j][i] + cost[i][k];
      }
    }
  }
  //Print answers
  cout << "\nFinal Cost Matrix\n";
  for (i = 1; i <= n; i++)
  {
    for (j = 1; j <= n; j++)
      cout << cost[i][j] << "   ";
    cout << "\n";
  }

  return 0;
}