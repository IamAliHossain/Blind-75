#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> arr = {1,4,2,5,3} ;
    int n = arr.size();
    vector<int> pref(n+1);
    pref[0] = 0;
    int ans = 0;

    for(int i=1; i<=n; i++){
        pref[i] = pref[i-1] + arr[i-1] ;
    }
    for(int i=0; i<n-2; i++){
        for(int j=i+1; j<=n; j+=2){
            ans += (pref[j] - pref[i]);
        }
    }
    // for(int i=1; i<n-2; i++){
    //     for(int j=1; j<n; j+=2){
    //         ans += (pref[j] - pref[i]);
    //     }
    // }
    for(auto u : pref){
        cout << u << ' ';
    }
    cout << endl;
    cout << ans << endl;
}