// Step1. 讀取景點資料
// Step2. 讀取查詢
// Step3. 解析查詢
// Step4. 檢查每個景點

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

int getIndex(string s){
    if(s == "MT") return 0;
    if(s == "BE") return 1;
    if(s == "CU") return 2;
    if(s == "NP") return 3;
    if(s == "UR") return 4;
    if(s == "WD") return 5;
    if(s == "LA") return 6;
    return -1;
}

int main(){
    // number of attractions
    int n;
    cin >> n;
    cin.ignore();

    vector<string> name(n);
    bool att[10][7] = {0};

    // 讀取景點資料
    for(int i = 0; i < n; i++){

        cin >> name[i];

        string line;
        getline(cin, line);

        stringstream ss(line);
        string code;
        
        while(ss >> code){ 
            int id = getIndex(code);  // 找到屬性編號
            if(id != -1){
                att[i][id] = true;  //把景點屬性標記起來
            }
        }
    }

    // 讀取查詢
    // number of searching for
    int m;
    cin >> m;
    cin.ignore();

    while(m--){
        string q;
        getline(cin, q);

        string tmp = "";
        for(char c : q) if(c != ' ') tmp += c;
        q = tmp;

        vector<string> group;  // 存放每個 OR 條件
        string t = "";  // 暫存字串

        // 解析查詢
        for(char c : q){
            if(c == '+'){
                group.push_back(t);
                t = "";
            } else {
                t += c;
            } 
        }

        group.push_back(t);  // group will be like {"MTBE", "NPLA"}

        bool found = false;  // found：用來判斷是否找到至少一個符合調減的景點

        // 檢查每個景點
        for(int i = 0; i < n; i++){
            bool ok = false;  // 判斷該景點是否符合條件
            for(string g : group){
                bool all = true;  // 假設所有屬性都符合

                for(int j = 0; j < g.size(); j+= 2){  // 每個屬性 ＝ 2個字母
                    string code = g.substr(j,2);
                    int id = getIndex(code);

                    // 檢查該景點是否有此屬性
                    if(!att[i][id]){
                        all = false;
                        break;
                    }
                }

                // 如果 AND 條件成立
                if(all){
                    ok = true;
                    break;
                }
            }

            if(ok){
                    if(found) cout << " ";
                    cout << name[i];
                    found = true;
            }
        }

        if(!found) cout << "None";

        cout << endl;
    }

    return 0;
}