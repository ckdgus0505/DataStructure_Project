#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <ctime>
#include <vector>
#include <fstream>
#include <sstream>
class member {
public: // 18�� �׸�
	int ID; // ȸ����ȣ
	char* name; // �̸�
	char* addr; // �ְ���
	char* phone; // ��ȭ��ȣ
	char* recommender; // ��õ��
	char* birthday; //�������
	char* ticket; // ���Ż�ǰ
	char*  pt_enroll; // pt��Ͽ���
	char* trainer; // ��� Ʈ���̳�
	double BMIfirst; // ù BMI����
	double BMInow; // ���� BMI����
	double BMIgoal; // ��ǥ BMI����
	int locker; // ��� ��Ŀ
	char* enroll_date; // ���� �����
	int exer_cnt; // ���� �
	int pt_cnt; // ���� PT Ƚ��
	char* latest; // ���� �ֱ� ���
	char* finish; // ��ǰ�� ���� �ñ�
};
void loader();
void parser();
std::vector<std::string> split(std::string str, char delimiter);
