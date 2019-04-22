#include<iostream>

using namespace std;
typedef struct _FFF{
	int l;
	int w;
}R;
bool isOk(R a,R b,R c)
{
	if((a.l+b.l == c.l||a.l+b.l == c.w) && a.w == b.w)return true;
	else if((a.l+b.w == c.l||a.l+b.w == c.w) && a.w == b.l)return true;
	else if((a.w+b.l == c.l||a.w+b.l == c.w) && a.l == b.w)return true;
	else if((a.w+b.w == c.l||a.w+b.w == c.w) && a.l == b.l)return true;
	else if((a.l+c.l == b.l||a.l+c.l == b.w) && a.w == c.w)return true;
	else if((a.l+c.w == b.l||a.l+c.w == b.w) && a.w == c.l)return true;
	else if((a.w+c.l == b.l||a.w+c.l == b.w) && a.l == c.w)return true;
	else if((a.w+c.w == b.l||a.w+c.w == b.w) && a.l == c.l)return true;
	else if((b.l+c.l == a.l||b.l+c.l == a.w) && b.w == c.w)return true;
	else if((b.l+c.w == a.l||b.l+c.w == a.w) && b.w == c.l)return true;
	else if((b.w+c.l == a.l||b.w+c.l == a.w) && b.l == c.w)return true;
	else if((b.w+c.w == a.l||b.w+c.w == a.w) && b.l == c.l)return true;
	else if(a.l == b.l&&(c.l == a.l||c.w == a.l))return true;
	else if(a.l == b.w&&(c.l == a.l||c.w == a.l))return true;
	else if(a.w == b.l&&(c.l == a.w||c.w == a.w))return true;
	else if(a.w == b.w&&(c.l == a.w||c.w == a.w))return true;
	return false;
}
int main()
{
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	while(T--)
	{
		R a,b,c,d;
		cin >>a.l>>a.w>>b.l>>b.w>>c.l>>c.w>>d.l>>d.w;
		if(isOk(a,b,c)||isOk(a,b,d)||isOk(a,c,d)||isOk(b,c,d))cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
}