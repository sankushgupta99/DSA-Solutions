class Solution{
    public:
    int exactly3Divisors(int N)
    {
        int res = 0;
        for(int i = 2; i <= sqrt(N); i++){
            int num = i;
            int flag = 0;
            for(int j = 2; j <= sqrt(i); j++){
                if(i % j == 0){
                    flag++;
                    break;
                }
            }
            if(!flag)
            res++;
        }
        return res;
    }
};