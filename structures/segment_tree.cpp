
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
using pii = pair<ll, ll>;

#define gd(r, c, i) gd(r, vi(c, i))
#define fix(p) cout<<setprecision(p)<<fixed

#define mid(l, r) (l&r)+((l^r)>>1)
#define fir(a) for(int i=0; i<a; ++i)
#define fjr(a) for(int j=0; j<a; ++j)

template<typename node, typename change>
class sgtr{
public: 
  int n;

  node *tree, idnt;
  node (*merge)(node, node);
  change *lazy, nochange;
  
  void (*applyud)(ll, ll, node&, change);
  void (*mergeud)(ll, ll, change&, change);

  void build(vector<node> &inp, ll lo, ll hi, ll root=0){
    if(lo==hi){
      tree[root]=inp[lo];
      return;
    }
    ll md=mid(lo, hi), lc=2*root+1, rc=2*root+2;
    build(inp, lo, md, lc);
    build(inp, md+1, hi, rc);
 
    tree[root]=merge(tree[lc], tree[rc]);
    return;
  }
  void prgt(ll lo, ll hi, ll root){
    applyud(lo, hi, tree[root], lazy[root]);
    if(lo<hi){
      ll md=mid(lo, hi), lc=2*root+1, rc=2*root+2;
      mergeud(lo, md, lazy[lc], lazy[root]);
      mergeud(md+1, hi, lazy[rc], lazy[root]);
    }
    lazy[root]=nochange;
    return;
  }
  void updt(ll fr, ll to, ll lo, ll hi, ll root, change del){
    if(lo>hi) return;
    prgt(lo, hi, root);
    if(fr>hi || to<lo) return;
    if(fr<=lo && to>=hi){
      mergeud(lo, hi, lazy[root], del);
      prgt(lo, hi, root);
      return;
    }
    ll md=mid(lo, hi), lc=2*root+1, rc=2*root+2;
    updt(fr, to, lo, md, lc, del);
    updt(fr, to, md+1, hi, rc, del);

    tree[root]=merge(tree[lc], tree[rc]);
    return;
  }
  node query(ll fr, ll to, ll lo, ll hi, ll root){
    if(lo>hi) return idnt;
    prgt(lo, hi, root);
    if(fr>hi || to<lo) return idnt;
    if(fr<=lo && to>=hi) return tree[root];

    ll md=mid(lo, hi), lc=2*root+1, rc=2*root+2;
    node q1=query(fr, to, lo, md, lc);
    node q2=query(fr, to, md+1, hi, rc);
    
    return merge(q1, q2);
  }

public:
  sgtr(sgtr &st):
    tree(st.tree), lazy(st.lazy), n(st.n),
    merge(st.merge), idnt(st.idnt),
    applyud(st.applyud), mergeud(st.mergeud),
    nochange(st.nochange){}

  sgtr(
    vector<node> &inp,
    node (*merge)(node, node),
    node idnt,
    void (*applyud)(ll, ll, node&, change),
    void (*mergeud)(ll, ll, change&, change),
    change nochange):
    n(inp.size()),
    merge(merge), idnt(idnt),
    applyud(applyud), mergeud(mergeud),
    nochange(nochange){
    tree=new node[n<<2];
    build(inp, 0, n-1);
    lazy=new change[n<<2];
    fill(lazy, lazy+(n<<2), nochange);
  }
  node query(ll fr, ll to){
    if(fr>to || to>n) return idnt;
    return query(fr, to, 0, n-1, 0);
  }
  void updt(ll fr, ll to, change del){
    updt(fr, to, 0, n-1, 0, del);
  }
  ~sgtr(){
    delete[] tree;
    delete[] lazy;
  }
};

//----------------------------------------
using nd=ll;
using dl=pii;

nd merg(nd a, nd b){
  nd res= ;
  return res;
}
void aplz(ll lo, ll hi, nd &val, dl del0){

  return;
}
void mrlz(ll lo, ll hi, dl &del1, dl del2){

  return;
}

void solve(){
  ll n, q, qq, a, b, c;
  cin>>n>>q;
  vector<nd> v(n);
  for(auto &i: v) cin>>i;

  nd idn = 0;
  dl lzid={1, 0};
  sgtr<nd, dl> st(v, merg, idn, aplz, mrlz, lzid);

  while(q--){
    cin>>qq>>a>>b;
    a--; b--;
    if(qq == 1){
      
    }
    if(qq == 2){
      
    }
    if(qq==3){}
  }
  return;
}

int main(){
  //freopen("input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int tt=1; //cin>>tt;
  while(tt--){
    solve();
  }
  return 0;
}
