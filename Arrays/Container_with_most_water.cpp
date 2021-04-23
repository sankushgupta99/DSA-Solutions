class Solution {
public:
    long int maxArea(vector<int>& height) {
        long int i = 0;
        long int j = height.size() - 1;
        
        long int max_area  = (j - i) * min(height[j], height[i]);
        
        while(i<j){
            max_area = max(max_area, ((j - i) * min(height[j], height[i])));
            if(height[i] < height[j])
                i++;
            else
                j--;
        }
        return max_area;
    }
};