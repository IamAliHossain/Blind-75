#include<bits/stdc++.h>
using namespace std;


int main(){
    int n; cin >> n;
    
    // Left Triangle 
    cout << "Left Triangle\n";
    for(int i=1; i<=n; i++){
        for(int j=1; j<=i; j++){
            cout << j << ' ';
        }
        for(int k=i; k<=n; k++){
            cout << "  ";
        }cout << endl;
    }

    cout << "\nRight Triangle\n";
    for(int i=1; i<=n; i++){
        // right-triangle er jonno 1st inner loop e 2ta kore space hobe
        for(int j=1; j<=n-i; j++){
            cout << "  ";
        }
        // right-triangle er jonno loop e 1ta kore space hobe
        for(int k=1; k<=i; k++){
            cout << k << ' ';
        }cout << endl;
    }
    cout << "\nCenter Aligned\n";
    // center-aligned korte hoile just 1st inner loop er 2ta space na diye 1ta dite hobe
    for(int i=1; i<=n; i++){
        // center-aligned er jonno 1st inner loop e 1ta kore space hobe
        for(int j=1; j<=n-i; j++){
            cout << " ";
        }
        for(int k=1; k<=i; k++){
            cout << k << ' ';
        }cout << endl;
    }
}