#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int cnt[2][50];
char s[1000];

int main(){
    printf("Enter first word:");
    scanf("%s", s + 1);
    int len = 1;
    while(s[len] != '\0') len++;
    len--;
    for(int i = 1; i <= len; ++i) cnt[0][s[i] - 'a']++;
    printf("Enter first word:");
    scanf("%s", s + 1);
    len = 1;
    while(s[len] != '\0') len++;
    len--;
    for(int i = 1; i <= len; ++i) cnt[1][s[i] - 'a']++;
    int fl = 1;
    for(int i = 0; i < 26; ++i) if(cnt[0][i] != cnt[1][i]){
        fl = 0;
        break;
    }
    if(fl) puts("The words are anagrams.");
    else puts("The words are not anagrams.");
    return 0;
}