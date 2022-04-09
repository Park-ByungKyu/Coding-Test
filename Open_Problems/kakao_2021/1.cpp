#include <string>
#include <vector>

using namespace std;

string solution(string new_id) {
    string answer = new_id;
    for (int i = 0; i < answer.size(); i++) {
        if (answer[i] >= 'A' && answer[i] <= 'Z') {
            answer[i] = answer[i]-'A'+'a';
        } 
    }
    for (int i = 0; i < answer.size(); i++) {
        if ((answer[i] >= 'a' && answer[i] <= 'z') || (answer[i]>='0'&&answer[i]<='9') || answer[i]=='-'||answer[i]=='_'||answer[i]=='.') {} 
        else {
            answer.erase(answer.begin()+i, answer.begin()+i+1);
            i--;
        }
    }
    for (int i = 0; i < answer.size()-1; i++) {
        if (answer[i]=='.' && answer[i+1]=='.') {
            answer.erase(answer.begin()+i, answer.begin()+i+1);
            i--;
        }
    }
    if (answer[0] == '.') answer.erase (answer.begin(), answer.begin()+1);
    if (answer[answer.size()-1] == '.') answer.pop_back();
    
    if (answer.size() == 0) answer.push_back('a');
    if (answer.size() >= 16) {
        for (int i = 15; i < answer.size(); i++) {
            answer.erase(answer.begin()+i, answer.begin()+i+1);
            i--;
        }
    }
    if (answer[answer.size()-1] == '.') answer.pop_back();
    if (answer.size() == 1) {
        answer.push_back(answer[0]);
    }
    if (answer.size() == 2) {
        answer.push_back(answer[1]);
    }
    return answer;
}
