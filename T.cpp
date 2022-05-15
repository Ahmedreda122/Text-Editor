/*#include<iostream>
#include<fstream>
#include<map>
#include<string>
typdef std ::map<std::string, int >StringIntMap;
void count_words(std::istream& in ,StrIntMap& words){

std::string text;
while(in>>text){
      ++words[text];
}

}
int main (int argc , chr **argv)
{
 std::ifstream in("AhmedRedaBayomy.txt")
 StrIntMap words_maps;
 cout_words(in,words_map);


 for(StrIntMap::iterator it = words_map.begin();it!=words_map.end(); ++it){
     std::cout <<it->first<<" occured "<<it->second<<std:endl;

}
}*/




#include<iostream>
#include<fstream>
#include<string>

using namespace std ;

int main (void){
string search ;
int offset ;
string line ;

 ifstream Myfile ;
 Myfile .open ("names.txt");
 cout<<"Type the name you want to search : "<<endl ;
 cin>> search ;

 if (Myfile.is_open())
 {
while (!Myfile.eof())
 {

 getline(Myfile,line);
 if ((offset = line.find(search,0)) != string :: npos)
{
    cout<< "The word has been founded"<<search<< endl;

}
Myfile.close();
}
 else
 cout<<"could not open file"<<endl;
 system("PAUSE");
 return 0 ;
}
