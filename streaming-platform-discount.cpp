#include <iostream>
#include <iomanip>

using namespace std;

int main(){
    int minutes;
    const double fee_per_min = 0.9;
    double amount_due = 0.0;
    
    cin >> minutes;
    
    if(minutes <= 800) amount_due = minutes * fee_per_min;
    else if(minutes > 800 && minutes < 1500) amount_due = minutes * fee_per_min * 0.9;
    else amount_due = minutes * fee_per_min * 0.79;
    
    cout << fixed << setprecision(1) << amount_due << '\n';
    
    return 0;
}
