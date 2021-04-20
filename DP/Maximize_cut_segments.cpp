int maximizeTheCuts(int n, int x, int y, int z)
{
    int length[5];
    length[0]=x;
    length[1]=y;
    length[2]=z;
    int dp[4][n+1];
    for(int i=0;i<=3;i++){
        for(int j=0;j<=n;j++){
            if(i==0)
            dp[i][j]=INT_MIN;
            else if(j==0)
            dp[i][j]=0;
            else if(i==1)
            {
                if(j%x==0)
                dp[i][j]=j/x;
                else 
                dp[i][j]=INT_MIN;
            }
        }
    }
    for(int i=2;i<=3;i++){
        for(int j=1;j<=n;j++){
            if(length[i-1]<=j){
                dp[i][j]=max(dp[i-1][j],1+dp[i][j-length[i-1]]);
            }else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    if(dp[3][n]<0)
    return 0;
    else
    return dp[3][n];
}