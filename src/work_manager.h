
#ifndef WORK_MANAGER_H
#define WORK_MANAGER_H

#include <memory>

#include "nqueens_solver.h"

class WorkManager
{
public:

    /// Constructor
    WorkManager(int n, int degree);

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
};

#endif // WORK_MANAGER_H
