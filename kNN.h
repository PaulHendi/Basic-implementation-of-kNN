#ifndef __kNN__
#define __kNN__



#include <cmath>
#include <vector>
#include <algorithm>
#include "parameters.h"

using namespace std;


class kNNAlgorithm
{

// Class that computes the kNN algorithm

    public : 

        vector<float> predict(vector<data_struct> data_train,vector<data_struct> data_test);
        float computeAccuracy(vector<float> label, vector<float> predicted, int size);

    private :

        float computeEuclideanDistance(float x_1,float x_2);

};


#endif
