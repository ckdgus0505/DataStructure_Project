#define _CRT_SECURE_NO_WARNINGS
#include <locale>
#include "member.h"
#include "trainer.h"

member* table;
char buffer[1024];
int pt_age[8][2];

int line = 0; // 회원 수

void most_addr(member* list); //q4문제 해결을 위한 함수 원형 선언

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
		/* 최영우 시작 */
	atrain t_arr; // class trainer배열을 담을 클래스
	t_arr.init(); // class trainer 100칸을 만듦

	t_arr.loading(line); // 배열을 읽으며 트레이너 생성

	t_arr.best1(); // 가장 회원을 많이 갖은 트레이너는 누구인가

	t_arr.best2(); // 포인트가 가장 높은 트레이너느 누구인가

	//t_arr.deb(); // (디버그용) 각각의 트레이는 몇 포인트를 갖고 있는가?
	/* 최영우 끝 */

	// 6, 12, 19 출력을 위한 코드
	Q6(10);
	pt();
	Q12();
	Q19();

	std::locale::global(std::locale("ko_KR.UTF-8"));
	most_addr(table); //q4 출력
				
	return 0;
}