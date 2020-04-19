#include<bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    vector<priority_queue<int,vector<int>,greater<int>>*> q(n+1);
    for(int i=1;i<=n;i++){
        q[i]=new priority_queue<int,vector<int>,greater<int>>();
    }
    while(m--){
        string s;
        cin>>s;
        if(s=="insert"){
            int i,x;
            cin>>i>>x;
            q[i]->push(x);
        }else if(s=="join"){
            int i,j;
            cin>>i>>j;
            if(q[j]->size()>q[i]->size()){
                swap(q[i],q[j]);
            }
            while(!q[j]->empty()){
                q[i]->push(q[j]->top());
                q[j]->pop();
            }
        }else if(s=="extract"){
            int i;
            cin>>i;
            if(q[i]->empty()){
                cout<<"NULL"<<endl;
            }else{
                cout<<q[i]->top()<<endl;
                q[i]->pop();
            }
        }else if(s=="lookup"){
            int i;
            cin>>i;
            if(q[i]->empty()){
                cout<<"NULL"<<endl;
            }else{
                cout<<q[i]->top()<<endl;
            }
        }
    }


return 0;
}
