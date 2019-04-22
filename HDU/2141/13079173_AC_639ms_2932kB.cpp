#include<iostream>
#include<string.h>
#include<cstring>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	int L, N, M, O;
	int S;
	int A[550], B[550], C[550];
	int D[250020];

	int cas = 0;
	while (cin >> L >> N >> M)
	{
		cas++;
		
		O = 0;
		for (int i = 0; i<L; i++)
		{
			cin >> A[i];
		}
		for (int i = 0; i<N; i++)
		{
			cin >> B[i];
		}
		for (int i = 0; i<M; i++)
		{
			cin >> C[i];
		}

		for (int i = 0; i<L; i++)
		{
			for (int j = 0; j<N; j++)
			{
				D[O++] = A[i] + B[j];
			}
		}
		sort(D, D + O);
		{
			cout << "Case " << cas <<":"<< endl;
		}
		cin >> S;

		for (int i = 0; i<S; i++)
		{
			int X;
			bool flag = false;
			cin >> X;
			for (int j = 0; j<M; j++)
			{
				int temp = X - C[j];
				int temp_pos = lower_bound(D, D + O, temp) - D;
				if (temp_pos != O && D[temp_pos] == temp)
				{
					flag = true;
					break;
				}
			}
			if (flag)
			{
				cout << "YES" << endl;
			}
			else {
				cout << "NO" << endl;
			}
		}
	}
}