#include<iostream>
#include<vector>
#include<string>
using namespace std;

void dfs(int i,int j,vector<vector<int>>&visit,vector<vector<char>>&arr){
    if(j<0 || j>=arr[0].size() || i<0 || i>=arr.size() || visit[i][j]==1 || arr[i][j]=='#') {
        return;
    }
    visit[i][j]=1;
    dfs(i+1,j,visit,arr);
    dfs(i-1,j,visit,arr);
    dfs(i,j+1,visit,arr);
    dfs(i,j-1,visit,arr);

}

int main(int argc, char const *argv[])
{
    int n,m;
    cin>>n>>m;
    vector<vector<char>>arr(n,vector<char>(m));
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cin>>arr[i][j];
        }
    }

    vector<vector<int>>visit(n,vector<int>(m,0));
    int cnt=0;

    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(visit[i][j]==0 && arr[i][j]=='.') {
                dfs(i,j,visit,arr);
                cnt++;
            }
        }
    }

    cout<<cnt<<endl;

    return 0;
}
