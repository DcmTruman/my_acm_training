#include<iostream>
using namespace std;
int Map[6][6];
int times = 0;
int dx[7] = { 0,-1,0,1,0 }, dy[7] = { -1,0,0,0,1 };
bool checkWin()
{
	int a = Map[0][0];
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (Map[i][j] != a) {
				return false;
			}
		}
	}
	return true;
}
bool win = false;
void flip(int x, int y)
{
	for (int i = 0; i < 5; i++) {
			if(Map[x + dx[i]][y + dy[i]])Map[x + dx[i]][y + dy[i]] =0;
			else Map[x + dx[i]][y + dy[i]] = 1;
	}
}
void Dfs(int i, int j,int d)
{
	if (d == times) {
		win = checkWin();
		return;
	}
	if (win || i==4) {
		return;
	}
	flip(i, j);
	if (j < 3) Dfs(i, j + 1, d + 1);
	else Dfs(i + 1, 0, d + 1);

	flip(i, j);                      //  还原状态，不对点(row,col)进行翻动。
	if (j  < 3) Dfs(i, j + 1, d );
	else Dfs(i + 1, 0, d );
}
int main()
{
	int ans;
	bool Flag = false;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			char s;
			cin >> s;
			if (s == 'b') {
				Map[i][j] = 0;
			}
			else {
				Map[i][j] = 1;
			}
		}
	}
	for (times = 0; times <= 16; times++)
	{
		Dfs(0, 0, 0);
		if (win)break;
	}
	if (win)cout << times << endl;
	else cout << "Impossible" << endl;
}