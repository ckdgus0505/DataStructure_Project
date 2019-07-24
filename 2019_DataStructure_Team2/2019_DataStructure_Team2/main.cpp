#define _CRT_SECURE_NO_WARNINGS
#include <locale>
#include "member.h"
#include "trainer.h"

member* table;
char buffer[1024];
int pt_age[8][2];

int line = 0; // ȸ�� ��

void most_addr(member* list); //q4���� �ذ��� ���� �Լ� ���� ����

void load()
{
	std::ifstream in("info.csv");
	std::locale::global(std::locale("ko_KR.UTF-8"));


	if (in.is_open())
	{
		in.getline(buffer, 1024);
	}
	std::string str;
	table = new member[1000];
	while (getline(in, str))
	{
		std::vector<std::string> parsing = split(str, ',');
		for (int i = 0; i < 18; i++)
		{
			switch (i)
			{
			case 0:
				table[line].ID = atoi(parsing[i].c_str());
				break;
			case 1:
				table[line].name = (char*)malloc(sizeof(char) * 256);
				strcpy(table[line].name, parsing[i].c_str());
				break;
			case 2:
				table[line].addr = (char*)malloc(sizeof(char) * 256);
				strcpy(table[line].addr, parsing[i].c_str());
				break;
			case 3:
				table[line].phone = (char*)malloc(sizeof(char) * 256);
				strcpy(table[line].phone, parsing[i].c_str());
				break;
			case 4:
				table[line].recommender = (char*)malloc(sizeof(char) * 256);
				strcpy(table[line].recommender, parsing[i].c_str());
				break;
			case 5:
				table[line].birthday = (char*)malloc(sizeof(char) * 256);
				strcpy(table[line].birthday, parsing[i].c_str());
				break;
			case 6:
				table[line].ticket = (char*)malloc(sizeof(char) * 256);
				strcpy(table[line].ticket, parsing[i].c_str());
				break;
			case 7:
				table[line].pt_enroll = (char*)malloc(sizeof(char) * 256);
				strcpy(table[line].pt_enroll, parsing[i].c_str());
				break;
			case 8:
				table[line].trainer = (char*)malloc(sizeof(char) * 256);
				strcpy(table[line].trainer, parsing[i].c_str());
				break;
			case 9:
				table[line].BMIfirst = atof(parsing[i].c_str());
				break;
			case 10:
				table[line].BMInow = atof(parsing[i].c_str());
				break;
			case 11:
				table[line].BMIgoal = atof(parsing[i].c_str());
				break;
			case 12:
				table[line].locker = atoi(parsing[i].c_str());
				break;
			case 13:
				table[line].enroll_date = (char*)malloc(sizeof(char) * 256);
				strcpy(table[line].enroll_date, parsing[i].c_str());
				break;
			case 14:
				table[line].exer_cnt = atoi(parsing[i].c_str());
				break;
			case 15:
				table[line].pt_cnt = atoi(parsing[i].c_str());
				break;
			case 16:
				table[line].latest = (char*)malloc(sizeof(char) * 256);
				strcpy(table[line].latest, parsing[i].c_str());
				break;
			case 17:
				table[line].finish = (char*)malloc(sizeof(char) * 256);
				strcpy(table[line].finish, parsing[i].c_str());
				break;
			}
		}
		line++;
	}

	in.close();
}

int main()
{

	load();
		/* �ֿ��� ���� */
	atrain t_arr; // class trainer�迭�� ���� Ŭ����
	t_arr.init(); // class trainer 100ĭ�� ����

	t_arr.loading(line); // �迭�� ������ Ʈ���̳� ����

	t_arr.best1(); // ���� ȸ���� ���� ���� Ʈ���̳ʴ� �����ΰ�

	t_arr.best2(); // ����Ʈ�� ���� ���� Ʈ���̳ʴ� �����ΰ�

	//t_arr.deb(); // (����׿�) ������ Ʈ���̴� �� ����Ʈ�� ���� �ִ°�?
	/* �ֿ��� �� */

	// 6, 12, 19 ����� ���� �ڵ�
	Q6(10);
	pt();
	Q12();
	Q19();

	std::locale::global(std::locale("ko_KR.UTF-8"));
	most_addr(table); //q4 ���
				
	return 0;
}