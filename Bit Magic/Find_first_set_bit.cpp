class Solution
{
    public:
    //Function to find position of first set bit in the given number.
    unsigned int getFirstSetBit(int n)
    {
        if(n == 0)
        return 0;
        
        int pos = 0;
        while(true){
            pos++;
            if(n % 2 == 1){
                break;
            }
            n /= 2;
        }
        return pos;
    }
};