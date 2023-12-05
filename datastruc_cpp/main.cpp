#include <iostream>
using namespace std;
int recur(int n) {
    if (n==0) {
        return 0;
    }
    else {
        return recur(--n)+2;
    }
}
int multiply(int n) {
    if (n == 0) {
        return 1;
    }
    else if (n % 2 == 0) {
        return multiply(--n)*3;
    }
    else if (n % 2 == 1) {
        return multiply(--n)*2;
    }
}

int main () {
    int n;
    cin >> n;
    cout << recur(n) << endl;
    cout << multiply(n);
}
