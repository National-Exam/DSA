#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

vector<vector<string>> readFromFile(const string &filename)
{
    vector<vector<string>> data;
    ifstream file(filename);
    if (file.is_open())
    {
        string line;
        while (getline(file, line))
        {
            vector<string> row;
            size_t startPos = 0;
            size_t commaPos = line.find(',');

            while (commaPos != string::npos)
            {
                row.push_back(line.substr(startPos, commaPos - startPos));
                startPos = commaPos + 1;
                commaPos = line.find(',', startPos);
            }

            if (startPos != line.length())
                row.push_back(line.substr(startPos));

            data.push_back(row);
        }

        file.close();
    }
    else
    {
        cerr << "Unable to open file." << endl;
    }

    return data;
}

int main()
{
    vector<vector<string>> data = readFromFile("data.csv");

    for (const auto &row : data)
    {
        for (const auto &col : row)
        {
            cout << col << " ";
        }
        cout << endl;
    }

    return 0;
}
