#include <bits/stdc++.h>

using namespace std ;

int main()
{
    int s ; //starting point of sam's house
    int t ; //end point...
    int a ; //loc of apple tree
    int b ; //loc of orange tree
    int m ;
    int n ;
    int app, appcnt=0 ;
    int oran, orancnt=0 ;
    cin>>s>>t>>a>>b>>m>>n ;

    for(int i=0;i<m;i++)
    {
        cin>>app ;
        if(a+app>=s && a+app<=t)
        {
            appcnt++ ;
        }
        
    }
    for(int j=0;j<n;j++)
    {
        cin>>oran ;
        if(b+oran>=s && b+oran<=t)
        {
            orancnt++ ;
        }
    }
    cout<<appcnt<<endl ;
    cout<<orancnt<<endl ;
    return 0 ;


}
