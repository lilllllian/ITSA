#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int main() {
    int k;
    if(!(cin >> k)) return 0;
    
    vector<int> a(k);
    for(int i = 0; i < k; i++){
        cin >> a[i];
    }
    
    int s1 = 0, s2 = 0;
    
    for(int i = k - 1; i > 0; i--){
        if(s1 > s2){
            s2 += a[i];
        }
        if(s1 <= s2){
            s1 += a[i];
        }
    }
    
    cout << abs(s1 - s2) << endl;
    return 0;
}
