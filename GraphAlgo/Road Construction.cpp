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
int main(int argc, char const *argv[])
{
    int n,m;
    cin>>n>>m;
    
    Disjoint ds(n+1);

    vector<vector<int>>edges(m,vector<int>(2));
    for(int i=0;i<m;i++) {
        cin>>edges[i][0] >> edges[i][1];
    }
    int size=1,cnt=n;
    for(int i = 0; i < m; i++) 
    {

        int a=edges[i][0],b=edges[i][1];
        if(ds.UPar(a)==ds.UPar(b)){
            cout<<cnt<<" "<<size<<endl;
        }else{
            ds.Union(a,b);
            size=max(size,ds.size[ds.UPar(a)]);
            cnt=cnt-1;
            cout<<cnt<<" "<<size<<endl;
        }
    }

    




    return 0;
}
