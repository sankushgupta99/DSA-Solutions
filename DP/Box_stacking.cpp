class Solution{
    public:
    struct Box{
        int length;
        int width;
        int height;
    };
    static bool sortbyarea(Box B1, Box B2){
        return (B1.length * B1.width) > (B2.length * B2.width);
    }
    int maxHeight(int height[],int width[],int length[],int n)
    {
        struct Box B[3*n];
        for(int i = 0; i < n; i++){
            B[3*i].height = height[i];
            B[3*i].length = max(width[i],length[i]);
            B[3*i].width = min(width[i],length[i]);
            B[3*i+1].height = width[i];
            B[3*i+1].length = max(height[i],length[i]);
            B[3*i+1].width = min(height[i],length[i]);
            B[3*i+2].height = length[i];
            B[3*i+2].length = max(height[i],width[i]);
            B[3*i+2].width = min(height[i],width[i]);
        }
        sort(B, B + (3*n), sortbyarea);
        int dp[3*n];
        for(int i = 0; i < 3*n; i++){
            dp[i] = B[i].height;
        }
        int maxheight = 0;
        for(int i = 1; i < 3*n; i++){
            for(int j = 0; j < i; j++){
                if(B[i].length < B[j].length && B[i].width < B[j].width)
                {
                    dp[i] = max(dp[i], dp[j] + B[i].height);
                    maxheight = max(maxheight, dp[i]);
                }
            }
        }
        return maxheight;
    }
};