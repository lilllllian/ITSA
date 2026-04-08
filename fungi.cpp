#include <iostream>

using namespace std;

int main(){
    int N;
    cin >> N;
    while(N--){
        int V = 0, M;
        cin >> V >> M;
        
        long long age1 = V;
        long long age2 = 0;
        long long age3 = 0;
        
        for(int month = 1; month <= M; month++){
            long long total = age1 + age2 + age3;
            long long newborn = (total / 2) * 3; //繁殖
            
            age3 = age2;
            age2 = age1;
            age1 = newborn;
        }
        
        cout << (age1 + age2 + age3) << "\n";
        
    }
    
    return 0;
}
