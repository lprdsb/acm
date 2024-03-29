import java.util.Scanner;

public class A {
    static int maxn = 100000;
    static int n, m, cnt = 0;
    static int[] op = new int[maxn + 5], pos = new int[maxn + 5], tp = new int[2],
            as = new int[maxn + 5], opt = new int[maxn + 5];
    static int[][] st = new int[2][maxn + 5];

    public static void main(String args[]) {
        // freopen("in", "r", stdin);
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        m = sc.nextInt();
        for (int i = 1; i <= m; ++i) {
            op[i] = sc.nextInt();
            pos[i] = sc.nextInt();
        }
        m++;
        op[m] = 0;
        pos[m] = 1;
        m++;
        op[m] = 1;
        pos[m] = n;
        for (int i = 1; i <= m; ++i) {
            if (op[i] == 0) {
                while (tp[0] != 0 && pos[st[0][tp[0]]] <= pos[i])
                    tp[0]--;
                st[0][++tp[0]] = i;
            } else {
                while (tp[1] != 0 && pos[st[1][tp[1]]] >= pos[i])
                    tp[1]--;
                st[1][++tp[1]] = i;
            }
        }
        int[] now = {1, 0};
        while (now[0] <= tp[0] && now[1] <= tp[1]) {
            while (now[0] <= tp[0] && st[0][now[0]] <= st[1][now[1]])
                now[0]++;
            if (now[0] > tp[0])
                break;
            opt[++cnt] = pos[st[0][now[0]]];
            while (now[1] <= tp[1] && st[1][now[1]] <= st[0][now[0]])
                now[1]++;
            if (now[1] > tp[1])
                break;
            opt[++cnt] = pos[st[1][now[1]]];
        }
        // for (int i = 1; i <= cnt; ++i)
        // System.out.print(opt[i] + " ");
        int l = 1, r = n, o = 0, mx = n;
        for (int i = 0; i <= cnt; ++i) {
            o ^= 1;
            if (o != 0) {
                for (int j = l; j <= opt[i] - 1; ++j) {
                    as[l++] = mx--;
                    if (l > r)
                        break;
                }
            } else {
                for (int j = r; j >= opt[i] + 1; --j) {
                    as[r--] = mx--;
                    if (l > r)
                        break;
                }
            }
            if (l > r)
                break;
        }
        for (int i = 1; i <= n; ++i)
            System.out.printf("%d ", as[i]);
        sc.close();
    }

}
