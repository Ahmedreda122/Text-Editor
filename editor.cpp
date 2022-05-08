#include <iostream>
#include <fstream>
#include <cstring>
#include <regex>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

void empty();
void display();
void append();
void load(fstream &file, vector<string> &text);
void save(fstream &file, vector<string> &text);
void encrypt();
void decrypt();

fstream file;
vector<string> text;

int main()
{
	string function;

    while (true)
    {
        cout << "Please, Choose a function to perform it:\n1- Appending\n2- Display content\n3- Empty the file.\n4- Encrypt the content of the file.\n5- decrypt the content of the file.\n15- Save\n16- Exit\n>>";
        // Getting the input from the user
        getline(cin, function);
        // Removing the spaces from the input string to the end of it, then returning a pointer to the beginning of the removed spaces then Erasing the content from if_remove returning pointer to the end of the string
        function.erase(remove_if(function.begin(), function.end(), ::isspace), function.end());
        cin.ignore(0);
        if (function == "1")
        {
            load(file, text);
            append();
            return 0;
        }
        else if (function == "2")
        {
            load(file, text);
            display();
            return 0;
        }
        else if (function == "3")
        {
            empty();
        }
        else if (function == "4")
        {
            load(file, text);
            encrypt();
            return 0;
        }
        else if (function == "5")
        {
            load(file, text);
            decrypt();
            return 0;

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
        else if (function == "10")
        {

        }
        else if (function == "11")
        {

        }
        else if (function == "15")
        {
            save(file, text);
        }
        else if (function == "16")
        {
            return 1;
        }
    }

}

void load(fstream &file, vector<string> &text)
{
    string filename;

    cout << "Please Enter the name of a .txt file: ";

    getline(cin, filename);
    cin.ignore(0);

    filename += ".txt";

    file.open(filename);

    if (file.fail())
    {
        cout << "This is a new file. I created it for you :)\n";
    }
    else
    {
        cout << "This File Already Exists.\n";
        while(!file.eof())
        {
            char buff[500];
            file.getline(buff, 500, '\n');
            text.push_back(string(buff));
        }
    }
    file.close();
}

void save(fstream &file, vector<string> &text)
{
    string filename;

    cout << "Please Enter the name of a .txt file that you want to save into: ";

        getline(cin, filename);
        cin.ignore(0);

        filename += ".txt";

        file.open(filename, ios::out);

        if (file.fail())
        {
            cout << "This is a new file.We will save text into it.\n";
            for (string line: text)
            {
                file << line;
            }
        }
        else
        {
            cout << "This File Already Exists.We will overwrite it\n";
            for(string line: text)
            {
                file << line;
            }
        }
        file.close();
}

void append()
{  	
	cout << "Please, Enter a content to add to the chosen file \nPress CTRL+Z without any content before it when you finish\n>>";

    string buffer;
    text.push_back("\n");
    while(true)
    {
        buffer = getchar();
        if (buffer[buffer.size() - 1] == EOF)
        {
            break;
        }
        text.push_back(buffer);
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