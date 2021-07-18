class Solution {
public:
    vector<int> threeEqualParts(vector<int>& arr) {
        int n = arr.size();
        int count = 0;
         
        for(int i = 0; i < n; i++){
            count += arr[i];
        }
        
        if(count % 3)
            return {-1,-1};
        
        if(count == 0)
            return {0,2};
            
        count /= 3;
        int ind1 = -1, ind2 = -1, ind3 = -1;
        int curr_count = 0;
        
        for(int i = n-1; i >= 0; i--){
            if(arr[i] == 1){
                curr_count++;
                if(curr_count == 1)
                    ind1 = i;
                if(curr_count == count + 1)
                    ind2 = i;
                if(curr_count == 2*count + 1)
                    ind3 = i;
            }
        }
        
        vector<int> res;
        res.push_back(ind3 + (n - ind1 - 1));
        res.push_back(ind2 + (n - ind1));
        
        string str1, str2, str3;
        int flag1 = 0, flag2 = 0, flag3 = 0;
        
        for(int i = 0; i < n; i++){
            if(i <= res[0]){
                if(arr[i] == 1 && !flag1)
                    flag1++;
                if(flag1)
                    str1 += (arr[i] + '0');
            }
            else if(i < res[1]){
                if(arr[i] == 1 && !flag2)
                    flag2++;
                if(flag2)
                    str2 += (arr[i] + '0');
            }
            else{
                if(arr[i] == 1 && !flag3)
                    flag3++;
                if(flag3)
                    str3 += (arr[i] + '0');
            }
        }
        
        if(str1 == str2 && str2 == str3)
            return res;
        return {-1,-1};
    }
};