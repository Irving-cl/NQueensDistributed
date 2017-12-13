
#ifndef NQUEENS_SOLVER_H
#define NQUEENS_SOLVER_H

#include <cstdint>

#include <iostream>
#include <queue>
#include <vector>

class Work
{
public:

    /// Constructor
    Work(int n, std::vector<int>& constraints);
    Work(int n);

    /// Paritition it into multiple divisions
    std::vector<std::vector<Work>> partition(int div);

    /// Calculate count for this work
    int64_t solve();

    /// Unit partition
    void unit_partition(int degree);

    void print()
    {
        for (int i = 0; i < constraints_.size(); i++)
            std::cout << constraints_[i] << " ";
        std::cout << "\n";
    }
private:

    /// Size of N queens
    int32_t n_;

    /// The constraints_
    std::vector<int> constraints_;

    /// To store the result
    int64_t cnt_;

    /// To store unit works for threads
    std::queue<Work> works_;

    /// The board
    int32_t board_[30];

    /// Go deeper
    bool deepen();

    /// Move forward, go to the next constraint
    bool forward(int idx);

    /// Search solutions recursively
    void dfs(int idx);

};

#endif // NQUEENS_SOLVER_H
