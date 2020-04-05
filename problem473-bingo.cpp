#include<bits/stdc++.h>

using namespace std;
int m[50][50];
bool check[50][50];
void mClear(){
    for(int i=0;i<50;++i){
        for(int j=0;j<50;++j){
            m[i][j]=0;
            check[i][j]=0;
        }
    }
}
int main(){
    //fstream file;
    //file.open("output.txt",ios::out);
    string s;
    mClear();
    int row=0;
    while(getline(cin,s)){
        vector<int> vec;
        if(s[0]=='+'){
            continue;
        }else if(s[0]=='|'){
            if(s[1]==' '){
                mClear();
                row=0;
                continue;
            }else{
                string temp="";
                for(int i=1;i<s.size();++i){
                    if(s[i]=='|'){
                        stringstream ss;
                        int t;
                        ss<<temp;
                        ss>>t;
                        vec.push_back(t);
                        temp.clear();
                    }else{
                        temp+=s[i];
                    }
                }
                for(int i=0;i<vec.size();++i){
                    m[row][i]=vec[i];
                }
                row++;
            }
        }else{
            stringstream ss;
            int t;
            ss<<s;
            ss>>t;
            bool a=false;
            for(int i=0;i<row;++i){
                for(int j=0;j<row;++j){
                    if(m[i][j]==t){
                        check[i][j]=1;
                        a=true;
                        break;
                    }
                }
            }
            if(!a){
                continue;
            }
            /*for(int i=0;i<row;++i){
                for(int j=0;j<row;++j){
                    cout<<check[i][j]<<" ";
                }
                cout<<endl;
            }
            cout<<endl;*/

            int ans_row=0;
            int ans_col=0;
            for(int i=0;i<row;++i){
                bool f=true;
                for(int j=0;j<row;++j){
                    if(check[i][j]==0){
                        f=false;
                        break;
                    }
                }
                if(f){
                    ans_row++;
                }
            }
            for(int i=0;i<row;++i){
                bool f=true;
                for(int j=0;j<row;++j){
                    if(check[j][i]==0){
                        f=false;
                        break;
                    }
                }
                if(f){
                    ans_col++;
                }
            }
            cout<<ans_row<<" "<<ans_col<<endl;
            //file<<ans_row<<" "<<ans_col<<endl;
        }


    }





return 0;
}
