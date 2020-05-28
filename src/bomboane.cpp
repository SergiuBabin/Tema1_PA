#include <bits/stdc++.h>
#include <unordered_set>
#include <cmath>
#define IN 1000000007
using namespace std;

struct Object {
    int start;
    int end;

    Object(int _start, int _end) : start(_start), end(_end) {}
};

class Task {
 public:
    void solve() {
        read_input();
        print_output(get_result());
    }

 private:
    // n -> Elevi
    // k -> Bomboane
    // objs -> vector de posibilitati pentru a imparti bomboanele
    int n, k;
    vector<Object> objs;

    // Citire din fisier
    void read_input() {
        ifstream fin("bomboane.in");
        fin >> n >> k;
        for (int i = 0, start, end; i < n; i++) {
            fin >> start >> end;
            objs.push_back(Object(start, end));
        }
        fin.close();
    }

    // Rezolvare
    long get_result() {
        // Memorare valori partiale
        vector<vector<long>> dp(n+1, vector<long>(k+1));
        long p, i, j;

        // Caz de baza
        for (j = objs[0].start; j <= objs[0].end; ++j) {
            if (j <= k)
                dp[0][j] = 1;
        }

        // Completarea matricii dp.
        // dp[i][j] = suma dp[i-1][p], p = j - start ... j - stop.
        for (i = 1; i <= n; ++i) {
            for (j = 0; j <= k; ++j) {
                if (j - objs[i].start >= 0) {
                    // p = j - objs[i].end;
                    if (j - objs[i].end < 0)
                        p = 0;
                    else
                        p = j - objs[i].end;
                    for (; p <= j - objs[i].start; p++) {
                        dp[i][j] = (dp[i][j] + dp[i-1][p])%IN;
                    }
                }
            }
        }
        return dp[n-1][k];
    }

    void print_output(long nr) {
        ofstream fout("bomboane.out");
        fout << nr;
        fout.close();
    }
};

int main() {
    Task *task = new Task();
    task->solve();
    delete task;
    return 0;
}
