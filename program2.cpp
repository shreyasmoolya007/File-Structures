#include<bits/stdc++.h>
#include<fstream>
#include<iostream>
using namespace std;
class program2
{
    private : char name[20],sem[10],branch[10],buff[45];
    public : void read()
    {
        cout<<"Enter the Name\n";
        cin>>name;
        cout<<"Enter Semester\n";
        cin>>sem;
        cout<<"Enter the Branch\n";
        cin>>branch;
    }

    void pack(fstream &ofile)
    {
        int input;
        cout<<"Enter the number of students\n";
        cin>>input;
        for(int i=0;i<input;i++)
        {
            read();
        strcpy(buff,"");
        strcat(buff,name);
        strcat(buff,"|");
        strcat(buff,sem);
        strcat(buff,"|");
        strcat(buff,branch);
        strcat(buff,"|");
        while(strlen(buff)<45)
        {
            strcat(buff,"!");
        }
        strcat(buff,"\n");
        ofile.write(buff,strlen(buff));
        }
        
    }
};


int main()
{
    fstream ofile;
    string filename;
    program2 st;
    cout<<"Enter the filename\n";
    cin>>filename;
    ofile.open(filename,ios::out | ios::app);
    st.pack(ofile);
    ofile.close();
    return 0;
}