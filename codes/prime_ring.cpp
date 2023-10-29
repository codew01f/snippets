

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

si prms = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
int tc  = 1;
set<vi> res={};
vi cur={1};
si used={1};

void dfs(int n){
  
  if(cur.size() == n){
    if(prms.find(cur[0]+cur[n-1]) != prms.end()){
      res.insert(cur);
    }
    return;
  }

  for(int i=2; i<=n; ++i){
    if(used.find(i) != used.end()) continue;
    int prm = i+cur.back();
    if(prms.find(prm) == prms.end()) continue;

    cur.push_back(i);
    used.insert(i);
    dfs(n);
    cur.pop_back();
    used.erase(i);
  }
}

void solve(){
  cout<<"Case "<<tc<<":\n";
  int n; cin>>n;
  res={};
  dfs(n);
  for(vi v: res){
    for(int i: v){
      cout<<i<<" ";
    }
    cout<<"\n";
  }
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int tt=1; cin>>tt;
  while(tt--){
    solve();
    tc++;
  }
  return 0;
}
