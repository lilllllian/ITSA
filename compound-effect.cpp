#include <iostream>

using namespace std;

int main() {
    long double R;
    int N;
    long long P;
    
    //只有一組測資：cin >> R >> N >> P;
    if(!(cin >> R)) return 0;
    cin >> N >> P;

    long double balance = 0.0L;
    for(int i = 0; i < N; i++){
        balance = balance + (long double)P; // 月初先存入Ｐ
        balance = balance * (1.0L + R); // 整筆金額加利息（月利率R）
    }
    
    //無條件捨去（對正數，直接轉為 long long 即為捨去小數）
    //long long ≈ 10^18, unsigned long long ≈ 10^20
    long long result = (long long) balance;
    cout << result << '\n';
    
    return 0;
}
