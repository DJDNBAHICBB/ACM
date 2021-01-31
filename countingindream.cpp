#include "bits/stdc++.h"
using namespace std;
int base[10];
int main()
{
    int l,r ;
    cin >> l >> r;
    for(int i = l ;i <= r; i++)
    {
        int t = i;
        while(t>0)
        {
            base[t%10]++;
            t/=10;
        }
    }
    for(int i = 0; i < 10; i++)
    {
        cout << base[i] << ' ';
    }
}