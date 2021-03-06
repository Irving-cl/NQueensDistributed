
#include <algorithm>
#include <iomanip>
#include <iostream>

#include <sys/time.h>

int n = 10;
int board[30];
int tot = 0;

void print_solution() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j == board[i]) std::cout << "Q";
            else std::cout << ".";
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}

void dfs(int idx) {
    if (idx == n) {
        //print_solution();
        tot++;
        return;
    }
    // search current position 
    for (int i = 0; i < n; i++) {
        bool flag = true;
        // check
        for (int j = 0; j < idx; j++) {
            if (board[j] == i ||
                abs(i - board[j]) == abs(idx - j)) {
                flag = false;
                break;
            }
        }
        if (flag) {
            board[idx] = i;
            dfs(idx + 1);
        }
    }
}

void nqueens(int n) {
    int idx = 0;
    std::fill_n(board, 30, -1);
    while (idx >= 0) {
        if (idx == n) {
            tot++;
            idx--;
        } else {
            board[idx]++;
            if (board[idx] == n) {
                board[idx] = -1;
                idx--;
            } else {
                bool flag = true;
                // check
                for (int j = 0; j < idx; j++) {
                    if (board[j] == board[idx] ||
                        abs(board[idx] - board[j]) == abs(idx - j)) {
                        flag = false;
                        break;
                    }
                }
                if (flag) idx++;
            }
        }
    }
}

int main(int argc, char* argv[])
{
    if (argc != 2) {
        std::cerr << "Usage: nqueens <n>\n";
        return -1;
    }

    struct timeval tpstart, tpend;
    gettimeofday(&tpstart, NULL);

    n = ::atoi(argv[1]);
    dfs(0);
    //nqueens(n);
    std::cout << "total: " << tot << "\n";

    gettimeofday(&tpend, NULL);
    double timeuse = 1000000 * (tpend.tv_sec - tpstart.tv_sec) + tpend.tv_usec - tpstart.tv_usec;
    std::cout << "Time cost: " << std::setprecision(4) << timeuse / 1000000 << "s\n";
}
