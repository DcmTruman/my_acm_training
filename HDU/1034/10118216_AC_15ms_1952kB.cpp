#include<iostream>
#include<vector>
using namespace std;
long long Give[10000000] = { 0 };
int main()
{
	long long N;
	cin >> N;
	while (N != 0)
	{
		//Give[100000] = { 0 };
		int count = 0;
		vector<long long>V;
		for (int i = 0; i < N; i++) {
			long long a;
			cin >> a;
			V.push_back(a);
		}
		while (1) {
			int flag = 1;
			for (int i = 0; i < V.size() - 1; i++)
			{
				if (V[i] != V[i + 1]) { flag = 0; break; }
			}
			if (flag)break;
			else
			{
				for (int i = 0; i < V.size(); i++) {
					
						V[i] /= 2;
						Give[i] = V[i];
						if (i != 0) V[ i] += Give[i - 1];
				}
				V[0] += Give[V.size() - 1];
				for (int i = 0; i < V.size() ; i++)
				{
					if (V[i] & 1)V[i] += 1;
				}
				count++;
			}
		}
		cout << count<<" "<<V[0]<< endl;
		cin >> N;
	}
}