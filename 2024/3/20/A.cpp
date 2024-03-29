#include<stdio.h>
#include<stdlib.h>
int main() {
    int people[100] = { 0 };                        //n变量代表有n个人
    for(int i = 0;i < 20;i++) {                    //给people变量赋值1，代表当前的人还在报数，0则代表该位置的人已经空了
        people[i] = 1;
    }

    void sort(int people[5], int n);
    sort(people, 20);                            //需要n传入有多少人参与排序
    system("pause");
}


void sort(int people[100], int n) {
    int now = 1, least = n, now_people = 0;        //now变量代表是当前的报数为多少,least变量表示当前当前剩余的人数,now_people是指当前轮到哪个人报数
    do {
        if(now_people > n - 1) {            //判断当前轮到的人是否超出最多人数，如果超出，则变成0
            now_people = 0;
        }
        if(people[now_people] == 0) {        //如果当前为空，就往前加一个
            now_people++;
        }
        else {                            //如果当前不为空
            if(now == 2) {                    //如果报数是三，那么当前的元素就变成0
                people[now_people] = 0;
                least--;
                now = 1;                    //重置报数
            }
            else {
                now++;
            }
            now_people++;
        }
    } while(least > 1);                                    //当人数仅剩一人的时候跳出循环

    for(int i = 0;i < n;i++) {                //输出唯一的属性为1的元素
        if(people[i] == 1) {
            printf("%d", i + 1);            //输出是剩下的是第几个人
        }
    }
}