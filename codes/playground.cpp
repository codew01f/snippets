
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



grid mkst(vi &v){
  int n = v.size();
  int k = log2(n-1);
  grid st(k+1, vi(n, 0));

  fir(n){
    st[0][i] = v[i];
  }
  fir(k){
    fjr(n-(2<<i)+1){
      st[i+1][j] = min(st[i][j], st[i][j+(1<<i)]);
    }
  }
  return st;
}

ll stgm(grid &st, int l, int r){ //0 indexed;
  int i = log2(r-l);
  ll mi = min(st[i][l], st[i][r-(1<<i)+1]);

  return mi;
}void solve(){
  vi v = {24, 1, 23, -2, 20, 4, 8, 12, 16};
  grid sp = mkst(v);
  for(vi x:sp){
    for(ll i:x){
      cout<<i<<" ";
    }
    cout<<endl;
  }
  cout<<stgm(sp, 0, 8);
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
