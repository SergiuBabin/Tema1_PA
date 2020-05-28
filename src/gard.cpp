#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
#define IN 1000000007

// Structura pentru obiectele de tip Gard
struct Gard {
    int start;
    int end;

    Gard(int _start, int _end) : start(_start), end(_end) {}
};

// Comparator pentru sortare crescatoare
bool comp(Gard &e1, Gard &e2) {
    if (1.0*e1.start < 1.0*e2.start)
        return true;
    else if (1.0*e1.start > 1.0*e2.start)
        return false;
    return (1.0*e1.end > 1.0*e2.end);
}

class Task {
 public:
    void solve() {
        read_input();
        print_output(get_result());
    }

 private:
    // n -> numarul de garduri
    // gard -> vector de tip gard
    int n;
    vector<Gard> gard;

    // Citire input din fisier
    void read_input() {
        ifstream fin("gard.in");
        fin >> n;
        for (int i = 0, start, end; i < n; i++) {
            fin >> start >> end;
            gard.push_back(Gard(start, end));
        }
        fin.close();
    }

    // Rezolvare folosind algoritm Greedy
    unsigned int get_result() {
        // Sortarea vectorului de tip Gard
        sort(gard.begin(), gard.end(), comp);
        // Obiect pentru a memora gardul precedent
        Gard mid = Gard(gard[0].start, gard[0].end);

        unsigned int rez = 0;
        // Verificare coliziuni si gasire bucati de gard redundante
        for (int i = 1; i < gard.size(); i++) {
            if (gard[i].start >= mid.start && gard[i].end <= mid.end) {
                rez++;
                continue;
            }
            mid.start = gard[i].start;
            mid.end = gard[i].end;
        }
        return rez;
    }

    // Printare rezultat
    void print_output(unsigned int n) {
        ofstream fout("gard.out");
        fout << n << '\n';
        fout.close();
    }
};

int main() {
    Task *task = new Task();
    task->solve();
    delete task;
    return 0;
}
