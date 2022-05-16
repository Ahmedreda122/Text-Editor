#ifndef EDITORFNS_H_
#define EDITORFNS_H_

#include <string>
#include <map>

using namespace std;

typedef map<string, int> StrIntMap;

fstream file;
vector<string> text;
vector<string> mergedText;
string filename;

// Defining the functions.
void empty();
void display();
void append();
string load(fstream &file, vector<string> &text);
void save(fstream &file, vector<string> &text, vector<string> mergedText);
void encrypt();
void decrypt();
void upper();
void lower();
void capitalize();
void search();
void count();
void countWords(istream& in ,StrIntMap& words);
void nWords();
void nCharacters();
void nLines();

#endif