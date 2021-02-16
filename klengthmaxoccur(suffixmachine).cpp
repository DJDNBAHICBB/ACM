//
// Created by acer on 2021/2/16.
//
//判断子串，不同子串个数，所有子串字典序第i大，最长公共子串

#include <cstring>
#include <iostream>
#include "string"


#define mem(x, i) memset(x,i,sizeof(x))
using namespace std;
const int MAXN = 3e5 + 10;

int len[MAXN << 1];
int ch[MAXN << 1][27];
int fa[MAXN << 1];
int weig[MAXN << 1];
int last = 1;
int tot = 1;
int p;
int size[MAXN<<1];
void add(int c) {
    p = last;
    last = ++tot;
    int np = last;
    size[np] = 1;
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
char s[MAXN<<1];
int id[MAXN<<1];
int ans[MAXN<<1];
int main() {
    scanf("%s", s + 1);
    int l = strlen(s+1);
    for (int i = 1; i <= l; ++i) {
        add(s[i]-'a');
    }
    for (int k = 1; k <= tot; ++k) {       //给每个点赋权值
        weig[len[k]] ++;

    }
    for (int m = 1; m <= tot; ++m) {     //获得长度大于等于m的点的总个数，所以必然是不会相同的，故可以用来标记。
        weig[m] += weig[m-1];
    }
    for (int n = 1; n <= tot; ++n) {  //根据点出现顺序获得拓扑序
        id[weig[len[n]]--] = n;
//        cout << weig[len[n]]+1 <<' ' << id[weig[len[n]]+1] << endl;
    }
//    for (int j = 1; j <= tot; ++j) {
//        cout << id[j] << endl;
//    }
    for (int i = tot; i >= 1 ; --i) {
        size[fa[id[i]]] += size[id[i]];
        ans[len[id[i]]] = max(ans[len[id[i]]], size[id[i]]);
    }

    for(int i = tot; i >= 1; --i) ans[i] = max(ans[i], ans[i + 1]);
    for(int i = 1; i <= l; ++i) printf("%d\n", ans[i]);
}