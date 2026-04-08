#include <iostream>
#include <vector>
using namespace std;

int main(){
    int N, M;
    cin >> N >> M;
    string first, second;
    cin >> first >> second;

    vector<vector<int>> dp(N + 1, vector<int>(M + 1, 0));

    for(int i = 1; i <= N; ++i){
        for(int j = 1; j <= M; ++j){
            if(first[i - 1] == second[j - 1]){
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }    

    cout << dp[N][M] << endl;
    return 0;
}