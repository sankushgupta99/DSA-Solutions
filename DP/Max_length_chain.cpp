/*
The structure to use is as follows
struct val{
	int first;
	int second;
};*/
int dp[110];
bool sortbysec(struct val p1, struct val p2){
    if(p1.second!=p2.second)
    return p1.second < p2.second;
    else
    return p1.first < p2.first;
}
int maxChainLenUtil(struct val p[], int n){
    dp[0]=0;
    dp[1]=1;
    for(int i=2;i<=n;i++){
        int j=i-2;
        while(j>=0 && p[j].second>=p[i-1].first)
        j--;
        dp[i] = max(1+dp[j+1],dp[i-1]);
    }
    return dp[n];
}
int maxChainLen(struct val p[],int n)
{
    sort(p, p+n, sortbysec);
    //memset(dp,-1,sizeof(dp));
    int ans = maxChainLenUtil(p,n);
    return ans;
}