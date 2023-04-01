#include <bits/stdc++.h>
using namespace std;
#define N 4

void print_solution(int board[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
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

bool isSafe(int board[N][N], int row, int col)
    int i, j;
    for (i = 0; i < col; i++)
    {
        if (board[row][i])
        {
            return false;
        }
    }
    for (i = row, j = col; i >= 0, j >= 0; i--, j--)
    {
        if (board[i][j])
        {
            return false;
        }
    }
    for (i = row, j = col; i < N, j >= 0; i++, j--)
    {
        if (board[i][j])
        {
            return false;
        }
    }
    return true;
}

bool queen_place(int board[N][N], int col)
{
    if (col >= N)
    {
        return true;
    }
    for (int i = 0; i < N; i++)
    {
        if (isSafe(board, i, col))
        {
            board[i][col] = 1;
            if (queen_place(board, col + 1))
            {
                return true;
            }
            board[i][col] = 0;
        }
    }
    return false;
}

void nq_util()
{
    int board[N][N] = {{0, 0, 0, 0},
                       {0, 0, 0, 0},
                       {0, 0, 0, 0},
                       {0, 0, 0, 0}};
    if (queen_place(board, 0) == false)
    {
        cout << "Solution does not exist" << endl;
        ;
        return;
    }

    print_solution(board);
}

int main()
{
    nq_util();
    return 0;
}