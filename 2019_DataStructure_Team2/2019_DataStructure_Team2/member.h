#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <ctime>
#include <vector>
#include <fstream>
#include <sstream>
#include <time.h>
#include<algorithm>
#include<queue>
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
	void Q6(int num); // ���� ������ ȸ��(num)�� ��ŭ ������ش�.
void pt();
void Q12();
void Q19();

std::vector<std::string> split(std::string str, char delimiter);
