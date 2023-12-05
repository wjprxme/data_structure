#include <iostream>
#include <vector>
using namespace std;
void multiple_add(vector<int> &v, int value, int position, int count) { 
    // write your code here
    // for (int i = 0; i < count; i++) {
    //     v.insert(v.begin() + position, value);
    // }
    vector <int> before;
    for (int i = 0; i < position; i++) {
        before.push_back(v[i]);
    }
    vector <int> insert;
    for (int i = 0; i < count; i++) {
        insert.push_back(value);
    }
    vector <int> after;
    for (int i = position; i < v.size(); i++) {
        after.push_back(v[i]);
    }
    v = before;
    for (int i = 0; i < insert.size(); i++) {
        v.push_back(insert[i]);
    }
    for (int i = 0; i < after.size(); i++) {
        v.push_back(after[i]);
    }
    

}
int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, value, position, count;
    cin >> n >> value >> position >> count;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    multiple_add(v, value, position, count);
    cout << "After call multiple_add" << endl
         << "Size = " << v.size() << endl;
    for (auto &x : v)
        cout << x << " ";
    cout << endl;
}