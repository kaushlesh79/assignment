#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

void extractLogs(const string& date) {
   string logFile = "log2024.log";  // Correct relative path
    ifstream inputFile(logFile);
    if (!inputFile.is_open()) {
        cerr << "Error: Unable to open log file." << endl;
        return;
    }

    string outputFile = "output/output_" + date + ".txt";
    ofstream output(outputFile);
    if (!output.is_open()) {
        cerr << "Error: Unable to open output file." << endl;
        return;
    }

    string line;
    size_t dateLength = date.length();
    while (getline(inputFile, line)) {
        if (line.compare(0, dateLength, date) == 0) {
            output << line << endl;
        }
    }

    inputFile.close();
    output.close();
    cout << "Log entries for " << date << " have been saved to " << outputFile << endl;
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cerr << "Usage: " << argv[0] << " <YYYY-MM-DD>" << endl;
        return 1;
    }

    string date = argv[1];
    extractLogs(date);

    return 0;
}
