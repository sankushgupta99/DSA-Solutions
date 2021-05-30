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