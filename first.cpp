#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>
#include<fstream>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;
string getCurrentTimeFormatted()
{
    // Get current system time
    time_t currentTime = time(nullptr);

    string timeString = ctime(&currentTime);   

    return timeString;
}

string helpMenu () 
{
    string headerLine = "============================================\n\n";
    string headerTitle = "*           HELP MENU             * \n\n";
    string helpCommands =
        "add <Location>                       :Add a new location \n"
        "delete <Location>                    :Delete an existing location \n"
        "record <Location> <disease> <cases>  :Record a disease and its cases \n"
        "list locations                       :List all existing locations \n"
        "list diseases                        :List  existing diseases in location \n"
        "where <disease>                      :Find where disease exists \n";
        "cases <location> <disease>           :Find cases of a disease in locations \n";
        "cases <disease>                      :Find total cases of a disease in location \n";
        "help                                 :Prints user manual \n";
        "exit                                 :Exit the program \n";


        return headerLine + headerTitle + headerLine + helpCommands;
        
}

void saveToFile( string data, string fileName)
{
        ofstream outputFile;
        outputFile.open(fileName, ios::app);
        if(!outputFile.is_open()){
            cout << "Error opening file" << endl;
        }else{
            outputFile << data << endl;
        }
    outputFile.close();
}

vector<string> splitString(const string &input)
{
    vector<string> tokens;
    istringstream iss(input);
    string token;

    while (iss >> token)
    {
            tokens.push_back(token);
    }

    return tokens;
}

vector<string> readCSV(string filename, int column)
{
    vector<string> columnData;

    ifstream file(filename);
    if (file.is_open())
    {
            string line;
            while (getline(file, line))
            {
                stringstream ss(line);
                string token;
                int currentColumn = 0;
                while (getline(ss, token, ','))
                {
                    if (currentColumn == column)
                    {
                        columnData.push_back(token);
                        break;
                    }
                    currentColumn++;
                }
            }
            file.close();
    }
    else
    {
            cout << "Failed to open the file: " << filename << endl;
    }

    return columnData;
}

void sortData(vector<string> &data)
{
    sort(data.begin(), data.end());
}

void deleteLocation (string fileName,string givenLocation) {
   ifstream file(fileName);
   stringstream ss;
   if(file.is_open()){
    string line;
    while(getline(file,line)){
        if(line.find(givenLocation) != string::npos){
            continue;
        }
        ss << line << endl;
    }
    file.close();
    ofstream outfile(fileName);
    outfile << ss.str() << endl;
    outfile.close();    
   }else{
    cout << "Failed to open the fiels" << endl;
   }
}
vector<string> findLocationByDisease(string fileName, string givenDisease)
{
   vector<string> results;
   ifstream file(fileName);   
   if (file.is_open())
   {
    string line;
    while (getline(file, line))
    {
        if (line.find(givenDisease) != string::npos)
        {
            results.push_back(line.substr(0,line.find(",")));
        }        
    } 
    file.close();
   }
   else
   {
    cout << "Failed to open the fiels" << endl;
   }
   return results;
}
int countCases(string filename, string disease, string location = "")
{
   int result = 0;
   string line;
   ifstream infile;
   infile.open(filename);
   while (getline(infile, line))
   {
    if (line.find(disease) != string::npos && (location.empty() ? true : line.find(location) != string::npos))
    {
        vector<string> tokens;
        string::size_type startPos = 0;
        string::size_type commaPos = line.find(',');

        while (commaPos != string::npos)
        {
            string token = line.substr(startPos, commaPos - startPos);
            tokens.push_back(token);

            startPos = commaPos + 1;
            commaPos = line.find(',', startPos);
        }

        // Add the last token after the last comma
        string lastToken = line.substr(startPos);
        tokens.push_back(lastToken);

        result += stoi(tokens[2]);
    }
   }
   infile.close();
   return result;
}
int main()

{
    string command;   
    cout << "============================================\n\n";
    cout << "*  Welcome to Disease Cases Reporting System!   * \n\n";
    cout << "*  ******************************************  * \n";
    cout << "*                                 * \n";
    cout << "* It is developed by RCA Student Name as Practical     * \n";
    cout << "* Evaluation for the end of year 3.    * \n";
    cout << "============================================\n";
    cout << "Starting time: " << getCurrentTimeFormatted() << "!\n";
    cout << "Need a help? Type 'help' then press Enter key.!\n";    
    cout << "Enter a command: ";
    getline(cin, command);

    // Convert the user input to lowercase for case-insensitive comparison
    for (char &c : command)
    {
        c = tolower(c);
    }
    if (command == "help")
    {
        cout << helpMenu() << endl;
    }
    else if (command.substr(0, 3) == "add"){
        string location = command.substr(4);
        saveToFile(location,"locations.csv");
        cout << "Location added successfully" << endl;
    }
    else if (splitString(command)[0] == "record"){
        string csvOutputOfTokens = splitString(command)[1] + "," + splitString(command)[2] + "," + splitString(command)[3];
        saveToFile(csvOutputOfTokens,"cases.csv");
        cout << "Case recorded successfully" << endl;
    }
    else if (splitString(command)[0] == "list" && splitString(command)[1] == "locations"){
        vector<string> locations = readCSV("cases.csv", 0);
        sortData(locations);
        for (string location : locations)
        {
            cout << location << endl;
        }
    }
    else if (splitString(command)[0] == "list" && splitString(command)[1] == "diseases"){
        vector<string> diseases = readCSV("cases.csv", 1);
        sortData(diseases);
        for (string disease : diseases)
        {
            cout << disease << endl;
        }
    }
    else if (splitString(command)[0] == "delete"){
        deleteLocation("cases.csv", splitString(command)[1]);    
        cout << "Location deleted succesfully\n";
    }
    else if (splitString(command)[0] == "where"){
      vector<string> locations =  findLocationByDisease("cases.csv", splitString(command)[1]);
      sortData(locations);
      for (string location : locations)
      {
            cout << location << endl;
      }
    }
    else if (splitString(command)[0] == "cases"){
      vector<string> splittedString = splitString(command);
      int cases = splittedString.size() > 2 ? countCases("cases.csv", splittedString[1],splittedString[2]) : countCases("cases.csv", splittedString[1]);
      string msg = splittedString.size() > 2 ? "Cases of" + splittedString[1] + "at" + splittedString[2] : "Total cases of " + splittedString[1];
      cout  << cases << endl;
    }
        else if (command == "quit")
        {
            cout << "Quit command selected." << endl;
        }
    else if (command == "settings")
    {
        cout << "Settings command selected." << endl;
    }
    else
    {
        cout << "Invalid command." << endl;
    }

    return 0;
}
