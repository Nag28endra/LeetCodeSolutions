class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int leftSum=0,rightSum=0;
        int maxSum=0;
        int n=cardPoints.size();
        // perform left sum
        for(int i = 0; i<=k-1; i++){
            leftSum += cardPoints[i];
        }
        // set the left sum as maxisum
        maxSum = leftSum;
        // create a right index that is used to add values from the back
        int rightIdx = n-1;
        // perform right sum as well as the maximum sum
        for(int i=k-1; i>=0;i--){
            leftSum -= cardPoints[i];
            rightSum += cardPoints[rightIdx];
            // move the pointer
            rightIdx--;
            maxSum = max(maxSum, leftSum+rightSum);

        }
        return maxSum;
    }
};