#include <vector>
#include <algorithm>
using namespace std;

template <typename T>
vector<T> Union(const vector<T>& A, const vector<T>& B) {
    vector<T> v;
    v = A;
    for (auto& i : B) {
        if (find(v.begin(), v.end(), i) == v.end()) {
          v.push_back(i);
        }
    }
    return v;
}

template <typename T>
vector<T> Intersect(const vector<T>& A, const vector<T>& B) {
    vector<T> v;
    for (auto& i : A) {
        if (find(B.begin(), B.end(), i) != B.end()) {
          v.push_back(i);
        }
    }
    return v;
}

