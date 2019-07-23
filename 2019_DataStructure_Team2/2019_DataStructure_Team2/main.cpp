#define _CRT_SECURE_NO_WARNINGS
#include <locale>
#include "member.h"
#include "trainer.h"
#include "pt_table.h"

member* table; // load �� ȸ���� ������ ���� member �迭
char buffer[1024]; // file ������ ���� ����
int pt_age[8][2];

int line = 0; // ȸ�� ��

void most_addr(member* list); //q4���� �ذ��� ���� �Լ� ���� ����

void load()
{
	std::ifstream in("info.csv");
	std::locale::global(std::locale("ko_KR.UTF-8"));  // csv������ utf-8 �ΰ���� ����ϱ� ������ ����� �ڵ�

	// ������ ���� ù��° ���� ȸ�� ������ �ƴϹǷ� ������.
	if (in.is_open())
	{
		in.getline(buffer, 1024);
	}
	std::string str;
	table = new member[1000]; 

	// ȸ�� ������ 1�پ� �о����� ',' ������ �ڸ���.
	// �ڸ� ���ڿ��� vector�� �ε��� ������ ����ȴ�.
	// index ������ ����� ���ڿ��� member ������ �����Ͽ� table �迭�� �����Ѵ�.
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


	std::locale::global(std::locale("korean"));
	printf("������������������������������������������������������\n");
	printf("��            Q01          ��\n");
	printf("������������������������������������������������������\n");
		/* ���⼭���� ���� ���� �ڵ�*/
	int t_cnt;
	trainer arr[100];
	std::locale::global(std::locale("ko_KR.UTF-8"));
	t_cnt = trainer_load(arr, table, line);
	trainer_best(arr, t_cnt);
	trainer_check_print(arr, table, t_cnt);

	std::locale::global(std::locale("korean"));
	printf("������������������������������������������������������\n");
	printf("��            Q04          ��\n");
	printf("������������������������������������������������������\n");
	std::locale::global(std::locale("ko_KR.UTF-8"));
	most_addr(table); //q4 ���


	std::locale::global(std::locale("korean"));
	printf("������������������������������������������������������\n");
	printf("��            Q06          ��\n");
	printf("������������������������������������������������������\n");
	Q6(10);

	pt();
	printf("������������������������������������������������������\n");
	printf("��            Q12          ��\n");
	printf("������������������������������������������������������\n");
	Q12();
	printf("������������������������������������������������������\n");
	printf("��            Q19          ��\n");
	printf("������������������������������������������������������\n");
	Q19();

				
	return 0;
}