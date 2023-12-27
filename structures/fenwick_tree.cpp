
void ftud(vi &ft, ll i, ll del){
  i++;
  ll n=ft.size();
  for(; i<n; i+= -i&i){
    ft[i]+=del;
  }
  return;
}

vi mkft(vi &a){
  ll n=a.size();
  vi ft(n+1, 0);

  fir(n) ftud(ft, i, a[i]);
  return ft;
}

ll gt(vi &ft, ll i){
  i++;
  ll res=0;

  for(; i; i-= i&-i){
    res+=ft[i];
  }
  return res;
}

ll ftgs(vi &ft, ll l, ll r){
  return gt(ft, r)-gt(ft, l-1);  
}
