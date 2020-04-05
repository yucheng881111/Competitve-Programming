#include<bits/stdc++.h>

using namespace std;
typedef unsigned long long ll;
int main(){
    string s;
    while(getline(cin,s)){
        stringstream ss;
        ll u;
        vector<ll> vec;
        ss<<s;
        while(ss>>u){
            vec.push_back(u);
        }
        int s=sqrt(vec.size());
        ll m[s][s];
        ll a[s];
        memset(m,0,sizeof(m));
        memset(a,0,sizeof(a));
        sort(vec.begin(),vec.end());
        bool yes=true;
        for(int i=0;i<s;++i){
            if(i==0){
                if((ll)sqrt(vec[0])*(ll)sqrt(vec[0])!=vec[0]){
                    yes=false;
                    break;
                }else{
                    a[0]=sqrt(vec[0]);
                    m[0][0]=vec[0];
                }
                vec.erase(vec.begin());
            }else{
                if(vec[0]%a[0]!=0){
                    yes=false;
                    break;
                }
                a[i]=vec[0]/a[0];
                for(int k=0;k<i;++k){
                    vector<ll>::iterator iter=find(vec.begin(),vec.end(),a[i]*a[k]);
                    if(iter==vec.end()){
                        yes=false;
                        break;
                    }else{
                        m[i][k]=*iter;
                        vec.erase(iter);
                    }
                    iter=find(vec.begin(),vec.end(),a[k]*a[i]);
                    if(iter==vec.end()){
                        yes=false;
                        break;
                    }else{
                        m[k][i]=*iter;
                        vec.erase(iter);
                    }
                }
                vector<ll>::iterator iter=find(vec.begin(),vec.end(),a[i]*a[i]);
                if(iter==vec.end()){
                    yes=false;
                    break;
                }else{
                    m[i][i]=*iter;
                    vec.erase(iter);
                }
            }
            if(!yes){
                break;
            }
        }
        /*for(int i=0;i<s;++i){
            cout<<a[i]<<" ";
        }
        cout<<endl<<endl;
        for(int i=0;i<s;++i){
            for(int j=0;j<s;++j){
                cout<<m[i][j]<<" ";
            }
            cout<<endl;
        }*/
        if(yes&&vec.empty()){
            cout<<"Yes"<<endl;
            for(int i=0;i<s;++i){
                cout<<a[i]<<" ";
            }
            cout<<endl;
        }else{
            cout<<"No"<<endl;
        }

    }


return 0;
}
//16 16 24 24 36 16 16 24 24 36 24 24 36 36 54 24 24 36 36 54 36 36 54 54 81


