class Solution
{
    public:
    //Function to check if the number is sparse or not.
    bool isSparse(int n)
    {
        bool res = true;
        while(n > 0){
            if((n & 1) && (n & 2))
            res = false;
            n >>= 1;
        }
        return res;
    }
};

//OR

bool isSparse(int n)
{
    if(n & (n >> 1))
        return false;
    return true;
}