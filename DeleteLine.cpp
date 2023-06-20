#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void deleteLineFromFile(const string &filename, int lineToDelete)
{
    ifstream inputFile(filename);
    ofstream outputFile("temp.csv");

    if (inputFile.is_open() && outputFile.is_open())
    {
        string line;
        int lineNum = 0;

        while (getline(inputFile, line))
        {
            lineNum++;
            if (lineNum != lineToDelete)
            {
                outputFile << line << "\n";
            }
        }

        inputFile.close();
        outputFile.close();

        // Rename the temporary file to the original filename
        remove(filename.c_str());
        rename("temp.csv", filename.c_str());

        cout << "Line deleted successfully." << endl;
    }
    else
    {
        cerr << "Unable to open file." << endl;
    }
}

int main()
{
    deleteLineFromFile("data.csv", 2); // Delete line number 2

    return 0;
}
