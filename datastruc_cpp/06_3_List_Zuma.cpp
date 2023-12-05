#include <iostream>
#include <list>
using namespace std;
int main () {
    int n, k, v, initial;
    cin >> n >> k >> v;
    list <int> l;
    for (int i = 0; i < n; i++) {
        cin >> initial;
        l.push_back(initial);
    }
    auto rightitr = l.insert(next(l.begin(), k), v);
    auto leftitr = rightitr;
    bool status = 1;
    while (l.size() > 0) {
        int leftcount = 0, rightcount = 0;
        while (*rightitr == *(++rightitr)) {
            rightcount++;
        }
        while (*leftitr == *(--leftitr)) {
            leftcount++;
        }
        leftitr++;
        int range = leftcount + rightcount + 1;
        if (range >= 3 && (leftcount >= 1 || status))  {
            while (range--) {
                leftitr = l.erase(leftitr);
            }
        }
        else {
            break;
        }
        status = 0;
    }
    for (auto& x : l) {
        cout << x << ' ';
    }
}