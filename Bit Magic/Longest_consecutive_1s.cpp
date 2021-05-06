class Solution
{
    public:
    int maxConsecutiveOnes(int N)
    {
        int max_till_here = 0;
        int max_so_far = 0;
        while(N > 0){
            if(N & 1){
                max_till_here++;
                max_so_far = max(max_so_far, max_till_here);
            }
            else{
                max_till_here = 0;
            }
            N >>= 1;
        }
        return max_so_far;
    }
};

//OR

class Solution
{
    public:
    int maxConsecutiveOnes(int N)
    {
        int count = 0;
        while(N > 0){
            N = N & (N << 1);
            count++;
        }
        return count;
    }
};