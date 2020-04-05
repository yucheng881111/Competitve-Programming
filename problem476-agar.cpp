#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
int main(){
    string s;
    char c;
    vector<ll> vec;
    while(c=getchar()){
        if(c==EOF){
            break;
        }
        if(isdigit(c)){
            s+=c;
            continue;
        }else if(c==' '){
            stringstream ss;
            ss<<s;
            ll i;
            ss>>i;
            vec.push_back(i);
            s.clear();
            continue;
        }else{
            stringstream ss;
            ss<<s;
            ll i;
            ss>>i;
            vec.push_back(i);
            s.clear();
        }

        vector<ll>::iterator it_max=max_element(vec.begin(),vec.end());
        vector<ll>::iterator it_min=min_element(vec.begin(),vec.end());
        ll up_bound=*it_max;
        ll low_bound=1;
        while(1){
            ll middle;
            if((low_bound+up_bound)%2==0){
                middle=(low_bound+up_bound)/2;
            }else{
                middle=(low_bound+up_bound)/2+1;
            }
            if(middle==up_bound){
                break;
            }
            ll temp=middle;
            bool success=true;
            for(int i=0;i<vec.size();++i){
                if(temp>vec[i]){
                    if(vec[i]%2!=0){
                        temp+=vec[i]/2+1;
                    }else{
                        temp+=vec[i]/2;
                    }
                }else if(temp<vec[i]){
                    temp/=2;
                }
                if(temp==0){
                    success=false;
                    break;
                }
            }
            if(!success){
                low_bound=middle;
            }else{
                up_bound=middle;
            }
        }
        cout<<up_bound<<endl;
        vec.clear();
    }





return 0;
}
