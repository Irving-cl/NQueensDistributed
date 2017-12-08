
#ifndef NQUEENS_SOLVER_H
#define NQUEENS_SOLVER_H

#include <cstdint>
#include <vector>

class NQueensSolver
{
public:

    /// To limit the solution space
    typedef std::vector<int> Constraint;

    /// Solve nqueens with constraint
    int64_t solve(int n, Constraint& constraint);
  
private:
    
    /// Search solutions recursively
    void dfs(int idx);

    /// Check if the constraint is valid
    bool is_constraint_valid(int n, Constraint& constraint);

    /// The board
    int board_[30];

    /// Count of solutions, to store the middle result
    int cnt_;

    // Size of the board
    int size_;
};

#endif // NQUEENS_SOLVER_H
