// 用 map<int, int> 來統計每個單位出現次數
/* map 是一種「關聯式容器」，會自動根據key排序(預設從小到大)*/

#include <iostream>
#include <map>

using namespace std;

int main() {
    int N;
    scanf("%d", &N);
    //建立一個 C++ STL 的對應容器(map)，用來儲存<key, value>形式的資料
    map<int, int> count;
    
    for(int i = 0; i < N; ++i){
        int x; // x 代表這份文件要送去的單位編號
        scanf("%d", &x);
        count[x]++;
    }
    
    cout << count.size() << "\n"; //輸出不同單位的數量

    for(auto &p : count){
        cout << p.first << ": " << p.second << "\n";
        //p.first -> key(單位), p.second -> value(收到幾份)
    }
    //count 是一個 map<int, int>
    //每次迴圈會從count中取出一個「元素(pair)」
    //這個元素型態是 pair<const int, int>
    
    return 0;
}

//auto p : count -> 複製每一對資料，效率略低
//auto &p : count -> 參照方式，不會複製資料，節省記憶體與時間
//const auto &p : count -> 不允許修改內容，只是輸出較安全
