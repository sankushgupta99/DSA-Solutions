class Solution
{
    public:
    //Function to find the first position with different bits.
    int posOfRightMostDiffBit(int m, int n)
    {
        if(m == n)
        return -1;
        
        int pos = 0;
        while(m > 0 || n > 0){
            pos++;
            if((m & 1) != (n & 1)){
                break;
            }
            m = m >> 1;
            n = n >> 1;
        }
        return pos;
    }
};

//OR

class Solution
{
    public:
    //Function to find the first position with different bits.
    int posOfRightMostDiffBit(int m, int n)
    {
        if(m == n)
        return -1;
        
        int pos = 0;
        while(true){
            pos++;
            if(m % 2 != n % 2){
                break;
            }
            m /= 2;
            n /= 2;
        }
        return pos;
    }
};