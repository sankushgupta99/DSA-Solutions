class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        horizontalCuts.push_back(0);
        horizontalCuts.push_back(h);
        sort(horizontalCuts.begin(), horizontalCuts.end());
        
        verticalCuts.push_back(0);
        verticalCuts.push_back(w);
        sort(verticalCuts.begin(), verticalCuts.end());
        
        long long int max_width = 0, max_height = 0;
        
        for(int i = 1; i < horizontalCuts.size(); i++)
            if(horizontalCuts[i] - horizontalCuts[i-1] > max_width)
                max_width = horizontalCuts[i] - horizontalCuts[i-1];
        
        for(int i = 1; i < verticalCuts.size(); i++)
            if(verticalCuts[i] - verticalCuts[i-1] > max_height)
                max_height = verticalCuts[i] - verticalCuts[i-1];
        
        long long int max_area = (max_width * max_height) % 1000000007;
        
        return max_area;
    }
};