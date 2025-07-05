#include <iostream>
#include<vector>
using namespace std;

int solve_case(int n, int mod) {
    vector<int> dp(n + 1, 0);
    dp[0] = 1 % mod;
    int max_k = 0;

    for (int p = n; p >= 1; --p) {
        for (int k = max_k; k >= 0; --k) {
            if (dp[k] == 0) continue;
            int free = n - p + 1 - k;
            if (free <= 0) break;

            long long add = (1LL * dp[k] * free) % mod;
            add = (add * p) % mod;

            dp[k + 1] = (dp[k + 1] + add) % mod;
        }
        if (dp[max_k + 1]) max_k++;
    }

    int res = 0;
    for (int val : dp) {
        res = (res + val) % mod;
    }
    return res;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        cout << solve_case(n, m) << '\n';
    }
    return 0;
}
