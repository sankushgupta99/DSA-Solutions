class Solution
{
public:
    int setKthBit(int N, int K)
    {
        N = N | (1 << K);
        return N;
    }
    
};