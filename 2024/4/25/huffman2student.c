//�ļ�ѹ��-Huffmanʵ��
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXSIZE 32

struct tnode {					//Huffman���ṹ
	char c;
	int weight;					//���ڵ�Ȩ�أ�Ҷ�ڵ�Ϊ�ַ������ĳ��ִ���
	struct tnode *left, *right;
};
int Ccount[128] = { 0 };			//���ÿ���ַ��ĳ��ִ�������Ccount[i]��ʾASCIIֵΪi���ַ����ִ��� 
struct tnode *Root = NULL; 		//Huffman���ĸ��ڵ�
char HCode[128][MAXSIZE] = { {0} }; //�ַ���Huffman���룬��HCode['a']Ϊ�ַ�a��Huffman���루�ַ�����ʽ�� 
int Step = 0;						//ʵ�鲽�� 
FILE *Src, *Obj;

void statCount();				//����1��ͳ���ļ����ַ�Ƶ��
void createHTree();				//����2������һ��Huffman�������ڵ�ΪRoot 
void makeHCode();				//����3������Huffman������Huffman����
void atoHZIP(); 				//����4������Huffman���뽫ָ��ASCII���ı��ļ�ת����Huffman���ļ�

void print1();					//�������1�Ľ��
void print2(struct tnode *p);	//�������2�Ľ�� 
void print3();					//�������3�Ľ��
void print4();					//�������4�Ľ��

int main() {
	if((Src = fopen("input.txt", "r")) == NULL) {
		fprintf(stderr, "%s open failed!\n", "input.txt");
		return 1;
	}
	if((Obj = fopen("output.txt", "w")) == NULL) {
		fprintf(stderr, "%s open failed!\n", "output.txt");
		return 1;
	}
	scanf("%d", &Step);					//���뵱ǰʵ�鲽�� 

	statCount();						//ʵ�鲽��1��ͳ���ļ����ַ����ִ�����Ƶ�ʣ�
	if(Step == 1)
		print1(); 			//���ʵ�鲽��1���	
	createHTree();						//ʵ�鲽��2�������ַ�Ƶ��������Ӧ��Huffman��
	if(Step == 2)
		print2(Root); 		//���ʵ�鲽��2���	
	makeHCode();				   		//ʵ�鲽��3������RootΪ���ĸ���Huffman��������ӦHuffman����
	if(Step == 3)
		print3(); 			//���ʵ�鲽��3���
	if(Step >= 4)
		atoHZIP(), print4(); 	//ʵ�鲽��4����Huffman��������ѹ���ļ��������ʵ�鲽��4���	

	fclose(Src);
	fclose(Obj);

	return 0;
}

//��ʵ�鲽��1����ʼ 

void statCount() {
	Ccount[0] = 1;
	char c;
	while(~fscanf(Src, "%c", &c)) Ccount[(int)c]++;
}

//��ʵ�鲽��1������

//��ʵ�鲽��2����ʼ

#define cst const
#define For(i, a, b) for(int i = (a); i <= (b); ++i)
#define Rof(i, a, b) for(int i = (a); i >= (b); --i)
typedef struct tnode tnode;
int cmp(cst void *_x, cst void *_y) {
	tnode x = *(tnode*)(*(tnode**)_x), y = *(tnode*)(*(tnode**)_y);
	if(x.weight != y.weight) return y.weight - x.weight;
	return (int)y.c - (int)x.c;
}
void createHTree() {
	int tp = 0;
	tnode *st[128];
	For(i, 0, 127) if(Ccount[i]) {
		tnode *p = malloc(sizeof (tnode));
		p->left = p->right = 0;
		p->weight = Ccount[i];
		p->c = i;
		st[++tp] = p;
	}
	qsort(st + 1, tp, sizeof (tnode*), cmp);
	// For(i, 1, tp) printf("%c ", st[i]->c); puts("");
	while(tp > 1) {
		tnode *t1, *t2; t1 = st[tp--]; t2 = st[tp--];
		tnode *p = malloc(sizeof (tnode));
		p->left = t1; p->right = t2;
		p->weight = t1->weight + t2->weight;
		For(i, 1, tp + 1) if(i == tp + 1 || p->weight >= st[i]->weight) {
			Rof(j, tp + 1, i + 1) st[j] = st[j - 1];
			st[i] = p;
			tp++;
			break;
		}
	}
	Root = st[1];
}

//��ʵ�鲽��2������

//��ʵ�鲽��3����ʼ
char s[MAXSIZE];
void dfs(tnode *u, char *ss) {
	*ss = '\0';
	if(!u->left && !u->right) strcpy(HCode[u->c], s);
	if(u->left) {
		*ss = '0';
		dfs(u->left, ss + 1);
	}
	if(u->right) {
		*ss = '1';
		dfs(u->right, ss + 1);
	}
}
void makeHCode() {
	dfs(Root, s);
}

//��ʵ�鲽��3������

//��ʵ�鲽��4����ʼ

#define maxn 100000
int as[maxn + 5];
void atoHZIP() {
	Src = fopen("input.txt", "r");
	char c;
	int now = 0;
	while(~fscanf(Src, "%c", &c)) {
		char *p = HCode[c];
		while(*p != '\0') {
			as[++now] = *p == '1';
			p++;
		}
	}
	char *p = HCode['\0'];
	while(*p != '\0') {
		as[++now] = *p == '1';
		p++;
	}
	while(now % 8) as[++now] = 0;
	// For(i, 1, now) fprintf(Obj, "%d", as[i]);
	For(i, 1, now) {
		int byte = 0;
		For(j, 1, 8) byte = byte << 1 | as[i++]; i--;
		fprintf(Obj, "%c", byte);
		printf("%x", byte);
	}
}

//��ʵ�鲽��4������

void print1() {
	int i;
	printf("NUL:1\n");
	for(i = 1; i < 128; i++)
		if(Ccount[i] > 0)
			printf("%c:%d\n", i, Ccount[i]);
}

void print2(struct tnode *p) {
	if(p != NULL) {
		if((p->left == NULL) && (p->right == NULL))
			switch(p->c) {
				case 0: printf("NUL ");break;
				case ' ':  printf("SP ");break;
				case '\t': printf("TAB ");break;
				case '\n':  printf("CR ");break;
				default: printf("%c ", p->c); break;
			}
		print2(p->left);
		print2(p->right);
	}
}

void print3() {
	int i;

	for(i = 0; i < 128; i++) {
		if(HCode[i][0] != 0) {
			switch(i) {
				case 0: printf("NUL:");break;
				case ' ':  printf("SP:");break;
				case '\t': printf("TAB:");break;
				case '\n':  printf("CR:");break;
				default: printf("%c:", i); break;
			}
			printf("%s\n", HCode[i]);
		}
	}
}

void print4() {
	long int in_size, out_size;

	fseek(Src, 0, SEEK_END);
	fseek(Obj, 0, SEEK_END);
	in_size = ftell(Src);
	out_size = ftell(Obj);

	printf("\nԭ�ļ���С��%ldB\n", in_size);
	printf("ѹ�����ļ���С��%ldB\n", out_size);
	printf("ѹ���ʣ�%.2f%%\n", (float)(in_size - out_size) * 100 / in_size);
}
