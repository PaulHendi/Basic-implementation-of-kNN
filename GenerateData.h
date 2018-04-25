#ifndef __GENERATEDATA__
#define __GENERATEDATA__


#include <vector>
#include "parameters.h"

using namespace std;



class DataManager
{

// Class that generates 2d data 

    public : 

        // Constructor
        // Allocate 2d array of size (length,2)
        DataManager(int length)
        {
            m_length = length; 
            m_data = new float*[2];
            for(int i=0;i<m_length;i++){
                m_data[i] = new float[m_length];
            }
        };



        void generateData();
        void printData();
        void getStats();

        float** getData(){return m_data;};
        vector<data_struct> getDataTrain(){return m_data_train;};
        vector<data_struct> getDataTest(){return m_data_test;};

        void train_test_split(float train_size);


    private :

        int m_length;
        float** m_data;
        vector<data_struct> m_data_train, m_data_test;


};

#endif
