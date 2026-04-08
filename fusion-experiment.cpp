// 1. 讀取input，記錄每種chem不能使用的粉末
// 2. 列舉排列：產生 4! = 24 種排列
/*      do {
            // 檢查這個排列
        } while(next_permutation(p, p+4));
*/  
// 3. 檢查排列是否違反 forbidden 條件
// 4. 如果此排列ok：輸出
// 5. 如果都!ok：輸出"No" 

#include <iostream>
#include <algorithm> //next_permutation
using namespace std;

int main() {
    int N;
    cin >> N;
    while(N--){
        bool forbid[4][5] = {false}; // 4種藥劑：A, B, C, D｜4種粉末：1, 2, 3, 4

        char chem;
        int no;

        for(int i = 0; i < 4; i++){
            cin >> chem;

            int index = chem - 'A';  // A -> 0, B -> 1, C -> 2, D -> 3

            while(cin >> no && no != 0){ 
                forbid[index][no] = true;
            }
        }

        int p[4] = {1, 2, 3, 4}; // p[0] ~ p[4]：A ~ D用的粉末

        bool found = false;

        // 列舉所有排列
        do { 
            bool ok = true;

            // 逐一檢查排列是否違反 forbidden 條件
            for(int i = 0; i < 4; i++){
                if(forbid[i][p[i]]){  
                    ok = false;
                    break;
                } 
            }

            // 如果這個排列合法
            if(ok){
                // 第一次找到解時才印 ABCD
                if(!found){
                    cout << "ABCD\n";
                }

                found = true;

                for(int i = 0; i < 4; i++){
                    cout << p[i];
                }
                cout << "\n";
            }

        } while (next_permutation(p, p+4)); // 產生下一個排列

        // 如果完全沒有找到合法解
        if(!found){
            cout << "No\n";
        }

        cout << "\n";
    }

    return 0;
    
}
