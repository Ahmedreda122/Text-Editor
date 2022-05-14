#include <iostream>
#include <fstream>
#include <cstring>
#include <regex>
#include <algorithm>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

fstream file;
vector<string> text;
vector<string> mergedText;

void empty();
void display();
void append();
void load(fstream &file, vector<string> &text);
void save(fstream &file, vector<string> &text, vector<string> mergedText);
void encrypt();
void decrypt();
void upper();
void lower();
void capitalize();


int main()
{
	string function;

    load(file, text);

    while (true)
    {
        cout << "Please, Choose a function to perform it:\n1- Appending\n2- Display content\n3- Empty the file.\n4- Encrypt the content of the file.\n5- decrypt the content of the file.\n6- Merge another file\n12- Turn the file content to upper case.\n13- Turn the file content to lower case.\n14- Turn file content to 1st caps\n15- Save\n16- Exit\n>>";
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
            load(file, mergedText);
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

void load(fstream &file, vector<string> &text)
{
    string filename;

    cout << "Please Enter the name of a .txt file: ";

    getline(cin, filename);
    cin.ignore(0);

    filename += ".txt";

    file.open(filename, ios::in);

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
        cout << "This is a new file.We will save text into it.\n";
        for (string line: text)
        {
            file << line << '\n';
        }
    }
    else
    {
        cout << "This File Already Exists. We will overwrite it\n";
        for(string line: text)
        {
            file << line << '\n';
        }
        if(!mergedText.empty())
        {
            for(string line: mergedText)
            {
                file << line << '\n';
            }
        }
    }
    file.close();
}

void append()
{  	
	cout << "Please, Enter a content to add to the chosen file \nPress CTRL+Z without any content before it when you finish\n>>";

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