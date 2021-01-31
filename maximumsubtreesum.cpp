#include "bits/stdc++.h"
using namespace std;
#define MAXN 160100
int beaut[MAXN];
int b[MAXN];
vector<int> son[MAXN];

void dp(int x)
{
    beaut[x]=b[x];
    for (int i = 0; i <son[x].size() ;i++) {
        int y = son[x][i];
        dp(y);
        beaut[x]=max(beaut[x],beaut[x]+beaut[y]);
    }
}
int main()
{



    int N;
    cin >> N ;
    for(int i=1;i<=N;i++)
    {
        cin >> b[i];
    }
    int v[16001]={0};
    for(int i=1;i<N;i++)
    {
        int x,y;
        cin >> x >> y ;
        son[y].push_back(x);
        v[x]=1;
    }
    int k;
    for(int i=1;i<=N;i++)
    {
        if(!v[i]) {
          k=i;
          break;
        }
    }
    dp(k);
    cout << beaut[k];
}