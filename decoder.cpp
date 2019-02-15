#include <iostream>
#include <cstdlib>
#include <time.h>
#include <fstream>

using namespace std;

string dechange(int k,int l, int p, string cmsg)
{
    string msg=cmsg;
    for(int i=0;i<cmsg.length();i++)
    {
        msg[i]=(cmsg[i]+l-p)- k;
    }
    return msg;
}

void decode()
{
    cout<<"in decode"<<endl;
    int k,l,p;
    size_t m1length,m2length;
    string cmessage="";
    string message="",msg1="",msg2="";
    ifstream fileinput;
    fileinput.open("code.pass");
    if(fileinput.is_open())
    {
        fileinput>>k>>l>>p>>cmessage;
        message=dechange(k,l,p,cmessage);
        fileinput>>m2length>>k>>l>>p;
        if((char)(message[0])=='2')
        {
            for(int i=5;i<m2length+1;i++)
            {
                msg2=msg2+message[i];
            }
        }
        else
        {
            for(int i=4;i<m2length+1;i++)
            {
                msg2=msg2+message[i];
            }
        }
        msg2=dechange(k,l,p,msg2);

        fileinput>>m1length>>k>>l>>p;
        int s=m2length+1;
        if((char)(message[s])=='2')
        {
            for(int i=s+5;i<s+m1length+1;i++)
            {
                msg1=msg1+message[i];
            }
        }
        else
        {
            for(int i=s+4;i<s+m1length+1;i++)
            {
                msg1=msg1+message[i];
            }
        }
        msg1=dechange(k,l,p,msg1);
        message=msg1+msg2;
        cout << message << endl;
        fileinput.close();
    }
    else cout<<"file was not opened/couldnt be opened (check if code.txt exists)"<<endl;
}
