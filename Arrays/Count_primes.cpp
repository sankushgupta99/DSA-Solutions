class Solution {
public:
    int countPrimes(int n) {
        if(n <= 2)
            return 0;
        
        bool sieve[n];
        memset(sieve, 0, sizeof(sieve));
        int prime_count = 0;
        
        for(int i = 2; i < n; i++){
            if(sieve[i] == 0){
                prime_count++;
                for(int j = 2 * i; j < n; j += i)
                    sieve[j] = 1;
            }
        }
        
        return prime_count;
    }
};

//OR

class Solution {
public:
    int countPrimes(int n) {
        if(n <= 2)
            return 0;
        
        vector<bool> sieve(n, true);
        sieve[0] = false; sieve[1] = false;
        
        for(int i = 2; i < sqrt(n); i++){
            if(sieve[i]){
                for(int j = i * i; j < n; j += i)
                    sieve[j] = false;
            }
        }
        
        int count = 0;
        for(int i = 2; i < n; i++){
            if(sieve[i])
                count++;
        }
        
        return count;
    }
};