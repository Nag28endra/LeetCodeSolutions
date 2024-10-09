class Solution {
public:
    int trap(vector<int>& height) {
        int leftTallerBuilding = 0;
        int rightTallerBuilding = 0;
        int leftCurrentBuilding = 0;
        int rightCurrentBuilding = height.size() - 1;
        int total = 0;

        while( leftCurrentBuilding < rightCurrentBuilding){
            // figure out which is smallest building from left and right
            // if left building is small
            if (height[leftCurrentBuilding] <= height[rightCurrentBuilding]){
                // check is there any other building to the left taller than the current left building
                if(leftTallerBuilding > height[leftCurrentBuilding]){
                        total += leftTallerBuilding - height[leftCurrentBuilding];
                }
                // make the current left building as the left most taller building.
                else {
                    leftTallerBuilding = height[leftCurrentBuilding];
                }
                leftCurrentBuilding +=1;
            }
            // if right current building is small
            else{
                // check is there any other taller building to the right.
                if(rightTallerBuilding > height[rightCurrentBuilding]){
                        total += rightTallerBuilding - height[rightCurrentBuilding];
                }
                // make the current right building as the right most taller building.
                else {
                    rightTallerBuilding = height[rightCurrentBuilding];
                }
                rightCurrentBuilding -=1;
            }
        }
        return total;
    }
};