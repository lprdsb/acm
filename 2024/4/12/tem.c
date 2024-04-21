#define _CRT_SECURE_NO_WARNINGS 1
/*思路：
先读入已有操作，再读入新的操作，处理字符串
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 512

typedef struct {
    int op;
    int pos;
    char str[MAX_LENGTH];
}Editoperation;
int top = -1;
void insert_str(char* s, int pos, char* str1);
void delete_str(char* s, int pos, int len);
void undo(char* s, Editoperation* operations);

char origin_str[MAX_LENGTH];//原始字符串
int main() {
    // freopen("in.txt", "r", stdin);
    Editoperation stack[100];

    //初始字符串以及已经进行的操作
    int n;//已进行的操作次数
    fgets(origin_str, sizeof(origin_str), stdin);
    origin_str[strcspn(origin_str, "\n")] = '\0'; // 删除换行符
    scanf("%d", &n);
    int len;
    for(top = 0; top < n; top++) {
        //	printf("%d\n", top);
        scanf("%d", &stack[top].op);
        if(stack[top].op == 1) {
            scanf("%d %s", &stack[top].pos, stack[top].str);//吞空格
        }
        else if(stack[top].op == 2) {
            len = 0;
            scanf("%d %s", &stack[top].pos, stack[top].str);
        }
    }
    top--;//跳出循环的时候也会自增一次要把它给消掉
    //读取将要进行的操作
    while(1) {
        int op;
        scanf("%d", &op);
        if(op == 1) {
            top++;
            stack[top].op = op;
            scanf("%d %s", &stack[top].pos, stack[top].str);//吞空格
            insert_str(origin_str, stack[top].pos, stack[top].str);
        }
        else if(op == 2) {
            top++;
            stack[top].op = op;
            len = 0;
            scanf("%d", &stack[top].pos);
            scanf("%d", &len);
            // 清空字符串
            memset(stack[top].str, 0, sizeof(stack[top].str));
            // 将指定长度的字符串从 origin_str 复制到 stack[top].str
            strncpy(stack[top].str, origin_str + stack[top].pos, len);
            // 确保 stack[top].str 以空字符结尾
            stack[top].str[len] = '\0';
            delete_str(origin_str, stack[top].pos, len);
        }
        else if(op == 3) {
            if(top < 0)
                continue;
            else {
                undo(origin_str, stack);
                top--;
            }
        }
        else if(op == -1) {
            break;
        }
    }
    printf("%s\n", origin_str);
    return 0;
}
void strcpy1(char *s1, char *s2) {
    int now = 0;
    while(*(s2 + now)) *(s1 + now) = *(s2 + now), now++;
    *(s1 + now) = 0;
}
void insert_str(char* s, int pos, char* str1) {
    char temp[MAX_LENGTH];
    strcpy(temp, s + pos);
    s[pos] = '\0';
    strcat(s, str1);
    strcat(s, temp);
}
void delete_str(char* s, int pos, int len) {
    if(pos + len >= strlen(s))
        s[pos] = '\0';//判断条件不是大于等于strlen(s)-1是因为，本来s[strlen(s)]就是'\0';
    else
        strcpy(s + pos, s + pos + len);//把pos到pos+len-1的都删掉
}
void undo(char* s, Editoperation* operations) {
    if(operations[top].op == 1) {
        delete_str(origin_str, operations[top].pos, strlen(operations[top].str));
    }
    else if(operations[top].op == 2) {
        insert_str(origin_str, operations[top].pos, operations[top].str);
    }
}