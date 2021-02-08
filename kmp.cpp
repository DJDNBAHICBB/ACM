//
// Created by acer on 2021/2/8.
//
#define int long long
const int maxn = 1000000;
int nxt[maxn];
void search(string s)
{
    int k=-1;
    nxt[0]=-1;
    int j=0;
    while(j<s.length())
    {
        if(k<0 || s[k]==s[j])
        {
            j++;
            k++;
            nxt[j] = k;
        }
        else {
            k=nxt[k];
        }

    }
}