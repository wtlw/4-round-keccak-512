#include "MitmSHA3.h"



int main(int argc, char* argv[]) {
    GRBEnv* env =  new GRBEnv();                        //��������
    int Rounds = 2;                                     //������������
   // env->set(GRB_IntParam_OutputFlag, 0);
   // env->set(GRB_DoubleParam_TimeLimit, 100.0);
    env->set(GRB_IntParam_Threads, 8);

    GRBModel model = GRBModel(*env);                    //�����µ�MILPģ��

    Mitm mitm(Rounds);                                  //������Ӧ������

    mitm.Value(model);                                  //��ÿһ�����鸳ֵ����������ʼ������Ĺ�ϵ
    mitm.article_attack(model);
    mitm.addconstraint(model);                          //������������ģ��
    mitm.solve(model);                                  //���ģ�ͣ�������tikz����

    delete env;
    
    return 0;
}



