#include "kNN.h"



// Commonly use to compute distance between points
float kNNAlgorithm::computeEuclideanDistance(float x_1,float x_2)
{
    return sqrt(fabs(pow(x_2,2) - pow(x_1,2)));  
}



vector<float> kNNAlgorithm::predict(vector<data_struct> data_train,vector<data_struct> data_test)
{

    vector<float> distances,predictions;

    vector<float>::iterator min_iterator;
    int min_index;


    int nb_train = data_train.size();
    int nb_test = data_test.size();

    for (int j=0;j<nb_test;j++){
        for (int i=0;i<nb_train;i++){
            distances.push_back(computeEuclideanDistance(data_test[j].X, data_train[i].X));            
        }
        min_iterator = min_element(distances.begin(), distances.end());
        min_index = min_iterator - distances.begin();   
        predictions.push_back(data_train[min_index].y);
        distances.clear();
    }

    return predictions;

}



float kNNAlgorithm::computeAccuracy(vector<float> label, vector<float> predicted, int size)
{
    int count = 0;

    for (int i=0; i<size; i++){
        if (label[i] == predicted[i]) count+=1;
    }

    return (float)count/(float)size;    

}




