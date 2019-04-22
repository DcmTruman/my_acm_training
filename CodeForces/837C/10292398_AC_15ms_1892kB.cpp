#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int ans = 0;
typedef struct rec{
    int x,y,s;
}R;
vector<R>Rec;

int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    for( int i = 0;i<n;i++)
    {
        R temp;
        cin>>temp.x>>temp.y;
        temp.s = temp.x * temp.y;
        Rec.push_back(temp);
    }
    for( int i = 0;i<n-1;i++){
        for( int j = i+1;j<n;j++){
            if(((Rec[i].x+Rec[j].x<=m)&&(max(Rec[i].y,Rec[j].y)<=k))||
            ((Rec[i].y+Rec[j].x<=m)&&(max(Rec[i].x,Rec[j].y)<=k))||
            ((Rec[i].x+Rec[j].y<=m)&&(max(Rec[i].y,Rec[j].x)<=k))||
            ((Rec[i].y+Rec[j].y<=m)&&(max(Rec[i].x,Rec[j].x)<=k))||
             ((Rec[i].x+Rec[j].x<=k)&&(max(Rec[i].y,Rec[j].y)<=m))||
              ((Rec[i].y+Rec[j].x<=k)&&(max(Rec[i].x,Rec[j].y)<=m))||
              ((Rec[i].x+Rec[j].y<=k)&&(max(Rec[i].y,Rec[j].x)<=m))||
              ((Rec[i].y+Rec[j].y<=k)&&(max(Rec[i].x,Rec[j].x)<=m)))
                {
                    ans = (Rec[i].s+Rec[j].s>ans)?Rec[i].s+Rec[j].s:ans;
                }
             
        }
    }
    cout<<ans;
}