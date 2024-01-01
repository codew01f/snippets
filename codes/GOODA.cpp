
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<ll>;
using pii = pair<ll, ll>;
using grid = vector<vi>;


#define fir(a) for(int i=0; i<a; ++i)


//------------------SCC tarjans' alg

vi mn(1000009, 0);
vi instk(1000009, 0);
vi idx(1000009, 0);
vi vst(1000009, 0);
ll id = 1;
vi sc(1000009, 0);
vi fun(1000009, 0);
stack<ll> stk;

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

//------sssd dp

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
   // edg[to].push_back(fr); //if undirected;
  }
  return edg; 
}
void solve(){
  ll n, m, s, e; cin>>n>>m>>s>>e;
  fir(n) cin>>fun[i+1];
  grid gph = mkgph(n, m);
  vi sc = scc(gph); //sc[i]=representative of SCC containing i;
  
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
  vi shortd = sssd(comgph, topsort, sc[s]);

  cout<<fun[sc[s]]-shortd[sc[e]]<<"\n";
  
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
