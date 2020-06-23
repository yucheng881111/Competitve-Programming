#include<bits/stdc++.h>

using namespace std;

int dp[10001];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    memset(dp,0,sizeof(dp));
    int n;
    cin>>n;
    int sum=0;
    vector<int> vec(n+1);
    for(int i=1;i<=n;++i){
        int x;
        cin>>x;
        sum+=x;
        vec[i]=x;
    }
    int target=sum/2;

    for(int i=1;i<=n;++i){
        for(int j=target;j>=vec[i];j--){
            dp[j]=max(dp[j],dp[j-vec[i]]+vec[i]);
        }
    }

    cout<<sum-dp[target]*2<<endl;




return 0;
}
