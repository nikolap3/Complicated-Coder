#include <iostream>
#include <cstdlib>
#include <time.h>
#include <fstream>

using namespace std;

size_t length1=0,length2=0;

string inttostring(int n,string m)
{
    if(n<10)
    {
        switch((int)n)
        {
            case 0:
                return m+"0";
            case 1:
                return m+"1";
            case 2:
                return m+"2";
            case 3:
                return m+"3";
            case 4:
                return m+"4";
            case 5:
                return m+"5";
            case 6:
                return m+"6";
            case 7:
                return m+"7";
            case 8:
                return m+"8";
            case 9:
                return m+"9";
        }
    }
    return m+inttostring(n/10,m)+inttostring(n%10,m);
}

string change(string msg)
{
    int k=rand()%18 +1, l=rand()%5 +3,p=rand()%7 +2;
    string cmsg=msg;
    for(unsigned int i=0;i<msg.length();i++)
    {
        cmsg[i]=msg[i]+k-l+p;
    }
    if(k<10)
        cmsg ="1"+inttostring(k,"")+inttostring(l,"")+inttostring(p,"")+cmsg;
    else
        cmsg ="2"+inttostring(k,"")+inttostring(l,"")+inttostring(p,"")+cmsg;
    if(cmsg=="")cout<<"message wasnt codded correctly"<<endl;
    return cmsg;
}

void split(string *msg1,string *msg2, string msg)
{
    int l=rand()%(msg.length()) +1;
    for(int i=0;i<l;i++)
    {
        *msg1=*msg1+msg[i];
    }
    *msg1=change(*msg1);
    length1=(*msg1).length();
    for(unsigned int i=l;i<msg.length();i++)
    {
        *msg2=*msg2+msg[i];
    }
    *msg2=change(*msg2);
    length2=(*msg2).length();
    return;
}

void code()
{
    cout<<"in code"<<endl;
    string cmessage="";
    string message="";
    char sm[256];
    ofstream fileoutput;
    ifstream fileinput;
    fileoutput.open("code.txt");
    srand(time(0));
    cin.get();
    cin.getline(sm,256);
    string msg1="",msg2="";
    message=sm;
    split(&msg1,&msg2,message);
    cmessage=cmessage+msg2+msg1;
    cmessage=change(cmessage);
    if(fileoutput.is_open())
    {
        if((char)(cmessage[0])=='2')
        {
            fileoutput<<cmessage[1]<<cmessage[2]<<endl<<cmessage[3]<<endl<<cmessage[4]<<endl;
            for(unsigned int i=5;i<cmessage.length();i++)fileoutput<<cmessage[i];
            fileoutput<<endl;
            if((char)(msg2[0])=='2')
            {
                fileoutput<<length2-1<<endl<<msg2[1]<<msg2[2]<<endl<<msg2[3]<<endl<<msg2[4]<<endl;
            }
            else
            {
                fileoutput<<length2-1<<endl<<msg2[1]<<endl<<msg2[2]<<endl<<msg2[3]<<endl;
            }
            if((char)(msg1[0])=='2')
            {
                fileoutput<<length1-1<<endl<<msg1[1]<<msg1[2]<<endl<<msg1[3]<<endl<<msg1[4];
            }
            else
            {
                fileoutput<<length1-1<<endl<<msg1[1]<<endl<<msg1[2]<<endl<<msg1[3];
            }
        }
        else
        {
            fileoutput<<cmessage[1]<<endl<<cmessage[2]<<endl<<cmessage[3]<<endl;
            for(unsigned int i=4;i<cmessage.length();i++)fileoutput<<cmessage[i];
            fileoutput<<endl;
            if((char)(msg2[0])=='2')
            {
                fileoutput<<length2-1<<endl<<msg2[1]<<msg2[2]<<endl<<msg2[3]<<endl<<msg2[4]<<endl;
            }
            else
            {
                fileoutput<<length2-1<<endl<<msg2[1]<<endl<<msg2[2]<<endl<<msg2[3]<<endl;
            }
            if((char)(msg1[0])=='2')
            {
                fileoutput<<length1-1<<endl<<msg1[1]<<msg1[2]<<endl<<msg1[3]<<endl<<msg1[4];
            }
            else
            {
                fileoutput<<length1-1<<endl<<msg1[1]<<endl<<msg1[2]<<endl<<msg1[3];
            }
        }
        cout << cmessage << endl;
        fileoutput.close();
    }
    else cout<<"file was not opened/created"<<endl;
}
