class Solution{
public:	
		
	int isDivisible(string s){
	    int len = s.length();
	    int pos = 1;
	    int sum = 0;
	    for(int i = len-1; i >= 0; i--){
	        if(s[i] == '1'){
    	        if(pos % 2 == 1){
    	            sum += 1;
    	        }
    	        else{
    	            sum += 2;
    	        }
	        }
	        pos++;
	    }
	    if(sum % 3 == 0)
	    return 1;
	    else
	    return 0;
	}

};