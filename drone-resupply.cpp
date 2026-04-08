#include <iostream>
using namespace std;

int main(){
    int T;
    cin >> T;
    while(T--){
        int n, m, L;
        cin >> n >> m >> L;

        bool grid[21][21] = {false};  // 是否拿到補給

        for(int i = 0; i < L; i++){
            int x, y;
            cin >> x >> y;

            if(x >= 1 && x <= n && y >= 1 && y <= m) grid[x][y] = true;
            if(x + 1 <= n) grid[x + 1][y] = true;
            if(x - 1 >= 1) grid[x - 1][y] = true;
            if(y + 1 <= m) grid[x][y + 1] = true;
            if(y - 1 >= 1) grid[x][y - 1] = true;
        }

        bool ok = true;
        
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(!grid[i][j]) ok = false;  // 檢查是否有人沒拿到補給
            }
        }

        if(ok == true){
            cout << "Y" << endl;
        } else {
            cout << "N" << endl;
        }
    }
    return 0;
}