#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0);
    map <string, int> mapname;
    int n, m;
    cin >> n >> m;
    string name;
    for (int i = 0; i < n; i++) {
        cin >> name;
        mapname[name]++;
    }
    vector <int> v;
    for(auto&itr : mapname) {
        v.push_back(itr.second);
    }
    sort(v.begin(),v.end());
    if (v.size() < m) {
        cout << v[0];
    }
    else {
        m--;
        while (m-- && v.size() > 0){
            v.pop_back();
        }
        cout << *(v.end() - 1);
    }
}