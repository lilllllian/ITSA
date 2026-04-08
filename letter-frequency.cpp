#include <iostream>
#include <sstream>
#include <map>
#include <vector>
#include <algorithm>
#include <cctype>
using namespace std;

int main() {
    int n;
    cin >> n;
    cin.ignore(); // 忽略換行符號
    
    for(int t = 0; t < n; t++){
        string line;
        getline(cin, line);
        
        // ----- 計算字數 -----
        stringstream ss(line);  // 把整行字串 line 放進 stringstream 物件 ss 中
        // stringstrem 是一種「可以像 cin 一樣讀取字串」的工具，根據空白(space、tab、換行)分割單字
        string word;  // word 用來暫時存放每次從 ss 讀出的單字
        int wordCount = 0;
        while(ss >> word){
            wordCount++;
        }
        cout << wordCount << endl;
        
        // ----- 計算字母出現次數 -----
        map<char, int> count;  // map會自動根據key的字典順序(A~Z, a~z)排序
        for (char c : line){
            if (isalpha(c)){  // 判斷這個字元是不是「英文字母」
                count[c]++;
            }
        }
        /* for (char c : line)：C++範圍式for迴圈(Range-based for loop)的寫法
           -> 用來「逐一取出容器或陣列裡的元素」*/

        // ----- 把出現過的字母放入vector -----
        vector<char> letters;
        for(auto &p : count)
            letters.push_back(p.first);
        
        // ----- 排序規則 -----
        sort(letters.begin(), letters.end(), [](char a, char b){
            if(tolower(a) ==  tolower(b))
                return (bool)isupper(a);
            return tolower(a) < tolower(b);
        });
        
        // ---- 輸出結果 -----
        for(char c : letters){
            cout << c << " : " << count[c] << endl;
        }
    }
    return 0;
}
