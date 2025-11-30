#include <bits/stdc++.h>
using namespace std;

int main() {
    
    string s;
    getline(cin,s);
    stringstream ss(s);
    int x;
    vector<int> vc;
    set<int> st;
    while(ss>>x){
        vc.push_back(x);
    }
    for(int val:vc){
        st.insert(val);
    }
    int maxlen=0;
    for(int i=0;i<vc.size();i++){
        for(int j=i+1;j<vc.size();j++){
            int a=vc[i];
            int b=vc[j];
            int len=2;
            while(st.count(a+b)){
                int c=a+b;
                a=b;
                b=c;
                len++;
            }
            maxlen=max(len,maxlen);
        }
    }
    cout<<maxlen;
    
    

    return 0;
}

