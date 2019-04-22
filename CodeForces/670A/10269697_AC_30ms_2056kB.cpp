#include<iostream>
using namespace std;

int main()
{
    int N,min,max;
    cin >> N;
    int a=N/7*2;
    int temp = N%7;
    if(temp>5)min =1;
    else min = 0;
    if(temp>2)max = 2;
    else max = temp;
    cout<<a+min<<" "<<a+max<<endl;
}
