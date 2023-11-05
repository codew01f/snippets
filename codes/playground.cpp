

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


ll cn = 7; //node count;
ll ce = 9; //edge count;

grid edg1(cn+1, vi(0)); //unweighted;

void mkgph(grid &edg, ll ce){
  ll fr, to, wt;
  fir(ce){
    cin>>fr>>to;
    //if unweighted;
    edg[fr].push_back(to);
    edg[to].push_back(fr); //if undirected;
  }
  return; 
}
vi vst1(cn+1, 0);
vi prt1(cn+1, 0);

void bfs(grid &edg, ll sn, vi &vst, vi &prt){
  ll lv=-1, cl=0, nl=1;
  
  queue<ll> call;
  call.push(sn);
  while(!call.empty()){
    
    vst[sn]++;
    if(!cl){
      lv++;
      cl=nl;
      nl=0;
    }

    int at=call.front();
    call.pop(); cl--;

    for(ll to:edg[at]){
      if(!vst[to]){

        prt[to]=at;
        call.push(to);
        vst[to]++;
        nl++;
      }
    }
  }
}

void solve(){
  mkgph(edg1, ce);
  bfs(edg1, 1, vst1, prt1);
  fir(cn+1){
    cout<<"\nnode "<<i<<"par "<<prt1[i];
  }
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
