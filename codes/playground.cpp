
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<long long>;
using si = set<long long>;
using pii = pair<long long, long long>;
using mii = map<long long, long long>;
using grid = vector<vector<ll>>;

#define gd(r, c, i) gd(r, vi(c, i))
#define fix(p) cout<<setprecision(p)<<fixed

#define mid(l, r) (l&r)+((l^r)>>1)
#define fir(a) for(int i=0; i<a; ++i)
#define fjr(a) for(int j=0; j<a; ++j)

grid gd(5,5,-1);

void bfs(vector<vi> &q, int r, int c){
  int row=q.size();
  int col=q[0].size();
  queue<pii> call;

  ll lv=-1, cl=0, nl=1;
  
  vi dx={1, -1, 0, 0};
  vi dy={0, 0, -1, 1};

  call.push({r, c});
  while(!call.empty()){
    if(!cl){
      lv++;
      cl=nl;
      nl=0;
    }
    
    auto [y, x]=call.front();
    call.pop(); cl--;
    q[y][x]=lv;
    for(int d=0; d<4; d++){
      if(-1<y+dy[d] && y+dy[d]<row
      && -1<x+dx[d] && x+dx[d]<col
      && q[y+dy[d]][x+dx[d]] == -1){ //check !visited
        
        if(1){
          call.push({y+dy[d], x+dx[d]});
          nl++;
        }
      }
    }
  }
  return;
}


void solve(){
  gd = grid(5, vi(5, -1));
  ll r, c; cin>>r>>c;

  bfs(gd, r, c);
  fir(5){
    fjr(5){
      cout<<gd[i][j]<<" ";
    }
    cout<<"\n";
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
