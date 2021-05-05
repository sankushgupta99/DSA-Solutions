class Solution{
    public:
    // Function to check if given number n is a power of two.
    bool isPowerofTwo(long long n){
        int set_bit_count = 0;
        while(n > 0){
            if(n & 1)
            set_bit_count++;
            n /= 2;
        }
        return set_bit_count == 1;
    }
};