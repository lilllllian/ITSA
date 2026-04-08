#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    int N;
    cin >> N;
    int product[26] = {};
    int total = 0;
    for(int i = 0; i < N; i++){
        char c;
        int num;
        cin >> c >> num;
        product[(int)(c - 'A')] += num;
        total += num;
    }
    
    for(int i = 0; i < 26; i++){
        if(product[i] != 0){
            printf("%c(%.2f)\n", (char)(i + 'A'), (float)product[i] / total);
            // (float)product[i] / total:
        }
    }
    return 0;
}
