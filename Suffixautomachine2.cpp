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
int last = 1;
int tot = 1;
int p;

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

int solve() {
    int len1 = strlen(s1 + 1);
    int ans =0 ; int tmp = 0;
    for (int i = 1; i <= len1; ++i) {

        int c = s1[i] - 'a';
        if (ch[p][c]) p = ch[p][c], tmp++;
        else {
            while (p && !(ch[p][c]))
                p = fa[p];
            if (!p) p = 1, tmp = 0;
            else {
                tmp = len[p] + 1;
                p = ch[p][c];
            }
        }
        ans = max(ans,tmp);
    }
    return ans;
}


int main() {
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
    scanf("%s", s + 1);
    int len = strlen(s + 1);
    for (int i = 1; i <= len; ++i) {
        add(s[i] - 'a');
    }
    scanf("%s", s1 + 1);
    cout << solve();
}