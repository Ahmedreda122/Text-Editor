#include <iostream>
#include <fstream>
#include <cstring>
#include <regex>
#include <algorithm>
#include <string>
#include <vector>
#include <cctype>
#include <map>

using namespace std;

typedef map<string, int> StrIntMap;

fstream file;
vector<string> text;
vector<string> mergedText;
string filename;

void empty();
void display();
void append();
void load(fstream &file, vector<string> &text, string& filename);
void save(fstream &file, vector<string> &text, vector<string> mergedText);
void encrypt();
void decrypt();
void upper();
void lower();
void capitalize();
void search();
void count();
void countWords(istream& in ,StrIntMap& words);
void nWords(string filename = filename);
void nCharacters(string filename = filename);
void nLines(string filename = filename);


int main()
{
	string function;

    load(file, text, filename);

    while (true)
    {
        cout << "\nPlease, Choose a function to perform it:\n1-  Appending\n2-  Display content\n3-  Empty the file.\n4-  Encrypt the content of the file.\n5-  Decrypt the content of the file.\n6-  Merge another file\n7-  Count the number of words\n8-  Count the number of characters\n9-  Count the number of lines\n10- Search for the word\n11- Count the number of times a word exist\n12- Turn the file content to upper case.\n13- Turn the file content to lower case.\n14- Turn file content to 1st caps\n15- Save\n16- Exit\n>>";
        // Getting the input from the user
        getline(cin, function);
        // Removing the spaces from the input string to the end of it, then returning a pointer to the beginning of the removed spaces then Erasing the content from if_remove returning pointer to the end of the string
        function.erase(remove_if(function.begin(), function.end(), ::isspace), function.end());
        cin.ignore(0);
        if (function == "1")
        {
            append();
        }
        else if (function == "2")
        {
            display();
        }
        else if (function == "3")
        {
            empty();
        }
        else if (function == "4")
        {
            encrypt();
        }
        else if (function == "5")
        {
            decrypt();
        }
        else if (function == "6")
        {
            load(file, mergedText, filename);
        }
        else if (function == "7")
        {
            nWords();
        }
        else if (function == "8")
        {
            nCharacters();
        }
        else if (function == "9")
        {
            nLines();
        }
        else if (function == "10")
        {
            search();
        }
        else if (function == "11")
        {
            count();
        }
        else if (function == "12")
        {
            upper();
        }
        else if (function == "13")
        {
            lower();
        }
        else if (function == "14")
        {
            capitalize();
        }        
        else if (function == "15")
        {
            save(file, text, mergedText);
        }
        else if (function == "16")
        {
            return 1;
        }
    }

}

void load(fstream &file, vector<string> &text, string& filename)
{

    cout << "Please Enter the name of a .txt file: ";

    getline(cin, filename);
    cin.ignore(0);

    filename += ".txt";

    file.open(filename, ios::in);

    if (file.fail())
    {
        cout << "\nThis is a new file. I created it for you :)\n";
    }
    else
    {
        cout << "\nThis File Already Exists.\n";
        while(!file.eof())
        {
            char buff[500];
            file.getline(buff, 500, '\n');
            text.push_back(string(buff));
        }
    }
    file.close();
}

void save(fstream &file, vector<string> &text, vector<string> mergedText)
{
    string filename;

    cout << "Please Enter the name of a .txt file that you want to save into: ";

    getline(cin, filename);
    cin.ignore(0);

    filename += ".txt";

    file.open(filename, ios::out);

    if (file.fail())
    {
        cout << "\nThis is a new file.We will save text into it.\n";
        for (string line: text)
        {
            file << line << '\n';
        }
    }
    else
    {
        cout << "\nThis File Already Exists. We will overwrite it\n";
        for(string line: text)
        {
            file << line << '\n';
        }
        if(!mergedText.empty())
        {
            for(string line: mergedText)
            {
                file << line << '\n';
                text.push_back(line);
            }
        }
    }
    file.close();
}

