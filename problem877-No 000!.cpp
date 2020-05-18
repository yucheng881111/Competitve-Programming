#include<bits/stdc++.h>

using namespace std;

void mul(vector<vector<long long>> &a,vector<vector<long long>> &b,vector<vector<long long>> &ans){
    //size=3x3
    vector<vector<long long>> temp(3,vector<long long>(3,0));
    for(int i=0;i<3;++i){
        for(int j=0;j<3;++j){
            for(int k=0;k<3;++k){
                temp[i][j]+=(a[i][k]*b[k][j])%2147483647;
            }
        }
    }
    for(int i=0;i<3;++i){
        for(int j=0;j<3;++j){
            temp[i][j]%=2147483647;
        }
    }
    ans=temp;
}

vector<vector<long long>> fastpow(int n){
    vector<vector<long long>> base(3,vector<long long>(3,0));
    base[0][0]=1;base[0][1]=1;base[0][2]=1;
    base[1][0]=1;base[1][1]=0;base[1][2]=0;
    base[2][0]=0;base[2][1]=1;base[2][2]=0;
    vector<vector<long long>> ans(3,vector<long long>(3,0));
    ans[0][0]=1;ans[0][1]=0;ans[0][2]=0;
    ans[1][0]=0;ans[1][1]=1;ans[1][2]=0;
    ans[2][0]=0;ans[2][1]=0;ans[2][2]=1;
    while(n!=0){
        if(n&1){
            mul(base,ans,ans);
        }
        mul(base,base,base);
        n>>=1;
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    while(n--){
        int x;
        cin>>x;
        if(x==1){
            cout<<"2"<<endl;
            continue;
        }else if(x==2){
            cout<<"4"<<endl;
            continue;
        }
        long long x0=1,x1=2,x2=4;
        vector<vector<long long>> vec=fastpow(x-2);
        /*for(int i=0;i<3;++i){
            for(int j=0;j<3;++j){
                cout<<vec[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;*/

        long long sum=vec[0][0]*x2+vec[0][1]*x1+vec[0][2]*x0;
        cout<<sum%2147483647<<endl;


    }






return 0;
}
