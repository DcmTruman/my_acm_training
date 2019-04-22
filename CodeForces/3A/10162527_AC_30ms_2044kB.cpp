#include<iostream>
#include<math.h>
using namespace std;

int main()
{
	int x,y,p,q,ans;
	char t;
	cin>>t>>y;
	x = t-96;
	cin>>t>>q;
	p = t-96;
	int xx=x-p;
	int yy = y-p;
	int dx = abs(x-p);
	int dy = abs(y-q);
	if(p>x&&q>y)
	{
		if(dx<=dy)
		{
			cout<<dy<<endl;
			for(int i=0;i<dx;i++)cout<<"RU"<<endl;
			for(int i=0;i<(dy-dx);i++)cout<<"U"<<endl;
		}
		else
		{
			cout<<dx<<endl;
			for(int i=0;i<dy;i++)cout<<"RU"<<endl;
			for(int i=0;i<(dx-dy);i++)cout<<"R"<<endl;
		}
	}
	if(p>x&&q<y)
	{
		if(dx<=dy)
		{
			cout<<dy<<endl;
			for(int i=0;i<dx;i++)cout<<"RD"<<endl;
			for(int i=0;i<(dy-dx);i++)cout<<"D"<<endl;
		}
		else
		{
			cout<<dx<<endl;
			for(int i=0;i<dy;i++)cout<<"RD"<<endl;
			for(int i=0;i<(dx-dy);i++)cout<<"R"<<endl;
		}
	}
	if(p<x&&q<y)
	{
		if(dx<=dy)
		{
			cout<<dy<<endl;
			for(int i=0;i<dx;i++)cout<<"LD"<<endl;
			for(int i=0;i<(dy-dx);i++)cout<<"D"<<endl;
		}
		else
		{
			cout<<dx<<endl;
			for(int i=0;i<dy;i++)cout<<"LD"<<endl;
			for(int i=0;i<(dx-dy);i++)cout<<"L"<<endl;
		}
	}
	if(p<x&&q>y)
	{
		if(dx<=dy)
		{
			cout<<dy<<endl;
			for(int i=0;i<dx;i++)cout<<"LU"<<endl;
			for(int i=0;i<(dy-dx);i++)cout<<"U"<<endl;
		}
		else
		{
			cout<<dx<<endl;
			for(int i=0;i<dy;i++)cout<<"LU"<<endl;
			for(int i=0;i<(dx-dy);i++)cout<<"L"<<endl;
		}
	}
	if(p==x&&q!=y)
	{
		cout<<dy<<endl;
		if(q>y){
		for(int i=0;i<dy;i++)cout<<"U"<<endl;
		}
		else if(q<y)
		{
			for(int i=0;i<dy;i++)cout<<"D"<<endl;
		}
	}
	if(q==y&&p!=x)
	{
		cout<<dx<<endl;
		if(p>x){
		for(int i=0;i<dx;i++)cout<<"R"<<endl;
		}
		else if(p<x)
		{
			for(int i=0;i<dx;i++)cout<<"L"<<endl;
		}
	}
	if(p==x&&q==y)cout<<"0"<<endl;
}