class Solution{
    public:
    long long toh(int N, int from, int to, int aux) {
        if(N == 0){
            return 0;
        }
        
        long long move_count1 = toh(N-1, from, aux, to);
        cout<<"move disk "<<N<<" from rod "<<from<<" to rod "<<to<<endl;
        long long move_count2 = toh(N-1, aux, to, from);
        
        return move_count1 + 1 + move_count2;
    }
};