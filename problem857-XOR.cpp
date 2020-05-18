#include<bits/stdc++.h>

using namespace std;

int query(vector<vector<int>> &seg, int h, int pos, int l, int r){
    // at level h and position pos
    int L = pos << h, R = (pos+1) << h;
    if (L == l && R == r) return seg[h][pos];
    int M = (L+R)/2;
    if (r <= M) return query(seg, h-1, pos*2 , l, r);
    if (l >= M) return query(seg, h-1, pos*2 + 1, l, r);
    return query(seg, h-1, pos*2, l, M) ^ query(seg, h-1, pos*2 + 1, M, r);
}

int main() {
    int n, q;
    scanf("%d %d", &n, &q);
    vector<vector<int>> seg(18,vector<int>());
    for (int i = 0; i < 18; i++) {
        seg[i].resize(1 << (17 - i)); //query size = 2^17 = 131072 > 100000
    }
    for (int i = 0; i < n; i++) {
        scanf("%d",&seg[0][i]);
    }
    // build
    for (int h = 1; h < 18; h++) {
        for (int i = 0; i < seg[h].size(); i++) {
            seg[h][i] = seg[h-1][2*i] ^ seg[h-1][2*i+1];
        }
    }

    // process queries
    while (q--) {
        int l, r;
        scanf("%d%d",&l,&r);
        l--;
        // [l, r) and max h == 17, find range from the top.
        int res = query(seg, 17, 0, l, r);
        printf("%d\n",res);
    }
    return 0;
}
















