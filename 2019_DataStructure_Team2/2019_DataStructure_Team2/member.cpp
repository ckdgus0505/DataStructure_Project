#define _CRT_SECURE_NO_WARNINGS
#include "member.h"
typedef std::pair<int, char*> enrollname;


void member_info::init(int max_size)
{
	n = max_size;
	cnt = 0;
	list = (member*)calloc(n, sizeof(member));
	pt_age = (int(*)[2])malloc(sizeof(int*));
}
void member_info::load()
{
	std::ifstream in("info.csv");
	std::locale::global(std::locale("ko_KR.UTF-8"));
	char buffer[1024];

	if (in.is_open())
	{
		in.getline(buffer, 1024);
	}
	std::string str;
	list = new member[1000];
	while (getline(in, str))
	{
		std::vector<std::string> parsing = split(str, ',');
		for (int i = 0; i < 18; i++)
		{
			switch (i)
			{
			case 0:
				list[cnt].ID = atoi(parsing[i].c_str());
				break;
			case 1:
				list[cnt].name = (char*)malloc(sizeof(char) * 256);
				strcpy(list[cnt].name, parsing[i].c_str());
				break;
			case 2:
				list[cnt].addr = (char*)malloc(sizeof(char) * 256);
				strcpy(list[cnt].addr, parsing[i].c_str());
				break;
			case 3:
				list[cnt].phone = (char*)malloc(sizeof(char) * 256);
				strcpy(list[cnt].phone, parsing[i].c_str());
				break;
			case 4:
				list[cnt].recommender = (char*)malloc(sizeof(char) * 256);
				strcpy(list[cnt].recommender, parsing[i].c_str());
				break;
			case 5:
				list[cnt].birthday = (char*)malloc(sizeof(char) * 256);
				strcpy(list[cnt].birthday, parsing[i].c_str());
				break;
			case 6:
				list[cnt].ticket = (char*)malloc(sizeof(char) * 256);
				strcpy(list[cnt].ticket, parsing[i].c_str());
				break;
			case 7:
				list[cnt].pt_enroll = (char*)malloc(sizeof(char) * 256);
				strcpy(list[cnt].pt_enroll, parsing[i].c_str());
				break;
			case 8:
				list[cnt].trainer = (char*)malloc(sizeof(char) * 256);
				strcpy(list[cnt].trainer, parsing[i].c_str());
				break;
			case 9:
				list[cnt].BMIfirst = atof(parsing[i].c_str());
				break;
			case 10:
				list[cnt].BMInow = atof(parsing[i].c_str());
				break;
			case 11:
				list[cnt].BMIgoal = atof(parsing[i].c_str());
				break;
			case 12:
				list[cnt].locker = (char*)malloc(sizeof(char) * 256);
				strcpy(list[cnt].locker, parsing[i].c_str());
				break;
			case 13:
				list[cnt].enroll_date = (char*)malloc(sizeof(char) * 256);
				strcpy(list[cnt].enroll_date, parsing[i].c_str());
				break;
			case 14:
				list[cnt].exer_cnt = atoi(parsing[i].c_str());
				break;
			case 15:
				list[cnt].pt_cnt = atoi(parsing[i].c_str());
				break;
			case 16:
				list[cnt].latest = (char*)malloc(sizeof(char) * 256);
				strcpy(list[cnt].latest, parsing[i].c_str());
				break;
			case 17:
				list[cnt].finish = (char*)malloc(sizeof(char) * 256);
				strcpy(list[cnt].finish, parsing[i].c_str());
				break;
			}
		}
		cnt++;
	}
	in.close();
}

void Q11(member_info table) {
	int i;

	std::locale::global(std::locale("korean"));
	printf("<PT 받는 회원 중 라커를 이용하지 않는 회원>\n");
	std::locale::global(std::locale("ko_KR.UTF-8"));
	for (i = 0; i < table.cnt; i++) { //인자로 넘겨받은 배열을 하나씩 확인하면서
		if ((strcmp(table.list[i].pt_enroll, "Y") == 0) && (strcmp(table.list[i].locker, "-") == 0)) { //PT등록이 Y이면서 라커를 사용하지 않는 회원 출력
			{
				printf("%d %s PT: %s Locker: %s \n", table.list[i].ID, table.list[i].name, table.list[i].pt_enroll, table.list[i].locker);
			}
		}
	}

}