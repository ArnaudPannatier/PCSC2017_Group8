//
// Created by pcsc on 12/1/17.
//

#ifndef PROJECT_UTILS_H
#define PROJECT_UTILS_H

#include "Matrix.h"
#include "Vector.h"
#include <fstream>
#include <sstream>

Matrix readFromText(string filename) {

    // Read from text file
    string line;

    vector2D data;
    ifstream infile(filename);

    while (infile)
    {
        string s;
        if (!getline( infile, s )) break;

        istringstream ss( s );
        vector <double> record;

        while (ss)
        {
            string s;
            if (!getline( ss, s, ',' )) break;
            record.push_back( stof(s) );
        }

        data.push_back( record );
    }

    return Matrix(data);

}


#endif //PROJECT_UTILS_H
