#include<bits/stdc++.h>

using namespace std;

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    int m,n,q;
    //cin>>m>>n>>q;
    scanf("%d%d%d",&m,&n,&q);
    map<int,int> chocolate;
    chocolate[0]=1<<30;
    chocolate[1<<30]=0;
    long long All=(long long)m*n;
    while(q--){
        int x,y;
        //cin>>x>>y;
        scanf("%d%d",&x,&y);
        map<int,int>::iterator iter=chocolate.lower_bound(x);
        if(iter->second>=y){
            //cout<<"QAQ"<<endl;
            puts("QAQ");
            continue;
        }
        long long cnt=0;
        int last=iter->second;
        vector<int> e_pos;
        while(true){
            iter--;
            long long ate=(long long)(x-(iter->first))*(min(y,iter->second)-last);
            cnt+=ate;
            All-=ate;
            last=iter->second;
            if(iter->second>y){
                break;
            }
            e_pos.push_back(iter->first);
        }
        for(int i=0;i<e_pos.size();++i){
            chocolate.erase(e_pos[i]);
        }
        //cout<<cnt<<endl;
        printf("%lld\n",cnt);
        chocolate[x]=y;
    }
    //cout<<All<<endl;
    printf("%lld\n",All);



return 0;
}
