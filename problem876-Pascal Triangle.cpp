#include<bits/stdc++.h>
#define Lint long long
using namespace std;

Lint modpow(Lint a, Lint b, Lint c){
	if(b == 0) return 1;
	if(b % 2 == 1) return a * modpow(a*a % c, b/2, c) % c;
	else return modpow(a*a % c, b/2, c) % c;
}

int main(){
    int n;
    scanf("%d",&n);
    while(n--){
        Lint x;
        scanf("%llu",&x);
        Lint ans=modpow(2,x+1,998244353);
        x=(x+2)%998244353;
        ans=ans-x;
        if(ans<0){
            ans=ans+998244353;
        }
        printf("%lld\n",ans);
    }



return 0;
}
