
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

ll cn = 10, ce=14; 
vi mn(cn+1, 0);
vi instk(cn+1, 0);
vi idx(cn+1, 0);
vi vst(cn+1, 0);
ll id = 1;
vi sc(cn+1, 0);
stack<ll> stk;


grid mkgph(ll cn, ll ce){
  grid edg(cn+1, vi(0)); 

  ll fr, to;
  fir(ce){
    cin>>fr>>to;
    edg[fr].push_back(to);
//    edg[to].push_back(fr); //if undirected;
  }
  return edg; 
}


void dfs(grid &edg, ll n){
  vst[n]++;
  idx[n]=id;
  mn[n]=id;
  id++;
  stk.push(n); instk[n]++;
  for(ll to: edg[n]){
    if(!vst[to]){
      dfs(edg, to);
      mn[n]=min(mn[n], mn[to]);
    }else if(instk[to]){
      mn[n]=min(mn[n], idx[to]);
    }
  }

  if(mn[n]==idx[n]){
    while(1){
      ll at = stk.top();
      sc[at]=n;
      stk.pop(); instk[at]=0;
      if(at==n) break;
    }
  }
}

vi scc(grid &edg){
  ll cn = edg.size();
  fir(cn){
    if(!vst[i]) dfs(edg, i);
  }
  return sc;
}

void solve(){
  grid g = mkgph(cn, ce);
  vi c = scc(g);
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
