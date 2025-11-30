#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    int k;
    cin>>s;
    cin>>k;
    while (s.length()>k)
    {
        string str="";
        for (int i=0;i<s.length();i+=k)
        {
            string sub;
            if (i+k<=s.length())
            {
                sub=s.substr(i,k);
            }
            else
            {
                sub=s.substr(i);
            }
            int sum=0;
            for (char ch:sub)
            {
                sum+=(ch-'0');
            }
            str+=to_string(sum);
        }
        s=str;
    }
    cout<<s;
    return 0;
}

