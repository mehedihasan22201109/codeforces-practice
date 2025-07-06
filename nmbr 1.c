#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        bool f = false;
        for (int i = 0; i < n && !f; i++) {
            for (int j = i + 1; j < n; j++) {
                if (a[i] > a[j]) {
                    cout << "YES\n2\n" << a[i] << " " << a[j] << "\n";
                    f = true;
                    break;
                }
            }
        }
        if (!f)
            cout << "NO\n";
        }
    return 0;
}
