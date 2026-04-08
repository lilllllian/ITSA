#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;

    int a[5];

    for(int i = 0; i < 5; i++){
        cin >> a[i];
    }

    bool have[14] = {false};  // 牌 1 ~ 13

    // 輸入朋友的牌
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 5; j++){
            int x;
            cin >> x;
            have[x] = true;
        }
    }

    int count = 0;

    for(int i = 0; i < 5; i++){
        // 如果朋友有出過同樣數字
        if(have[a[i]]) count++;
    }

    cout << count << endl;
    
    return 0;
}