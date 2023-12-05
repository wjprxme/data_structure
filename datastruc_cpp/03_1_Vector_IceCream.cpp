#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    vector<int> money(100001,0);
    int n, m, start;
    cin >> n >> m >> start;
    money[0] = start;
    int a, s, sum = start;
    for (int i = 0; i < n; i++) {
        cin >> a >> s;
        money[a] = s;
    }

    for (int i = 1; i < money.size();i++){
        if (money[i] == 0){
            money[i] = money[i-1] + sum;
        }
        else{
            sum = money[i];
            money[i] = money[i - 1] + sum;
        }
    }
    for (int i = 0; i < m; i++) {
        int p, x;
        cin >> p >> x;
        if (money[x] >= p) {
            cout << lower_bound(money.begin(), money.end(), p) - money.begin() << ' ';
        }
        else {
            cout << lower_bound(money.begin(), money.end(),  p + money[x]) - money.begin() << ' ';
        }
    }
}
