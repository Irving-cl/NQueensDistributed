
#ifndef NQUEENS_SOLVER_H
#define NQUEENS_SOLVER_H

#include <cstdint>
#include <vector>
#include <iostream>

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

    /// The board
    int32_t board_[30];

    /// Go deeper
    bool deepen();

    /// Move forward, go to the next constraint
    bool forward(int idx);

    /// Search solutions recursively
    void dfs(int idx);

};

/*
class NQueensSolver
{
public:

    /// Solve nqueens with constraint
    int64_t solve(int n, Constraint& constraint);
  
private:
    
    /// Search solutions recursively
    void dfs(int idx);

    /// Check if the constraint is valid
    bool is_constraint_valid(int n, Constraint& constraint);

    /// The board
    int32_t board_[30];

    /// Count of solutions, to store the middle result
    int32_t cnt_;

    // Size of the board
    int32_t size_;
};
*/
#endif // NQUEENS_SOLVER_H
