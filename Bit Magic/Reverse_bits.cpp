class Solution {
  public:
    long long reversedBits(long long X) {
        long long res = 0;
        for(int i = 0; i < 32; i++){
            res = res << 1;
            if(X & 1){
                res += 1;
            }
            X = X >> 1;
        }
        return res;
    }
};

//OR

class Solution {
  public:
    long long reversedBits(long long X) {
        long long pow2[35];
        pow2[0] = 1;
        for(int i = 1; i <= 32; i++){
            pow2[i] = pow2[i-1] * 2;
        }
        long long res = 0;
        int pos = 0;
        while(X > 0){
            if(X & 1){
                res += pow2[31-pos];
            }
            X = X >> 1;
            pos++;
        }
        return res;
    }
};