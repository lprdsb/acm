#include<stdio.h>

int mon[20] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int chk(int year){
    if(year % 4 == 0){
        if(year % 100 == 0) return year % 400 == 0;
        return 1;
    }
    return 0;
}

void split_date(int day_of_year, int year, int *month, int *day){
    int ok = chk(year);
    for(int i = 1; i <= 12; ++i){
        int now = mon[i] + (ok && i == 2);
        if(day_of_year > now) day_of_year -= now;
        else{
            *month = i, *day = day_of_year;
            break;
        }
    }
}

int main(){

}