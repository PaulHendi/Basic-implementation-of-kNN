#include <stdlib.h>
#include <iostream>
#include <time.h>
#include "kNN.h"
#include "GenerateData.h"



using namespace std;


int main()
{

    srand(time(NULL)); // random seed  


    DataManager Data(100);
    Data.generateData(); 
    Data.train_test_split(0.9);
    //Data.printData(); 
    //Data.getStats(); 
    
    vector<data_struct> data_train = Data.getDataTrain();
    vector<data_struct> data_test = Data.getDataTest();

    int nb_train = data_train.size();
    int nb_test = data_test.size();

    kNNAlgorithm kNN;
    vector<float> predictions = kNN.predict(data_train,data_test);
    vector<float> labels;

    
    for (int j=0;j<nb_test;j++){
        //cout << "Actual : " << data_test[j].y << "\tPredicted : " << predictions[j] << endl;           
        labels.push_back(data_test[j].y );
    }

  

    cout << "Accuracy : " << kNN.computeAccuracy(labels , predictions, nb_test) << endl; 


    return 0;
}
