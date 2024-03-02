// the solution of problem C in ncpc_preliminary_2023

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

ll cs=1;

vector<pii> lic(vi &v){
  ll n=v.size();
  vector<pii> seq(n); set<ll> s;
  fir(n){
    auto it=s.lower_bound(v[i]);
    if(it==s.end()) s.insert(v[i]);
    else{
      s.erase(it);
      s.insert(v[i]);
    } 
    seq[i]={s.size(), *(s.rbegin())};
  }
  return seq;
}

void solve(){
  ll n; cin>>n;
  vi v(n); fir(n) cin>>v[i];

  vector<pii> forw = lic(v);
  
  reverse(v.begin(), v.end()); 
  vector<pii> back = lic(v);
  reverse(back.begin(), back.end());


  ll mx=0;
  fir(n){
    ll lft=forw[i].first;
    ll rgt=back[i].first;
    if(lft==1 || rgt==1) continue;
    else mx=max((lft+rgt)-(forw[i].second==back[i].second), mx);
  }
  cout<<"Case "<<cs++<<": ";
  cout<<(mx>2 ? mx:-1);
  cout<<"\n";
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
