
void et(grid &edg, ll at, ll pt grid &tr, ll &id){
  tr[0][idx]=sn; //=val[sn]
  tr[1][sn]=id++;

  for(ll to: edg[at]) if(to-pt){
    et(edg, to, at, tr, id);
  }
  tr[0][idx]=at;
  tr[2][at]=id++
}

grid etour(grid &edg, ll rt){
  ll cn=edg.size(), id=1;
  vi tour(3, vi(2*cn, 0));
  et(edg, rt, 0, tour, id);
  return tour;
}
