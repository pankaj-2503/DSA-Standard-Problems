 // TC:O(NlogN) , SC:O(N)
    static bool comp( pair<int,int>&a,pair<int,int>&b){
        return a.second<b.second;
    }
    
    int maxMeetings(int n, int start[], int end[]) {
       
        vector<pair<int,int>>v;
        for(int i=0;i<n;i++){
            v.push_back({start[i],end[i]});
        }
        // sorting based on end time of meeting
        sort(v.begin(),v.end(),comp);
        int cnt=1;
        int last=v[0].second;
        for(int i=1;i<n;i++){
            if(v[i].first>last){
                cnt++;
                last=v[i].second;
            }
        }
        return cnt;
    }