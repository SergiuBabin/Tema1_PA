#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
#define IN 1000000007

class Task {
 public:
    void solve() {
        read_input();
        print_output(get_result());
    }

 private:
	// n -> Tipul instructiunii
	// k -> Nr. elemente interval
    int n, k;

    // Citire informatii din fisier
    void read_input() {
        ifstream fin("bani.in");
        fin >> n >> k;
        fin.close();
    }

    // Ridicarea la putere rapida
    unsigned long fast_pow(long x, long y, long p) {
        unsigned long rez = 1;
        x = x % p;

        while (y > 0) {
            if (y % 2 != 0)
                rez = (rez * x) % p;
            x = (x * x) % p;
            y = y / 2;
        }
        return rez;
    }

    // Rezolvare
    unsigned int get_result() {
        unsigned long all = 0;
        // Verificare tipului de instructiuni
        if (n == 1)
            all = (5*fast_pow(2, k-1, IN))%IN;
        else
        	all = get_n2();
        return all;
    }


    unsigned long get_n2() {
    	long n10[2] = {0, 1};
    	long n50[2] = {0, 1};
    	long n100[2] = {0, 1};
    	long n200[2] = {0, 1};
    	long n500[2] = {0, 1};

    	// Generarea elementelor pe baza rezultatelor precedente
    	for (long i = 1; i <= k; i++) {
    		n10[0] = n10[1]%IN;
	    	n50[0] = n50[1]%IN;
	    	n100[0] = n100[1]%IN;
	    	n200[0] = n200[1]%IN;
	    	n500[0] = n500[1]%IN;

    		n10[1] = n50[0]%IN + n100[0]%IN;
    		n50[1] = n10[0]%IN + n200[0]%IN;
    		n100[1] = n10[0]%IN + n100[0]%IN;
    		n200[1] = n50[0]%IN + n100[0]%IN + n500[0]%IN;
    		n500[1] = n200[0]%IN + n10[0]%IN;
    	}

    	return (n10[0]+n50[0]+n100[0]+n200[0]+n500[0])%IN;
    }

    // Printare informatii in fisier
    void print_output(unsigned int n) {
        ofstream fout("bani.out");
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
