#include<bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        vector<pair<int,int>> vec;
        for(int i=0;i<n;++i){
            int x,y;
            cin>>x>>y;
            pair<int,int> p(x,y);
            vec.push_back(p);
        }
        sort(vec.begin(),vec.end());
        /*for(int i=0;i<n;++i){
            cout<<vec[i].first<<" "<<vec[i].second<<endl;
        }*/
        vector<int> Search(n,INT_MAX);
        int L=0;
        for(int i=0;i<n;++i){
            int index=upper_bound(Search.begin(),Search.end(),vec[i].second)-Search.begin();
            //cout<<index<<endl;
            Search[index]=vec[i].second;
            if(index+1>L){
                L=index+1;
            }
        }
        cout<<L<<endl;
    }






return 0;
}
