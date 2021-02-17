//
// Created by acer on 2021/2/16.
//
//判断子串，不同子串个数，所有子串字典序第i大，最长公共子串

#include <cstring>
#include <iostream>
#include "string"


#define mem(x, i) memset(x,i,sizeof(x))
using namespace std;
const int MAXN = 1e5 + 10;
int mxlen[MAXN<<1];
int anslen[MAXN<<1];
int len[MAXN << 1];
int ch[MAXN << 1][27];
int fa[MAXN << 1];
int id[MAXN << 1];
int last = 1;
int tot = 1;

int p;
int visit[MAXN<<1];
void add(int c) {
    p = last;
    last = ++tot;
    int np = last;
    len[np] = len[p] + 1;
    for (; p && !(ch[p][c]); p = fa[p]) ch[p][c] = np;
    if (!p) fa[np] = 1;
    else {
        int q = ch[p][c];
        if (len[q] == len[p] + 1) fa[np] = q;
        else {
            int nq = ++tot;
            memcpy(ch[nq],ch[q],sizeof(ch[nq]));
            fa[nq] = fa[q];
            len[nq] = len[p] + 1;
            fa[np] = fa[q] = nq;
            for (; p && ch[p][c] == q; p = fa[p]) {
                ch[p][c] = nq;
            }
        }

    }

}
char s[MAXN], s1[MAXN];
int mx= 0;
void solve() {
    p = 1;
    int len1 = strlen(s1 + 1);
    int tmp = 0;
    for (int i = 1; i <= len1; ++i) {
        int c = s1[i] - 'a';
        if (ch[p][c]) {p = ch[p][c], tmp++;}
        else {
            while (p && !(ch[p][c])) p = fa[p];
            if (!p) p = 1, tmp = 0;
            else {tmp = len[p] + 1;p = ch[p][c];}
        }
        visit[p]++;
        mxlen[p] = max(mxlen[p],tmp);
    }
    for (int j = tot; j >= 1; --j) {
        int k = id[j];
        anslen[k] = min(anslen[k],mxlen[k]);
        if (anslen[k] && fa[k]) mxlen[fa[k]] = max(mxlen[fa[k]],len[fa[k]]);
        mxlen[k] = 0;
    }

}


int main() {
    scanf("%s", s + 1);
    int l = strlen(s + 1);
    for (int i = 1; i <= l; ++i) {
        add(s[i] - 'a');
    }
    for (int k = 1; k <= tot; ++k) {       //给每个点赋权值
        anslen[len[k]] ++;

    }
    for (int m = 1; m <= tot; ++m) {     //获得长度小于等于m的点的总个数，所以必然是不会相同的，故可以用来标记。
        anslen[m] +=anslen[m-1];
    }
    for (int n = 1; n <= tot; ++n) {  //根据点出现顺序获得拓扑序
        id[anslen[len[n]]--] = n;
    }
    int ct =  1;
    while (scanf("%s", s1 + 1)!=EOF)
    {
        ++ct;
        solve();
    }
    for (int j = 1; j <= tot; ++j) {
        mx = max(mx,anslen[j]);
    }
    if (ct == 1) printf("%d",l);
    else printf("%d",mx);
}