class Solution{
public:
    int rotationCount(long long R, long long D)
    {
        int min_rotations = 0;
        while(D > 0 || R > 0){
            int x = R % 10;
            int y = D % 10;
            
            if(y > x)
                min_rotations += min(y - x, 10 - y + x);
            else
                min_rotations += min(x - y, 10 - x + y);
            
            R /= 10;
            D /= 10;
        }
        return min_rotations++;
    }
};