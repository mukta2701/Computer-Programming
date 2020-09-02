#include <bits/stdc++.h>

using namespace std ;

int main()
{
    int n;
    cin>>n ;
    long int d1=0,d2=0 ;

    int array[n][n];

    for (int i=0;i<n;i++) 
    {
    for(int j=0;j<n;j++)
    {
        cin>>array[i][j];
        if(i==j)
        {
            d1+=array[i][j] ;
        }
        if(i==n-j-1)
        {
            d2+=array[i][j];
        }

    }
    }
    cout<<abs(d1-d2)<<endl ;
    return 0 ;
}
