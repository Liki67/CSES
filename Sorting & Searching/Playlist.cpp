#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<unordered_set>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    unordered_set<int> st;
    st.reserve(n * 2);         
    st.max_load_factor(0.25);  

    
    int l = 0, ans = 0;

    for (int r = 0; r < n; r++) {
        while (st.count(arr[r])) {
            st.erase(arr[l]);
            l++;
        }
        st.insert(arr[r]);
        ans = max(ans, r - l + 1);
    }

    cout << ans;
}