#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

void updateValueInFile(const string &filename, const string &searchValue, const vector<string> &newData)
{
    ifstream inputFile(filename);
    ofstream outputFile("temp.csv");

    if (inputFile.is_open() && outputFile.is_open())
    {
        string line;
        bool valueFound = false;

        while (getline(inputFile, line))
        {
            if (line.find(searchValue) != string::npos)
            {
                valueFound = true;
                for (const auto &data : newData)
                {
                    outputFile << data << ",";
                }
                outputFile << "\n";
            }
            else
            {
                outputFile << line << "\n";
            }
        }

        inputFile.close();
        outputFile.close();

        if (valueFound)
        {
            remove(filename.c_str());
            rename("temp.csv", filename.c_str());
            cout << "Value updated successfully." << endl;
        }
        else
        {
            cerr << "Value not found in the file." << endl;
            remove("temp.csv");
        }
    }
    else
    {
        cerr << "Unable to open file." << endl;
    }
}

int main()
{
    string filename = "data.csv";
    string searchValue;
    vector<string> newData = {"Alice", "28", "Tokyo"};

    cout << "Enter the value to search for: ";
    cin >> searchValue;

    updateValueInFile(filename, searchValue, newData);

    return 0;
}
