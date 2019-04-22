//对于向量的角度进行维护，因为旋转一个角度，这个线段之上的所有线段都要进行旋转，很像一个区间维护，所以用线段树
//感谢demian详细的代码和教程
//http://www.cnblogs.com/demian/p/6164613.html

#include<iostream>
#include<math.h>

using namespace std;

const int maxn = 10002;
const int root = 1;
const int MAXN = maxn;
const int ROOT = 1;
const double PI = acos(-1.0);  
const double EPS = 1e-8;  

#define LSon(x)((x)<<1)//x*2
#define RSon(x)((x)<<1|1)//x*2+1


struct Seg{
	double x,y;
	int flag;
	int degree;
};

void Rotate(Seg& node,int degree);
double GetRad(int x);  

struct SegTree{
	Seg node[maxn<<2];
	void Update(int pos)
	{
		node[pos].x = node[LSon(pos)].x+node[RSon(pos)].x;
		node[pos].y = node[LSon(pos)].y+node[RSon(pos)].y;
	}
	void Build(int l,int r,int pos)
	{
		node[pos].x = node[pos].y = 0;
		node[pos].flag = 0;
		node[pos].degree = 0;
		if(l == r){
			scanf("%lf", &node[pos].y);  
			return;
		}
		int m = l+r>>1;
		Build(l,m,LSon(pos));
		Build(m+1,r,RSon(pos));
		Update(pos);
	}
	void Push(int pos)
	{
		Seg& father = node[pos];
		Seg& lson = node[LSon(pos)];
		Seg& rson = node[RSon(pos)];
		if(father.flag)
		{
			Rotate(lson,father.flag);
			Rotate(rson,father.flag);
			lson.flag += father.flag;
			rson.flag += father.flag;
			father.flag = 0;
		}
	}
	void Modify(int l,int r,int pos,int x,int y,int z)
	{
		if(x<=l&&r<=y)//修改区间包含当前区间
		{
			Rotate(node[pos],z);
			node[pos].flag += z;
			return;
		}
		Push(pos);
		int m = l+r >> 1;
		if(x<=m)Modify(l,m,LSon(pos),x,y,z);
		if(y>m)Modify(m+1,r,RSon(pos),x,y,z);
		Update(pos);
	}
	int Query(int l,int r,int pos,int x)
	{
		if(l == r)return node[pos].degree;
		Push(pos);//之前对于区间的修改，不是对于叶子节点全部修改，所以有一个flag用来表示，这个节点的子节点要加上对应的值，对如果有时候要具体的查询，必定不能只改变非叶子节点，所以在查询过程中也加入Push操作，将当前节点的改变push到其叶子节点，算是一种优化吧
		int m = l+r >> 1;
		if(x<=m)return Query(l,m,LSon(pos),x);
		else return Query(m+1,r,RSon(pos),x);
	}
};

int n,c;
int s,a;

SegTree tree;

int main()
{
	bool first = true;
	while(cin>>n>>c)
	{
		tree.Build(0,n-1,root);
		printf("%s",first?first = false,"":"\n");
		for(int i = 0;i<c;i++)
		{
			cin>>s>>a;
			int degree = tree.Query(0,n-1,root,s-1)+180+a-tree.Query(0,n-1,root,s);
            tree.Modify(0,n-1,root,s,n-1,degree);
            printf("%.2lf %.2lf\n", tree.node[root].x + EPS, tree.node[root].y + EPS);
		}
	}
    return 0;
}

double GetRad(int x)
{
    return x*PI/180;
}

void Rotate(Seg&node,int degree)
{
    double rad = GetRad(degree);  
    double x = node.x; double y = node.y;  
    node.x = x * cos(rad) + y * -sin(rad);  
    node.y = x * sin(rad) + y * cos(rad);  
    node.degree = (node.degree + degree) % 360;  
}
