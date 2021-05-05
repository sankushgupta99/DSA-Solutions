class Solution{
    public:
    // Function to find number of bits needed to be flipped to convert A to B
    int countBitsFlip(int a, int b){
        int bit_flip_count = 0;
        while(a > 0 || b > 0){
            if((a & 1) != (b & 1)){
                bit_flip_count++;
            }
            a /= 2;
            b /= 2;
        }
        return bit_flip_count;
    }
};