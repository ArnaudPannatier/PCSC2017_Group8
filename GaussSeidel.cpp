//
// Created by Arnaud Pannatier on 08.12.17.
//

#include "GaussSeidel.h"

void GaussSeidel::step () {
    size_t size = A.size().lines;

    for (int i = 0; i < size; i++) {

        double y = (B(i) / A[i][i]);

        for (int j = 0; j < size; j++) {
            if (j == i) continue;

            y = y - ((A[i][j] / A[i][i]) * X(j));
            X(i) = y;
        }
    }
}
