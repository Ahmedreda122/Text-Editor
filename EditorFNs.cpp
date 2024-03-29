/* 
    Program   : editor.cpp
    Purpose   : Devoloping the act of
                importing a file and Choosing an 
                option to be done for it 
                Counting , Merge , Searching , etc

    Authors   : Ahmed Reda Bayomi       ID: 20210019
                Youssef Hamed Mohamed   ID: 20210494

    Date      : 16 MAY 2022
    Version   : 1.0 
 */

#include <iostream>
#include <fstream>
#include <cstring>
#include <regex>
#include <algorithm>
#include <vector>
#include <cctype>
#include "EditorFNs.h"

using namespace std;

string load(fstream &file, vector<string> &text)
{
    string filename;

    cout << "Please Enter the name of a .txt file: ";

    getline(cin, filename);
    cin.ignore(0);

    filename += ".txt";

    // Opening file in reading mode
    file.open(filename, ios::in);

    // If file cannot be found or opened
    if (file.fail())
    {
        cout << "\nThis is a new file. I created it for you :)\n";
    }
    else
    {
        cout << "\nThis File Already Exists.\n";
        // While the reading cursor does not reach the end of the file
        while(!file.eof())
        {
            // creating a Buffer
            char buff[500];
            // Storing the line from the file to the buffer
            file.getline(buff, 500, '\n');
            // Adding that buffer to a vector
            text.push_back(string(buff));
        }
    }
    // Closes the file
    file.close();
    // Returning the name of the file
    return filename;
}

void save(fstream &file, vector<string> &text, vector<string> mergedText)
{
    string filename;

    cout << "Please Enter the name of a .txt file that you want to save into: ";
    
    getline(cin, filename);
    cin.ignore(0);

    filename += ".txt";

    // Opening file in write mode
    file.open(filename, ios::out);

    // If file cannot be found or opened
    if (file.fail())
    {
        // Print this
        cout << "\nThis is a new file. We will save text into it.\n";
    }
    else
    {
        // Otherwise, print this
        cout << "\nThis File Already Exists. We will overwrite it\n";
    }

    // For every line(element) in text vector
    for(string line: text)
    {
        // Write the line in the file 
        file << line << '\n';
    }
    // If we load a content from a file to be merged to this file, then write(add) it too
    if(!mergedText.empty())
    {
        // For every line(element) in text vector
        for(string line: mergedText)
        {
            // Write the line in the file 
            file << line << '\n';
            /* 
                Add the content of the mergedText vector 
                To "text" vector to edit on them both if user choose another option after this
                In other words merge the two vectors into the first ("text" vector)
                And perform any possible incoming changes to it. 
            */
            text.push_back(line);
        }
    }
    file.close();
}

void append()
{  	
	cout << "\nPlease, Enter a content to add to the chosen file \nPress CTRL+Z without any content before it then hit Enter, Once you finish\n>>";

    string new_line;
    while(true)
    {
        // Get a character Then add it in new_line string
        new_line += getchar();
        // If the last character in the new_line was EOF or CTRL+Z (Pressed Ctrl+Z then Enter)
        if (new_line[new_line.size() - 1] == (char) 26 || new_line[new_line.size() - 1] == EOF)
        {
            // Delete the EOF char from end of the new_line string
            new_line.pop_back();
            // Add this "new_line" to the text vector
            text.push_back(new_line);
            // And break the loop
            break;
        }
        // IF you input a newline char (Pressed enter)
        else if (new_line[new_line.size() - 1] == '\n')
        {
            // Delete the newline char from end of the new_line string
            new_line.pop_back();
            // Add this "new_line" to the text vector
            text.push_back(new_line);
            // Empty the new_line string to input another line to it.
            new_line = "";
        }  
    }

}

void display()
{
    // If the file was empty tell them there's no thing to display
	if (text.empty())
	{
		cout << "There is no content in this file to display.\n";
	}
	else
	{
		cout << "______________________________________\n\n";
        // For every line in the text vector, Print this line
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
    // Get the confirmation that the user really want to empty the file
	cout << "Are you sure that you want to delete content of " << filename << "?\nPress Enter if you agree, Press anything else otherwise\n>>";
	agree = getchar();
    // If user pressed Enter or agreed
	if (agree == '\n')
	{	
        // Opens the file in writing mode and truncate (or delete) its previous content.
		file.open(filename, ios::out | ios::trunc);
        // Closes the file
		file.close();
	}
} 

void encrypt()
{
    // Looping after every character in the vector and increasing its ASCII Code by one 
    
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
    // Looping after every character in the vector and decreasing its ASCII Code by one in order to decrypt it
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
        // Transforming the whole string to uppercase by Getting every character in the string and perform toupper function to it.
        transform(text[i].begin(), text[i].end(), text[i].begin(), ::toupper);
    }
    
}

