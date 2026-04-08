#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n;
    if(!(cin >> n)) return 0;
    for(int tc = 0; tc < n; ++tc){
        int m;
        long double X;
        cin >> m >> X;  // m：樓層數，X：1樓巡查時間
        
        long double total = 0.0L;
        for(int i = 1; i <= m; i++){
            long double raw = X * ((long double)(i + 1) / 2.0L);  // X * (i + 1) / 2
            if(i % 2 == 1) total += raw;  //odd floor -> full time
            else total += raw / 2.0L;  //even floor -> half time
        }
        
        // 自己做四捨五入到小數第二位
        long long cents = (long long) floor(total * 100.0L + 0.5L + 1e-12L);
        /* total * 100.0L：放大100倍（方便四捨五入到小數第2位）
           +0.5L：四捨五入的原理
           +1e-12L：防止浮點誤差造成邊界錯誤（e.x.,79.9999999 -> 79)
           floor(...)：取不大於輸入的最大整數 */
        
        //手動控制輸出格式 xx.yy
        long long integer_part = cents / 100;
        long long frac_part = llabs(cents % 100); // llabs()：避免負數情況
        cout << integer_part << ".";
        if(frac_part < 10) cout << '0';
        cout << frac_part << "\n";
    }
    return 0;
}
