int find(int par[],int x)
{
     if(par[x] == x)
     return x;
     
     int temp = find(par, par[x]);
     par[x] = temp;
     return temp;
}
void unionSet(int par[],int x,int y, int rank[])
{
	int lox = find(par, x);
	int loy = find(par, y);
	
	if(lox != loy){
		if(rank[lox] > rank[loy]){
			par[loy] = lox;
		}
		else if(rank[loy] > rank[lox]){
			par[lox] = loy;
		}
		else{
			par[lox] = loy;
			rank[loy]++;
		}
	}
}