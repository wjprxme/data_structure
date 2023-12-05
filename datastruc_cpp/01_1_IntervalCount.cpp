#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    long long k;
    cin >> n >> m >> k;
    vector<int> vn;

    for (int i = 0; i < n; i++) {
        long long x;
        cin >> x;
        vn.push_back(x);
    }
    sort(vn.begin(), vn.end());

    for (int i = 0; i < m; i++) {
        long long p;
        cin >> p;
        int lower = p - k;
        int upper = p + k;
        int count = upper_bound(vn.begin(), vn.end(), upper) - lower_bound(vn.begin(), vn.end(), lower);
        cout << count << ' ';
    }
    return 0;
}