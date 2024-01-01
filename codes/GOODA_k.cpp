
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<ll>;
using pii = pair<ll, ll>;
using grid = vector<vi>;

#define fir(a) for(int i=0; i<a; ++i)


vi fun(1000009, 0);
//------------------SCC kosaraju
grid revg(1000009, vi(0));
vi vst(1000009, 0);
vi sc(1000009, 0);
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
//--------------------------

//------------------------tsort
vi wtsort(vector<vector<pii>> &edg){
  ll cn=edg.size()-1;
  vi ts(cn, 0), indg(cn+1, 0);
  queue<ll> call;

  for(auto v:edg){
    for(auto[to, wt]:v) indg[to]++;
  }
  fir(cn){
    if(!indg[i+1]) call.push(i+1);
  }

  ll id=0;
  while(!call.empty()){
    ll at=call.front();
    call.pop();
    ts[id++]=at;

    for(auto [to, wt]:edg[at]){
      indg[to]--;
      if(!indg[to]) call.push(to);
    }
  }
  return ts;
}
//-----------------------/tsort

//single source shortest dis
vi sssd(vector<vector<pii>> &edg, vi &ts, ll s){
  ll cn=edg.size();
  vi dis(cn, INT_MAX);
  dis[s]=0;

  ll idx=0;
  while(ts[idx]!=s) idx++;
  while(idx<cn-1){
    ll at=ts[idx];
    for(auto [to, wt]:edg[at]){
      dis[to]=min(dis[to], dis[at]+wt);
    }
    idx++;
  }
  return dis;
}
//----------------/sssd


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
  ll n, m, s, e; cin>>n>>m>>s>>e;
  fir(n) cin>>fun[i+1];
  grid gph = mkgph(n, m);
  vi sc = scc(gph, revg);
  
  for(int i=1; i<=n; i++){ //calculates fun of scc to head.
    if(i != sc[i]){
      fun[sc[i]]+=fun[i];
    }
  }

  vector<vector<pii>> comgph(n+1, vector<pii>(0));
  fir(n) for(ll to: gph[i+1]){
    if(sc[i+1]-sc[to])
    comgph[sc[i+1]].push_back({sc[to], -fun[to]});
  }
  
  vi topsort = wtsort(comgph);
  vi shortd = sssd(comgph, topsort, s);
  
  cout<<fun[s]-shortd[sc[e]]<<"\n";
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
