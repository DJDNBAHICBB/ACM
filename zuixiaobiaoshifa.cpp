//
// Created by acer on 2021/2/1.
//
//求循环字符串的长度为k的最小子串
int MinimumRepresentation(int *s, int l)
{
    int i,j,k;
    i=0;j=1;k=0;
    while(i<l&&j<l)
    {
        k=0;
        while(s[i+k]==s[j+k]&&k<l) k++;
        if(k==l) return i;
        if(s[i+k]>s[j+k])
            if(i+k+1>j) i=i+k+1;
            else i=j+1;
        else if(j+k+1>i) j=j+k+1;
        else  j=i+1;
    }
    if(i<l) return i;
    else return j;
}
