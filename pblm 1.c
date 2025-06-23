#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        int a, x, y;
        cin >> a >> x >> y;

        bool ok = false;
        // Search a reasonably large range of integer positions for Bob
        // Bob cannot choose 'a' itself
        for(int b = -1000; b <= 1000 && !ok; ++b){
            if(b == a) continue;

            // Bob must be strictly closer than Alice to both x and y
            if(abs(b - x) < abs(a - x) && abs(b - y) < abs(a - y)){
                ok = true;
            }
        }

        cout << (ok ? "YES\n" : "NO\n");
    }

    return 0;
}
