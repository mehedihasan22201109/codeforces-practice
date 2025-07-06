
#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;

// Fenwick Tree (Binary Indexed Tree) for frequency counts on values from 1 to n
struct Fenwick {
    int N;
    vector<ll> f;

    Fenwick(int _N) : N(_N), f(N + 1, 0) {}

    void update(int i, ll delta) {
        while (i <= N) {
            f[i] += delta;
            i += (i & -i);
        }
    }

    // Returns the number of elements <= x
    ll count_le(int x) const {
        if (x < 1) return 0;
        if (x > N) x = N;
        ll sum = 0;
        while (x > 0) {
            sum += f[x];
            x -= (x & -x);
        }
        return sum;
    }
};

void solve() {
    int n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    // Check if already a palindrome
    bool is_palindrome = true;
    for (int i = 0; i < n / 2; ++i) {
        if (a[i] != a[n - 1 - i]) {
            is_palindrome = false;
            break;
        }
    }

    if (is_palindrome || k == 1) {
        cout << "YES\n";
        return;
    }

    Fenwick bit(n);
    for (ll v : a)
        bit.update((int)v, 1);

    int l = 0, r = n - 1;
    while (l < r) {
        if (a[l] == a[r]) {
            l++;
            r--;
            continue;
        }

        bool can_delete_l = (bit.count_le((int)a[l]) >= k);
        bool can_delete_r = (bit.count_le((int)a[r]) >= k);

        if (!can_delete_l && !can_delete_r) {
            cout << "NO\n";
            return;
        }

        if (can_delete_l && (!can_delete_r || a[l] > a[r])) {
            bit.update((int)a[l], -1);
            l++;
        } else {
            bit.update((int)a[r], -1);
            r--;
        }
    }

    cout << "YES\n";
}

int main(){
    int t;cin>>t;
    while(t--){
        solve();
    }
}
