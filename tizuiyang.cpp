//
// Created by SANZONG on 2020/8/13.
//

#include "bits//stdc++.h"
using namespace std;
#define MAXN 200001
#define alpha 0.8         //越接近0.5，拍扁次数越多
struct scapegoat_node{
    int son[2],val,valid,total;
    bool exist;
}e[MAXN];
int memory[MAXN];      //内存池
int cur[MAXN];       //拍扁时的内存
int pool,p;
int root,to_rebuild;
inline bool isbad(int now)           //如果一个节点拥有的节点总数乘以alpha小于左/右子树的节点总数，说明在退化成链，我们就要拍扁他
{
    if((double )e[now].valid*alpha <= (double)max(e[e[now].son[0]].valid , e[e[now].son[1]].valid)) return true;
    return false;
}
void dfs(int now) //中序遍历
{
    if(!now) return;
    dfs(e[now].son[0]);
    if(e[now].exist) cur[++p] = now;   //这时是拍扁的数组
    else memory[++pool] = now;
    dfs(e[now].son[1]);

}
void build(int l,int r, int &now)
{
    int mid = l + r >> 1;
    now =  cur[mid];
    if(l == r)
    {
        e[now].son[0] = e[now].son[1] = 0;
        e[now].valid = e[now].total = 1;
        return;
    }
    if(l < mid) build(l,mid-1,e[now].son[0]);   //mid-1,因为mid已经被赋值
    else e[now].son[0] = 0;
    build(mid+1,r,e[now].son[1]);
    e[now].total = e[e[now].son[0]].total + e[e[now].son[1]].total + 1;
    e[now].valid = e[e[now].son[0]].valid + e[e[now].son[1]].valid + 1;
}
void rebuild(int &now)       //now随着建树变化
{

    p = 0;
    dfs(now);
    if(p) build(1,p,now);
    else
        now = 0;
}


void insert(int &now,int val)
{
    if(!now)   //若找到一个空位
    {
        now = memory[pool--];
        e[now].val = val;
        e[now].exist = e[now].total = e[now].valid = 1;
        e[now].son[0] = e[now].son[1] = 0;
        return;
    }
    //若未找到，更新一些值
    e[now].total++;e[now].valid++;
    if(e[now].val >= val) insert(e[now].son[0],val);
    else insert(e[now].son[1],val);
    if(isbad(now)) rebuild(now);
//    if(!isbad(now))          //判断是否拍
//    {
//        if(to_rebuild)
//        {
//            if(e[now].son[0] == to_rebuild) rebuild(e[now].son[0]);   //回溯过程中判断
//            else rebuild(e[now].son[1]);
//            to_rebuild = 0;
//        }
//
//    }
//    else
//        to_rebuild = now;         //若要拍，就拍父节点，因为会回溯，所以会判断到
}
void del(int &now,int pos)
{
    if(e[now].exist && e[e[now].son[0]].valid + 1 == pos)   //往左子树找，因为本身有序，左子树数量加此节点数量即为位置
    {
        e[now].exist = false;
        e[now].valid--;
        return;
    }
    e[now].valid--;
    if(e[e[now].son[0]].valid+e[now].exist >= pos ) del(e[now].son[0],pos);  //加exist而不是1
    else del(e[now].son[1],pos - (e[e[now].son[0]].valid+e[now].exist) );
}

int find_ranket(int num) //排第num的是多少
{
    int now = root;
    while (now)
    {
        if(e[now].exist && e[e[now].son[0]].valid+ 1 == num) return e[now].val;
        else if(e[e[now].son[0]].valid>= num) now = e[now].son[0];
        else{
            num -= e[e[now].son[0]].valid + e[now].exist;
            now = e[now].son[1];
        }

    }
}

int find_rank(int num)      //num排第几
{
    int ans = 1;     //e[now].val > num时不会+1,所以防止意外退出先+1
    int now = root;
    while (now)
    {
        if(e[now].val >= num) now = e[now].son[0];
        else
        {
            ans += e[e[now].son[0]].valid+e[now].exist;
            now = e[now].son[1];
        }
    }
    return ans;
}

inline void dele(int num)
{
    del(root,find_rank(num));
    if((double)e[root].total*alpha > e[root].valid) rebuild(root);    //如果删了太多
}
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin  >> n;
    for(int i =200000;i >= 1;i--)       //手动先分配好now
    {
        memory[++pool] = i;
    }
    while(n--)
    {
        int t;
        int f ;
        cin >> f;
        switch (f) {
            case 1:cin >> t;
                insert(root,t);
                break;
            case 2:cin >> t;
                dele(t);
                break;
            case 3:cin >> t;
                cout << find_rank(t) << endl;
                break;
            case 4:cin >> t;
                cout << find_ranket(t) << endl;
                break;
            case 5:cin >> t;
                cout << find_ranket(find_rank(t)-1) << endl;
                break;
            case 6:cin >> t;
                cout << find_ranket(find_rank(t+1)) << endl;  //这里想想平衡树的特性，第在t后面的不一定是第t+1个，t前面的一定是t-1个
                break;
        }
    }
}