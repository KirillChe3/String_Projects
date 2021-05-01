#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>
#include <sstream>
#include <string>
#include <fstream>

using namespace std;

void replace_delimeters_by_space(string& text, string delimeters, char delim)
{
    std::size_t position = text.find_first_of(delimeters.c_str());
    while (position!=std::string::npos)
    {
        if( text[position]!=delim ) text[position] = delim;
        position = text.find_first_of ( delimeters.c_str(),position+1 );
    }
    stringstream ss(text);
    text.clear();
    string word;
    while ( ss >> word )
    text += word + delim;
}

vector<string> split(string& text, char delim)
{
    vector<string> vs;
    string word;
    stringstream ss(text);
    while (ss>>word) vs.insert(vs.end(), word);
    return vs;
}

int main(int argc, char* argv[])
{
    string string_from_file;
    cout << "Input character...";
    char ch1;
    cin >> ch1;
    ifstream file_txt;
    file_txt.open("my_text.txt", ios::in);

    while (!file_txt.eof())
{
getline(file_txt, string_from_file);
const char * delimeters=",.!? \n\t-"; //разделители
replace_delimeters_by_space(string_from_file, delimeters, ' ');
vector<string> vector_of_strings=split(string_from_file, ' ');
vector<string> vector_sorted{};
int k=0;
for (size_t i=0; i<vector_of_strings.size(); ++i)
    {
        const auto &string_from_file = vector_of_strings[i];
        for(size_t j =0; j<string_from_file.length(); ++j)
            {
                if (tolower(string_from_file[j]) == tolower(ch1))
                        {
                            k=k+1;
                            cout << "Sorted words:   " << vector_of_strings[i] << endl;
                      }
                //vector_sorted[i] = vector_of_strings[i];
            }
    }
 //for(auto m : vector_sorted)
 cout << "Words with given character founds "<< k << " times" << endl; ' ';
}
file_txt.close();
cin.get();
return 0;
}
