#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int INF = 1e9;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    vector<int> qs(T), allm;
    allm.reserve(T);
    int M = 0;
    for(int i = 0; i < T; i++) {
        cin >> qs[i];
        M = max(M, qs[i]);
    }

    // We'll need dp up to M, and minSize up to M*2.
    int K = M * 2;
    vector<vector<int>> divisors(M+1);

    // precompute divisors >= 3
    for(int d = 3; d <= M; d++) {
        for(int m = d; m <= M; m += d) {
            divisors[m].push_back(d);
        }
    }

    vector<int> dp(M+1, INF), minSize(K+1, INF);
    dp[1] = 0;
    if(M >= 2) dp[2] = INF;

    // Build dp and minSize in increasing order
    for(int m = 3; m <= K; m++) {
        // a subtree whose root-color-count is m has size:
        //     minSize[m] = 1 + dp[m-2]
        //     (dp[1]=0 so minSize[3]=1, a leaf)
        minSize[m] = 1 + dp[m-2];

        // Only fill dp[m] if m <= M
        if(m > M) break;

        // Option 1: single child subtree of count = m
        dp[m] = minSize[m];

        // Option 2: split m = d * (m/d), with d>=3
        for(int d : divisors[m]) {
            int q = m / d;
            // q*d == m
            // if dp[q] was achievable, try combining:
            if(dp[q] < INF) {
                dp[m] = min(dp[m], dp[q] + minSize[d]);
            }
        }
    }

    // Answer queries
    for(int m : qs) {
        if(m == 1) {
            // only the root
            cout << 1 << "\n";
        }
        else if(dp[m] >= INF) {
            // impossible to factor m into counts >=3
            cout << -1 << "\n";
        }
        else {
            // 1 for the root, plus dp[m] for its children's total sizes
            cout << 1 + dp[m] << "\n";
        }
    }

    return 0;
}
