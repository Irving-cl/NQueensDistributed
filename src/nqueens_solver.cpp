
#include "nqueens_solver.h"

#include <iostream>
#include <stdlib.h>
#include <string.h>

Work::Work(int n, std::vector<int>& constraints)
  : n_(n),
    constraints_(constraints)
{
}

Work::Work(int n)
  : n_(n)
{
}

bool Work::deepen()
{
    if (static_cast<int>(constraints_.size()) < n_)
    {
        constraints_.push_back(0);
        return true;
    }
    return false;
}

bool Work::forward(int idx)
{
    if (idx >= static_cast<int>(constraints_.size()) || idx < 0)
    {
        return false;
    }

    if (constraints_[idx] + 1 < n_)
    {
        constraints_[idx]++;
        return true;
    }
    else
    {
        constraints_[idx] = 0;
        return forward(idx - 1);
    }
}

std::vector<std::vector<Work>> Work::partition(int div)
{
    int32_t rem = 1;
    if (!constraints_.empty())
    {
        rem = n_ - 1 - constraints_.back();
    }

    std::vector<std::vector<Work>> works(div);
    while (rem > 0)
    {
        while (rem < div && deepen())
        {
            rem *= n_;
        };
        int32_t cnt = rem / div;
        rem = rem % div;
        for (int i = 0; i < div; i++)
        {
            for (int j = 0; j < cnt; j++)
            {
                works[i].push_back(Work(n_, constraints_));
                forward(constraints_.size() - 1);
            }
        }

        if (cnt == 0)
        {
            for (int j = 0; j < rem; j++)
            {
                works[0].push_back(Work(n_, constraints_));
                forward(constraints_.size() - 1);
            }
            break;
        }
    }

    return works;
}

int64_t Work::solve()
{
    // Clear
    memset(board_, 0, sizeof(board_));
    cnt_ = 0;
    
    for (int i = 0; i < static_cast<int>(constraints_.size()); i++)
    {
        board_[i] = constraints_[i];
        for (int j = 0; j < i; j++)
        {
            if (board_[j] == board_[i] || abs(board_[i] - board_[j]) == abs(i - j))
            {
                return 0;
            }
        }
    }

    // Run dfs
    dfs(constraints_.size());

    return cnt_;
}

void Work::dfs(int idx)
{
    // A solution is found
    if (idx == n_)
    {
        cnt_++;
        return;
    }

    // Search current position
    for (int i = 0; i < n_; i++)
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

