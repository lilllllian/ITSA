#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    int N;
    while(cin >> N){
        double best = 1e300;
        for(int i = 0; i < N; i++){
            int M, K;
            cin >> M >> K;
            double hours = (double) M / (K * 60.0);
            if(hours < best) best = hours;
        }
        
        // 四捨五入到小數點第一位
        // floor() : 取「不大於該數的整數」（無條件捨去）
        double rounded = floor(best * 10.0 + 0.5) / 10.0;
        cout << fixed << setprecision(1) << rounded << "\n";
    }
    return 0;
}
