 
#include <bits/stdc++.h>
using namespace std;
 
#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl n
 
template<typename node, typename change>
class SegmentTree
{
public:
    int n;
 
    node *tree, identity;
    node (*merge)(node, node);
 
    change *lazy, noChange;
    void (*applyUpdate)(int, int, node&, change);
    void (*mergeUpdate)(int, int, change&, change);
 
    void build(vector<node> &input, int lo, int hi, int root=0)
    {
        if(lo==hi)
        {
            tree[root]=input[lo];
            return;
        }
 
        int mid=lo+hi>>1, leftChild=2*root+1, rightChild=2*root+2;
        build(input, lo, mid, leftChild);
        build(input, mid+1, hi, rightChild);
 
        tree[root]=merge(tree[leftChild], tree[rightChild]);
    }
 
    void propagate(int lo, int hi, int root)
    {
        applyUpdate(lo, hi, tree[root], lazy[root]);
 
        if(lo<hi)
        {
            int mid=lo+hi>>1, leftChild=2*root+1, rightChild=2*root+2;
 
            mergeUpdate(lo, mid, lazy[leftChild], lazy[root]);
            mergeUpdate(mid+1, hi, lazy[rightChild], lazy[root]);
        }
 
        lazy[root]=noChange;
    }
 
    void update(int from, int to, int lo, int hi, int root, change delta)
    {
        if(lo>hi) return;
        
        propagate(lo, hi, root);
        if(from>hi || to<lo) return;
 
        if(from<=lo && to>=hi)
        {
            mergeUpdate(lo, hi, lazy[root], delta);
            propagate(lo, hi, root);
            return;
        }
 
        int mid=lo+hi>>1, leftChild=2*root+1, rightChild=2*root+2;
        update(from, to, lo, mid, leftChild, delta);
        update(from, to, mid+1, hi, rightChild, delta);
 
        tree[root]=merge(tree[leftChild], tree[rightChild]);
    }
 
    node query(int from, int to, int lo, int hi, int root)
    {
        if(lo>hi) return identity;
        
        propagate(lo, hi, root);
        if(from>hi || to<lo) return identity;
 
        if(from<=lo && to>=hi) return tree[root];
        
        int mid=lo+hi>>1, leftChild=2*root+1, rightChild=2*root+2;
        node q1=query(from, to, lo, mid, leftChild), q2=query(from, to, mid+1, hi, rightChild);
        return merge(q1, q2);
    }
 
public:
    SegmentTree(SegmentTree& st):
        tree(st.tree), lazy(st.lazy), n(st.n),
        merge(st.merge), identity(st.identity),
        applyUpdate(st.applyUpdate), mergeUpdate(st.mergeUpdate), noChange(st.noChange)
    {}
 
    SegmentTree(
        vector<node> &input,
        node (*merge)(node, node),
        node identity,
        void (*applyUpdate)(int, int, node&, change),
        void (*mergeUpdate)(int, int, change&, change),
        change noChange
        ):
        n(input.size()),
        merge(merge), identity(identity),
        applyUpdate(applyUpdate), mergeUpdate(mergeUpdate), noChange(noChange)
    {
        tree=new node[n<<2];
        build(input, 0, n-1);
 
        lazy=new change[n<<2];
        fill(lazy, lazy+(n<<2), noChange);
    }
 
    node query(int from, int to)
    {
        if(from>to || to>n) return identity;
        return query(from, to, 0, n-1, 0);
    }
 
    void update(int from, int to, change delta)
    {
        update(from, to, 0, n-1, 0, delta);
    }
 
    ~SegmentTree()
    {
        delete[] tree;
        delete[] lazy;
    }
};
 
void pre()
{
  freopen("input.txt", "r", stdin);
    fastio;
 
    
}
 
int minVal(int a, int b)
{
    return (a+b)%998244353;
}
 
void applyReplace(int lo, int hi, int& val, pair<bool,pair<int, int>> delta)
{
    auto [flag, newVal]=delta;
    if(flag==true) val= (val*newVal.first)+newVal.second;
}
 
void mergeReplace(int lo, int hi, pair<bool,pair<int, int>>& delta1, pair<bool,pair<int, int>> delta2)
{
    auto [flag, d2]=delta2;
    auto [a, b]= delta1.second; auto [aa, bb]=d2;
    if(flag==true) delta1={1, {a*aa, bb+(aa*b)}};
}
 
void solve(int tc)
{
    int i, n, q, k, u, l, r, t;
    cin >> n >> q;
 
    vector<int> v(n);
    for(auto &it: v) cin >> it;
 
    pair<bool,pair<int, int>> noChange={0, {1,0}}, delta;
    SegmentTree<int,pair<bool,pair<int, int>>> st(v, minVal, 0, applyReplace, mergeReplace, noChange);
 
    while(q--)
    {
        cin >> t;
 
        if(t==0)
        {
            cin >> k >> u>>r>>t;
 
            delta={1, {r, t}}; // flag=true, value = u
            st.update(k, u-1, delta); // from=k, to=k, delta=delta
        }
 
        if(t==1)
        {
            cin >> l >> r;
            cout << st.query(l, r-1) << "\n";
        }
    }
}
 
signed main()
{
    pre();
 
    int tc, tt=1;
    // cin >> tt;
    
    for(tc=1; tc<=tt; tc++)
    {
        solve(tc);
        // cout << endl;
    }
 
    return 0;
}
