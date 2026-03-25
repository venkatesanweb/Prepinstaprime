
#include <bits/stdc++.h>
using namespace std;

int longseq(vector<int> vc){
    if(vc.size()==0) return 0;
    sort(vc.begin(),vc.end());
    int s=1;
    int maxi=1;
    for(int i=1;i<vc.size();i++){
        if(vc[i]==vc[i-1]) continue;
        if(vc[i]==(vc[i-1]+1)){
            s++;
        }
        else{
            s=1;
        }
        maxi=max(s,maxi);
    }
    return maxi;
}
int longseqopt(vector<int> vc){
    int curr=1;
    int maxi=1;
    unordered_set<int> st(vc.begin(),vc.end());
    for(int num : st){
        if(st.find(num-1)==st.end()){
            int curr=num;
            int s=1;
            while(st.find(curr+1)!=st.end()){
                s++;
                curr++;
            }
            maxi=max(maxi,s);
        }
    }
    return maxi;
}

int main() {
    int n;
    cin>>n;
    vector<int> vc(n);
    for(int i=0;i<n;i++){
        cin>>vc[i];
    }
    cout<<longseqopt(vc);
    return 0;
}