void lower()
{
    // Looping after every element (line) in the text vector
    for (int i = 0; i < text.size(); ++i)
    {
        // Transforming the whole string to lowercase by Getting every character in the string and perform tolower function to it.
        transform(text[i].begin(), text[i].end(), text[i].begin(), ::tolower);
    }
    
}

void capitalize()
{
    // Looping after every element (line) in the text vector
    for (int i = 0; i < text.size(); ++i)
    {
        // Taking the first char of every line and uppercase it
        text[i][0] = toupper(text[i][0]);
        // Looping over the rest of characters in the line  
        for (int j = 1; j < text[i].size(); ++j)
        {
            /*
               If (a space or a comma or a dot or a semicolon or colon or score or question mark) was followed by the current character, 
               Capitalize it(turn it to uppercase)
            */
            if (text[i][j-1] == ' ' || text[i][j-1] == ',' || text[i][j-1] == '.' || text[i][j-1] == ';' || text[i][j-1] == ':' || text[i][j-1] == '-' || text[i][j-1] == '?')
            {
                text[i][j] = toupper(text[i][j]);
            }
        }
    }
}

// Searching for any word
void search()
{
    string search;
    int offset;
    string line;
    //geting the word from the user
    ifstream Myfile;
    Myfile.open(filename);//open file
    cout << "Type the name you want to search : " << endl;

    getline(cin, search); //search for the word
    cin.ignore(0);
    
    if (Myfile.is_open())
    {
        while (!Myfile.eof())
        {
            getline(Myfile, line);
            if ((offset = line.find(search,0)) != string :: npos)
            {/*if the word is found 
               out put the the word *** has been founded*/
                cout << "\nThe word "<< search << " has been founded!" << endl;
                Myfile.close(); //close file
                return;
            }  
        }/* if the word is not found
            out put the the word does not exist */
        cout << "\nThis word does not Exist.";
        Myfile.close();
    }    
    else
    { //for any other problems
        cout << "\nCould not open file"<<endl;
        return;
    }   
}

void count()
{//function for counting
    ifstream in(filename);
    StrIntMap words_map;
    countWords(in, words_map);

    for(StrIntMap::iterator it = words_map.begin();it != words_map.end(); ++it)
    {
        cout << it->first << " occured "<< it->second << endl;
    }
}//pointer for labboling the search with the file

void countWords(istream& in ,StrIntMap& words)
{
    string text;
    while(in >> text)
    {
        ++words[text];
    }
}


void nWords()//function for counting words
{
    ifstream indata;
    char ch;
    int words = 0;/*incialize the words with zero
    to be add by each backspace or new line*/

    indata.open(filename);//open searching file
    indata.get(ch);//get all char
    while(indata)
    {
        if (ch == '\n')/*if you are going new line
        then words will be add by one*/
        {
            words++;
        }
        else if (ch == ' ')
            words++;/*if you are tabimg backspace
        then words will be add by one*/

        indata.get(ch);
    }


    cout<<"\nNumber of Words: " << words << endl;
    return;
}

void nCharacters()//function for counting characters
{
    ifstream indata;
    char ch;
    int chr = 0;/*incialize the characters with zero
    to be add by each backspace or new line*/

    indata.open(filename);
    indata.get(ch);
    while(indata)
    { 
        chr++;//count all char
        indata.get(ch);
    }

    cout<<"\nNumber of Characters: " << chr  << endl;
    return;
}

void nLines()//function for counting lines
{
    ifstream indata;
    char ch;
    int lines = 0;/*incialize the lines with zero
    to be add by each backspace or new line*/

    indata.open(filename);
    indata.get(ch);
    while(indata)
    {
        if (ch == '\n')
        {/*if you are going new line
        then words will be add by one*/
          lines++;
        }
        indata.get(ch);
    }

    cout<<"\nNumber of Lines: " << lines << endl;
    return;
}