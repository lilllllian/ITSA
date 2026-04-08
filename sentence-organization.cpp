/*1. 先讀入N
  2. 每筆測資中讀入三個字
  3. 根據主詞、受詞、動詞的排列組合成合法句型
  4. 若有多種合法組合（如主詞和受詞都可能是人名），印出所有合法句型，用"or"分隔。*/

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool isSubject(const string &w){
    return w == "I" || w == "He" || w == "She" || w == "They" || w == "Mary" || w == "John";
}

bool isVerb(const string &w){
    return w == "love" || w == "like" || w == "see" || w == "find";
}

bool isObject(const string &w){
    return w == "me" || w == "him" || w == "her" || w == "them" || w == "Mary" || w == "John";
}

string reflexiveOf(const string &subj){
    if (subj == "I") return "myself";
    if (subj == "He" || subj == "John") return "himself";
    if (subj == "She" || subj == "Mary") return "herself";
    if (subj == "They") return "themselves";
    return "";
}

string addS(const string &verb, const string &subj){
    if (subj == "He" || subj == "She" || subj == "Mary" || subj == "John"){
        if(verb.back() != 's') return verb + "s";
    }
    return verb;

}

int main() {
    int N;
    cin >> N;
    while(N--){
        string a, b, c;
        cin >> a >> b >> c;
        vector<string> words = {a, b, c};
        vector<string> results;
        
        sort(words.begin(), words.end());
        do{
            string subj = words[0], verb = words[1], obj = words[2];
            if(isSubject(subj) && isVerb(verb) && isObject(obj)){
                if((subj == "I" && obj == "me") ||
                    (subj == "He" && obj == "him") ||
                    (subj == "She" && obj == "her") ||
                    (subj == "They" && obj == "them") ||
                    ((subj == "Mary") && (obj == "Mary" || obj == "her")) ||
                    ((subj == "John") && (obj == "John" || obj == "him"))){
                        obj = reflexiveOf(subj);
                }
                results.push_back(subj + " " + addS(verb, subj) + " " + obj);
            }
        } while(next_permutation(words.begin(), words.end()));
        
        //移除重複的句子
        sort(results.begin(), results.end());
        results.erase(unique(results.begin(), results.end()), results.end());
        
        for(int i = 0; i < results.size(); ++i){
            if(i > 0) cout << " or ";
            cout << results[i];
        }
        cout << "\n";
    }
    return 0;
}
