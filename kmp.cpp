#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int lps[8000];

void computeTemporaryArray(char *pattern)
{
    int j =0;
    int len = strlen(pattern);
    for(int i=1; i < len ;)
    {
        if(pattern[i] == pattern[j])
        {
            lps[i] = j + 1;
            j++;
            i++;
        }
        else
        {
            if(j != 0)
            {
                j = lps[j-1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
    //return lps;
}
//int pos=-1;
int KMP(char *text, char *pattern)
{
    int cnt=0;
    int i=0; // text
    int j=0; // pattern
    int lent = strlen(text);
    int lenp = strlen(pattern);
    while(i < lent && j < lenp)
    {
        if(text[i] == pattern[j])
        {
            i++;
            j++;
        }
        else
        {
            if(j!=0)
            {
                j = lps[j-1];
            }
            else
            {
                i++;
            }
        }
        if(j==lenp)
        {
            cnt++;
            //i++;   text[i] == pattern[j]时，就已经都加过了
            j=0;
        }
    }
    if(j == lenp)
    {
        return cnt;
    }
    return cnt;
}



int main(void)
{
    char t[1020];
    char p[1020];
    while(~scanf("%s",t))
    {
        if(t[0]=='#')return 0;
        scanf("%s",p);
        computeTemporaryArray(p);
        int cnt = KMP(t,p);
//        if(cnt)
//        {
//            printf("YES!\n");
//            //printf("pos=%d\n",pos);
//        }
//        else
//        {
//            printf("NO!\n");/*printf("pos=%d\n",pos);*/
//        }
//        for(int i=0; i<strlen(p); i++)
//        {
//            printf("lps[%d]=%d\n",i,lps[i]);
//        }
        printf("%d\n",cnt);
    }

    return 0;
}
