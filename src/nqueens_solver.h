
#ifndef NQUEENS_SOLVER_H
#define NQUEENS_SOLVER_H

#include <vector>

class NQueensSolver
{
public:

    /// To limit the solution space
    typedef std::vector<int> Constraint;

    /// Solve nqueens with constraint
    int solve(int n, Constraint& constraint);
  
private:

    /// The board
    int board_[30];
};

#endif // NQUEENS_SOLVER_H
