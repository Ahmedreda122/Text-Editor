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

#include "EditorFNs.cpp"

using namespace std;


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