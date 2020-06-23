#include<bits/stdc++.h>

using namespace std;

int dp[20][1<<20];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    memset(dp,0,sizeof(dp));
    int input[n][m+1];
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            int x;
            cin>>x;
            dp[i][1<<(x-1)]=j+1;
            input[i][j+1]=x;
        }
    }

    for(int i=1;i<n;++i){
        for(int j=0;j<(1<<n);++j){
            bitset<20> b(j);
            if(b.count()==i+1){
                int t=1;
                for(int k=0;k<n;++k){
                    if(dp[i-1][j^t]!=0&&dp[i][t]!=0){
                        dp[i][j]=dp[i][t];
                        break;
                    }
                    t<<=1;
                }
            }
        }
    }

    /*for(int i=0;i<n;++i){
        for(int j=0;j<(1<<n);++j){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }*/

    vector<int> vec(n);
    int curr=(1<<n)-1;
    for(int i=n-1;i>=0;i--){
        vec[i]=dp[i][curr];
        curr^=(1<<(input[i][vec[i]]-1));
    }

    for(int i=0;i<n;++i){
        cout<<vec[i]<<" ";
    }











return 0;
}
