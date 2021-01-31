#include "bits/stdc++.h"
using namespace std;
int main()
{
    int N;
    int sum=0;
    string s;
    cin >> N >> s;
    printf("%c*%d^%d",s[0],N,s.length()-1);
    for (int i = 1; i <s.length() ; i++) {
        if (s[i] != '0')
            printf("+%c*%d^%d", s[i], N, s.length() - i - 1);
    }
}