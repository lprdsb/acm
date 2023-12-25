#include<stdio.h>

int mon[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
struct Date{
    int month, day, year;
};

int chk(int year){
    if(year % 4 == 0){
        if(year % 100 == 0) return year % 400 == 0;
        else return 1;
    }
    else return 0;
}

int day(struct Date dat){
    int res = 0;
    for(int i = 1900; i < dat.year; ++i){
        res += 365 + chk(i);
    }
    for(int i = 1; i < dat.month; ++i) res += mon[i] + (chk(dat.year) && i == 2);
    return res + dat.day - 1;
}

int difDays(struct Date dat1, struct Date dat2){
    return day(dat2) - day(dat1);
}

int main(){
    printf("%d\n", day((struct Date){2, 1, 1900}));
    printf("%d\n", difDays((struct Date){2, 1, 1900}, (struct Date){3, 1, 1900}));
}