
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

void foo(int id, std::vector<Work>& vec) {
    for (auto& work : vec) {
        int64_t tmp = work.solve();
        std::lock_guard<std::mutex> lock(mtx);
        ans += tmp;
    }
}


int main(int argc, char* argv[])
{
    if (argc != 3)
    {
        std::cerr << "Usage: nqueens_mul_thrd <n> <threads>\n";
        return -1;
    }

    struct timeval tpstart, tpend;
    gettimeofday(&tpstart, NULL);

    int n = ::atoi(argv[1]);
    int n_threads = ::atoi(argv[2]);

    // Divide into three threads temporarily
    Work work(n);
    std::vector<std::vector<Work>> works = work.partition(n_threads);
    /*
    for (auto& ele:works) {
        for (auto& work:ele) work.print();
        std::cout << "\n";
    }*/
    std::vector<std::thread> thrds;
    for (int i = 0; i < n_threads; i++)
    {
        thrds.push_back(std::thread(foo, i, std::ref(works[i])));
    }
    for (int i = 0; i < n_threads; i++)
    {
        thrds[i].join();
    }

    std::cout << "n: " << n << "  answer: " << ans << "\n";

    gettimeofday(&tpend, NULL);
    double timeuse = tpend.tv_sec - tpstart.tv_sec + (tpend.tv_usec - tpstart.tv_usec) * 1e-6;
    std::cout << "Use seconds: " << tpend.tv_sec - tpstart.tv_sec << "  microseconds: " << tpend.tv_usec - tpstart.tv_usec << "\n";
    std::cout << "Time cost: " << std::setprecision(4) << timeuse << "s\n";
}
