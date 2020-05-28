#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
    int N;
    scanf("%d",&N);
    while(N--){
        int n;
        ll l,r;
        scanf("%d %lld %lld",&n,&l,&r);
        if(n==0){
            printf("%lld\n",l);
            continue;
        }
        ll x;
        vector<bool> vec(min(r-l+1,(ll)10000000),0);
        for(int i=0;i<n;++i){
            scanf("%lld",&x);
            x-=l;
            if(x<vec.size()){
                vec[x]=1;
            }
        }
        bool b=false;
        for(int i=0;i<vec.size();++i){
            if(vec[i]==0){
                printf("%lld\n",i+l);
                b=true;
                break;
            }
        }
        if(!b){
            printf("^v^\n");
        }



    }



return 0;
}
