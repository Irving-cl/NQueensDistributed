
#include "nqueens_solver.h"

#include <iostream>
#include <stdlib.h>
#include <string.h>

int64_t NQueensSolver::solve(int n, Constraint& constraint)
{
    // Clear
    memset(board_, 0, sizeof(board_));
    size_ = n;
    cnt_ = 0;
    
    // Set constraint
    if (!is_constraint_valid(size_, constraint))
    {
        std::cerr << "Wrong constraint\n";
        return -1;
    }
    for (int i = 0; i < static_cast<int>(constraint.size()); i++)
    {
        board_[i] = constraint[i];
    }

    // Run dfs
    dfs(constraint.size());

    return cnt_;
}

void NQueensSolver::dfs(int idx)
{
    // A solution is found
    if (idx == size_)
    {
        cnt_++;
        return;
    }

    // Search current position
    for (int i = 0; i < size_; i++)
    {
        bool flag = true;
        // Check
        for (int j = 0; j < idx; j++)
        {
            if (board_[j] == i || abs(i - board_[j]) == abs(idx - j))
            {
                flag = false;    // Invalid
                break;
            }
        }
        if (flag)
        {
            board_[idx] = i;
            dfs(idx + 1);
        }
    }
}

bool NQueensSolver::is_constraint_valid(int n, Constraint& constraint)
{
    if (static_cast<int>(constraint.size()) > n)
    {
        return false;
    }
    for (int ele : constraint)
    {
        if (ele < 0 || ele >= n)
        {
            return false;
        }
    }
    return true;
}

