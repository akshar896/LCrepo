#define ll long long
ll INF=1e18;
class Solution {
public:
    long long elevatorRequests(int n, int start, vector<vector<int>>& requests) {
        //dp[i][j] is minimum time such that ith mask have been fulfilled 
        //
        int m=requests.size();
        vector<vector<ll>>dp(1<<m,vector<ll>(m,INF));
        for(ll i=0;i<m;i++){
            ll travelTime=abs(start-requests[i][1]);
            ll arrivalTime=requests[i][0];
            dp[1<<i][i]=max(travelTime,arrivalTime);
        }
        for(ll i=0;i<(1<<m);i++){
            for(ll j=0;j<m;j++){
                if(dp[i][j]!=INF){//it means this state has been calculated
                    for(ll k=0;k<m;k++){
                        if(dp[i][k] == INF){
                            ll travelTime=dp[i][j]+abs(requests[j][1]-requests[k][1]);
                            ll arrivalTime=requests[k][0];
                            dp[((1<<k)|i)][k]=min(max(travelTime,arrivalTime),dp[((1<<k)|i)][k]);
                        }
                    }
                }
            }
        }
        ll res=1e18;;
        for(ll last=0;last<m;last++){
            res=min(res,dp[(1<<m)-1][last]);
        }
        return res;
    }
};