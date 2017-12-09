//
// Created by pcsc on 12/4/17.
//

#ifndef PROJECT_INPUTOUTPUT_H
#define PROJECT_INPUTOUTPUT_H

#include "Matrix.h"
#include "Vector.h"
#include <fstream>
#include <sstream>

class inputOutput {

public:

    /** \brief Reads a matrix from a text file
      * \param filename either relative or absolute path to the text file
      * \return a matrix
      *
      * This method reads a matrix from a text file. Note that column entries must be separated by commas and row
      * entries separated by a newline. The method does not
      *
      * @code
      * inputOutput io;
      * Matrix A = io.readFromText("A.txt");
      * Matrix b = io.readFromText("b.txt");
      * @endcode
      */

    static Matrix readFromText(string filename);

    static void writeToText(Matrix data, string filename);

};


#endif //PROJECT_INPUTOUTPUT_H
