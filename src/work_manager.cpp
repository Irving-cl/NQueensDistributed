
#include "work_manager.h"

#include <algorithm>
#include <memory>

WorkManager::WorkManager(int n, int degree)
  : n_(n),
    degree_(degree),
    idx_(0),
    start_idx_(0)
{
    std::fill_n(board_, 30, -1);
}

bool WorkManager::set_constraint(std::vector<int>& constraint)
{
/*
    if (constraint.size() > n_ - degree_)
    {
        return false;
    }
*/
    start_idx_ = constraint.size();
    std::fill_n(board_, 30, -1);
    for (idx_ = 0; idx_ < constraint.size(); idx_++)
    {
        board_[idx_] = constraint[idx_];
    }
    
    return true;
}

std::shared_ptr<Work> WorkManager::get_work()
{
    while (idx_ >= start_idx_) {
        if (idx_ + degree_ >= n_) {    // get a work
            std::vector<int> constraint(board_, board_ + idx_);
            idx_--;
            return std::make_shared<Work>(n_, constraint);
        } else {
            board_[idx_]++;
            if (board_[idx_] == n_) {
                board_[idx_] = -1;
                idx_--;
            } else {
                bool flag = true;
                // check
                for (int j = 0; j < idx_; j++) {
                    if (board_[j] == board_[idx_] ||
                        abs(board_[idx_] - board_[j]) == abs(idx_ - j)) {
                        flag = false;
                        break;
                    }
                }
                if (flag) idx_++;
            }
        }
    }

    // return empty shared_ptr
    return std::shared_ptr<Work>();
}
