#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        ll px, py, qx, qy;
        cin >> px >> py >> qx >> qy;
        vector<ll> a(n);
        ll S = 0, M = 0;
        for(int i = 0; i < n; i++){
            cin >> a[i];
            S += a[i];
            M = max(M, a[i]);
        }

        ll L = max(0LL, 2*M - S);

        ll dx = qx - px;
        ll dy = qy - py;
        ll dist2 = dx*dx + dy*dy;

        bool ok = (dist2 <= S*S) && (dist2 >= L*L);
        cout << (ok ? "Yes\n" : "No\n");
    }
    return 0;
}
