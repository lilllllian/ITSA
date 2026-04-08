#include <iostream>
using namespace std;

int main(){
    int N;

    while(cin >> N && N != -1){
        int count = 0;
        
        for(int i = 1; i <= N; i++){
            count = count + i*i;
        }
        cout << count << endl;
    } 

    return 0;
}