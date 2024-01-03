
grid mkuf(ll n){
  grid uf(2, vi(n+1, 1));
  fir(n+1) uf[0][i]=i;
  return uf;
}

ll ufgp(grid &uf, ll n){
  ll pr=n;
  while(pr-uf[0][pr]){
    pr=uf[0][pr];
  }
  while(n-pr){
    ll nx=uf[0][n];
    uf[0][n]=pr;
    n=nx;
  }
  return pr;
}

void ufnu(grid &uf, ll a, ll b){
    uf[1][ufgp(uf, a)]+=uf[1][ufgp(uf, b)];
    uf[0][ufgp(uf, b)]=ufgp(uf, a);
    return;
}
