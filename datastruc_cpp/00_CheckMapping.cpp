#include <iostream>
#include <set>
using namespace std;
int main(){
    int N;
    cin >> N;
    set <int> A;
    for (int i = 1; i <= N; i++) {
        A.insert(i);
    }
    set <int> B;
    int b;
    for (int i = 0; i < N; i++) {
        cin >> b;
        B.insert(b);
    }
    if (A == B) {
        cout << "YES";
    }
    else {
        cout << "NO";
    }
}