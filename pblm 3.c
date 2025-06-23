
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        // array is given non-decreasing
        // but let's be safe and sort
        sort(a.begin(), a.end());

        // global maxima
        int gmax = a[n-1];
        int smax = a[n-2];

        ll ans = 0;

        // consider each k as the largest index in the triple
        for (int k = 2; k < n; k++) {
            // threshold from recoloring the red max element a[k]
            ll t1 = 2LL * a[k];
            // threshold from picking the largest uncolored element
            ll t2 = (k == n-1 ? smax : gmax);
            ll T = max(t1, t2);
            // we need a[i] + a[j] > T
            // => a[i] + a[j] > T - a[k]
            ll x = T - a[k];

            // count pairs (i, j) with (0 <= i < j < k and a[i] + a[j] > x)
            int l = 0, r = k - 1;
            while (l < r) {
                ll sum = 1LL * a[l] + a[r];
                if (sum > x) {
                    // all pairs (i = l .. r-1, j = r) satisfy
                    ans += (r - l);
                    r--;
                } else {
                    l++;
                }
            }
        }

        cout << ans << "\n";
    }

    return 0;
}
