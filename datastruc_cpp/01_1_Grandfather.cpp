#include <iostream>
#include <unordered_map>
using namespace std;

long long findfather(unordered_map<long long, long long>& fathers, long long person) {
    if (fathers.find(person) == fathers.end()) {
        return -1;
    } 
    return fathers[person];
}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);

    long long N, M, F, S, A, B;
    cin >> N >> M;

    unordered_map<long long, long long> fathers;

    for (long long i = 0; i < N; i++) {
        cin >> F >> S;
        fathers[S] = F;
    }
    
    for (long long i = 0; i < M; i++) {
        cin >> A >> B;
        long long fatherA = findfather(fathers, A);
        long long fatherB = findfather(fathers, B);
        long long grandfatherA = findfather(fathers, fatherA);
        long long grandfatherB = findfather(fathers, fatherB);
        if (grandfatherA == grandfatherB && A != B && grandfatherA != -1) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
}