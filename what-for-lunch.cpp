#include <iostream>
using namespace std;

int main(){
    int N, T;
    cin >> N >> T;

    int count[1000] = {0};  // 請初始化！！！！

    while(N--){
        int no;
        cin >> no;
        
        count[no]++;
    }

    for(int i = 0; i < 1000; i++){
        if(count[i] >= T){
            cout << i << "," << count[i] << endl;
        }
    }

    return 0;
}