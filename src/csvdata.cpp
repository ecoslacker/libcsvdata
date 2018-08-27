#include <fstream>
#include <iostream>
#include <sstream>
#include "csvdata.h"

CsvData::CsvData()
{
}

bool CsvData::parseFromFile(const std::string &filename, std::vector<std::vector<std::string> > &data, char delimiter)
{
    //std::cout << "Parsing CSV file: " << filename << std::endl;
    std::string line;

    // Open a file for input (reading)
    std::ifstream dataFile(filename);

    // Try to open the file, exits if failure
    if (!dataFile) {
        std::cerr << "Unable to open file: " << filename << " for reading." << std::endl;
        return false;
    }

    // Create a buffer std::string stream, and read the complete file
    std::stringstream content;
    content << dataFile.rdbuf();

    // Set the data content to the list of std::strings
    data = parse(content.str(), delimiter);
    return true;

}

std::vector<std::vector<std::string> > CsvData::parse(const std::string &string_content, char delimiter)
{
    /* Parse
     *
     * Parses a std::string, get all the values separated by commas in a line.
     *
     */

    enum State {Normal, Quote} state = Normal;
    std::vector < std::vector<std::string> > data;
    std::vector <std::string> line;
    std::string value;

    for (size_t i = 0; i < string_content.size() ; i++) {
        char current = string_content.at(i);
        //std::cout << "current: " << current << std::endl;

        // Normal
        if (state == Normal) {
            // newline
            if (current == '\n') {
                // add value
                line.push_back(value);
                value.clear();
                // add line
                data.push_back(line);
                line.clear();
            }
            // Delimiter, default is a comma
            else if (current == delimiter) {
                // add line
                line.push_back(value);
                value.clear();
            }
            // double quote
            else if (current == '"') {
                state = Quote;
            }
            // character
            else {
                value += current;
            }
        }
        // Quote
        else if (state == Quote) {
            // double quote
            if (current == '"') {
                int index = (i+1 < string_content.size()) ? i+1 : string_content.size();
                char next = string_content.at(index);
                if (next == '"') {
                    value += '"';
                    i++;
                } else {
                    state = Normal;
                }
            }
            // other
            else {
                value += current;
            }
        }
    }

    return data;
}

bool CsvData::write(const std::string &filename, std::vector< std::vector<std::string> > &data, std::string delimiter)
{
    //std::cout << "Opening file: " << filename << std::endl;
    //std::cout << &data << std::endl;

    // Open the file for output (writing)
    std::ofstream outFile(filename);

    // Try to open the file, exits if failure
    if (!outFile) {
        std::cerr << "Unable to open file: " << filename << " for writing." << std::endl;
        return false;
    }

    for (size_t i = 0; i < data.size(); i++) {
        // Parse each line
        std::vector<std::string> output;
        std::string value;

        //std::cout << "Line: " << i << " (" << data.at(i).size() << ")" << std::endl;

        for (size_t j = 0; j < data.at(i).size(); j++) {

            // Parse each value in the line
            value = data.at(i).at(j);
            //std::cout << "Col " << j << ": " << value << std::endl;

            size_t foundComma = value.find(','); // Search for ",|\r\n"
            size_t foundBeam = value.find('|');
            size_t foundReturn = value.find('\r');
            size_t foundNewline = value.find('\n');
            size_t foundQuote = value.find('\"');
            
            if (foundComma != std::string::npos || foundBeam != std::string::npos ||
                foundReturn != std::string::npos || foundNewline != std::string::npos) {
                output.push_back("\"" + value + "\"");
            } else if (foundQuote != std::string::npos) {
                output.push_back(value.replace(foundQuote, 1, "”"));
            } else {
                output.push_back(value);
            }
        }

        // Write the output line to the file
        for (size_t cell = 0; cell < output.size(); cell++)  {
            outFile << output.at(cell);

            // Write delimiter character
            if (cell != (output.size() - 1)) {
                outFile << delimiter;
            }

        }

        // Write an endline
        outFile << std::endl;
    }

    // Close the file
    outFile.close();
    
    return true;
}

bool CsvData::write(const std::string &filename, std::vector< std::vector<double> > &data, std::string delimiter)
{
    std::vector< std::vector< std::string > > str_data;
    for (size_t i = 0; i < data.size(); i++) {
        std::vector<std::string> line;

        for (size_t j = 0; j < data.at(i).size(); j++) {
            std::string str_cell = std::to_string(data.at(i).at(j));
            line.push_back(str_cell);
        }
        str_data.push_back(line);
    }

    write(filename, str_data, delimiter);
    return true;
}
