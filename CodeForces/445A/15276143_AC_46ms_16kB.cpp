 #include<iostream>
 #include<stdio.h>
 using namespace std;
 
 
    int main()
    {
        int n,m;
        cin>>n>>m;
        for(int i=0;i<n;i++)
		{
           // getchar();
            for(int j=0;j<m;++j)
            {
                char c;cin>>c;
                if(c =='-')cout<<c;
                else
                {
                	if((i+j)%2==0)cout<<"B";
                	else cout<<"W";
				}
            }
            cout<<endl;
        }
        return 0;
    }