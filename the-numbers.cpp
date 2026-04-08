#include <iostream>
using namespace std;

int main(){
    string N, M;
    cin >> N >> M;

    int count = 0;

    // 遍歷字符串 M，目的是檢查 M 中每個長度為 N.length() 的子字符串
    for(size_t i = 0; i <= M.length() - N.length(); i++){

        // M.substr(i, N.length())：從 M 的位置 i 開始，取長度為 N.length() 的子字符串
        // 如果這個子字符串與 N 相等 -> 在 M 中從位置 i 開始的部分與 N 完全一致
        if(M.substr(i, N.length()) == N){ 
            count++;
        }
    }

    cout << count << endl;

    return 0;
}