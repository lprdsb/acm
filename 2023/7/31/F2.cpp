#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n , q;
struct seg {
    seg* ch[2];
    int sum , l , r , tsum;
    seg() {
        ch[0] = ch[1] = nullptr;
        sum = tsum = 0;
    }
};
void ins(seg*u,int l,int r,int v,int s)
{
    u->sum += s; u->l = l , u->r = r;
    u->tsum++;
    if(l == r) return;
    int md = (l + r >> 1);
    if(v <= md) r = md;
    else l = md + 1;
    if(!u->ch[v > md]) u->ch[v > md] = new seg;
    ins(u->ch[v > md] , l , r , v , s);
    return;
}
struct fenwick {
    int c[100005];
    void add(int u,int v) {
        while(u <= n) {
            c[u] += v;
            u += (u & (-u));
        }
    }
    int query(int u) {
        int ans = 0;
        while(u) {
            ans += c[u] ; u -= (u&(-u));
        }
        return ans;
    }
    void reset() {
        memset(c,0,sizeof(c));
    }
}F;
struct odt {
    int l , r;
    int tag = 0; ///0升序 1降序
    seg* rt;
};
bool operator < (odt a,odt b)
{
    return a.l < b.l;
}
int lv[100005] , a[100005];
set<odt> st;
void rec(seg* u)
{
    u->sum = 0;
    u->tsum = 0;
    if(u->ch[0]) {u->sum += u->ch[0]->sum;u->tsum += u->ch[0]->tsum;}
    if(u->ch[1]) {u->sum += u->ch[1]->sum;u->tsum += u->ch[1]->tsum;}
    return;
}
int ttag ;
void split(seg* u,seg* &l,seg* &r,int k)
{
   // printf("split okay %d %d , %d , %d\n",u->l,u->r , k , u->sum);
    assert(u != nullptr);
    l = new seg ; r = new seg;
    l->l = r->l = u->l;
    l->r = r->r = u->r;
    if(u->l == u->r) {
        l->sum = r->sum = 0;
        if(u->sum) {
            if(ttag && k != u->tsum) r->sum = 1;
            else l->sum = 1;
        }
        l->tsum = k ; r->tsum = u->tsum - k;
        return;
    }
  //  printf("ok \n");
    if(!(u->ch[0]) || u->ch[0]->tsum < k) {
        l->ch[0] = u->ch[0];
        r->ch[0] = nullptr;
  //  printf("ok1 \n");
   // printf("U %d\n",k - (((u->ch[0]) ? u->ch[0]->tsum : 0)));
        split(u->ch[1] , l->ch[1] , r->ch[1] , k - (((u->ch[0]) ? u->ch[0]->tsum : 0)));
    }
    else {
   // printf("ok2 \n");
        l->ch[1] = nullptr;
        r->ch[1] = u->ch[1];
        split(u->ch[0] , l->ch[0] , r->ch[0] , k);
    }
    rec(l) ; rec(r);
   // printf("spl %d %d %d\n",r->l,r->r,r->sum);
}
set<odt>::iterator make_split(int pos) ///分成 >= pos和 < pos的部分
{
    auto it = st.upper_bound((odt){pos , pos ,0, nullptr}) ; it--;
    //printf("Split on %d %d %d\n",it->l , it->r , pos) ;
    if(it->r + 1 == pos) {
        assert(pos == n + 1) ; return it;
    }
    if(it->l == pos) {
        return it;
    }
    int k ;
    if(it->tag == 0) k = pos - it->l;
    else k = it->r - pos + 1;
    F.add(it->r , -(it->rt->sum));
    odt x , y;
    x.l = it->l , x.r = pos - 1; x.tag = it->tag;
    y.l = pos ; y.r = it->r; y.tag = it->tag;
    ttag = it->tag;
    if(it->tag == 0) split(it->rt , x.rt , y.rt , k);
    else split(it->rt , y.rt , x.rt , k);
    F.add(x.r , x.rt->sum);
    F.add(y.r , y.rt->sum);
  //  printf("ttag %d\n",ttag);
   // printf("new ins %d %d %d , %d %d %d\n",x.l,x.r,x.rt->tsum , y.l,y.r , y.rt->tsum);
    st.erase(it) ;st.insert(x);
    return st.insert(y).first;
}
void Merge(seg *u1,seg* u2,seg* &u)
{
    if(!u1) {u = u2 ; return;}
    if(!u2) {u = u1 ; return;}
    u = new seg; u->l = u1->l ; u->r = u1->r ;u->sum = u1->sum + u2->sum;
    u->tsum = u1->tsum + u2->tsum;
    Merge(u1->ch[0] , u2->ch[0] , u->ch[0]);
    Merge(u1->ch[1] , u2->ch[1] , u->ch[1]);
    return;
}
set<odt>::iterator make_merge(set<odt>::iterator it,int tag)
{
    auto it2 = it;it2++;
    F.add(it->r , -(it->rt->sum));
    F.add(it2->r , -(it2->rt->sum));
    odt x ; x.l = it->l;x.r = it2->r ; x.tag = tag;
    Merge(it->rt , it2->rt , x.rt);
    st.erase(it) ; st.erase(it2);
    //printf("ins %d %d\n",x.l,x.r);
    F.add(x.r , x.rt->sum);
    return st.insert(x).first;
}
int main()
{
//    freopen("in.txt","r",stdin);
    // freopen("out1.txt", "w", stdout);
   // freopen("out2.txt","w",stdout);
    ios::sync_with_stdio(false) ; cin.tie(0) ; cout.tie(0);
    cin >> n >> q;
    for(int i = 1;i <= n;i++) cin >> a[i];
    for(int i = 1;i <= n;i++) {
        odt u ; u.l = u.r = i;
        u.rt = new seg;
        if(!lv[a[i]] ) {
            ins(u.rt , 1 , n , a[i] , 1);
            lv[a[i]] = 1;
            F.add(i , 1);
        }
        else ins(u.rt , 1 , n , a[i] , 0);
        st.insert(u);
    }
    int lans = 0;
    for(int i = 1; i <= q; ++i){
       // lans = 0;
        int l , r , x;cin >> l >> r >> x;
        int tag = 0;
        // l ^= lans , r ^= lans , x ^= lans;
        if(r < l) {
            swap(l , r) ; tag = 1;
        }
        //printf("Query %d %d %d , %d\n",l,r,x,tag) ;
        //if(q == 4) exit(0);
        auto it = make_split(l);
        //printf("fir %d %d\n",it->l,it->r);
        if((it->r >= r) && r != n) {
            it = make_split(r + 1);it--;
        }
        else make_split(r + 1);
        if(it->r == r) {
            auto u = (*it);st.erase(it);
            u.tag = tag;
            st.insert(u);
        }
        else{
            while(it->r != r) {
               // printf("bef %d %d\n",it->r , r);
                it = make_merge(it , tag);
            }
        }
        // if(i == 11){
            // printf("Traverse before:\n");
            // cout << l << " " << r << endl;
            // for(auto &s : st) {
            //     printf("%d %d , %d\n",s.l,s.r,s.rt->sum);
            // }
        // }
        make_split(x + 1);
        cout << (lans = F.query(x)) << '\n';
        /*printf("Traverse :\n");
        for(auto &s : st) {
            printf("%d %d , %d\n",s.l,s.r,s.rt->sum);
        }*/
    }
    return 0;
}
