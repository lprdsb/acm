#include<stdio.h>
#include<string.h>

char s[105][25] = {"", "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

int m, d, y;

int main(){
    printf("Enter a date (mm/dd/yyyy): \n");
    scanf("%d/%d/%d", &m, &d, &y);
    printf("You entered the date %s %d, %d\n", s[m], d, y);
    return 0;
}