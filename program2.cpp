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
    
     void unpack(fstream &ifile)
    {
        char extra[45];
        while(!ifile.eof())
        {
            ifile.getline(name,20,'|');
            ifile.getline(sem,10,'|');
            ifile.getline(branch,10,'|');
            ifile.getline(extra,45,'\n');
            cout<<name<<" "<<sem<<" "<<branch<<" "<<extra<<endl; 
        }
        
    }
    
    int search(fstream &ifile, char key[20]){
        char extra[45];
        while(!ifile.eof()){
            ifile.getline(name,10,'|');
            ifile.getline(sem,10,'|');
            ifile.getline(branch,10,'|');
            ifile.getline(extra,45,'\n');
            if(strcmp(name,key)==0){
                cout<<"Record Found : ";
                cout<<name<<" "<<sem<<" "<<branch<<"\n";
                return 1;
            }
        }
        return 0;
    }
};

int main()
{
    fstream ofile,ifile;
    string filename;
    int ch;
    char key[20];
    program2 st;
    
    while(1)
    {
        
        cout<<"1]Packing\n2]Unpacking\n3]Search\n4]Exit\n";
        cin>>ch;
        switch(ch)
        {
            case 1:cout<<"Enter the filename\n";
                   cin>>filename;
                   ofile.open(filename,ios::out | ios::app);
                   st.pack(ofile);
                   ofile.close();
                   break;
            case 2:cout<<"Enter the filename\n";
                   cin>>filename;
                   ifile.open(filename,ios::in);
                   st.unpack(ifile);
                   ifile.close();
                   break;
            case 3:cout<<"Enter the filename\n";
                   cin>>filename;
                   cout<<"Enter the record you want to search\n";
                   cin>>key;
                   ifile.open(filename,ios::in);
                  if(st.search(ifile,key)==0){
                      cout<<"Record not found ";
                  }
                  ifile.close();
                  break;

            case 4:exit(0);
        }
    }
}
