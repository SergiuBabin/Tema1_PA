#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
#define IN 1000000007

struct Object {
    int start;
    int stop;

    Object(int _start, int _stop) : start(_start), stop(_stop) {}
};

bool comp(Object &e1, Object &e2) {
    if (1.0*e1.start*1.0*e1.stop < 1.0*e2.start*1.0*e2.stop)
        return false;
    else if (1.0*e1.start*1.0*e1.stop > 1.0*e2.start*1.0*e2.stop)
        return true;
    return (1.0*e1.start > 1.0*e2.start);
}

class Task {
 public:
    void solve() {
        read_input();
        print_output(get_result());
    }

 private:
    int n, k;
    vector<Object> objs;

    void read_input() {
        ifstream fin("sala.in");
        fin >> n >> k;
        for (int i = 0, start, stop; i < n; i++) {
            fin >> start >> stop;
            objs.push_back(Object(start, stop));
        }
        fin.close();
    }

    unsigned int get_result() {
        // sort(objs.begin(), objs.end(), comp);
        // Object mid = Object(objs[0].start, objs[0].stop);
        // cout<<"---------------------------";
        // unsigned int sum = 0;
        // unsigned int tempSum = mid.start*mid.stop;

        // for (int i = 1; i < objs.size(); i++) {
        //     sum = tempSum;
        //     if (tempSum > sum) {
        //         sum = tempSum;
        //         continue;
        //     }
        //     mid.start = objs[i].start;
        //     mid.stop = objs[i].stop;
        //     //cout<<objs[i].start <<" "<< objs[i].stop<<"\n";
        // }
        // return sum;
        return 0;
    }

    void print_output(unsigned int n) {
        ofstream fout("sala.out");
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
