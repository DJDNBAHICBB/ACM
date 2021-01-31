//
// Created by SANZONG on 2020/8/7.
//

#include "bits/stdc++.h"
using namespace std;
#define MAXN 800005
int a[MAXN];
int st[MAXN];
int sst[MAXN];
inline int ls(int root) {return root<<1;}
inline int rs(int root) {return root<<1|1;}
inline int push_up_max(int root){
    st[root] = max(st[ls(root)],st[rs(root)]);
}
inline int push_up_min(int root){
    sst[root] = min(sst[ls(root)],sst[rs(root)]);
}
void build(int root,int l ,int r)
{
    if(l == r) {
        st[root] = a[l];
        sst[root] = a[l];
        return;
    }
    int mid = (l + r)>>1;
    build(ls(root),l,mid);
    build(rs(root),mid+1,r);
    push_up_max(root);
    push_up_min(root);
}


void update(int root, int l ,int r ,int nl,int k)      //要使得给定的区间包围原区间
{
    if(l == r)
    {
        st[root] = k;
        sst[root] = k;
        return;
    }
    int mid = (l+r)>>1;
    if(nl<= mid)
        update(ls(root), l, mid,nl,k);
    else
        update(rs(root), mid+1, r,nl,k);
    push_up_max(root);
    push_up_min(root);
}

int query1(int root, int l,int r,int nl,int nr)
{

    if(nl <= l && r <= nr)  return st[root];
    int res =-10000 ;
    int mid = (l+r)>>1;
    if(nl <= mid) res=max(res,query1(ls(root),l,mid,nl,nr));
    if(nr > mid) res= max(res,query1(rs(root),mid+1,r,nl,nr));
    return res;
}
int query2(int root, int l,int r,int nl,int nr)
{
    if(nl <= l && r <= nr)  return sst[root];
    int res =1000000010 ;
    int mid = (l+r)>>1;
    if(nl <= mid) res=min(res,query2(ls(root),l,mid,nl,nr));
    if(nr > mid) res= min(res,query2(rs(root),mid+1,r,nl,nr));
    return res;
}
int quest(int n,int l,int r)
{
    if(query1(1,1,n,l,r) - query2(1,1,n,l,r) == r - l)
        return 1;
    else
        return 0;
}
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m;
    cin >> n ;cin >> m;
    for(int i = 1;i <= n ;i++)
    {
        cin >> a[i];
        sst[i] = 1000000100;
    }

    build(1,1,n);
    for(int i =1;i <= m ;i++)
    {
        int f ;
        cin >> f;
        switch (f) {
            case 1:
                int x,y ;
                cin >> x >> y ;
                update(1,1,n,x,y);
                break;
            case 2:
                int u , v;
                cin >> u >> v;
                if(quest(n,u,v) == 1)
                    cout << "YES" << endl;
                else
                    cout << "NO" << endl;
                break;
        }
    }
}