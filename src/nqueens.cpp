
#include <iostream>

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


int main(int argc, char* argv[])
{
    if (argc != 2) {
        std::cerr << "Usage: nqueens <n>\n";
        return -1;
    }

    n = ::atoi(argv[1]);
    dfs(0);
    std::cout << "total: " << tot << "\n";
}
