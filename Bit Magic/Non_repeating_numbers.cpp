class Solution
{
public:
    vector<int> singleNumber(vector<int> nums) 
    {
        vector<int> res;
        int xor1 = 0;
        for(int i = 0; i < nums.size(); i++){
            xor1 = xor1 ^ nums[i];
        }
        int pos = 0;
        while(xor1 > 0){
            if(xor1 & 1){
                break;
            }
            xor1 = xor1 >> 1;
            pos++;
        }
        int num1 = 0;
        int num2 = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] & (1 << pos)){
                num1 = num1 ^ nums[i];
            }
            else{
                num2 = num2 ^ nums[i];
            }
        }
        res.push_back(min(num1, num2));
        res.push_back(max(num1, num2));
        return res;
    }
};