// ======================================================================
// FILE:        MyAI.cpp
//
// AUTHOR:      Raymond Anggono
//
// DESCRIPTION: Agent Class For Minesweeper
// ======================================================================

#include "MyAI.hpp"

MyAI::MyAI(int _rowDimension, int _colDimension, int _totalMines, int _agentX, int _agentY) : Agent()
{
    rowDimension = _rowDimension;

    colDimension = _colDimension;

    // UNFLAG = -1
    // FLAG = -2

    board = vector<vector<int>>(_rowDimension, vector<int>(_colDimension, -1));

    nextTiles.push({_agentX, _agentY});

    coveredTiles = _rowDimension * _colDimension;

    totalMines = _totalMines;

    agentX = _agentX;

    agentY = _agentY;

    // ======================================================================
    // YOUR CODE ENDS
    // ======================================================================
};

Agent::Action MyAI::getAction(int number)
{
    // FLAGGED = -2
    // UNFLAGGED = -1

    int n = board.size();
    int row, col;

    if (coveredTiles == totalMines)
    {

        return {LEAVE, -1, -1};
    }
    else if (nextTiles.empty())
    { // random tiles if the algorithm confuse.

        int i = 0;
        for (i = 0; i < rowDimension * rowDimension; i++)
        {
            if (board[i / rowDimension][i % rowDimension] == -1)
            {
                break;
            }
        }
        int row = i / rowDimension;
        int col = i % rowDimension;
        board[row][col] = number;

        return {UNCOVER, row, col};
    }
    else
    {

        int row = nextTiles.front().first;
        int col = nextTiles.front().second;
        nextTiles.pop();
    }

    int n1 = 0, n2 = 0;
    for (int i = -1; i <= 1; i++)
    {
        for (int j = -1; j <= 1; j++)
        {
            int r = row + i, c = col + j;
            if (r < 0 || r == n || c < 0 || c == n)
                continue;
            if (board[r][c] >= 0)
                n1++;
            else if (board[r][c] == -1)
                n2++;
        }
    }

    for (int i = -1; i <= 1; i++)
    {
        for (int j = -1; j <= 1; j++)
        {
            int r = row + i, c = col + j;
            if (r < 0 || r == n || c < 0 || c == n)
                continue;
            if (board[r][c] == -1)
            {
                if (board[row][col] == n1)
                {
                    board[r][c] = number;
                    nextTiles.push({r, c});
                }
                else
                {
                    board[r][c] = -2;
                }
            }
        }
    }
    coveredTiles--;
    return {UNCOVER, row, col};
}
