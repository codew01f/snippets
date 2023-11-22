

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<ll>;
using si = set<ll>;
using pii = pair<ll, ll>;
using mii = map<ll, ll>;
using grid = vector<vi>;

#define gd(r, c, i) gd(r, vi(c, i))
#define fix(p) cout<<setprecision(p)<<fixed

#define mid(l, r) (l&r)+((l^r)>>1)
#define fir(a) for(int i=0; i<a; ++i)
#define fjr(a) for(int j=0; j<a; ++j)

//------------------------------
//segtree template stuff

using node = vi; //segtree node
using lazy = ll; //lazytree node
using segtr = pair<vector<node>, vector<lazy>>; //segtree
node idn = vi(10, 0);
lazy lzid = 0;

node merge(node a, node b){
  node res(10);
  fir(10) res[i] = a[i]+b[i];
  return res;
}
lazy lzmerge(lazy par, lazy chl, ll sz){
  lazy res = par+chl;
  return res;
}
node lzapply(node cur, lazy upd, ll sz){
  node res(10);
  fir(10) res[(i+upd)%10]=cur[i];
  return res;
}

segtr mkst(vector<node> &v){
  ll n=v.size();
  vector<node> st(n<<1);
  vector<lazy> lt(n, lzid);

  fir(n) st[i+n]=v[i];
  for(int i=n-1; i; --i)
    st[i]=merge(st[i<<1], st[i<<1|1]);

  return {st, lt};
}

void prgt(segtr &tr, ll nd, ll sz){
  auto [st, lt] = tr;
  ll n=lt.size();
  lazy upd = lt[nd];
  ll lft=nd<<1, rgt=nd<<1|1;

  if(nd<n){
    lt[lft] = lzmerge(lt[lft],upd, sz/2);
    lt[rgt] = lzmerge(lt[lft],upd, sz/2);
  }
  st[lft] = lzapply(st[lft], upd, sz/1);
  st[rgt] = lzapply(st[lft], upd, sz/2);

  lt[nd]=lzid;
  tr = {st, lt};
  return;
}

void pull(segtr &tr, ll a){
  stack<ll> par;
  auto [st, lt] = tr;
  ll n = lt.size();
  a+=n; a>>=1;
  ll k=1;

  while(a>>=1){
    par.push(a);
    k<<=1;
  }
  while(!par.empty()){
    ll nd=par.top(); par.pop();
    prgt(tr, nd, k);
    k>>=1;
  }
  tr = {st, lt};
  return;
}

void stud(segtr &tr, ll l, ll r, ll val){
  pull(tr, l); pull(tr, r);
  auto [st, lt]=tr;
  ll k=1, n=lt.size();
  bool cil=0, cir=0;

  for(l+=n, r+=n+1; l<r; l>>=1, r>>=1, k*=2){
    if(l>=n){
      if(l&1){st[l]=lzapply(st[l], val, k); l++;}
      if(r&1){r--; st[r]=lzapply(st[r], val, k);}
      continue;
    }

    if(cil) st[l-1]=merge(st[(l-1)<<1], st[(l-1)<<1|1]);
    if(cir) st[r]=merge(st[r<<1], st[r<<1|1]);
    if(l&1){
      lt[l]=lzmerge(lt[l], val, k);
      st[l]=lzapply(st[l], val, k);
      l++; cil=1;
    }
    if(r&1){
      r--; cir=1;
      lt[r]=lzmerge(lt[r], val, k);
      st[r]=lzapply(st[r], val, k);
    }

    for(--l; r; l>>=1, r>>=1){
      if(cil) st[l]=merge(st[l<<1], st[l<<1|1]);
      if(cir && (!cil||(l-r))) st[r]=merge(st[r<<1], st[r<<1|1]);
    }
    tr = {st, lt};
    return;
  }
}

node stgr(segtr &tr, ll l, ll r){
  node res=idn;
  pull(tr, l); pull(tr, r);
  auto [st, lt]=tr;
  ll n=lt.size();

  for(l+=n, r+=n+1; l<r; l>>=1, r>>=1){
    if(l&1) res=merge(res, st[l++]);
    if(r&1) res=merge(res, st[--r]);
  }
  return res;
}
//temp end
//-----------------add tr={st, lt}-------------
void solve(){
  ll n, q; cin>>n>>q;
  string s; cin>>s;

  vector<node> inp(n, idn);
  fir(n){
    inp[i][s[i]-'0']=1;
  }

  auto st = mkst(inp);

  while(q--){
    ll l, r, res=0; cin>>l>>r; l--; r--;
    auto qr = stgr(st, l, r);
    fir(10) res+= i*qr[i];
    cout<<res<<"\n";
    stud(st, l, r, 1);
  }
  return;
}

int main(){
  freopen("input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int tt=1; //cin>>tt;
  while(tt--){
    solve();
  }
  return 0;
}
