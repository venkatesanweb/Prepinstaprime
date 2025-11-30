#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    getline(cin,s);
    stringstream ss(s);
    int x;
    vector<int> vc;
    while (ss>>x)
    {
        vc.push_back(x);
    }
    sort(vc.begin(),vc.end());
    int min=vc[0];
    int max=vc[vc.size()-1];
    int val=gcd(min,max);
    cout<<val;
    // while (min!=0)
    // {
    //     int temp=min;
    //     min=max%min;
    //     max=temp;
    // }
    // cout<<max;

}

