class Solution {
public:
    map<string, bool> m1;
    bool isScramble(string s1, string s2) {
        if(s1.compare(s2) == 0){
            return true;
        }
        if(s1.length() <= 1){
            return false;
        }
        string key = s1;
        key.push_back(' ');
        key.append(s2);
        if(m1.find(key) != m1.end()){
            return m1[key];
        }
        int len = s1.length();
        bool flag = false;
        for(int k = 1; k < len; k++){
            if(isScramble(s1.substr(0, k), s2.substr(0,k)) == true && isScramble(s1.substr(k, len-k), s2.substr(k,len-k)) == true){
                flag = true;
                break;
            }
            if(isScramble(s1.substr(0, k), s2.substr(len-k,k)) == true && isScramble(s1.substr(k, len-k), s2.substr(0,len-k)) == true){
                flag = true;
                break;
            }
        }
        return m1[key] = flag;
    }
};