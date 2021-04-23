class Solution{
public:	
	// #define ull unsigned long long
	/* Function to get the nth ugly number*/
	ull getNthUglyNo(int n) {
	    ull Ugly[10010];
	    Ugly[1] = 1;
	    int two_ind = 1;
	    int three_ind = 1;
	    int five_ind = 1;
	    ull next_multiple_of_2 = 2;
	    ull next_multiple_of_3 = 3;
	    ull next_multiple_of_5 = 5;
	    for(int i = 2; i <= n; i++){
	        Ugly[i] = min(next_multiple_of_2, next_multiple_of_3);
	        Ugly[i] = min(Ugly[i], next_multiple_of_5);
	        if(Ugly[i] == next_multiple_of_2){
	            two_ind++;
	            next_multiple_of_2 = Ugly[two_ind] * 2;
	        }
	        if(Ugly[i] == next_multiple_of_3){
	            three_ind++;
	            next_multiple_of_3 = Ugly[three_ind] * 3;
	        }
	        if(Ugly[i] == next_multiple_of_5){
	            five_ind++;
	            next_multiple_of_5 = Ugly[five_ind] * 5;
	        }
	    }
	    return Ugly[n];
	}
};