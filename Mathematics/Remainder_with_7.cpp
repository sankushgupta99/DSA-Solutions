class Solution{
    public:
    int remainderWith7(string n)
    {
        int series[] = {1, 3, 2, -1, -3, -2};
        int series_index = 0;
        int ans = 0;
        
        for(int i = n.size() - 1; i >= 0; i--){
            int digit = n[i] - '0';
            ans = ans + (digit * series[series_index]);
            series_index = (series_index + 1) % 6;
            ans = ans % 7;
        }
        
        if(ans < 0)
        ans += 7;
        
        return ans;
    }
};

//OR

class Solution{
    public:
    int remainderWith7(string n)
    {
        int powerOfTen = 1;
        int ans = 0;
        for(int i = n.size()-1; i >= 0; i--){
            ans = (ans + (powerOfTen * (n[i] - '0')) % 7) % 7;
            powerOfTen = (powerOfTen * 10) % 7;
        }
        return ans;
    }
};