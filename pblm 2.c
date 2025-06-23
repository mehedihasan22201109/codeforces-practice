
#include <bits/stdc++.h>
using namespace std;

struct RMQ {
    int n, LOG;
    vector<vector<int>> mn, mx;

    RMQ(const vector<int>& A) {
        n = A.size();
        LOG = 32 - __builtin_clz(n);
        mn.assign(LOG, vector<int>(n));
        mx.assign(LOG, vector<int>(n));

        // level 0
        for(int i = 0; i < n; i++) {
            mn[0][i] = mx[0][i] = A[i];
        }

        // build
        for(int k = 1; k < LOG; k++) {
            int len = 1 << (k-1);
            for(int i = 0; i + 2*len <= n; i++) {
                mn[k][i] = min(mn[k-1][i], mn[k-1][i+len]);
                mx[k][i] = max(mx[k-1][i], mx[k-1][i+len]);
            }
        }
    }

    // query [l..r] inclusive
    pair<int,int> query(int l, int r) {
        int len = r - l + 1;
        int k = 31 - __builtin_clz(len);
        int j = 1<<k;
        int mnv = min(mn[k][l], mn[k][r-j+1]);
        int mxv = max(mx[k][l], mx[k][r-j+1]);
        return {mnv, mxv};
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; i++)
            cin >> a[i];

        // 0-cost check
        bool ok0 = false;
        for(int i = 0; i+1 < n; i++) {
            if(abs(a[i] - a[i+1]) <= 1) {
                ok0 = true;
                break;
            }
        }

        if (ok0) {
            cout << 0 << "\n";
            continue;
        }

        // build RMQ for range-min and range-max
        RMQ rmq(a);

        int best = n;  // sentinel: impossible

        // scan all pairs i < j
        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                int cost = j - i - 1;
               if (cost >= best) break;

               auto[mn1,mx1] = rmq.query(i, j-1);
               if(mn1 <= a[j] + 1 && mx1 >= a[j] - 1){
                    best=cost;
                    break;
               }
               auto [mn2, mx2] = rmq.query(i+1, j);
               if (mn2 <= a[i] + 1 && mx2 >= a[i] - 1){

        best =cost;
        break;

                }
            }
        }

        cout << (best == n ? -1 : best) << "\n";
    }

    return 0;
}
