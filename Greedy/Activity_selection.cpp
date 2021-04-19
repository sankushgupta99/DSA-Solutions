bool sortbysec(pair<long long int,long long int> p1,pair<long long int,long long int> p2)
{
    if(p1.second!=p2.second)
    return p1.second<p2.second;
    else
    return p1.first<p2.first;
}
int main() 
{
	long long int t,i,n,j,a[1010],b[1010],ans=0,next;
	cin>>t;
	for(i=0;i<t;i++)
	{
	    cin>>n;
	    ans=1;
	    vector<pair<long long int,long long int>> v;
	    for(j=0;j<n;j++)
	    {
	        cin>>a[j];
	    }
	    for(j=0;j<n;j++)
	    {
	        cin>>b[j];
	        v.push_back(make_pair(a[j],b[j]));
	    }
	    sort(v.begin(),v.end(),sortbysec);
	    next=v[0].second;
	    for(j=1;j<n;j++)
	    {
	        if(v[j].first>=next)
	        {
	            ans++;
	            next=v[j].second;
	        }
	    }
	    cout<<ans<<endl;
	}
	return 0;
}