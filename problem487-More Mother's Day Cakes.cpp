#include<bits/stdc++.h>

using namespace std;

long long dp[20][1<<20];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    memset(dp,0,sizeof(dp));
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            int x;
            cin>>x;
            dp[i][1<<(x-1)]++;
        }
    }

    for(int i=1;i<n;++i){
        for(int j=0;j<(1<<n);++j){
            bitset<20> b(j);
            if(b.count()==i+1){
                int t=1;
                for(int k=0;k<n;++k){
                    dp[i][j]+=(dp[i-1][j^t]*dp[i][t])%1000000007;
                    t<<=1;
                }
                dp[i][j]%=1000000007;

            }
        }
    }

    /*for(int i=0;i<n;++i){
        for(int j=0;j<(1<<n);++j){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }*/
    cout<<dp[n-1][(1<<n)-1]%1000000007<<endl;










return 0;
}
