//中序表達式：運算子在兩運算元中間 -> (1 + 3) * 2
//後序表達式：運算子在運算元後 -> 1 3 + 2 *

#include <iostream>
#include <string>
#include <array>
#include <cctype>  //isspace, isalpha, isupper, islower
#include <limits>
using namespace std;

int main() {
    int n;
    if(!(cin >> n)) return 0;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
    while(n--){
        string text;
        getline(cin, text);
        
        // 1) 計算句子數（. ! ? 視為句點）
        int dot_cnt = 0;
        bool has_nonspace = false;
        for(unsigned char ch : text){
            if(!isspace(ch)) has_nonspace = true;
            if(ch == '.') ++dot_cnt;
        }

        // 2) 計算單字數（連續的非空白視為一個字）
        int word_cnt = 0;
        bool in_word = false;
        for(unsigned char uch : text){
            if(!isspace(uch)){
                if(!in_word){
                    ++word_cnt;
                    in_word = true;
                }
            }
            else{
                in_word = false;
            }
        }
        
        // 3) 計算字母出現字數（大寫、小寫分開）
        int arr[26][2] = {};
        for(unsigned char uch : text){
            if(uch >= 'A' && uch <= 'Z'){
                arr[uch - 'A'][0]++;
            } else if (uch >= 'a' && uch <= 'z'){
                arr[uch - 'a'][1]++;
            }
        }
        
        // Output
        cout << word_cnt << '\n';
        for(int i = 0; i < 26; ++i){
            if(arr[i][0] != 0) cout << char('A' + i) << " : " << arr[i][0] << '\n';
            if(arr[i][1] != 0) cout << char('a' + i) << " : " << arr[i][1] << '\n';
        }
    }
    return 0;
}
