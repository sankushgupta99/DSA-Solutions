class Solution{
    public:
    // n: input to count the number of set bits
    //Function to return sum of count of set bits in the integers from 1 to n.
    int LastSetBit(int n){
        int lastsetbit = 0;
        while(n > 0){
            lastsetbit++;
            n /= 2;
        }
        return lastsetbit;
    }
    int countSetBits(int n)
    {
        int last_set_bit = LastSetBit(n);
        int total_set_bits = 0;
        int set_bits_till_now = 0;
        for(int i = last_set_bit-1; i >= 0; i--){
            if(n & (1 << i)){
                total_set_bits += ((set_bits_till_now) * pow(2,i)) + (i * pow(2, i-1));
                set_bits_till_now++;
            }
        }
        total_set_bits += set_bits_till_now;
        return total_set_bits;
    }
};