#include<bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m,x;
    cin>>n>>m;
    vector<int> vec(n);
    for(int i=0;i<n;++i){
        cin>>x;
        vec[i]=x;
    }
    bool e=true;
    if(m==0){
        vector<int> last=vec;
        reverse(last.begin(),last.end());
        next_permutation(vec.begin(),vec.end());
        if(last==vec){
            cout<<"hello world!"<<endl;
            return 0;
        }
    }
    for(int i=1;i<=m;++i){
        vector<int> last=vec;
        reverse(last.begin(),last.end());
        next_permutation(vec.begin(),vec.end());
        if(last==vec){
            if(e){
                cout<<"hello world!"<<endl;
            }
            break;
        }
        for(int i=0;i<n;++i){
            cout<<vec[i]<<" ";
        }
        e=false;
        cout<<endl;
    }





return 0;
}
