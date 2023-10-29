
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

int rr, cc;

vector<vi> res = {};
vi rws(8, 0);
vi d1 = {}; 
vi d2 = {};

int prs(vi &v, int t){
  for(ll i: v){
    if(i==t) return 1;
  }
  return 0;
}
void pb(int r, int c){
  rws[c-1]=r;
  d1.push_back(r+c);
  d2.push_back(r-c);
}
void ppb(int r, int c){
  rws[c-1]=0;
  d1.pop_back();
  d2.pop_back();
}

void dfs(int c){
  if(c==cc){
    dfs(c+1);
    return;
  }
  if(c==9){
    res.push_back(rws);
    return;
  }

  for(int r=1; r<9; ++r){
    if(prs(rws, r) ||
       prs(d1, r+c)||
       prs(d2, r-c)) continue;
    else{
      pb(r, c);
      dfs(c+1);
      ppb(r, c);
    }
  }
}
void solve(){
  cin>>rr>>cc;
  pb(rr,cc);
  dfs(1);
  for(vi v: res){
    for(ll i:v) cout<<i<<" ";
    cout<<"\n";
  }
  res={};
  rws=vi(8,0);
  d1={};
  d2={};
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
