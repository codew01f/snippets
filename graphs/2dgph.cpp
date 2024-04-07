
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
