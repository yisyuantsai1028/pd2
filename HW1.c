#include <stdio.h>
#include <string.h>
#define MAX_LEN 200000

void count(char *str, int freq[MAX_LEN][26]) {
    int len=strlen(str);
    for(int i=1;i<=len;i++)
    {
        memcpy(freq[i], freq[i - 1], 26 * sizeof(int)); 
        freq[i][str[i-1]-'a']++;
    }
}


int main()
{
    static int freq1[MAX_LEN][26]={0};
    static int freq2[MAX_LEN][26]={0};
    char str1[MAX_LEN];
    char str2[MAX_LEN];
    int n,a,b,c,d;
    int ans=1;
    scanf("%s",str1);
    scanf("%s",str2);
    scanf("%d",&n);
    count(str1,freq1);
    count(str2,freq2);
    
    
    for(int i=0;i<n;i++)
    {
        scanf("%d %d %d %d", &a, &b, &c, &d);
        if((b-a)!=(d-c))
        {
            ans=0;
        }

        else
        {
           

            for(int i=0;i<26;i++)
            {
                if((freq1[b][i]-freq1[a-1][i])==(freq2[d][i]-freq2[c-1][i]))
                {
                    ans=1;
                }
                else
                {
                    ans=0;
                    break;
                }
            }




        }


        if(ans==1)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }


    }
    
    return 0;
}