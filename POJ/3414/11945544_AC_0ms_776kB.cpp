#include<iostream>
#include<queue>
#include<vector>
#include<stack>

using namespace std;

typedef struct _node {
	int A, B;
	int op;
	int id;
	int lid;
	int step;
	void set(int a, int b, int c, int e, int d, int f)
	{
		A = a;
		B = b;
		op = c;
		id = e;
		lid = d;
		step = f;
	}
	void copy(_node B)
	{
		this->set(B.A, B.B, B.op, B.id, B.lid, B.step);
	}
}node;
bool visit[120][120];
int main()
{
	int Va, Vb, C;
	cin >> Va >> Vb >> C;

	queue<node> Q;
	vector<node>V;
	stack<node>S;


	node temp;
	int num = 0;
	temp.set(0, 0, 0, 0, 0, 0);
	Q.push(temp);
	V.push_back(temp);
	num++;
	int flag = false;
	int pos;
	while (!Q.empty())
	{
		node t;
		t = Q.front();
		Q.pop();
		if (t.A == C || t.B == C)
		{
			flag = true;
			pos = t.id;
			cout << t.step << endl;
			break;
		}
		node t1;
		if (!visit[Va][t.B]) {
			t1.set(Va, t.B, 1, num, t.id, t.step + 1);
			Q.push(t1);
			V.push_back(t1);
			visit[Va][t.B] = true;
			num++;
		}
		if (!visit[t.A][Vb]) {
			t1.set(t.A, Vb, 2, num, t.id, t.step + 1);
			Q.push(t1);
			V.push_back(t1);
			visit[t.A][Vb] = true;
			num++;
		}
		if (!visit[0][t.B]) {
			t1.set(0, t.B, 3, num, t.id, t.step + 1);
			Q.push(t1);
			V.push_back(t1);
			visit[0][t.B] = true;
			num++;
		}
		if (!visit[t.A][0]) {
			t1.set(t.A, 0, 4, num, t.id, t.step + 1);
			Q.push(t1);
			V.push_back(t1);
			visit[t.A][0] = true;
			num++;
		}
		if (Va - t.A > t.B)
		{
			if (!visit[t.A + t.B][0]) {
				t1.set(t.A + t.B, 0, 6, num, t.id, t.step + 1);
				Q.push(t1);
				V.push_back(t1);
				visit[t.A + t.B][0] = true;
				num++;
			}
		}
		else
		{
			if (!visit[Va][t.B - (Va - t.A)]) {
				t1.set(Va, t.B - (Va - t.A), 6, num, t.id, t.step + 1);
				Q.push(t1);
				V.push_back(t1);
				visit[Va][t.B - (Va - t.A)] = true;
				num++;
			}
		}
		
		if (Vb - t.B > t.A)
		{
			if (!visit[0][t.A + t.B]) {
				t1.set(0, t.A + t.B, 5, num, t.id, t.step + 1);
				Q.push(t1);
				V.push_back(t1);
				visit[0][t.A + t.B] = true;
				num++;
			}
		}
		else
		{
			if (!visit[t.A - (Vb - t.B)][Vb]) {
				t1.set(t.A - (Vb - t.B), Vb, 5, num, t.id, t.step + 1);
				Q.push(t1);
				V.push_back(t1);
				visit[t.A - (Vb - t.B)][Vb] = true;
				num++;
			}
		}
	}
	if (flag)
	{
		node now;
		now.copy(V[pos]);
		while (now.id != 0)
		{
			S.push(now);
			now = V[now.lid];
		}
		while (!S.empty())
		{
			now = S.top();
			S.pop();
			switch (now.op)
			{
			case 1:
				cout << "FILL(1)" << endl;
				break;
			case 2:
				cout << "FILL(2)" << endl;
				break;
			case 3:
				cout << "DROP(1)" << endl;
				break;
			case 4:
				cout << "DROP(2)" << endl;
				break;
			case 5:
				cout << "POUR(1,2)" << endl;
				break;
			case 6:
				cout << "POUR(2,1)" << endl;
				break;
			default:
				break;
			}
		}
	}
	else
	{
		cout << "impossible" << endl;
	}
}