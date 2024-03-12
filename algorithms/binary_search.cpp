
ll bs(vi &v, ll t){ // lower
  int l=0, r=v.size(); //add check cz ans might be out of bound.

  while(l<r){
    int m = mid(l, r);
    if(v[m]<t) l=m+1; // <= for upper
    else r=m;

    if(l==r) return l;
  }
}

