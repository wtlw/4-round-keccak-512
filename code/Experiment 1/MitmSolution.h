#ifndef MITMSOLUTION_H
#define MITMSOLUTION_H
#pragma once
#include <vector>

using namespace std;

class MitmSolution {
public:
    int Rounds;
    int objective;
    vector<vector<vector<vector<vector<int>>>>> DA;          //DA��Ӧÿһ�ֵ�״̬A
    vector<vector<vector<vector<int>>>> DP;                  //DP��Ӧÿһ�ֵ�״̬C
    vector<vector<vector<int>>> DC1_red;                         //DC1��ӦA->C���ĵ����ɶ�
    vector<vector<vector<int>>> DC1_blue;
    vector<vector<vector<vector<int>>>> DP2;
//    vector<vector<vector<int>>> DC12_red;
//    vector<vector<vector<int>>> DC12_blue;
    vector<vector<vector<vector<vector<int>>>>> DB;
    vector<vector<vector<vector<int>>>> DC2_red;
    vector<vector<vector<vector<int>>>> DC2_blue;
    vector<int> obj;
   // vector<vector<int>> dom1;
    vector<vector<int>> dom2;
    vector<vector<vector<int>>> beta1;
    vector<vector<vector<vector<int>>>> beta2;

    MitmSolution(int Rounds);

};

#endif