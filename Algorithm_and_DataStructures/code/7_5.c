#include<stdio.h>
#include<stdlib.h>
int price[20] = {
    168,
    10,
    145,
    60,
    10,
    124,
    124,
    105,
    126,
    184,
    186,
    135,
    89,
    98,
    62,
    132,
    86,
    125,
    126,
    0 };

int cal[20] = {
    496,
    45,
    325,
    347,
    61,
    486,
    446,
    22,
    110,
    475,
    520,
    325,
    221,
    322,
    152,
    216,
    322,
    105,
    221,
    210 };
int main() {
    int n = 20;
    int ans = 0, yen ,calo,max=0;
    // {0, 1, ..., n-1} ‚Ì•”•ªW‡‚Ì‘S’Tõ
    for (int bit = 0; bit < (1 << n); ++bit)
    {
        yen = 0;
        calo = 0;
        for (int i = 0; i < n; ++i) {
            if (bit & (1 << i)) { // i ‚ª bit ‚É“ü‚é‚©‚Ç‚¤‚©
                yen += price[i];
                calo += cal[i];
            }
        }
        if (yen <= 750) {
            //printf("%d %d\n", ans, max);
            if (max < calo) {
                max = calo;
                ans = bit;
            }
        }

    }
    for (int i = 0; i < n; ++i) {
        if (ans & (1 << i)) { // i ‚ª ans ‚É“ü‚é‚©‚Ç‚¤‚©
            printf("%d ", i);
        }
    }
    printf("\n%d\n%d\n",ans,max);
	return 0;
}