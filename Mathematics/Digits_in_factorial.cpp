class Solution{
    public:
    int digitsInFactorial(int N)
    {
        double digits;
        for(int i = 1; i <= N; i++){
            digits += log(i);
        }
        
        digits /= log(10);
        return floor(digits) + 1;
    }
};