//support 2 operations efficiently
//1. sum of certain range
//2. increment all element in range

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



ll n=8, h=log2(n);
vi v={2, -1, -3, 9, 0, -4, 8, 1};
vi st(n<<1, 0);
vi lt(n, 0);
ll idn=0;

void show(){ cout<<"               "<<st[1]<<"_"<<lt[1]<<"       \n";  cout<<"        "<<st[2]<<"_"<<lt[2]<<"              "<<st[3]<<"_"<<lt[3]<<"   \n"; cout<<"    "<<st[4]<<"_"<<lt[4]<<"     "<<st[5]<<"_"<<lt[5]<<"     "<<st[6]<<"_"<<lt[6]<<"     "<<st[7]<<"_"<<lt[7]<<" \n"; cout<<"  "<<st[8]<<"   "<<st[9]<<"    "<<st[10]<<"   "<<st[11]<<"   "<<st[12] <<"   "<<st[13]<<"    "<<st[14]<<"   "<<st[15]<<" ";cout<<endl;}

ll fun(ll a, ll b){return a+b;} //the function we'll query;

void mkst(){ //building segtree, obvious;
  fir(n) st[i+n]=v[i];
  for(int i=n-1; i; --i){
    st[i]=fun(st[i<<1], st[i<<1|1]);
  }
  return;
} 

void prgt(ll nd, ll k){
  //left child
  ll lc= nd<<1;
  if(nd<n) lt[lc]+=lt[nd];
  st[lc]+=lt[nd]*(k/2);
  //right child
  ll rc= nd<<1|1;
  if(nd<n) lt[rc]+=lt[nd];
  st[rc]+=lt[nd]*(k/2);

  lt[nd]=0;
  return;
}

void pull(ll a){ //will sync a node with all updates
  stack<ll> par;
  a+=n;
  a>>=1;
  ll k=1; // # of leaves under 
  while(a){ //puts all ancestors in stack;
    par.push(a);
    a>>=1;
    k<<=1;
  }
  while(!par.empty()){
    ll nd=par.top(); par.pop();
    prgt(nd, k);
    k>>=1;
  }
  return;
}

void updt(ll l, ll r, ll val){
  pull(l); pull(r);
  //we update lt[l] only if its the right 
  //child of the parent. else we update
  //lt[parent]; same for r.
  ll k=1; //careful, r is shifted +1 making range [l, r);
  bool cil=0, cir=0;
  for(l+=n, r+=n+1; l<r; l>>=1, r>>=1, k*=2){
    if(l>=n){ //leaf node case;
      if(l&1) {st[l++]+=val; cil=1;}
      if(r&1) {st[--r]+=val; cir=1;}
      continue;
    }
    if(cil) st[l-1]=fun(st[(l-1)<<1], st[(l-1)<<1|1]);
    if(l&1){
      lt[l]+=val;
      st[l]+=val*k;
      l++; cil=1;
    }
    if(cir) st[r]=fun(st[r<<1], st[r<<1|1]);
    if(r&1){
      r--; cir=1;
      lt[r]+=val;
      st[r]+=val*k;
    }
  }
  for(--l; r; l>>=1, r>>=1){ //jst syncs ancestors with change;
    if(cil) st[l]=fun(st[l<<1], st[l<<1|1]);
    if(cir && (!cil||l-r)) st[r]=fun(st[r<<1], st[r<<1|1]);
  } 
  return;
}

void stgr(ll l, ll r){
  ll res = idn;
  pull(l);
  pull(r);

  for(l+=n, r+=n+1; l<r; l>>=1, r>>=1){
    if(l&1) res=fun(res, st[l++]);
    if(r&1) res=fun(res, st[--r]);
  }
  cout<<"sum is "<<res<<endl;
  return;
}

void solve(){
  mkst();
  stgr(1, 7);
  updt(0, 7, 2);
  show();
  stgr(1, 6);
  show();
  updt(2, 5, 5);
  show();
  stgr(3, 4);
  stgr(1, 6);
  return;
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int tt=1; //cin>>tt;
  while(tt--){
    solve();
  }
  return 0;
}
