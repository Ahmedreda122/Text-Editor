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


int main()
{
	string function;

    // Storing filename in a variable to open it again once we need that
    filename = load(file, text);

    while (true)
    {
        // Displaying Menu
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
            load(file, mergedText);
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
            if (text[i][j-1] == ' ' || text[i][j-1] == ',' || text[i][j-1] == '.' || text[i][j-1] == ';' || text[i][j-1] == ':' || text[i][j-1] == '-'|| text[i][j-1] == '?')
            {
                text[i][j] = toupper(text[i][j]);
            }
        }
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
    ifstream in(filename);
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


void nWords()
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

void nCharacters()
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

void nLines()
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