
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
///---------dont touch
segtr mkst(vector<node> &v){
  ll n=v.size();
  vector<node> st(n<<1, idn);
  vector<lazy> lt(n, lzid);

  fir(n) st[i+n]=v[i];
  for(int i=n-1; i; --i)
    st[i]=merge(st[i<<1], st[i<<1|1]);

  return {st, lt};
}

void calc(segtr &tr, ll p, ll k){
  auto [st, lt] = tr;
  if(lt[p]==0) st[p]=merge(st[p<<1], st[p<<1|1]);
  else st[p]=lzapply(st[p], lt[p], k);
  tr={st, lt};
}

void apply(segtr &tr, ll p, lazy val, ll k){
  auto [st, lt] = tr;
  //cout<<"p is "<<p<<"\n";
  st[p]=lzapply(st[p], val, k);
  if(p<lt.size()) lt[p]=lzmerge(lt[p], val, k);
  tr={st, lt};
}

void push(segtr &tr, int l, int r) {
  auto [st, lt] = tr; ll n=lt.size();ll h=log2(n)+1;
  ll s = h, k = 1 << (h-1);
  for (l += n, r += n-1; s > 0; --s, k >>= 1)
    for (int i = l >> s; i <= r >> s; ++i) if (lt[i] != 0) {
      apply(tr, i<<1, lt[i], k);
      apply(tr, i<<1|1, lt[i], k);
      lt[i] = lzid;
    }
}
void modify(segtr &tr, int l, int r, lazy value) {
  auto [st, lt] = tr; ll n=lt.size();r++;
  if (value == lzid) return;
  push(tr, l, l+1);
  push(tr, r-1, r);
  bool cl = false, cr = false;
  int k = 1;//r+=n???????????
  for (l += n, r += n; l < r; l >>= 1, r >>= 1, k <<= 1) {
    if (cl) calc(tr, l - 1, k);
    if (cr) calc(tr, r, k);
    if (l&1) apply(tr, l++, value, k), cl = true;
    if (r&1) apply(tr, --r, value, k), cr = true;
  }
  for (--l; r > 0; l >>= 1, r >>= 1, k <<= 1) {
    if (cl) calc(tr, l, k);
    if (cr && (!cl || l != r)) calc(tr, r, k);
  }
}

node query(segtr &tr, int l, int r) {
  auto [st, lt] = tr; ll n=lt.size();
  r++;
  push(tr, l, l + 1);
  push(tr, r - 1, r);
  node res = idn;
  for(l+=n, r+=n; l<r; l>>=1, r>>=1){
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
  /*
  for(vi v:inp){
    for(ll i:v) cout<<i;
    cout<<n;
  }*/

  while(q--){
    ll l, r, res=0; cin>>l>>r; l--; r--;
    auto qr = query(st, l, r);
    fir(10) res+= i*qr[i];
    cout<<res<<"\n";
    modify(st, l, r, 1);
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
