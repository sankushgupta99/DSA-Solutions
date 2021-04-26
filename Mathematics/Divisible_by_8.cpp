class Solution{
    public:
    
    int isDivisible8(string S) {
        if(S.length() < 3)
        S += "00";
        
        int len = S.length();
        int flag = 0;
        for(int i = 0; i < len; i++){
            for(int j = 0; j < len; j++){
                for(int k = 0; k < len; k++){
                    int dig1 = S[i] - '0';
                    int dig2 = S[j] - '0';
                    int dig3 = S[k] - '0';
                    if(i != j && j != k && i != k && (dig1*100 + dig2*10 + dig3) % 8 == 0)
                    flag++;
                }
            }
        }
        if(flag)
        return 1;
        else
        return 0;
    }
    
};