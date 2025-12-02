#include<iostream>
#include<vector>
#include<string>
using namespace std;
bool check(string &n, string &m,int i) {
    if (i + m.length() > n.length()) return false; 
    int j=0;
    
    for (int j = 0; j < m.length(); j++) {
        if (n[i + j] != m[j]) return false;
    }
    return true;
}
int main(int argc, char const *argv[])
{
    string n,m;
    cin>>n>>m;

    int cnt=0;
    for(int i=0;i<n.length();i++){
        if(n[i]==m[0] && check(n,m,i)){
            cnt++;
        }
    }
    cout<<cnt;

    return 0;
}
