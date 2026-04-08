// using map<key, value>

#include <iostream> 
#include <string>
#include <map>

using namespace std;

int main() {

    map<string, int> p;

    p["O O O"] = 100;

    p["O A A"] = 50;
    p["O A O"] = 50;

    p["O S S"] = 50;
    p["O S O"] = 50;

    p["O AS A"] = 50;
    p["O AS S"] = 50;

    p["A A A"] = 75;
    p["A A O"] = 25;

    p["A S A"] = 25;
    p["A S S"] = 25;
    p["A S O"] = 25;
    p["A S AS"] = 25;

    p["A AS A"] = 50;
    p["A AS S"] = 25;
    p["A AS AS"] = 25;

    p["S S S"] = 75;
    p["S S O"] = 25;

    p["S AS A"] = 25;
    p["S AS S"] = 50;
    p["S AS AS"] = 25;

    p["AS AS A"] = 25;
    p["AS AS S"] = 25;
    p["AS AS AS"] = 50;

    int N;
    cin >> N;

    while(N--){
        string s1, s2, s3;
        cin >> s1 >> s2 >> s3;

        string key1 = s1 + " " + s2 + " " + s3;
        string key2 = s2 + " " + s1 + " " + s3;

        if(p.count(key1)){  // 問這個key裡有沒有存在
            printf("%d\n", p[key1]);
        } 
        else if(p.count(key2)){
            printf("%d\n", p[key2]);
        }
        else{
            printf("NO\n");
        }
    }
    return 0;
}