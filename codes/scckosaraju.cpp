
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<ll>;
using pii = pair<ll, ll>;
using grid = vector<vi>;

#define fix(p) cout<<setprecision(p)<<fixed
#define mid(l, r) (l&r)+((l^r)>>1)
#define fir(a) for(int i=0; i<a; ++i)
#define fjr(a) for(int j=0; j<a; ++j)

ll cn=10, ce=15;
grid revg(cn+1, vi(0));
vi vst(cn+1, 0);
vi sc(cn+1, 0);
vi stk;

void dfs1(grid &edg, ll at){
  vst[at]++;
  for(ll to: edg[at]) if(!vst[to]) dfs1(edg, to);
  stk.push_back(at);
  return;
}

void dfs2(grid &rev, ll at, ll sn){
  vst[at]--; sc[at]=sn;
  for(ll to: rev[at]) if(vst[to]) dfs2(rev, to, sn);
  return;
}

vi scc(grid &edg, grid &rev){
  ll cn=edg.size();
  fir(cn) if(!vst[i]) dfs1(edg, i);
  reverse(stk.begin(), stk.end());
  for(ll j: stk) if(vst[j]){
    dfs2(revg, j, j);
  }
  return sc;
}
//-------------------------------
grid mkgph(ll cn, ll ce){
  grid edg(cn+1, vi(0)); 

  ll fr, to;
  fir(ce){
    cin>>fr>>to;
    edg[fr].push_back(to);
    revg[to].push_back(fr); //if undirected;
  }
  return edg; 
}
void solve(){
  grid g = mkgph(cn, ce);
  vi c = scc(g, revg);
  for(ll i: c) cout<<i<<" ";
  cout<<endl;
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int tt=1; // cin>>tt;
  while(tt--){
    solve();
  }
  return 0;
}
