#include <bits/stdc++.h>
using namespace std;
using int64 = long long;

int64 gcd64(int64 a, int64 b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int64> b(n);
        for (int i = 0; i < n; i++) cin >> b[i];
        int64 L = 1;
        for (int i = 0; i + 1 < n; i++) {
            if (b[i] == 0 || b[i + 1] == 0) continue;
            int64 g = gcd64(b[i], b[i + 1]);
            int64 d = b[i] / g;
            int64 gg = gcd64(L, d);
            __int128 tmp = (__int128)L / gg * d;
            L = (int64)tmp;
        }
        cout << L << "\n";
    }
    return 0;
}
