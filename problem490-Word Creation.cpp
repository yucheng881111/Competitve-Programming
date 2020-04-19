#include<bits/stdc++.h>

using namespace std;
bool w[100][26];
bool used[100][26];
map<string,bool> M;
int n,m;
bool success=false;
string ans;
void dfs(int i,vector<char>& vec){
    if(success){
        return ;
    }
    if(i==m){
        string s="";
        for(int j=0;j<m;++j){
            s+=vec[j];
        }
        if(M[s]==0){
            success=true;
            ans=s;
        }
        return ;
    }

    for(int j=0;j<26;++j){
        if(w[i][j]&&!used[i][j]){
            used[i][j]=1;
            vec.push_back(j+97);
            dfs(i+1,vec);
            vec.pop_back();
            used[i][j]=0;
        }
    }



}

int main(){
    cin>>n>>m;
    string s;
    memset(w,0,sizeof(w));
    memset(used,0,sizeof(used));
    for(int i=0;i<n;++i){
        cin>>s;
        M[s]=1;
        for(int j=0;j<m;++j){
            w[j][s[j]-97]=1;
        }
    }

    vector<char> vec;
    dfs(0,vec);
    if(!success){
        cout<<"-1";
    }else{
        cout<<ans;
    }





return 0;
}
