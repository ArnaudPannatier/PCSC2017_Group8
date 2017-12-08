//
// Created by Haziq on 12/4/17.
//

#include "inputOutput.h"

//=================================================================================================
Matrix inputOutput::readFromText(string filename) {

    // Read from text file
    string line;

    vector2D data;
    ifstream infile(filename);

    //
    while (infile)
    {
        string s;
        if (!getline( infile, s )) break;

        istringstream ss( s );
        vector<double> record;

        // break the current line into separate strings, separated by ','
        while (ss)
        {
            string s;
            if (!getline( ss, s, ',' )) break;
            record.push_back( stof(s) );
        }

        data.push_back( record );

        // each row in the text file must have the same number of entries
        // cout << record.size() << " " << data[0].size() << endl;

        if(record.size() != data[0].size()) {
            cerr << filename + " has missing entries. Inserting zeros" << endl;
        }
    }

    return Matrix(data);

}

//=================================================================================================
void inputOutput::writeToText(Matrix data, string filename) {

    ofstream outFile;
    outFile.open(filename);

    for(size_t row = 0; row < data.size().lines; row++){
        for(size_t col = 0; col < data.size().cols; col++){
            outFile << data[row][col];
        }
    }

}