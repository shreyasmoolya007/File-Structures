#include<bits/stdc++.h>
#include<iostream>
using namespace std;
class program1
{
    private:char a[10][20];
    public: void std_io();
    public: void file_io();
};
void program1 :: std_io()
{
    int n;
    string s1;
    cout<<"Enter Number of Names\n";
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=0;i<n;i++)
    {
        s1=a[i];
        reverse(s1.begin(),s1.end());
        cout<<s1<<"\n";
    }
}

void program1 :: file_io()
{
    fstream f1;
    string ch;
    char input[10];
    cout<<"Enter the Filename\n";
    cin>>input;
    f1.open(input,ios::in);
    while(1)
    {
        f1>>ch;
        reverse(ch.begin(),ch.end());
        if(f1.fail()) break;
        cout<<ch<<"\n";
    }
}
int main()
{
    program1 x;
    //x.std_io();
    x.file_io();
}