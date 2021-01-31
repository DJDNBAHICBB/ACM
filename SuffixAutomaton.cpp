//
// Created by SANZONG on 2020/11/28.
//
//http://www.360doc.com/content/19/0331/17/5315_825519595.shtml
//坚持一下！-！学完它
//在线加点
#include "bits/stdc++.h"
#define mem(x,i) memset(x,i,sizeof(x))
using namespace std;
const int MAXN = 100001;

struct node{
    int ch[26];             //像trie树里的那个
    //ch，也就是trans，表示当前状态能够通过添加字符达到的其他状态，通俗的讲就是当前有一个字符串集合，我们
    // 给某些字符串末尾加一些字符，这样这些字符串就变成了另一个状态。
    int len;        //长度
    int fa;         //父节点
    node() {mem(ch,0);len = 0;}
}point[MAXN<<1];                  //point 是自动姬的节点
//样例abcab
int last = 1;int tot = 1;
void add(int c)
{
    int p = last;            //未加入c时的尾节点
    last = ++tot;
    int np = last;             //当前的自动机节点总数
    point[np].len = point[p].len + 1;
    for (; p && !point[p].ch[c]; p = point[p].fa) point[p].ch[c] = np;
    //遍历旧串的所有后缀，看看加c后endpos有无变化（即是否变长）
    //终止条件解释，{abca,bca,ca,a}加b之后{abcab,bcab,cab,ab},ab显然在abcab中出现过了，故可以退出
    if (!p) point[np].fa = 1; //case 1 说明c是一个没有出现过的字符，其父必为1
    else       //在第一个出现过c边的祖先停止
    {
        int q = point[p].ch[c];     //将q定义为p经过c边后的点
        if (point[q].len == point[p].len + 1) point[np].fa = q;  //case 2，刚好长度相差1说明没必要连了,因为已经存在后缀和长度相等的字串，例如aa，aaa。
        else{                                 //case 3 如果在c边停了，而且len(q) > len(p)+1，aababa
            //即p存在一个跳边为c，因为跳边的出现，会导致同是连c边的几个后缀的长度（endpos）不同,于是我们要拆跳边
            int nq = ++tot;
            point[nq]= point[q];   //拥有了q的所有后缀，包括p，且正好比p多1，且nq也是p经过c边后的状态
            point[nq].len = point[p].len + 1;
            point[q].fa = point[np].fa = nq;   //把q和np连回来，跟case 2一样
            for (;p && point[p].ch[c] == q;p = point[p].fa) {   //构造nq的自动机,把原来连在q上的线转接到nq上
                point[p].ch[c] = nq;
            }
        }
        last = np;
    }
}
char s[MAXN];
int len;
int main()
{
    scanf("%s",s);
    len = strlen(s);
    for (int i = 0; i < len; ++i) {
        add(s[i]-'a');
    }
}
