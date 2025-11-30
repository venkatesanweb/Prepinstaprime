
#include <iostream>
using namespace std;
int main() {
    int n,k;
    cin>>n>>k;
    string s="0";
    for(int i=2;i<=n;i++){
        string nex="";
        for(char c:s){
            if(c=='0') nex+="01";
            else nex+="10";
        }
        s=nex;
    }
    cout<<s[k-1];

    return 0;
}
