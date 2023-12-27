
grid mkst(vi &v){
  ll n = v.size();
  ll k = log2(n-1);
  grid st(k+1, vi(n, 0));

  fir(n){
    st[0][i] = v[i];
  }
  fir(k){
    fjr(n-(2<<i)+1){
      st[i+1][j] = min(st[i][j], st[i][j+(1<<i)]);
    }
  }
  return st;
}

ll stgm(grid &st, ll l, ll r){ //0 indexed;
  if(l==r) return st[0][l];
  
  ll i = log2(r-l);
  ll mi = min(st[i][l], st[i][r-(1<<i)+1]);
  return mi;
}
