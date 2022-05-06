#include <iostream>
#include <fstream>
#include <cstring>
#include <regex>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

void append();

int main()
{
	string function;

    cout << "Please, Choose a function to perform it:\n1- Appending:\n>>";
	// Getting the input from the user
	getline(cin, function);
	// Removing the spaces from the input string to the end of it, then returning a pointer to the beginning of the removed spaces then Erasing the content from if_remove returning pointer to the end of the string
	function.erase(remove_if(function.begin(), function.end(), ::isspace), function.end());
	cin.ignore(0);
    if (function == "1")
    {
		append();
        return 0;
    }
    else if (function == "2")
    {

    }
    else if (function == "3")
    {

    }
    else if (function == "4")
    {

    }
    else if (function == "5")
    {
 
    }
    else if (function == "6")
    {

    }
    else if (function == "7")
    {

    }
    else if (function == "8")
    {

    }
    else if (function == "9")
    {

    }
}

void append()
{  	
	string filename;

	cout << "Please Enter the name of a .txt file: ";

	getline(cin, filename);
	cin.ignore(0);

	filename += ".txt";

	fstream file;

	file.open(filename, ios::app | ios::out);

	if (file.fail())
	{
		cout << "This is a new file. I created it for you :)\n";
	}
	else
	{
		cout << "This File Already Exists.\n";
	}
	
	string text;

	cout << "Please Enter a content to add to the chosen file \nPress CTRL+Z when you finish\n>>";

    string buffer;

    while(true)
    {
        buffer = getchar();
        if (buffer[buffer.size() - 1] == EOF)
        {
            break;
        }
        text += buffer;
    }
    cout << text;
    file << text;
	file.close();
}

// fstream load(fstream &file, vector<string> &text)
// {
//      string filename;
    
// 	    cout << "Please Enter the name of a .txt file: ";

//      getline(cin, filename);
// 	    cin.ignore(0);

// 	    filename += ".txt";

// 	    file.open(filename);

// 	    if (file.fail())
// 	    {
// 		    cout << "This is a new file. I created it for you :)\n";
// 	    }
// 	    else
// 	    {
// 		    cout << "This File Already Exists.\n";
//          while(!file.eof())
//          {
//              char buff[250];
//              file.getline(buff, 250, '\n');
//              text.push_back(buff);
//          }
// 	    }
//      file.close();
// }