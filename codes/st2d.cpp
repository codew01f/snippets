
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

vector<grid> mkst(vector<vi> g){
  int r=g.size();
  int c=g[0].size();
  int k=log2(min(r, c)-1);

  vector<grid> res(k+1, grid(r, vi(c, 0)));
  fir(r){
    fjr(c){
      res[0][i][j]=g[i][j];
    }
  }
  for(int p=0; p<k; ++p){
    fir(r-(2<<p)+1){
      fjr(c-(2<<p)+1){
        ll m1=min(res[p][i][j], res[p][i][j+(1<<p)]);
        ll m2=min(res[p][i+(1<<p)][j], res[p][i+(1<<p)][j+(1<<p)]);

        res[p+1][i][j]=min(m1, m2);
      }
    }
  }
  return res;
}

ll stgm(vector<grid> st, int r, int c, int k){ //0 indexed;
  if(k==1) return st[0][r][c]; 
  int p = log2(k-1);
  int rr = r+k-1;
  int cc = c+k-1;
  ll mi1=min(st[p][r][c], st[p][rr-(1<<p)+1][c]);
  ll mi2=min(st[p][r][cc-(1<<p)+1], st[p][rr-(1<<p)+1][cc-(1<<p)+1]);
  return min(mi1, mi2);
}

void solve(){
  grid g = {{1, 2, 4, -10}, 
             {-2, 4, -1, 7},
             {3, 1, -5, -8}};
  auto st=mkst(g);
  grid d0 = st[0];
  for(vi v:d0){
    for(ll i: v){
      cout<<i<<" ";
    }
    cout<<endl;
  }
  cout<<stgm(st, 0, 1, 2)<<"\n";
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