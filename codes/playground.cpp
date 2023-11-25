
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
  ll row=ft.size();
  ll col=ft[0].size(), c;
  
  for(; rr<row; rr+= -rr&rr){
    for(c=cc; c<col; c+= -c&c){
      ft[rr][c]+=val;
    }
  }
  return;
}

grid mkft(grid &g){
  ll row=g.size();
  ll col=g[0].size();
  grid gd(row+1, col+1, 0);

  fir(row){
    fjr(col){
      ftud(gd, i+1, j+1, g[i][j]);
    }
  }
  return gd;
}

ll gt(grid &ft, ll rr, ll cc){
  //ll row=ft.size();
  //ll col=ft[0].size();
  ll res=0, c;
  
  for(; rr; rr -= rr&-rr){
    for(c=cc; c; c -= c&-c){
      res+=ft[rr][c];
    }
  }
  return res;
}

ll ftgs(grid &ft, ll r1, ll c1, ll r2, ll c2){
  return gt(ft, r2, c2)-gt(ft, r1-1, c2)
        -gt(ft, r2, c1-1)+gt(ft, r1-1, c1-1);
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
      ll y, x; cin>>y>>x;
      ll temp = ftgs(ft, y, x, y, x);
      ftud(ft, y-1, x-1, 1-2*temp);
    }
    else{
      ll y1, x1, y2, x2; cin>>y1>>x1>>y2>>x2;
      cout<<ftgs(ft, y1-1, x1-1, y2-1, x2-1)<<"\n";
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
