#include "bits/stdc++.h"
using namespace std;
int m,n;
int ans;
int wei[100];
bool tf[100];
bool f[20000];
int ret;
void dp();
void dfs(int cur , int now)
{
    if( now > m) return;
    if(cur == n ) {
        if(now == m)
        dp();
        return;
    }
    dfs(cur+1,now);
    tf[cur]=true;
    dfs(cur+1, now+1);
    tf[cur]=false;
}
void dp(){
    memset(f,0,sizeof(f));
    ans=0;
    f[0]=true;
    int tot=0;
    for (int i = 0; i < n; i++) {
        if(!tf[i])
        {
            for (int j = tot ; j >=0 ; j--) {
                if(f[j]&& !f[j+wei[i]])  f[j+wei[i]]=true,ans++;
            }
            tot+=wei[i];
        }

    }
    ret = max(ret , ans);
}
int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> wei[i];
    }
    dfs(0,0);
    cout << ret;
}