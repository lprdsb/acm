/*
�ַ����༭����(Edit Distance)���Ƕ���˹��ѧ��Vladimir Levenshtein����ĸ�������ַ���֮�����С�������ָ��һ���ַ���ת��Ϊ��һ���ַ���ʱ������Ҫ����С�༭����(���롢ɾ�����滻)�Ĵ�����
�༭������������3�֣�
�滻��substitution������һ���ַ��滻Ϊ��һ���ַ�
���루insertion��������һ���ַ�
ɾ����deletion����ɾ��һ���ַ�
���������һ�����ڶ�̬�滮�㷨�ı༭������㺯��editdistDP ��C����ʵ�֣��ú�������Ϊ2���ַ���������ֵΪ2���ַ����ı༭���룬����ʵ�����£�
*/

#define max2(a,b) ((a)>(b)?(a):(b))
int **Dp, MaxDP = 3300;								//for dynamic programming
int min3(int a, int b, int c) {
    int min = a < b ? a : b;
    return min < c ? min : c;
}
int initDP() {
    int i;
    Dp = (int **)malloc(MaxDP * sizeof(int *));
    for(i = 0; i < MaxDP; i++)
        Dp[i] = (int *)malloc(MaxDP * sizeof(int));
    return 0;
}
int editdistDP(char *str1, char *str2) {
    int i, j;
    int len1, len2;
    static int flag = 0;

    (flag++) ? 1 : initDP();
    len1 = strlen(str1) + 1; len2 = strlen(str2) + 1;
    for(i = 0; i <= len1; i++) {
        for(j = 0; j <= len2; j++) {
            if(i == 0)
                Dp[i][j] = j;
            else if(j == 0)
                Dp[i][j] = i;
            else if(str1[i - 1] == str2[j - 1])
                Dp[i][j] = Dp[i - 1][j - 1];
            else
                Dp[i][j] = 1 + min3(Dp[i][j - 1], Dp[i - 1][j], Dp[i - 1][j - 1]);
        }
    }
    return Dp[len1][len2];
}
