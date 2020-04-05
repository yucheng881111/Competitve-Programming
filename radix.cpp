#include<bits/stdc++.h>

using namespace std;
//input has >n/2 same numbers
//find that number
int main() {
    int n;
    scanf("%d",&n);
    int high[1<<16] = {}, low[1<<16] = {};
    for (int i = 0; i < n; i++) {
        int ai;
        scanf("%d",&ai);
        low[ai & 0xFFFF]++;
        high[(ai >> 16) & 0xFFFF]++;
    }
    int x_high, x_low;
    for (int i = 0; i < (1<<16); i++) {
        if (low[i] > n/2) {
            x_low = i;
        }
        if (high[i] > n/2) {
            x_high = i;
        }
    }
    printf("%d\n",(x_high<<16)|x_low);
}