void append()
{  	
	cout << "\nPlease, Enter a content to add to the chosen file \nPress CTRL+Z without any content before it when you finish\n>>";

    string new_line;
    while(true)
    {
        new_line += getchar();
        if (new_line[new_line.size() - 1] == (char) 26)
        {
            // Delete the EOF char from end of the new_line string
            new_line.pop_back();
            // Add this "line" to the text vector
            text.push_back(new_line);
            break;
        }
        // IF you input a newline char (Pressed enter)
        else if (new_line[new_line.size() - 1] == '\n')
        {
            // Delete the newline char from end of the new_line string
            new_line.pop_back();
            // Add this "line" to the text vector
            text.push_back(new_line);
            // Empty the new_line string to input another line to it.
            new_line = "";
        }  
    }

}

void display()
{
	if (text.empty())
	{
		cout << "There is no content in this file to display.\n";
	}
	else
	{
		cout << "______________________________________\n\n";
		for(string line: text)
		{
			cout << line << '\n';
		}
		cout << "_____________________________________\n";
	}
}

void empty()
{
	char agree;
	
	string filename;

    cout << "Please Enter the name of a .txt file: ";

    getline(cin, filename);
    cin.ignore(0);

    filename += ".txt";

	cout << "Are you sure that you want to delete content of " << filename << "?\nPress Enter if you agree, Press anything else otherwise\n>>";
	agree = getchar();
	if (agree == '\n')
	{	
		file.open(filename, ios::out | ios::trunc);
		file.close();
	}
} 

void encrypt()
{
	for (int i = 0; i < text.size(); ++i)
	{
		for(int j = 0; j < text[i].size(); ++j)
		{
			text[i][j] = (char) ( (int) text[i][j] + 1);
		}
	} 
}

void decrypt()
{
	for (int i = 0; i < text.size(); ++i)
	{
		for(int j = 0; j < text[i].size(); ++j)
		{
			text[i][j] = (char) ( (int) text[i][j] - 1);
		}
	} 
}

void upper()
{
    for (int i = 0; i < text.size(); ++i)
    {
        // Transforming the whole string to uppercase.
        transform(text[i].begin(), text[i].end(), text[i].begin(), ::toupper);
    }
    
}

void lower()
{
    for (int i = 0; i < text.size(); ++i)
    {
        // Transforming the whole string to lowercase.
        transform(text[i].begin(), text[i].end(), text[i].begin(), ::tolower);
    }
    
}

void capitalize()
{
    for (int i = 0; i < text.size(); ++i)
    {
        text[i][0] = toupper(text[i][0]); 
    }
}

void search()
{
    string search;
    int offset;
    string line;

    ifstream Myfile;
    Myfile.open(filename);
    cout << "Type the name you want to search : " << endl;
    
    getline(cin, search);
    cin.ignore(0);
    
    if (Myfile.is_open())
    {
        while (!Myfile.eof())
        {
            getline(Myfile, line);
            if ((offset = line.find(search,0)) != string :: npos)
            {
                cout << "\nThe word "<< search << " has been founded!" << endl;
                Myfile.close();
                return;
            }  
        }
        cout << "\nThis word does not Exist.";
        Myfile.close();
    }    
    else
    {
        cout << "\nCould not open file"<<endl;
        return;
    }   
}

void count()
{
    ifstream in("data.txt");
    StrIntMap words_map;
    countWords(in, words_map);

    for(StrIntMap::iterator it = words_map.begin();it != words_map.end(); ++it)
    {
        cout << it->first << " occured "<< it->second << endl;
    }
}

void countWords(istream& in ,StrIntMap& words)
{
    string text;
    while(in >> text)
    {
        ++words[text];
    }
}


void nWords(string filename)
{
    ifstream indata;
    char ch;
    int words = 0;

    indata.open(filename);
    indata.get(ch);
    while(indata)
    {
        if (ch == '\n')
        {
            words++;
        }
        else if (ch == ' ')
            words++;

        indata.get(ch);
    }


    cout<<"\nNumber of Words: " << words << endl;
    return;
}

void nCharacters(string filename)
{
    ifstream indata;
    char ch;
    int chr = 0;

    indata.open(filename);
    indata.get(ch);
    while(indata)
    { 
        chr++;
        indata.get(ch);
    }

    cout<<"\nNumber of Characters: " << chr  << endl;
    return;
}

void nLines(string filename)
{
    ifstream indata;
    char ch;
    int lines = 0;

    indata.open(filename);
    indata.get(ch);
    while(indata)
    {
        if (ch == '\n')
        {
          lines++;
        }
        indata.get(ch);
    }

    cout<<"\nNumber of Lines: " << lines << endl;
    return;
}