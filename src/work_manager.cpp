
#include "work_manager.h"

#include <algorithm>
#include <memory>

WorkManager::WorkManager(int n, int degree)
  : n_(n),
    degree_(degree),
    idx_(0)
{
    std::fill_n(board_, 30, -1);
}

std::shared_ptr<Work> WorkManager::get_work()
{
    while (idx_ >= 0) {
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
