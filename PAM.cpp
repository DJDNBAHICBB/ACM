#include <bits/stdc++.h>
using namespace std;
const int MAXN = 500000 , MAXK = 26;
char str[ MAXN + 5 ];long long weight[MAXN+5];
struct Palindrome_Automaton{
    int Size //总节点
    , Last , Root0 , Root1 , Trans[ MAXN + 5 ][ MAXK + 5 ] , Fail[ MAXN + 5 ];
    long long  Len[ MAXN + 5 ];

    Palindrome_Automaton( ) {
        Root0 = Size ++ , Root1 = Size; Last = Root1;
        Len[ Root0 ] = 0  , Fail[ Root0 ] = Root1;
        Len[ Root1 ] = -1 , Fail[ Root1 ] = Root1;
    }
    void Extend( int ch , int dex ) {
        int u = Last;
        while (str[ dex - Len[ u ] - 1 ] != str[ dex ] ) u = Fail[ u ]; //找到合格的后缀
        if( !Trans[ u ][ ch ] ) {         //无现成的边
            int Newnode = ++ Size , v = Fail[ u ];    //防止取掉整串
            Len[ Newnode ] = Len[ u ] + 2;
            while (str[ dex - Len[ v ] - 1 ] != str[ dex ] ) v = Fail[ v ];    //给他找一个fail指针
            Fail[ Newnode ] = Trans[ v ][ ch ] , Trans[ u ][ ch ] = Newnode;
        }
        Last = Trans[ u ][ ch ];
        weight[Last]++;
    }

    void Build( char *str ) {
        int len = strlen( str );
        for( int i = 0 ; i < len ; i ++ ) {
            Extend( str[ i ] - 'a' + 1 , i );
        }
    }

    void getWeight()
    {
        long long  ma =0 ;
        for (int k = Size; k >= 0; --k) {
            weight[Fail[k]] += weight[k];
        }
        for (int j = 0; j <= Size; ++j) {
            ma = max(ma,Len[j]*weight[j]);
        }
        cout << ma << endl;
    }

}PAM;

signed main( ) {
    scanf("%s", str );
    PAM.Build( str );
    PAM.getWeight();
    return 0;
}