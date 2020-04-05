#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> A;
    vector<int> B;
    vector<int> C;
    while(n--){
        A.clear();
        B.clear();
        C.clear();
        int x;
        cin>>x;
        int d;
        char cc;
        vector<int>::iterator iter;
        for(int i=0;i<x;++i){
            if(scanf("%d%c",&d,&cc)==0){
                getchar();
                A.push_back(99);
            }else{
                iter=find(A.begin(),A.end(),d);
                if(iter!=A.end()){
                    A.erase(iter);
                }else{
                    A.push_back(d);
                }

            }
        }
        cin>>x;
        for(int i=0;i<x;++i){
            if(scanf("%d%c",&d,&cc)==0){
                getchar();
                B.push_back(99);
            }else{
                iter=find(B.begin(),B.end(),d);
                if(iter!=B.end()){
                    B.erase(iter);
                }else{
                    B.push_back(d);
                }
            }
        }
        cin>>x;
        for(int i=0;i<x;++i){
            if(scanf("%d%c",&d,&cc)==0){
                getchar();
                C.push_back(99);
            }else{
                iter=find(C.begin(),C.end(),d);
                if(iter!=C.end()){
                    C.erase(iter);
                }else{
                    C.push_back(d);
                }
            }
        }
        int ai,bi,ci;
        cin>>ai;
        int a[ai+1];
        for(int i=1;i<=ai;++i){
            cin>>a[i];
        }
        cin>>bi;
        int b[bi+1];
        for(int i=1;i<=bi;++i){
            cin>>b[i];
        }
        cin>>ci;
        int c[ci+1];
        for(int i=1;i<=ci;++i){
            cin>>c[i];
        }
        if(A.empty()||B.empty()||C.empty()){
            for(int i=0;i<A.size();++i){
                if(A[i]==99){
                    cout<<"Alice"<<endl;
                }
            }
            for(int i=0;i<B.size();++i){
                if(B[i]==99){
                    cout<<"Bob"<<endl;
                }
            }
            for(int i=0;i<C.size();++i){
                if(C[i]==99){
                    cout<<"Carol"<<endl;
                }
            }
            continue;
        }



        /*for(int i=0;i<A.size();++i){
            cout<<A[i]<<" ";
        }
        cout<<endl;
        for(int i=0;i<B.size();++i){
            cout<<B[i]<<" ";
        }
        cout<<endl;
        for(int i=0;i<C.size();++i){
            cout<<C[i]<<" ";
        }
        cout<<endl;*/

        int round=1;
        while(round<=100000){
            //1 draw 2
            int t=B.size();
            int k=(a[(round-1)%ai+1]+t-1)%t+1;
            iter=find(A.begin(),A.end(),B[k-1]);
            if(iter!=A.end()){
                A.erase(iter);
            }else{
                A.push_back(B[k-1]);
            }
            B.erase(B.begin()+k-1);
            if(A.empty()||B.empty()){
                break;
            }
            //2 draw 3
            t=C.size();
            k=(b[(round-1)%bi+1]+t-1)%t+1;
            iter=find(B.begin(),B.end(),C[k-1]);
            if(iter!=B.end()){
                B.erase(iter);
            }else{
                B.push_back(C[k-1]);
            }
            C.erase(C.begin()+k-1);
            if(B.empty()||C.empty()){
                break;
            }
            //3 draw 1
            t=A.size();
            k=(c[(round-1)%ci+1]+t-1)%t+1;
            iter=find(C.begin(),C.end(),A[k-1]);
            if(iter!=C.end()){
                C.erase(iter);
            }else{
                C.push_back(A[k-1]);
            }
            A.erase(A.begin()+k-1);
            if(C.empty()||A.empty()){
                break;
            }
            round++;
        }
        if(round>100000){
            cout<<"Good Game"<<endl;
        }else{
            for(int i=0;i<A.size();++i){
                if(A[i]==99){
                    cout<<"Alice"<<endl;
                }
            }
            for(int i=0;i<B.size();++i){
                if(B[i]==99){
                    cout<<"Bob"<<endl;
                }
            }
            for(int i=0;i<C.size();++i){
                if(C[i]==99){
                    cout<<"Carol"<<endl;
                }
            }

        }




    }





return 0;
}
