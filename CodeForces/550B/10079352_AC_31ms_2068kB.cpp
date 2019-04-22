#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int n;
int ans = 0;
long long l, r, x;
long long ADD[20] = {0};
vector<long long>CDD;
bool BDD[20] = { false };
long long Sum(vector<long long>C)
{
	long long sum = 0;
	for (int i = 0; i < C.size(); i++) {
		sum += C[i];
	}
	return sum;
}
void Dfs(int j)
{
	vector<long long>temp = CDD;
	sort(temp.begin(), temp.end());
	if (temp.size() >= 2) {
		if (Sum(temp) >= l&&Sum(temp) <= r && (temp[temp.size()-1] - temp[0]) >= x)ans++;
	}
	if (Sum(temp) > r)return;
	for (int i = j; i < n; i++) {
		if (i == n - 1&&!BDD[i]) {
			BDD[i] = true;
			CDD.push_back(ADD[i]);
			vector<long long>Temp = CDD;
			sort(Temp.begin(), Temp.end());
			if (Temp.size() >= 2) {
				if (Sum(Temp) >= l&&Sum(Temp) <= r && (Temp[Temp.size()-1] - Temp[0]) >= x)ans++;
			}
			BDD[i] = false;
			CDD.pop_back();
			break;
		}
		else if (!BDD[i]) {
			BDD[i] = true;
			CDD.push_back(ADD[i]);
			Dfs(i);
			BDD[i] = false;
			CDD.pop_back();
		}
	}
}
int main()
{
	cin >> n >> l >> r >> x;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		ADD[i] = a;
	}
	for (int i = 0; i < n; i++) {
		BDD[i] = true;
		CDD.push_back(ADD[i]);
		Dfs(i);
		BDD[i] = false;
		CDD.pop_back();
	}
	cout << ans << endl;
}