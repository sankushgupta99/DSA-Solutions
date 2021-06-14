class Solution {
public:
    static bool sortBySec(vector<int> &boxType1, vector<int> &boxType2){
        return boxType1[1] > boxType2[1];
    }
    
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), sortBySec);
        int maxUnits = 0;
        
        for(int i = 0; i < boxTypes.size(); i++){
            if(boxTypes[i][0] < truckSize){
                maxUnits += (boxTypes[i][0] * boxTypes[i][1]);
                truckSize -= boxTypes[i][0];
            }
            else{
                maxUnits += (truckSize * boxTypes[i][1]);
                break;
            }
        }
        
        return maxUnits;
    }
};