
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<long long>;
using si = set<long long>;
using pii = pair<long long, long long>;
using mii = map<long long, long long>;
using grid = vector<vector<ll>>;

#define mgd(r, c, i) mgd(r, vi(c, i))
#define fix(p) cout<<setprecision(p)<<fixed

#define mid(l, r) (l&r)+((l^r)>>1)
#define fir(a) for(int i=0; i<a; ++i)
#define fjr(a) for(int j=0; j<a; ++j)

vector<vi> mkst(vi &v){
  int n = v.size();
  int k = log2(n) + 1;
  vector<vi> st(k+1, vi(n, 0));

  fir(n){
    st[0][i] = v[i];
  }

  fir(k){
    fjr(n-(1<<i)+1){
      st[i+1][j] = min(st[i][j], st[i][j+(1<<i)]);
    }
  }
  return st;
}

ll stgm(vector<vi> &st, int l, int r){
  int i = log2(r-l+1);
  ll mi = min(st[i][l], st[i][r-(1<<i)+1]);

  return mi;
}void solve(){

  vi v = {2,3,4,5,6,7,8,7,6,3,2,1};
  grid st = mkst(v);
  
  fir(st.size()){
    fjr(st[0].size()){
      cout<<st[i][j]<<" ";
    }
    cout<<"\n";
  }
  cout<<stgm(st, 0, 11);
}


int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int tt=1;// cin>>tt;
  while(tt--){
    solve();
  }
  return 0;
}
