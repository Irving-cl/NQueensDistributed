
#ifndef WORK_MANAGER_H
#define WORK_MANAGER_H

#include <memory>
#include <vector>

#include "nqueens_solver.h"

/*
 * |-------------------- n --------------------|
 * |--------- work ---------|----- degree -----|
 */
class WorkManager
{
public:

    /// Constructor
    WorkManager(int n, int degree);

    /// Set constraint for current space, constraint size must be less or equal than work
    bool set_constraint(std::vector<int>& constraint);

    /// Get one unit work
    std::shared_ptr<Work> get_work();
 
private:

    /// Size of n-queens
    int32_t n_;

    /// Degree of one work unit
    int32_t degree_;

    /// Board, to store the state
    int32_t board_[30];

    /// Index, the important state
    int32_t idx_;

    /// Start Index, for constraint
    int32_t start_idx_;
};

#endif // WORK_MANAGER_H
