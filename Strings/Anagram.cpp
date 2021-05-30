class Solution
{
    public:
    //Function is to check whether two strings are anagram of each other or not.
    bool isAnagram(string a, string b){
        map<char, int> freq;
        for(int i = 0; i < a.length(); i++){
            freq[a[i]]++;
        }
        
        for(int i = 0; i < b.length(); i++){
            if(freq[b[i]] == 0)
            return false;
            freq[b[i]]--;
        }
        return true;
    }

};