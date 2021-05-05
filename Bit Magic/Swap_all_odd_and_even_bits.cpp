class Solution
{
    public:
    //Function to swap odd and even bits.
    unsigned int swapBits(unsigned int n)
    {
        int bit_val = 1;
        int ans = n;
        while(n > 0){
            if(n & 1)
            ans += bit_val;
            n /= 2;
            if(n & 1)
            ans -= bit_val;
            n /=2;
            bit_val *= 4;
        }
        return ans;
    }
};

//OR

class Solution
{
    public:
    //Function to swap odd and even bits.
    unsigned int swapBits(unsigned int n)
    {
        unsigned int even_bits = n & 0xAAAAAAAA;
        unsigned int odd_bits = n & 0x55555555;
        
        odd_bits <<= 1;
        even_bits >>= 1;
        
        return (odd_bits | even_bits);
    }
};