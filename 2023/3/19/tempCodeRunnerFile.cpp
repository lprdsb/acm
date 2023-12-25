
    while(q--){
        int l, r, fl = 0; read(l); read(r);
        For(o, 1, 17){
            int sta = (1 << o) - 1;
            // if(o == 1) cout << tr[o].que(l, r, (l + (1 << (o - 1))) & sta, (l + sta) & sta) << endl;
            if(tr[o].que(l, r, (l + (1 << (o - 1))) & sta, (l + sta) & sta) & 1){
                fl = 1;
                // if(!q) cout << tr[o].que(9, 9, 0, 0) << endl;
                break;
            }
        }
        printf(fl ? "A" : "B");
    }