#include "bits/stdc++.h"
using namespace std;
char c[1000];
int main()
{
    int n;
    cin >> n;
    char a[1001],b[1001];
    cin >> a;
    cin >> b;
    for (int i = 0; i <n ; i++) {
        if(a[i]>=b[i])
            c[i]=b[i];
        else
        {
            cout << -1;
            return 0;
        }
    }
    cout << c;
}