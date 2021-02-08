#include <bits/stdc++.h>

using namespace std;
const int maxn = 100000;
int trie[maxn*2+10][200];
int tot;
bool node[maxn*2+10];
set<int> st;


void insert_(string str)
{
    int root=0;
    for(int i=0;i<str.length();i++)
    {
        int id=str[i];
        if(!trie[root][id]) trie[root][id]=++tot;
        if (str[i] == '/') st.insert(tot);
        root=trie[root][id];
    }
    node[root]=true;
}


signed main()
{
    int n;
    cin >> n;
    while (n--)
    {
        string s;
        cin >> s;
        string ss = s.substr(1)+'/';
        insert_(ss);
        cout << st.size() << endl;
    }
}