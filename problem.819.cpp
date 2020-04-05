#include<bits/stdc++.h>

using namespace std;

int main(){
    //stringstream ss;
    string s="";
    string ans="";
    char c;
    while(c=getchar()){
        if(c!=' '&&c!='\n'){
            s+=c;
            continue;
        }
        string t;
        if(c==' '||c=='\n'){
            t=s;
            s="";
        }


        //while(ss>>t){
            if(ans==""){
               ans=t;
                continue;
            }
            string temp="";
            string a="";
            if(ans.size()>t.size()){
                for(int i=0;i<ans.size()-t.size();++i){
                    temp+="0";
                }
                temp+=t;
                bool in=false;
                for(int i=ans.size()-1;i>=0;i--){
                    int tmp=ans[i]-'0'+temp[i]-'0';
                    if(in){
                        tmp++;
                    }
                    if(tmp>=10){
                        in=true;
                        tmp-=10;
                    }else{
                        in=false;
                    }
                    a+=to_string(tmp);
                }
                if(in){
                    a+="1";
                }
                ans="";
                for(int i=a.size()-1;i>=0;i--){
                    ans+=a[i];
                }
            }else{
                for(int i=0;i<t.size()-ans.size();++i){
                    temp+="0";
                }
                temp+=ans;
                bool in=false;
                for(int i=temp.size()-1;i>=0;i--){
                    int tmp=temp[i]-'0'+t[i]-'0';
                    if(in){
                        tmp++;
                    }
                    if(tmp>=10){
                        in=true;
                        tmp-=10;
                    }else{
                        in=false;
                    }
                    a+=to_string(tmp);
                }
                if(in){
                    a+="1";
                }
                ans="";
                for(int i=a.size()-1;i>=0;i--){
                    ans+=a[i];
                }

            }

        //}
        //cout<<ans<<endl;
        if(c=='\n'){
            cout<<ans<<endl;
            ans="";
        }

    }





return 0;
}
