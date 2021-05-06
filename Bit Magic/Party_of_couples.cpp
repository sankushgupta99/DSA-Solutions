class Solution{
    public:
    int findSingle(int N, int arr[]){
        int xor1 = 0;
        for(int i = 0; i < N; i++){
            xor1 = xor1 ^ arr[i];
        }
        return xor1;
    }
};