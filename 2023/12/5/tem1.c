#include<stdio.h>

struct dialing_code{
    char s[105];
    int num;
};

const struct dialing_code country_codes[] ={{"Argentina",54}, {"Bangladesh",880}, {"Brazil",55}, {"Burma {Myanmar)", 95}
                                            , {"China",86},{"Colombia",573},{"Congo, Dem. Rep. of",243}, {"Egypt", 20}
                                            ,{"Ethiopia",251},{ "Germany", 49}, {"France", 33},{ "Indonesia", 62}
                                            ,{"India ", 92},{"Iran",98},{ "Italy",39},{"Japan",81},{ "Mexico",52}
                                            ,{"Pakistan",92},{ "Nigeria",234},{"Philippines",63},{ "Poland",48},{ "Russia",7}
                                            ,{"South Africa",273},{ "Korea",82},{"Spain",34},{"Sudan", 249},{"Thailand",66}
                                            ,{"Turkey",90},{"Ukraine",380},{"United Kingdom",44},{"United States",1},{"vietnam",84}};


struct dialing_code find(int num){
    for(int i = 0; i < 32; ++i) if(num == country_codes[i].num) return country_codes[i];
    puts("Wrong");
    return country_codes[32];
}

int main(){

}