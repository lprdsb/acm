#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define For(i, a, b) for(int i = (a), en = (b); i <= en; ++i)
#define Rof(i, a, b) for(int i = (a), en = (b); i >= en; --i)
struct Vec {
    int len, *v;
};
void Vec_Init(struct Vec *_F) { _F->len = 0; }
void Vec_Resize(struct Vec *_F, int len) {
    int len1 = _F->len;
    _F->len = len;
    if(len1) _F->v = realloc(_F->v, len * sizeof(int));
    else _F->v = malloc(len * sizeof(int));
    For(i, len1, len - 1) _F->v[i] = 0;
}
struct Vec Vec_Cpy(struct Vec *_F) {
    struct Vec res; Vec_Init(&res); Vec_Resize(&res, _F->len);
    For(i, 0, _F->len - 1) res.v[i] = _F->v[i];
    return res;
}
#define mod 998244353
int max(int x, int y) {
    return x < y ? y : x;
}
int fp(int x, int y) {
    int res = 1;
    while(y) {
        if(y & 1) res = 1ll * res * x % mod;
        x = 1ll * x * x % mod;
        y >>= 1;
    }
    return res;
}
void swap(int *_x, int *_y) {
    int tem = *_x;
    *_x = *_y;
    *_y = tem;
}
int g = 3;
struct Vec NTT_rev, NTT_gpw;
int tot = 0;
void NTT(struct Vec *_F) {
    int lim = _F->len;
    // printf("%d\n", ++tot);
    if(NTT_rev.len != lim) {
        Vec_Resize(&NTT_rev, lim);
        int k = __builtin_ctz(lim) - 1;
        For(i, 0, lim - 1) NTT_rev.v[i] = (NTT_rev.v[i >> 1] >> 1) | ((i & 1) << k);
    }
    For(i, 0, lim - 1) if(i < NTT_rev.v[i]) swap(&_F->v[i], &_F->v[NTT_rev.v[i]]);
    if(NTT_gpw.len < lim) {
        int k = __builtin_ctz(NTT_gpw.len);
        Vec_Resize(&NTT_gpw, lim);
        while((1 << k) < lim) {
            int w = fp(g, (mod - 1) >> (k + 1));
            For(i, 1 << (k - 1), (1 << k) - 1) {
                NTT_gpw.v[i << 1] = NTT_gpw.v[i];
                NTT_gpw.v[i << 1 | 1] = 1ll * w * NTT_gpw.v[i] % mod;
            }
            k++;
        }
    }
    for(int i = 2; i <= lim; i <<= 1) {
        int ii = i >> 1;
        for(int j = 0; j < lim; j += i) {
            For(p, 0, ii - 1) {
                int tem1 = _F->v[j + p], tem2 = 1ll * NTT_gpw.v[ii + p] * _F->v[j +
                    ii + p] % mod;
                _F->v[j + p] = (tem1 + tem2) % mod;
                _F->v[j + ii + p] = (tem1 - tem2 + mod) % mod;
            }
        }
    }
    // printf("asd\n");
}
void INTT(struct Vec *_F) {
    int lim = _F->len;
    For(i, 1, lim - 1) if(i < lim - i) swap(&_F->v[i], &_F->v[lim - i]);
    NTT(_F);
    int inv = fp(lim, mod - 2);
    For(i, 0, lim - 1) _F->v[i] = 1ll * _F->v[i] * inv % mod;
}
struct Vec Vec_Mul(struct Vec *F, struct Vec *G) {
    if(!F->len || !G->len) {
        F->len = 0;
        return *F;
    }
    struct Vec _F = Vec_Cpy(F), _G = Vec_Cpy(G);
    int len = _F.len + _G.len - 1, lim = 1;
    while(lim < len) lim <<= 1;
    Vec_Resize(&_F, lim); Vec_Resize(&_G, lim);
    NTT(&_F); NTT(&_G);
    // For(i, 0, lim - 1) printf("%d ", _F.v[i]); puts("");
    For(i, 0, lim - 1) _F.v[i] = 1ll * _F.v[i] * _G.v[i] % mod;
    INTT(&_F);
    Vec_Resize(&_F, len);
    return _F;
}
struct Vec Vec_Mul_Int(struct Vec _F, int x) {
    For(i, 0, _F.len - 1) _F.v[i] = 1ll * x * _F.v[i] % mod;
    return _F;
}
struct Hint {
    struct Vec x;
};
void Hint_Init(struct Hint *_F) {
    Vec_Init(&_F->x);
    // printf("asd%d\n", _F->x.len);
}
void Hint_Resize(struct Hint *_F, int len) {
    Vec_Resize(&_F->x, len);
}
void Hint_Build(struct Hint *_F, char *_s) {
    int len = strlen(_s);
    Vec_Resize(&_F->x, len);
    For(i, 0, len - 1) _F->x.v[i] = _s[len - 1 - i] - '0';
}
int Hint_Com(struct Hint *_F, struct Hint *_G) {
    if(_F->x.len != _G->x.len) return _F->x.len < _G->x.len;
    int len = _F->x.len;
    Rof(i, len - 1, 0) if(_F->x.v[i] != _G->x.v[i]) return _F->x.v[i] < _G->x.v[i];
    return 0;
}
struct Hint Hint_Mul(struct Hint *F, struct Hint *G) {
    struct Vec _H = Vec_Mul(&F->x, &G->x);
    struct Hint res; Hint_Init(&res);
    Hint_Resize(&res, _H.len);
    int tem = 0;
    For(i, 0, _H.len - 1) {
        res.x.v[i] = _H.v[i] + tem;
        tem = 0;
        if(res.x.v[i] >= 10) {
            tem += res.x.v[i] / 10;
            res.x.v[i] %= 10;
        }
    }
    int now = _H.len;
    while(tem) {
        Vec_Resize(&res.x, now + 1);
        res.x.v[now - 1] = tem % 10;
        tem /= 10;
        now++;
    }
    return res;
}
struct Hint Hint_Add(struct Hint *_F, struct Hint *_G) {
    int len = max(_F->x.len, _G->x.len);
    struct Hint res; Hint_Init(&res); Hint_Resize(&res, len);
    int tem = 0;
    For(i, 0, len - 1) {
        if(i >= _F->x.len) res.x.v[i] = _G->x.v[i];
        else if(i >= _G->x.len) res.x.v[i] = _F->x.v[i];
        else res.x.v[i] = _F->x.v[i] + _G->x.v[i];
        res.x.v[i] += tem; tem = 0;
        if(res.x.v[i] >= 10) {
            tem++;
            res.x.v[i] -= 10;
        }
    }
    // printf("%d\n", res.x.len);
    return res;
}
struct Hint Hint_Minu(struct Hint *_F, struct Hint *_G) {
    int len = max(_F->x.len, _G->x.len);
    struct Hint res; Hint_Init(&res); Hint_Resize(&res, len);
    int tem = 0;
    For(i, 0, len - 1) {
        if(i >= _G->x.len) res.x.v[i] = _F->x.v[i];
        else res.x.v[i] = _F->x.v[i] - _G->x.v[i];
        res.x.v[i] -= tem; tem = 0;
        if(res.x.v[i] < 0) {
            tem++;
            res.x.v[i] += 10;
        }
    }
    return res;
}
int Hdou_bas = 50000;
struct Hdou {
    int k;
    struct Hint x;
};
void Hdou_Init(struct Hdou *_F) {
    Hint_Init(&_F->x);
    Hint_Resize(&_F->x, 2 * Hdou_bas);
    _F->k = 1;
}
void Hdou_Build(struct Hdou *_F, char *_s) {
    _F->k = 1;
    if(_s[0] == '-') _F->k = -1, _s++;
    int len = strlen(_s), pos = len;
    For(i, 0, len - 1) if(_s[i] == '.') {
        pos = i;
        break;
    }
    // printf("%d\n", pos);
    For(i, 0, len - 1) if(_s[i] != '.') _F->x.x.v[Hdou_bas + pos - i - (i <= pos)] =
        _s[i] - '0';
}
struct Hdou Hdou_Add(struct Hdou *_F, struct Hdou *_G) {
    struct Hdou res; Hdou_Init(&res);
    if(_F->k == _G->k) {
        res.k = _F->k;
        res.x = Hint_Add(&_F->x, &_G->x);
        // printf("%d\n", res.x.x.len);
    }
    else {
        if(Hint_Com(&_F->x, &_G->x)) {
            struct Hdou *tem = _F;
            _F = _G;
            _G = tem;
        }
        res.k = _F->k;
        res.x = Hint_Minu(&_F->x, &_G->x);
    }
    return res;
}
struct Hdou Hdou_Minu(struct Hdou *_F, struct Hdou *_G) {
    struct Hdou tem = *_G;
    tem.k *= -1;
    return Hdou_Add(_F, &tem);
}
struct Hdou Hdou_Mul(struct Hdou *_F, struct Hdou *_G) {
    struct Hint H = Hint_Mul(&_F->x, &_G->x);
    struct Hdou res; Hdou_Init(&res);
    res.k = _F->k * _G->k;
    For(i, 0, 2 * Hdou_bas - 1) res.x.x.v[i] = H.x.v[Hdou_bas + i];
    return res;
}
int Div_len = 0;
struct Hdou Hdou_Div(struct Hdou *_F, struct Hdou *_G) {
    struct Hdou H; Hdou_Init(&H);
    For(i, 0, 2 * Hdou_bas - 1) if(_G->x.x.v[i]) Div_len = i;
    H.x.x.v[2 * Hdou_bas - Div_len - 1] = 10 / _G->x.x.v[Div_len];
    For(o, 0, 20) {
        struct Hdou tem = Hdou_Add(&H, &H);
        H = Hdou_Mul(&H, &H);
        H = Hdou_Mul(&H, _G);
        H = Hdou_Minu(&tem, &H);
    }
    // For(i, 0, H.x.x.len - 1) printf("%d ", H.x.x.v[i]); printf("\n");
    H = Hdou_Mul(&H, _F);
    return H;
}
int dig;
char s1[100005], s2[100005];
int main() {
    Vec_Init(&NTT_rev); Vec_Init(&NTT_gpw);
    Vec_Resize(&NTT_gpw, 2);
    NTT_gpw.v[0] = 0; NTT_gpw.v[1] = 1;
    struct Hdou F, G, H; Hdou_Init(&F); Hdou_Init(&G); Hdou_Init(&H);
    // printf("Input dividend: ");
    scanf("%s", s1);
    // printf("Input divisor: ");
    scanf("%s", s2);
    // printf("Enter the number of decimal places to be retained: ");
    // scanf("%d", &dig);
    dig = 0;
    Hdou_Build(&F, s1); Hdou_Build(&G, s2);
    // Rof(i, 20, -20) printf("%d", F.x.x.v[Hdou_bas + i]); printf("\n");
    H = Hdou_Minu(&F, &G);
    // printf("%d\n", H.x.x.len);
    if(H.k == -1) printf("-");
    int fl = 0;
    Rof(i, 1000, 0) {
        int x = H.x.x.v[Hdou_bas + i];
        if(x) fl = 1;
        if(fl) printf("%d", x);
    }
    if(!fl) printf("0");
    // printf(".");
    // Rof(i, -1, -dig) printf("%d", H.x.x.v[Hdou_bas + i]);
    return 0;
}