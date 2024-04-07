
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

grid mk2dgph(ll r, ll c){
  grid edg(r*c, vi(0));
  function<void(ll, ll)> conn = [&](ll a, ll b){
    edg[a].push_back(b);
    edg[b].push_back(a);
  };
  
  vector<char> prv(c), cur(c); 
  fir(c){
    cin>>prv[i];
    if(i and prv[i]-'#' and prv[i-1]-'#') conn(i, i-1);
  }
  fir(r-1){ 
    fjr(c){
      ll id=c*(i+1)+j;
      cin>>cur[j];
      if(cur[j]-'#' and prv[j]-'#') conn(id, id-c);
      if(j and cur[j]-'#' and cur[j-1]-'#') conn(id, id-1);
    }
    prv=cur;
  }
  return edg;
}

void solve(){
  ll r, c; cin>>r>>c;
  grid edg=mk2dgph(r, c);
  
  for(vi v: edg){
    for(ll to: v) cout<<to<<" ";
    cout<<endl;
  }
  return;
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int tt=1; cin>>tt;
  while(tt--){
    solve();
  }
  return 0;
}
