");
        else if(!sum) puts("0");
        else{
            int fl = 0;
            For(i, 1, s){
                For(j, 1, sum) if(f[0][i][j] && f[1][i][sum - j]){
                    fl = 1;
                    printf("%d\n", i);
                    break;
                }
                if(fl) break;
            }
            if(!fl) puts("-1");
        }