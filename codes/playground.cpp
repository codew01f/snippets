
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
using pii = pair<ll, ll>;

#define gd(r, c, i) gd(r, vi(c, i))
#define fix(p) cout<<setprecision(p)<<fixed

#define mid(l, r) (l&r)+((l^r)>>1)
#define fir(a) for(int i=0; i<a; ++i)
#define fjr(a) for(int j=0; j<a; ++j)

//solves ax+by=gcd(a, b) for x, y
pii eea(ll a, ll b){
  ll x=1, y=0;
  ll x1=0, y1=1, a1=a, b1=b, q=0;
  while(b1){
  cout<<x1<<" "<<y1<<" "<<a1<<" "<<b1<<endl;
    q=a1/b1;
    tie(x, x1) = make_tuple(x1, x-q*x1);
    tie(y, y1) = make_tuple(y1, y-q*y1);
    tie(a1, b1) = make_tuple(b1, a1-q*b1);
  }
  cout<<x1<<" "<<y1<<" "<<a1<<" "<<b1<<endl;
  return {x, y};
}

void solve(){
  auto p = eea(375, 80);
  return;
}

int main(){
  //freopen("input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int tt=1; //cin>>tt;
  while(tt--){
    solve();
  }
  return 0;
}
