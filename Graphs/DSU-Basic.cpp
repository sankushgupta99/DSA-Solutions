int find(int a[],int x)
{
     if(a[x] == x)
     return x;
     
     return find(a, a[x]);
}
void unionSet(int a[],int x,int z)
{
	int lox = find(a, x);
	int loz = find(a, z);
	a[lox] = loz;
}