#define mod 1000000007;

long long getSum(int A[],int n)
{
    long long total_sum = 0;
    for(int i = 0; i < n; i++){
        total_sum += A[i];
    }
    
    for(int i = 1; i <= (n-1); i++){
        total_sum = (total_sum * i) % mod;
    }
    
    long long place_val_sum = 0;
    int powOfTen = 1;
    for(int i = 0; i <= (n-1); i++){
        place_val_sum = (place_val_sum + powOfTen) % mod;
        powOfTen = (powOfTen * 10) % mod;
    }
    
    total_sum = (total_sum * place_val_sum) % mod;
    return total_sum;
}