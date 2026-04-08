#include <iostream>
using namespace std;

int main(){
    int N;
    cin >> N;
    while(N--){
        int code;
        cin >> code;

        if(code < 1000 || code > 9999){
            cout << "Failure Input" << endl;
        }

        if(code >= 1000 && code <= 9999){
            int next_code = code;
            int count[10] = {0};  // count[0] ~ count[9]：存放 0 ~ 9

            while(next_code > 0){
                int x = next_code % 10;
                count[x]++;
                next_code = next_code / 10;
            }

            int one = 0;  // one：計算出現一次的數字
            int two = 0;  // two：計算出現兩次的數字

            // scan整個count陣列
            for(int i = 0; i < 10; i++){
                if(count[i] == 2) two++;
                if(count[i] == 1) one++;
            }

            if(two == 1 && one == 2){
                cout << "Yes" << endl;
            } else {
                cout << "No" << endl;
            }
        }
    }
    return 0;
}