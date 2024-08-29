#ifndef MITMSHA3_H
#define MITMSHA3_H

#pragma once
#include <sstream>
#include <iomanip>
#include <string>
#include <iostream>
#include <fstream>
#include <initializer_list>
#include <vector>
#include "gurobi_c++.h"
#include "MitmSolution.h"

using namespace std;

class Mitm {
public:
    int Rounds;                 //����
    vector<vector<vector<vector<vector<GRBVar>>>>> DA;          //DA��Ӧÿһ�ֵ�״̬A
    vector<vector<vector<vector<GRBVar>>>> DP;                  //DP��Ӧÿһ�ֵ�״̬C
    vector<vector<vector<GRBVar>>> DC1_red;                         //DC1��ӦA->C���ĵ����ɶ�
    vector<vector<vector<GRBVar>>> DC1_blue;                        
    vector<vector<vector<vector<GRBVar>>>> DP2;                     //ÿһ�ֵ�״̬D
  //  vector<vector<vector<GRBVar>>> DC12_red;                        //C->D���ĵ����ɶ�
  //  vector<vector<vector<GRBVar>>> DC12_blue;
    vector<vector<vector<vector<vector<GRBVar>>>>> DB;              // pai
    vector<vector<vector<vector<GRBVar>>>> DC2_red;                 //D->pai���ĵ����ɶ�
    vector<vector<vector<vector<GRBVar>>>> DC2_blue;
    vector<GRBVar> obj;
   // vector<vector<GRBVar>> dom1;
    vector<vector<GRBVar>> dom2;
    vector<GRBVar> avar;
    vector<vector<vector<GRBVar>>> beta1;
    vector<vector<vector<vector<GRBVar>>>> beta2;

    const std::string WhiteColor = "white";
    const std::string GrayColor = "lightgray";
    const std::string BlueColor = "blue";
    const std::string RedColor = "red";
    const std::string PurpleColor = "green!60";
    const int rho[5][5] = { {0, 36, 3, 41, 18},
                           {1, 44, 10, 45, 2},
                           {62, 6, 43, 15, 61},
                           {28, 55, 25, 21, 56},
                           {27, 20, 39, 8, 14} };

    Mitm(int Rounds);
    
    void Value(GRBModel& model);

    void solve(GRBModel& model);

    void getAllFoundSolutions(GRBModel& model, vector<MitmSolution>& solutions);

    void getSolution(GRBModel& model, MitmSolution& MitmSolution);

    void article_attack(GRBModel& model);

    void addconstraint(GRBModel& model);

    string generate_1(MitmSolution& MitmSolution);

    string generate_2(MitmSolution& MitmSolution);
};

class MitmFactory {
public:

    vector<vector<int>> rho = {
    {0, 36, 3, 41, 18},
    {1, 44, 10, 45, 2},
    {62, 6, 43, 15, 61},
    {28, 55, 25, 21, 56},
    {27, 20, 39, 8, 14}
    };

    MitmFactory();

    void addfivexor_red(vector<vector<vector<vector<vector<GRBVar>>>>> DA,
        vector<vector<vector<vector<GRBVar>>>> DP,
        vector<vector<vector<GRBVar>>> DC1_red, vector<vector<vector<GRBVar>>> DC1_blue, GRBModel& model);

    //void addtwoxor_red(vector<vector<vector<vector<GRBVar>>>> DP2,
    //    vector<vector<vector<vector<GRBVar>>>> DP,
    //    vector<vector<vector<GRBVar>>> DC12_red, vector<vector<vector<GRBVar>>> DC12_blue, GRBModel& model);

    void addtwoxor_red(vector<vector<vector<vector<GRBVar>>>> DP2,
        vector<vector<vector<vector<GRBVar>>>> DP, GRBModel& model);

    void addTheta_red(vector<vector<vector<vector<vector<GRBVar>>>>> DA,
        vector<vector<vector<vector<GRBVar>>>> DP2,
        vector<vector<vector<vector<vector<GRBVar>>>>> DB,
        vector<vector<vector<vector<GRBVar>>>> DC2_red, vector<vector<vector<vector<GRBVar>>>> DC2_blue, GRBModel& model);

    //void multiplication(vector<vector<vector<vector<vector<GRBVar>>>>> DA,
    //    vector<vector<vector<vector<vector<GRBVar>>>>> DB, GRBModel& model);

    void addSbox_nc(vector<vector<vector<vector<vector<GRBVar>>>>> DB,
        vector<vector<vector<vector<vector<GRBVar>>>>> DA, GRBModel& model);


    //void addDoMnew(vector<vector<vector<vector<vector<GRBVar>>>>> DA,
    //    vector<vector<GRBVar>> dom1, vector<vector<GRBVar>> dom2, GRBModel& model);

    void addDoMnew(vector<vector<vector<vector<vector<GRBVar>>>>> DA, vector<GRBVar> avar, vector<vector<GRBVar>> dom2, GRBModel& model);

    void betaConstraints(vector<vector<vector<vector<vector<GRBVar>>>>> DA,
        vector<vector<GRBVar>> beta, GRBModel& model);

    void Determine_Allzero(GRBVar mainVar, initializer_list<GRBVar> vars, GRBModel& model);

    void Determine_AllOne(GRBVar mainVar, initializer_list<GRBVar> vars, GRBModel& model);

    void Determine_ExistOne(GRBVar mainVar, initializer_list<GRBVar> vars, GRBModel& model);

    void Determine_Existzero(GRBVar mainVar, initializer_list<GRBVar> vars, GRBModel& model);

    GRBLinExpr linExprOf(vector<double> coeffs, initializer_list<GRBVar> vars);

    GRBLinExpr linExprOf(double constant, initializer_list<GRBVar> vars);

    GRBLinExpr linExprOf(initializer_list<GRBVar> vars);
};



#endif