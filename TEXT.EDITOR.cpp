/*#include<bits/stdc++.h>
using namespace std ;
int main()
{
    string  sen,res ;
    int counter = 0 ;
    getline(cin,sen);
    for(int i=0 ; i<sen.size();i++){
       if (sen[i]!=32 && sen[i]!='!' && sen[i]!='.' && sen[i]!=',' && sen[i]!='?' && sen[i]!='#' && sen[i]!='@' && sen[i]!='$' ){
          res+=sen[i];
       }
               if((sen[i]==32 ||sen[i]=='!' ||sen[i]=='.' ||sen[i]==',' ||sen[i]=='?' ||sen[i]=='#' ||sen[i]=='@' ||sen[i]=='$'|| i == sen.size()-1 ) && res.size()!=0){
    counter++ ;
    res = "";
      }
    }
    cout<<counter ;
    return 0 ;
}*/


#include<iostream>
#include<fstream>

using namespace std;

int main ()
{   ifstream indata ;
    char ch;
    int lines = 0 , words = 0 , chr = 0 ;
    string file_name ;
    getline(cin, file_name);
    file_name += ".txt";


    indata.open(file_name);
    indata.get(ch);
    while(indata)
    {
        if (ch == '\n'){
          lines++;words++;
        }
        else if (ch == ' ')
          words++ ;
        else
          chr++;
          indata.get(ch);
    }

    cout<<"1-Lines = "<<lines <<endl ;
    cout<<"2-Words = "<<words <<endl ;
    cout<<"3-characters = "<<chr  <<endl;


    return 0;
}
