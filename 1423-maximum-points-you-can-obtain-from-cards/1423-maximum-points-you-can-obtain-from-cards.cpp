class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();
        int ans=0;
        int total=0;
        for(int i=0;i<n;i++){
            total+=cardPoints[i];
        }
    int windowsum=0;
    int windowsize=n-k;
    if(windowsize==0){
        return total;
    }

    for(int i=0;i<windowsize;i++){
        windowsum+=cardPoints[i];
    }
    int minsum=windowsum;

    for(int i=windowsize;i<n;i++){

        windowsum+=cardPoints[i];
        windowsum-=cardPoints[i-windowsize];
        minsum=min(windowsum,minsum);
    }


       return total-minsum;
    }
};