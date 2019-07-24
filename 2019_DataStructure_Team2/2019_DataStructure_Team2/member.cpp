#define _CRT_SECURE_NO_WARNINGS
#include "member.h"
extern member* table;
extern int pt_age[8][2];
extern int line; // 회원 수
typedef std::pair<int, char*> enrollname;
bool greater(enrollname &a, enrollname &b)
{
	if ( a.first <  b.first) return true;
	else return false;
}

void Q6(int num)
{
	std::priority_queue<enrollname, std::vector<enrollname>, std::greater<enrollname>> min_heap;
	std::vector<enrollname> members;
	char tmp[9];
	for (int i = 0; i < line; i++)
	{
		int cnt = 0;
		for (int j = 0; j < 17; j++)
		{
	
			if (table[i].enroll_date[j] >= '0' && table[i].enroll_date[j] <= '9')
				tmp[cnt++] = table[i].enroll_date[j];
		}
		enrollname tmpn = std::pair<int, char*>(atoi(tmp), (char*)malloc(sizeof(char) * 16));
		strcpy(tmpn.second, table[i].name);
		//members.push_back(std::pair<int, char*>(atoi(tmp), (char*)malloc(sizeof(char) * 16)));
		//strcpy(members[i].second, table[i].name);
		min_heap.push(tmpn);
	}

	std::make_heap(members.begin(), members.end(), greater);
	for (int i = 0; i < num; i++)
	{
		enrollname tmpe = min_heap.top();
		//enrollname tmpe = members.front();
		printf("가장 오래된 회원 %d : %d가입 ",i + 1,  tmpe.first);
		std::locale::global(std::locale("ko_KR.UTF-8"));
		printf("%s\n", tmpe.second);
		std::locale::global(std::locale("korean"));
		//std::pop_heap(members.begin(), members.end());
		//members.pop_back();
		min_heap.pop();
	}
}
void pt()
{
	memset(pt_age, 0, sizeof(pt_age));
	time_t timer = time(NULL);
	struct tm* t = localtime(&timer);
	char age[5];
	int age_year;
	int age20s = 0;
	for (int i = 0; i < line; i++)
	{
		age[0] = table[i].birthday[0];
		age[1] = table[i].birthday[1];
		age[4] = '\0';
		age_year = atoi(age);
		if (age_year > 40)
			age_year += 1900;
		else age_year += 2000;

		if (strcmp(table[i].pt_enroll, "N") == 0) // PT를 안 받으면
		{
			if (t->tm_year + 1900 - age_year <= 19)
			{
				pt_age[1][0]++;
				pt_age[0][0]++;
			}
			else if (t->tm_year + 1900 - age_year >= 20 && t->tm_year + 1900 - age_year <= 29)
			{
				pt_age[2][0]++;
				pt_age[0][0]++;
			}
			else if (t->tm_year + 1900 - age_year >= 30 && t->tm_year + 1900- age_year <= 39)
			{
				pt_age[3][0]++;
				pt_age[0][0]++;
			}
			else if (t->tm_year + 1900 - age_year >= 40 && t->tm_year + 1900 - age_year <= 49)
			{
				pt_age[4][0]++;
				pt_age[0][0]++;
			}
			else if (t->tm_year + 1900 - age_year >= 50 && t->tm_year + 1900 - age_year <= 59)
			{
				pt_age[5][0]++;
				pt_age[0][0]++;
			}
			else if (t->tm_year + 1900 - age_year >= 60 && t->tm_year + 1900 - age_year <= 69)
			{
				pt_age[6][0]++;
				pt_age[0][0]++;
			}
			else if (t->tm_year + 1900 - age_year >= 70)
			{
				pt_age[7][0]++;
				pt_age[0][0]++;
			}
		}
		else // PT 받으면
		{
			if (t->tm_year + 1900 - age_year <= 19)
			{
				pt_age[1][1]++;
				pt_age[0][1]++;
			}
			else if (t->tm_year + 1900 - age_year >= 20 && t->tm_year + 1900 - age_year <= 29)
			{

				pt_age[2][1]++;
				pt_age[0][1]++;
			}
			else if (t->tm_year + 1900 - age_year >= 30 && t->tm_year + 1900 - age_year <= 39)
			{
				pt_age[3][1]++;
				pt_age[0][1]++;
			}
			else if (t->tm_year + 1900 - age_year >= 40 && t->tm_year + 1900 - age_year <= 49)
			{
				pt_age[4][1]++;
				pt_age[0][1]++;
			}
			else if (t->tm_year + 1900 - age_year >= 50 && t->tm_year + 1900 - age_year <= 59)
			{
				pt_age[5][1]++;
				pt_age[0][1]++;
			}
			else if (t->tm_year + 1900 - age_year >= 60 && t->tm_year + 1900 - age_year <= 69)
			{
				pt_age[6][1]++;
				pt_age[0][1]++;
			}
			else if (t->tm_year + 1900 - age_year >= 70)
			{
				pt_age[7][1]++;
				pt_age[0][1]++;
			}
		}
	}

}

void Q11(member* table, member * arr) {
	int i,j=0;

	std::locale::global(std::locale("korean"));
	printf("<PT 받는 회원 중 라커를 이용하지 않는 회원>\n");
	std::locale::global(std::locale("ko_KR.UTF-8"));
	for (i = 0; i < 350; i++) { //인자로 넘겨받은 배열을 하나씩 확인하면서
		if ((strcmp(table[i].pt_enroll, "Y") == 0) && (strcmp(table[i].locker, "-") == 0)) { //PT등록이 Y이면서 라커를 사용하지 않는 회원정보 중 ID, 이름, PT 등록여부, 라커를 새로운 배열에 저장
			//printf("%d %s PT: %s Locker: %s \n", table[i].ID, table[i].name, table[i].pt_enroll, table[i].locker);
			arr[j].ID = table[i].ID;
			arr[j].name = (char*)malloc(sizeof(char) * 256);
			strcpy(arr[j].name, table[i].name);
			arr[j].pt_enroll = (char*)malloc(sizeof(char) * 256);
			strcpy(arr[j].pt_enroll, table[i].pt_enroll);
			arr[j].locker = (char*)malloc(sizeof(char) * 256);
			strcpy(arr[j].locker, table[i].locker);
			j++;
		}
	}

	for (i = 0; i < j; i++) { //새로운 배열에 저장된 회원정보 출력
		printf("%d %s %s %s\n", arr[i].ID,arr[i].name,arr[i].pt_enroll,arr[i].locker);
	}

}
void Q12()
{
	double a = (double)(pt_age[2][0] + pt_age[2][1]) / (pt_age[0][0] + pt_age[0][1]);
	printf("회원 중에서 20대의 비율은 %d%% 입니다.\n",int(a*100));
}
void Q19()
{
	int max = 1, min = 1;
	for (int i = 1; i <= 7; i++)
	{
		if (pt_age[max][1] < pt_age[i][1])
			max = i;
		else if (pt_age[min][1] > pt_age[i][1])
			min = i;
	}
	printf("PT를 가장 많이 이용하는 연령대는 %d0 대이고, 가장 적게 이용하는 연령대는 %d0 대입니다.\n", max, min);

}
std::vector<std::string> split(std::string str, char delimiter) {
	std::vector<std::string> internal;
	std::stringstream ss(str);
	std::string temp;

	while (getline(ss, temp, delimiter)) {
		internal.push_back(temp);
	}

	return internal;
}