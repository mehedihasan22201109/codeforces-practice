#include <bits/stdc++.h>
using namespace std;
int main(){ios::sync_with_stdio(false);cin.tie(NULL);
int t; if(!(cin>>t)) return 0;
while(t--){int n;cin>>n; vector<long long>a(n+2),p(n+2),suf(n+3),c0(n+2);
for(int i=1;i<=n;i++)cin>>a[i];
p[1]=a[1]; for(int i=2;i<=n;i++) p[i]=min(p[i-1],a[i]);
long long S0=0; for(int i=1;i<=n;i++) S0+=p[i];
suf[n+1]=0; for(int i=n;i>=1;i--) suf[i]=p[i]+suf[i+1];
int f=n+1; for(int i=2;i<=n-1;i++) if(p[i]==p[i-1]){f=i; break;}
for(int i=2;i<=n;i++) c0[i]=p[i-1]-p[i];
long long best=0, M=LLONG_MAX;
for(int j=2;j<=n;j++){
long long sv;
if(j<=f){if(j==2) sv=suf[j]-a[j]; else{ M=min(M,c0[j-1]); sv=suf[j]-min(a[j],M); } }
else sv=suf[j];
best=max(best, sv);
}
cout<<S0-best;
if(t) cout<<"\n";
}
}
