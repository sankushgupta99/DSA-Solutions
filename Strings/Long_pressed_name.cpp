class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int i = 0; 
        int j = 0;
        int name_len = name.length();
        int typed_len = typed.length();
        while(i < name_len || j < typed_len){
            if(j == typed_len)
                return false;
            else if(i < name_len && name[i] == typed[j]){
                i++;
                j++;
            }
            else if(j != 0 && typed[j] == typed[j-1]){
                j++;
            }
            else
                return false;
        }
        return true;
    }
};

//OR

class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int i = 1;
        int j = 1;
        int count = 0;
        int name_len = name.length();
        int typed_len = typed.length();
        while(i < name_len && j < typed_len){
            while(i < name_len && name[i] == name[i-1]){
                count++;
                i++;
            }
            while(j < typed_len && typed[j] == typed[j-1]){
                count--;
                j++;
            }
            if(count > 0 || (name[i-1] != typed[j-1]))
                return false;
            if(i < name_len && j < typed_len){
                count = 0;
                i++;
                j++;
            }
        }
        if(count > 0 || (name[i-1] != typed[j-1]) || i != name_len)
                return false;
        while(j < typed_len){
            if(typed[j] != typed[j-1])
                return false;
            j++;
        }
        return true;
    }
};