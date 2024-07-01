class Solution{
 public:
 // Recursion -> Time complexity - O(3^N) 
 int solve(vector<vector<int>>&points,int day,int last){
        int maxi=0;
        if(day==0){
            //base case
            maxi=0;
            for(int i=0;i<3;i++){
                if(i!=last){
                    maxi=max(maxi,points[day][i]);
                }
            }
            return maxi;
        }
        maxi=0;
        for(int i=0;i<3;i++){
            if(i!=last){
               int activity=points[day][i]+solve(points,day-1,i);
               maxi=max(maxi,activity);
            }
            
        }
        return maxi;
        
        
    }
    int maximumPoints(vector<vector<int>>& points, int n) {
        // Code here
        int last=3;
       return solve(points,n-1,last);
    }
};


// Memoisation 
// Time complexity - O(N*4*3) , space complexity - O(N*4)
int f(int day, int last, vector<vector<int>> &points, vector<vector<int>> &dp) {
  
  if (dp[day][last] != -1) return dp[day][last];

  
  if (day == 0) {
    int maxi = 0;
   
    for (int i = 0; i <= 2; i++) {
      if (i != last)
        maxi = max(maxi, points[0][i]);
    }
    
    return dp[day][last] = maxi;
  }

  int maxi = 0;
  y
  for (int i = 0; i <= 2; i++) {
    if (i != last) {
      
      int activity = points[day][i] + f(day - 1, i, points, dp);
      maxi = max(maxi, activity);
    }
  }

   
  return dp[day][last] = maxi;
}

    int maximumPoints(vector<vector<int>>& points, int n) {
        // Code here
         vector<vector<int>> dp(n, vector<int>(4, -1));
  // Start the recursive calculation from the last day with no previous activity
         return f(n - 1, 3, points, dp);
    }

// Tabulation
// Time complexity - O(N*4*3) , space complexity - O(N*4)
int maximumPoints(vector<vector<int>>& points, int n) {
        // Code here
        // dp[i][j] represent maximum points at ith day considering last activity as j
        vector<vector<int>>dp(n,vector<int>(4,0));
        dp[0][0]=max(points[0][1],points[0][2]);
        dp[0][1]=max(points[0][0],points[0][2]);
        dp[0][2]=max(points[0][0],points[0][1]);
        dp[0][3]=max({points[0][1],points[0][2],points[0][0]});
        
        for(int day=1;day<n;day++){
            for(int last=0;last<4;last++){
                // iterating in task out of 3
                for(int i=0;i<3;i++){
                    if(i!=last){
                        int activity=points[day][i]+dp[day-1][i];
                        dp[day][last]=max(dp[day][last],activity);
                    }
                }
            }
        }
        return dp[n-1][3];
    }


// space optimised - space complexity - O(4)
int ninjaTraining(int n, vector<vector<int>>& points) {
  // Initialize a vector to store the maximum points for the previous day's activities
  vector<int> prev(4, 0);

  // Initialize the DP table for the first day (day 0)
  prev[0] = max(points[0][1], points[0][2]);
  prev[1] = max(points[0][0], points[0][2]);
  prev[2] = max(points[0][0], points[0][1]);
  prev[3] = max(points[0][0], max(points[0][1], points[0][2]));

  // Iterate through the days starting from day 1
  for (int day = 1; day < n; day++) {
    // Create a temporary vector to store the maximum points for the current day's activities
    vector<int> temp(4, 0);
    for (int last = 0; last < 4; last++) {
      temp[last] = 0;
      // Iterate through the tasks for the current day
      for (int task = 0; task <= 2; task++) {
        if (task != last) {
          // Calculate the points for the current activity and add it to the
          // maximum points obtained on the previous day (stored in prev)
          temp[last] = max(temp[last], points[day][task] + prev[task]);
        }
      }
    }
    // Update prev with the maximum points for the current day
    prev = temp;
  }

  // The maximum points for the last day with any activity can be found in prev[3]
  return prev[3];
}