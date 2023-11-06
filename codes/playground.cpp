

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

ll cn=13, ce=18;

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

vi tsort(ll cn, ll ce, grid &edg){
  vi ts(cn, 0);
  vi vst(cn+1, 0);
  stack<int> call;

  ll cnt=cn;
  fir(cn){
    if(vst[i+1]) continue;
    call.push(i+1);
    vst[i+1]++;

    while(!call.empty()){
      
      ll at=call.top();
      ll lf=1;
      for(ll to:edg[at]){
        if(vst[to]) continue;
        call.push(to);
        vst[to]++;
        lf=0;
      }
      if(lf){
        ts[--cnt]=at;
        call.pop();
      }
    }  
  }
  return ts;
}
void solve(){
  grid edg1 = mkgph(cn, ce);
  vi tpsrt=tsort(cn, ce, edg1);
  for(ll i:tpsrt) cout<<i<<" ";
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
