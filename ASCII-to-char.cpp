#include <iostream>
using namespace std;

int main(){
    int n;
    while(cin >> n){
        char c = n;  // 直接將整數 n 轉換為對應的字符
        cout << c << endl;
    }
    return 0;
}