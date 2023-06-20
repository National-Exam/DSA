#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

void writeToFile(const string &filename, const vector<vector<string>> &data)
{
    ofstream file(filename);
    if (file.is_open())
    {
        for (const auto &row : data)
        {
            for (const auto &col : row)
            {
                file << col << ",";
            }
            file << "\n";
        }
        file.close();
        cout << "Data written to file successfully." << endl;
    }
    else
    {
        cerr << "Unable to open file." << endl;
    }
}

int main()
{
    string filename;
    vector<vector<string>> data;

    cout << "Enter the filename to save the data: ";
    cin >> filename;

    int numRecords;
    cout << "Enter the number of records: ";
    cin >> numRecords;

    cin.ignore(); // Ignore the newline character left by previous input

    for (int i = 0; i < numRecords; i++)
    {
        vector<string> row;

        string name, age, city;
        cout << "Enter data for record " << i + 1 << " (Name, Age, City): ";
        getline(cin, name, ',');
        getline(cin, age, ',');
        getline(cin, city);

        row.push_back(name);
        row.push_back(age);
        row.push_back(city);

        data.push_back(row);
    }

    writeToFile(filename, data);

    return 0;
}
