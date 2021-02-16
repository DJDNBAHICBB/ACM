
//多模式串匹配

#include <queue>
#include <cstdlib>
#include <cmath>
#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn =  500000+9;
int trie[maxn][26]; //字典树
int cntword[maxn];  //记录该单词出现次数
int fail[maxn];     //失败时的回溯指针
int cnt = 0;
void insertWords(string s){
    int root = 0;
    for(int i=0;i<s.size();i++){
        int next = s[i] - 'a';
        if(!trie[root][next])
            trie[root][next] = ++cnt;
        root = trie[root][next];
    }
    cntword[root]++;
}
void getFail(){
    queue <int>q;
    for(int i=0;i<26;i++){      //将第二层所有出现了的字母扔进队列
        if(trie[0][i]){
            fail[trie[0][i]] = 0;
            q.push(trie[0][i]);
        }
    }
    while(!q.empty()){
        int now = q.front();
        q.pop();
        for(int i=0;i<26;i++){
            if(trie[now][i]){
                fail[trie[now][i]] = trie[fail[now]][i];
                q.push(trie[now][i]);
            }
            else trie[now][i] = trie[fail[now]][i];
        }
    }
}

int query(string s){
    int now = 0,ans = 0;
    for(int i=0;i<s.size();i++){
        now = trie[now][s[i]-'a'];
        for(int j=now;j && cntword[j]!=-1;j=fail[j]){
            ans += cntword[j];
            cntword[j] = -1;
        }
    }
    return ans;
}
void init()
{
    for(int i = 0 ; i<= cnt ; i++)
    {
        memset(trie[i], 0, sizeof(trie[i]));
    }
    memset(cntword,0,sizeof(cntword));
    cnt = 0;
}