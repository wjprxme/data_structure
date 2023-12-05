#include <iostream>
#include <set>
using namespace std;
int main() {
    int n,a;
    cin >> n >> a;
    set<int> s;
    s.insert(a);
    for(auto itr = s.begin(); itr != s.end(); itr++){
        int new1 = (*itr + 1)* 2 - 1;
        int new2 = (*itr + 1)* 2;
        if (new1 >= n) {
            continue;
        }
        s.insert(new1);
        if (new2 >= n) {
            continue;
        }
        s.insert(new2);
    }
    cout << s.size() << endl;
    for (auto itr = s.begin(); itr != s.end(); itr++){
        cout << *itr << ' ';
    }
}
