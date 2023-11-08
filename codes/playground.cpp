
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

ll cn=7, ce=12;

vector<vector<pii>> mkwgph(ll cn, ll ce){
  vector<vector<pii>> edg(cn+1, vector<pii>(0));

  ll fr, to, wt;
  fir(ce){
    cin>>fr>>to>>wt;
    edg[fr].push_back({to, wt});
    edg[to].push_back({fr, wt});
  }
  return edg; 
}

set<pii> mst(ll cn, ll ce, vector<vector<pii>> &edg){
  set<pii> mst;
  vi vst(cn+1, 0);
  priority_queue<pair<ll, pii>, vector<pair<ll, pii>>, greater<pair<ll, pii>>> call;
  
  for(auto [to, wt]:edg[1]){
    call.push({wt, {1, to}});
  }
  vst[1]++;
  while(!call.empty()){
    auto [wt0, nd]=call.top();
    auto [at0, to0]=nd;
    call.pop();

    if(vst[to0]) continue;
    mst.insert({at0, to0});
    vst[to0]++;
    for(auto [to, wt]:edg[to0]){
      if(!vst[to]) call.push({wt, {to0, to}});
    }
  }
  return mst;
}
void solve(){
  auto edg=mkwgph(cn, ce);
  set<pii> mst1=mst(cn, ce, edg);
  for(auto [x, y]:mst1) cout<<x<<" "<<y;
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
