#include <stdlib.h>
#include <iostream>
#include <time.h>
#include "GenerateData.h"

using namespace std;



void DataManager::printData()
{

    // Just printing m_data, m_data_train, m_data_test

    cout << "************************************************************\n";
    for(int i=0;i<m_length;i++){
        cout << "X : " << m_data[0][i] << " y : " << m_data[1][i] << endl;
    }


    for(int i=0;i<m_data_train.size();i++){
        cout << "X_train : " << m_data_train[i].X << " y_train : " << m_data_train[i].y << endl;
    }


    for(int i=0;i<m_data_test.size();i++){
        cout << "X_test : " << m_data_test[i].X << " y_test : " << m_data_test[i].y << endl;
    }

}



void DataManager::generateData()
{
    // Generates data; 
    // 2nd row of m_data is function of 1st row      
    // if X>0.5 => y = 1 

    for(int i=0;i<m_length;i++){
        m_data[0][i] = (rand() % 1000)/100.0;
        (m_data[0][i] > 5.0)? m_data[1][i] = 1 : m_data[1][i] = 0;
        
    }

}



void DataManager::getStats()
{
    // This function can be useful to check that the dataset is balanced

    int count = 0;
    for(int i=0;i<m_length;i++){
        if (m_data[1][i] == 1) count+=1;
    }
    cout << "Number of positive class : " << count << " which is : " << (float)count*100.0/(float)m_length << "%" << endl;

}



void DataManager::train_test_split(float train_size=0.9)
{

    // Split the dataset contained in m_data using the split parameter train_size
    // Output : vector of points (points are represented by the data_struct)
    
    for(int i=0;i<m_length;i++){   


        if ((float)i/(float)m_length >= train_size)
        { 
            m_data_test.push_back((data_struct) {m_data[0][i],m_data[1][i]});
        }
        else
        {
            m_data_train.push_back((data_struct) {m_data[0][i],m_data[1][i]});
        }


    }

}





