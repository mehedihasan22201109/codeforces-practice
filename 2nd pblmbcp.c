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
        int64 s;
        cin >> n >> s;
        int64 count = 0;
        for (int i = 0; i < n; i++) {
            int dx, dy;
            int64 x, y;
            cin >> dx >> dy >> x >> y;
            int64 delta = (dx * x - dy * y) % s;
            if (delta < 0) delta += s;
            if (delta == 0)
                count++;
        }
        cout << count << "\n";
    }

    return 0;
}
