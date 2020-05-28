#include<bits/stdc++.h>

using namespace std;

string convert(long long t){
    bitset<50> b(t);
    string s="";
    for(int i=48;i>=0;i-=2){
        int tmp=b[i+1]*2+b[i];
        if(tmp==0){
            s+='W';
        }else if(tmp==1){
            s+='Y';
        }else if(tmp==2){
            s+='P';
        }else{
            s+='B';
        }
    }
    return s;
}

long long convert_int(string s){
    string t="";
    for(int i=0;i<25;++i){
        if(s[i]=='W'){
            t+="00";
        }else if(s[i]=='Y'){
            t+="01";
        }else if(s[i]=='P'){
            t+="10";
        }else{
            t+="11";
        }
    }
    bitset<50> b(t);
    return b.to_ullong();
}

char board[5][5];
unordered_map<long long,bool> ms; //start to finish
unordered_map<long long,bool> mf; //finish to start
queue<long long> qs; //start to finish
queue<long long> qf; //finish to start
int step=1;

void solve(){

    while(1){
        // queue start to finish
        int qs_size=qs.size();
        for(int i=0;i<qs_size;++i){
            long long t=qs.front();
            string temp=convert(t);
            qs.pop();
            int p=0;
            int wi,wj;
            for(int k=0;k<5;++k){
                for(int l=0;l<5;++l){
                    board[k][l]=temp[p];
                    if(temp[p]=='W'){
                        wi=k;
                        wj=l;
                    }
                    p++;
                }
            }
            for(int i=0;i<5;++i){
                for(int j=0;j<5;++j){
                    if((abs(wi-i)==1&&abs(wj-j)==2)||(abs(wi-i)==2&&abs(wj-j)==1)){
                        swap(board[i][j],board[wi][wj]);
                        string b_swap="";
                        for(int k=0;k<5;++k){
                            for(int l=0;l<5;++l){
                                b_swap+=board[k][l];
                            }
                        }
                        long long convert_swap=convert_int(b_swap);
                        if(mf[convert_swap]==1){
                            return ;
                        }
                        if(ms[convert_swap]==0){
                            qs.push(convert_swap);
                            ms[convert_swap]=1;
                        }
                        swap(board[i][j],board[wi][wj]);
                    }
                }
            }

        }
        if(step==20){
            return ;
        }
        step++;

        int qf_size=qf.size();
        for(int i=0;i<qf_size;++i){
            long long t=qf.front();
            string temp=convert(t);
            qf.pop();
            int p=0;
            int wi,wj;
            for(int k=0;k<5;++k){
                for(int l=0;l<5;++l){
                    board[k][l]=temp[p];
                    if(temp[p]=='W'){
                        wi=k;
                        wj=l;
                    }
                    p++;
                }
            }
            for(int i=0;i<5;++i){
                for(int j=0;j<5;++j){
                    if((abs(wi-i)==1&&abs(wj-j)==2)||(abs(wi-i)==2&&abs(wj-j)==1)){
                        swap(board[i][j],board[wi][wj]);
                        string b_swap="";
                        for(int k=0;k<5;++k){
                            for(int l=0;l<5;++l){
                                b_swap+=board[k][l];
                            }
                        }
                        long long convert_swap=convert_int(b_swap);
                        if(ms[convert_swap]==1){
                            return ;
                        }
                        if(mf[convert_swap]==0){
                            qf.push(convert_swap);
                            mf[convert_swap]=1;
                        }
                        swap(board[i][j],board[wi][wj]);
                    }
                }
            }

        }
        step++;

    }

}

void clear_q(queue<long long> &q){
    queue<long long> e;
    swap(q,e);
}

int main(){
    int n;
    cin>>n;
    while(n--){
        ms.clear();mf.clear();clear_q(qs);clear_q(qf);
        step=1;
        string start="";
        string finish="";
        char c;
        for(int i=0;i<5;++i){
            for(int j=0;j<5;++j){
                cin>>c;
                start+=c;
            }
        }
        for(int i=0;i<5;++i){
            for(int j=0;j<5;++j){
                cin>>c;
                finish+=c;
            }
        }

        long long start_state=convert_int(start);
        long long finish_state=convert_int(finish);
        ms[start_state]=1;
        mf[finish_state]=1;
        if(start_state==finish_state){
            cout<<"0"<<endl;
            continue;
        }
        qs.push(start_state);
        qf.push(finish_state);
        solve();
        cout<<step<<endl;
    }





return 0;
}
