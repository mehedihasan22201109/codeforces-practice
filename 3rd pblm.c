#include <bits/stdc++.h>
using namespace std;
using int64 = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n;
        int64 m;
        cin >> n >> m;

        // Try chain-length R = 1..n
        bool found = false;
        int R = -1;
        int64 base, Srem;
        for (int r = 1; r <= n; ++r) {
            // divineness of the chain itself
            base = int64(r) * (r + 1) / 2;
            if (base > m) break;
            Srem = m - base;
            int64 L = n - r;
            // leftover must each give between 1 and r
            if (L <= Srem && Srem <= L * int64(r)) {
                R = r;
                found = true;
                break;
            }
        }

        if (!found) {
            cout << "-1\n";
            continue;
        }

        // Build the edges now

        // 1) The chain: R -> R-1 -> ... -> 2 -> 1
        vector<pair<int,int>> edges;
        for (int x = R; x > 1; --x) {
            edges.emplace_back(x, x - 1);
        }

        // 2) Distribute Srem among the n-R leftover nodes
        int64 L = n - R;
        int64 E = Srem - L; // after giving each leftover node +1

        // We'll attach each leftover v to chain-node labeled (1 + delta)
        // Where delta = min(E, R-1)
        for (int v = R + 1; v <= n; ++v) {
            int64 extra = min(int64(R - 1), E);
            E -= extra;
            int attach_to = int(1 + extra);
            edges.emplace_back(attach_to, v);
        }

        // E should now be 0
        assert(E == 0);

        // 3) Output
        cout << R << "\n";
        for (auto &e : edges) {
            cout << e.first << " " << e.second << "\n";
        }
    }

    return 0;
}
