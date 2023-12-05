#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main () {
    std::ios_base::sync_with_stdio(false); 
    std::cin.tie(0);

    int n, m;
    cin >> n >> m;

    int a, b;
    vector <int> date;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        date.push_back((a * 13) + b);
    }
    sort(date.begin(), date.end());

    int x, y;
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        int z = (x * 13) + y;
        auto w = lower_bound(date.begin(), date.end(), z);
        if (z == *(w)) {
            cout << "0 0 ";
        } 
        else if (z < *(date.begin())) {
            cout << "-1 -1 ";
        } 
        else {
            w--;
            cout << *(w) / 13  << ' ' << *(w) % 13 << ' ';
        }
    }
}
