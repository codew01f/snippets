
//solves ax+by=gcd(a, b) for (x, y)
pii eea(ll a, ll b){
  ll x=1, y=0;
  ll x1=0, y1=1, a1=a, b1=b, q=0;
  while(b1){
    q=a1/b1;
    tie(x, x1) = make_tuple(x1, x-q*x1);
    tie(y, y1) = make_tuple(y1, y-q*y1);
    tie(a1, b1) = make_tuple(b1, a1-q*b1);
  }
  return {x, y};
}
