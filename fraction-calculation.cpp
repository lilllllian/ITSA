#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <algorithm>
#include <numeric>

using namespace std;

// 求最大公因數
int gcd(int a, int b){
    return b == 0 ? a : gcd(b, a % b);
}

int main() {
    int n;
    cin >> n;
    cin.ignore(); // 忽略換行符號
    
    while(n--){
        string line;
        getline(cin, line);
        
        // 拆成兩個分數
        stringstream ss(line); // 建立一個可從字串中逐步讀資料的「文字輸入串流」
        string s1, s2;
        getline(ss, s1, ',');
        getline(ss, s2);
        
        int a, b, c, d; // a：第一個分數的分子, b：第一個分數的分母, c：第二個分數的分子, d：第二個分數的分母
        sscanf(s1.c_str(), "%d/%d", &a, &b); // 把 string 轉成 C-style 字串(const char*)，以便 sscanf() 使用
        sscanf(s2.c_str(), "%d/%d", &c, &d);
        
        // 加法：a/b + c/d = (ad + bc) / bd
        int num = a * d + b * c;
        int den = b * d;
        int g = gcd(abs(num), abs(den));
        cout << num / g << "/" << den / g << "\n";
        
        // 減法：a/b - c/d = (ad - bc) / bd
        num = a * d - b * c;
        den = b * d;
        g = gcd(abs(num), abs(den));
        cout << num / g << "/" << den / g << "\n";
        
        // 乘法：a/b * c/d = ac/bd
        num = a * c;
        den = b * d;
        g = gcd(abs(num), abs(den));
        cout << num / g << "/" << den / g << "\n";
        
        // 除法：(a/b) / (c/d) = (a/b) * (d/c) = ad/bc
        num = a * d;
        den = b * c;
        g = gcd(abs(num), abs(den));
        cout << num / g << "/" << den / g << "\n";
    }
    return 0;
}
