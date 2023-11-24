
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


void ftud(grid &ft, ll i, ll jj, ll val){
  ll r=ft.size();
  ll c=ft[0].size();
  
  ll j;
  for(; i<r; i += -i&i){
    for(j=jj; j<c; j += -j&j){
      ft[i][j]+=val;
    }
  }
  return;
}

grid mkft(grid &g){
  ll r=g.size();
  ll c=g[0].size();
  grid res(r+1, vi(c+1, 0));

  fir(r){
    fjr(c){
      ftud(res, i+1, j+1, g[j][i]);
    }
  }
  return res;
}

ll gt(grid &ft, ll x, ll yy){
  ll res=0, y;
  for(; x; x -= x&-x){
    for(y=yy; y; y -= y&-y){
      res+=ft[x][y];
    }
  }
  return res;
}

ll ftgs(grid &ft, ll x1, ll y1, ll x2, ll y2){
   x1++; y1++; x2++; y2++;
   return gt(ft, x2, y2)-gt(ft, x1-1, y2)-gt(ft, x2, y1-1)+gt(ft, x1-1, y1-1);
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
      ftud(ft, y-1, x-1, 1-2*temp);
    }
    else{
      ll y1, x1, y2, x2; cin>>x1>>y1>>x2>>y2;
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
