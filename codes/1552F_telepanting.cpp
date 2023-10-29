
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<long long>;
using si = set<long long>;
using mii = map<long long, long long>;
using grid = vector<vector<long long>>;

#define gd(a, b, c) gd(a, vi(b, c))

#define fir(a) for(int i=0; i<a; i++)
#define fjr(b) for(int j=0; j<b; j++)

ll ffp(ll i, vi &x, vi &y){
  ll l=0, r=y.size()-1, m;
  while(1){
    m=l+(r-l)/2;
    if(r==l) 
      return m;
    if(x[m]>=y[i]) r=m;
    else l=m+1;
  }
}
void solve(){
  ll n; cin>>n;
  vi x(n), y(n);vector<short> z(n);

  fir(n){
    cin>>x[i]>>y[i]>>z[i];
  }

  vi dp(n, 0), ps(n+1, 0);
  fir(n){
    ll e=x[i], s=y[i], ep=i-1, sp=ffp(i, x, y);
    ll sdp = ps[ep+1]-ps[sp];
    ll dis = (e-s)+sdp;

    dp[i]=dis;
    ps[i+1]=ps[i]+dis;
  }

  ll res=x[n-1]+1;
  fjr(n){
    if(z[j]) res+=dp[j];
    res%=998244353;
  }
  cout<<res<<"\n";
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int tt=1; cin>>tt;
  while(tt--){
    solve();
  }
  return 0;
}
