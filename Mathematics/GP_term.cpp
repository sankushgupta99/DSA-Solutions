class Solution{
    public:
    double termOfGP(int A,int B,int N)
    {
        double r = (double(B) / A);
        double res = A;
        for(int i = 0; i < N-1; i++){
            res *= r;
        }
        return res;
    }
};