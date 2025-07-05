#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--){
        ull n,l,r,k;
        cin>>n>>l>>r>>k;
        if(n==1){
            cout<<l<<"\n";
        } else if(n&1){
            if(k<=n) cout<<l<<"\n";
            else cout<<"-1\n";
        } else{
            if(n==2){
                cout<<"-1\n";
            } else{
                ull x=l;
                while(true){
                    bool ok=true;
                    for(int i=0;i<64;i++){
                        ull bit=1ULL<<i;
                        if((l&bit) && (x&bit)){
                            x+=bit;
                            x&=~(bit-1);
                            ok=false;
                            break;
                        }
                    }
                    if(ok) break;
                }
                if(x>r){
                    cout<<"-1\n";
                } else{
                    if(k<=n-2) cout<<l<<"\n";
                    else cout<<x<<"\n";
                }
            }
        }
    }
    return 0;
}


