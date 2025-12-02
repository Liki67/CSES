#include<iostream>
#include<vector>
#include<string>
#include<algorithm> 
#include<cmath>
#include<climits>
#include<set>
using namespace std;

/*int main(int argc, char const *argv[])
{
    int x,n;
    cin>>x>>n;

    
    vector<int>arr;
    arr.push_back(0);
    arr.push_back(x);
    
    vector<int>res;

    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        int ans=0;
        arr.push_back(a);
        sort(arr.begin(),arr.end());
        for(int i=1;i<arr.size();i++){
            ans=max(ans,abs(arr[i]-arr[i-1]));
        }
        res.push_back(ans);
    }

    for(int i=0;i<n;i++)
        cout<<res[i]<<" ";
    cout<<endl;

    return 0;
}
*/
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int x, n;
    cin >> x >> n;

    set<int> pos;
    pos.insert(0);
    pos.insert(x);

    multiset<int> lengths;
    lengths.insert(x);

    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;

        auto it = pos.lower_bound(a);
        int r = *it;
        int l = *prev(it);

        lengths.erase(lengths.find(r - l));
        lengths.insert(a - l);
        lengths.insert(r - a);

        pos.insert(a);

        cout << *lengths.rbegin() << " ";
    }

    return 0;
}