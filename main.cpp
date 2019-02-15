#include <iostream>
#include <cstdlib>
#include <time.h>
#include <fstream>
#include "head.h"
#include <string.h>
using namespace std;

int main()
{
    int a;
    g:
    cout << "1 = code"<<endl<<"2 = decode"<<endl;
    cin>>a;
    //entering a word will break this
    switch((int)a) //choosing an action
    {
        case 1:
            code();
            break;
        case 2:
            decode();
            break;
        default:
            cout<<"Invalid input"<<endl;
            goto g;
    }
    cout<<"type 1 if you want to leave"<<endl;
    cin>>a;
    //entering a word will break this
    switch(a)
    {
        case 1:
            break;
        default:
            goto g;
    }
    return 0;
}
