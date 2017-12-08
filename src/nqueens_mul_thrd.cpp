
#include <iomanip>
#include <iostream>
#include <mutex>
#include <stdint.h>
#include <thread>
#include <vector>

#include <sys/time.h>

#include "nqueens_solver.h"

std::mutex mtx;
int64_t ans = 0;

void foo(std::vector<int>& vec, int i, int n, int one_third) {
    std::vector<NQueensSolver::Constraint> constraints(vec[i]);
    for (int j = 0; j < vec[i]; j++)
    {
        constraints[j].push_back(j + one_third * i);
    }
    for (auto& constraint : constraints)
    {
        NQueensSolver solver;
        int64_t tmp = solver.solve(n, constraint);
        std::lock_guard<std::mutex> lck(mtx);
        ans += tmp;
    }
}

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        std::cerr << "Usage: nqueens_mul_thrd <n>\n";
        return -1;
    }

    struct timeval tpstart, tpend;
    gettimeofday(&tpstart, NULL);

    int n = ::atoi(argv[1]);

    // Divide into three threads temporarily
    int one_third = n / 3;
    std::vector<int> vec({ one_third, one_third, n - 2 * one_third });
    std::vector<std::thread> thrds;
    for (int i = 0; i < 3; i++)
    {
        thrds.push_back(std::thread(/*
            [&vec, &i, &n, &one_third](){
                std::vector<NQueensSolver::Constraint> constraints;
                for (int j = 0; j < vec[i]; j++)
                {
                    constraints[j].push_back(j + one_third * i);
                }
                for (auto& constraint : constraints)
                {
                    NQueensSolver solver;
                    int64_t tmp = solver.solve(n, constraint);
                    std::lock_guard<std::mutex> lck(mtx);
                    ans += tmp;
                }
            }));*/
                foo, std::ref(vec), i, n, one_third));
    }
    for (int i = 0; i < 3; i++)
    {
        thrds[i].join();
    }

    std::cout << ans << "\n";

    gettimeofday(&tpend, NULL);
    double timeuse = 1000000 * (tpend.tv_sec - tpstart.tv_sec) + tpend.tv_usec - tpstart.tv_usec;
    std::cout << "Time cost: " << std::setprecision(4) << timeuse / 1000000 << "s\n";
}
