
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<long long>;
using si = set<long long>;
using pii = pair<long long, long long>;
using mii = map<long long, long long>;
using grid = vector<vector<long long>>;

#define gd(r, c, i) gd(r, vi(c, i))
#define fix(p) cout<<setprecision(p)<<fixed

#define mid(l, r) (l&r)+((l^r)>>1)
#define fir(a) for(int i=0; i<a; ++i)
#define fjr(a) for(int j=0; j<a; ++j)


void ftud(grid &ft, ll rr, ll cc, ll val){
  return;
}

grid mkft(grid &g){
 
  return res;
}

ll gt(grid &ft, ll rr, ll cc){
   return res;
}

ll ftgs(grid &ft, ll r1, ll c1, ll r2, ll c2){
}

void solve(){
  ll n, q; cin>>n>>q; grid gd(n, n, 0);
  fir(n){
    string s; cin>>s;
    fjr(n){
      char c=s[j];
      if(c=='*') gd[i][j] = 1;
    }
  }
  auto ft=mkft(gd);

  while(q--){
    int qq; cin>>qq;
    if(q==1){
      ll x, y; cin>>x>>y;
      ll temp = ftgs(ft, x, y, x,y);
      ftud(ft, x-1, y-1, 1-2*temp);
    }
    else{
      ll y1, x1, y2, x2; cin>>y1>>x1>>y2>>x2;
      cout<<ftgs(ft, x1-1, y1-1, x2-1, y2-1)<<"\n";
    }
  }
  return;
}

int main(){
  freopen("input.txt", "r", stdin);
  
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int tt=1;// cin>>tt;
  while(tt--){
    solve();
  }
  return 0;
}
