#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Disjoint{
public:
    vector<int> parent,size;
    Disjoint(int n) {
        parent.resize(n);
        size.assign(n, 1);
        for (int i = 1; i < n; i++)
            parent[i] = i;
    }

    int UPar(int node){
        if(parent[node] == node)return node;
        return parent[node]=UPar(parent[node]);
    }

    void Union(int u, int v) {
        int ulp_U=UPar(u);
        int ulp_V=UPar(v);
        if(ulp_U == ulp_V)return;
        if(size[ulp_U]<size[ulp_V]){
            parent[ulp_U]=ulp_V;
            size[ulp_V]+=size[ulp_U];
        }else{
            parent[ulp_V]=ulp_U;
            size[ulp_U]+=size[ulp_V];
        }
    }

};


int main(){

    int n,m;
    cin>>n>>m;

    vector<pair<int,int>>edges(m);
    for(int i = 0; i < m; i++) 
        cin >> edges[i].first >> edges[i].second;

    Disjoint ds(n+1);

    for(int i=0;i<m;i++) {
        int A=edges[i].first,B=edges[i].second;
        ds.Union(A,B);
    }
    int cnt=0;vector<int>ans;
    for(int i=1;i<=n;i++){
        if(ds.parent[i] == i){
            cnt++;
            ans.push_back(i);
        }
            
    }
    cout<<cnt-1<<endl;
    if(cnt>1)
        for(int j=1;j<ans.size();j++){
            cout<<ans[0]<<" "<<ans[j]<<endl;
        }
    
    return 0;
}