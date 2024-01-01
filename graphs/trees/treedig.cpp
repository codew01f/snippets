
void par(grid &edg, vi &p, ll at, ll pt){
  for(ll to: edg[at]) if(to-pt){
    p[to]=at;
    par(edg, p, to, at);
  }
  return;
}

void dep(grid &edg, vi &d, ll at, ll pt){
  for(ll to: edg[at]) if(to-pt){
    d[to]=d[at]+1;
    dep(edg, d, to, at);
  }
  return;
}

void csn(grid &edg, vi &c, ll at, ll pt){
  ll cnt=1;
  for(ll to: edg[at]) if(to-pt){
    csn(edg, c, to, at);
    cnt+=c[to];
  }
  c[at]=cnt;
  return;
}

vi dig(grid &edg, ll rt){
  ll cn=edg.size(), pt=0;
  vi res(cn, 0);
  par(edg, res, rt, pt);
  return res;
}
