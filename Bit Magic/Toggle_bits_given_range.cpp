class Solution {
  public:
    int toggleBits(int N , int L , int R) {
        int num = ((1 << R)-1) ^ ((1 << (L-1))-1);
        return N ^ num;
    }
};

//OR

class Solution {
  public:
    int toggleBits(int N , int L , int R) {
        int num = (1 << (L-1));
        for(int i = 0; i <= R-L; i++){
            N = N ^ num;
            num = num << 1;
        }
        return N;
    }
};