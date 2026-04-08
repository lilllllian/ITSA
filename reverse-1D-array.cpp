#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    
    // 動態分配陣列空間
    int* arr = new int[n];
 
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    for(int i = n - 1; i >= 0; i--){  // 注意要從 n-1 開始，到 0 結束
        cout << arr[i] << " ";  
    }

    cout << endl;

    // 釋放動態分配的記憶體
    delete[] arr;

    return 0;
}
