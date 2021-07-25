class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;
        int j = n - 1;
        int k = m + n - 1;
        
        while(i >= 0 && j >= 0){
            if(nums1[i] < nums2[j]){
                nums1[k--] = nums2[j--];
            }
            else if(nums2[j] < nums1[i]){
                nums1[k--] = nums1[i--];
            }
            else{
                nums1[k--] = nums2[j--];
                nums1[k--] = nums1[i--];
            }
        }
        
        while(i >= 0)
            nums1[k--] = nums1[i--];
        
        while(j >= 0)
            nums1[k--] = nums2[j--];
    }
};

//OR

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;
        int j = n - 1;
        int k = m + n - 1;
        
        while(k >= 0){
            if(i == -1 || (j >= 0 && nums1[i] < nums2[j])){
                nums1[k--] = nums2[j--];
            }
            else if(j == -1 || nums2[j] < nums1[i]){
                nums1[k--] = nums1[i--];
            }
            else{
                nums1[k--] = nums2[j--];
                nums1[k--] = nums1[i--];
            }
        }
        
    }
};