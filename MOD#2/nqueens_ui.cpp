#include <bits/stdc++.h>

using namespace std;

void printSolution(const vector<vector<int>> &board)
{
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[i].size(); j++)
        {
            if (board[i][j])
            {
                cout << " Q ";
            }
            else
            {
                cout << " X ";
            }
        }
        cout << endl;
    }
}

bool isSafe(const vector<vector<int>> &board, int row, int col)
{
    for (int i = 0; i < col; i++)
    {
        if (board[row][i])
        {
            return false;
        }
    }
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j])
        {
            return false;
        }
    }
    for (int i = row, j = col; j >= 0 && i < board.size(); i++, j--)
    {
        if (board[i][j])
        {
            return false;
        }
    }
    return true;
}

bool solveNQUtil(vector<vector<int>> &board, int col)
{
    if (col >= board.size())
    {
        return true;
    }
    for (int i = 0; i < board.size(); i++)
    {
        if (isSafe(board, i, col))
        {
            board[i][col] = 1;
            if (solveNQUtil(board, col + 1))
            {
                return true;
            }
            board[i][col] = 0;
        }
    }
    return false;
}

bool solveNQ(int n)
{
    vector<vector<int>> board(n, vector<int>(n, 0)); // allocates the values of 0 for a 1D vector of size n and then n of these rows are made into a 2D representation
    if (solveNQUtil(board, 0) == false)
    {
        cout << "Solution does not exist" << endl;
        return false;
    }
    printSolution(board);
    return true;
}

int main()
{
    int n;
    cout << "Enter the size of the board (N): ";
    cin >> n;
    solveNQ(n);
    return 0;
}
