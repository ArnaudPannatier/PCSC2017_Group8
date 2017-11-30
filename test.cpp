//
// Created by Arnaud Pannatier on 30.11.17.
//

#include <iostream>
#include <vector>

using namespace std;

typedef vector < vector<double> > vector2D;


int main(){

    cout << " It is working" << endl;
    vector2D test = vector2D(3,{1,2,3});
    cout << "Case 1,1 = " <<test[1][1] << endl;

    return 0;
}
