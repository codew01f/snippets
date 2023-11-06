
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

ll cn=8, ce=13;

vector<vector<pii>> mkwgph(ll cn, ll ce){
  vector<vector<pii>> edg(cn+1, vector<pii>(0));

  ll fr, to, wt;
  fir(ce){
    cin>>fr>>to>>wt;
    edg[fr].push_back({to, wt});
  }
  return edg; 
}
vi wtsort(ll cn, ll ce, vector<vector<pii>> &edg){
  vi ts(cn, 0);
  vi indg(cn+1, 0);
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

vi sssd(ll cn, ll ce, ll s, vector<vector<pii>> &edg, vi &ts){
  vi dis(cn+1, INT_MAX);
  dis[s]=0;

  ll idx=0;
  while(ts[idx]!=s) idx++;
  while(idx<cn){
    ll at=ts[idx];
    for(auto [to, wt]:edg[at]){
      dis[to]=min(dis[to], dis[at]+wt);
    }
    idx++;
  }
  return dis;
}
void solve(){
  auto edg=mkwgph(cn, ce);
  vi ts=wtsort(cn, ce, edg);
  for(ll i:ts)cout<<i<<" ";
  cout<<endl;
  vi sd=sssd(cn, ce, 1, edg, ts);
  for(ll i:sd)cout<<i<<" ";
  cout<<endl;
  return; 
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
