#define _CRT_SECURE_NO_WARNINGS
#include "member.h"
#include "pt_table.h"
typedef std::pair<int, char*> enrollname;

bool greater(enrollname& a, enrollname& b)
{
	if (a.first < b.first) return true;
	else return false;
}
void Q6(int num, member_info table)
{
	std::priority_queue<enrollname, std::vector<enrollname>, std::greater<enrollname>> min_heap;
	std::vector<enrollname> members;
	char tmp[9];
	member* list = table.list;
	int cnt = table.cnt;
	for (int i = 0; i < cnt; i++)
	{
		int cnt = 0;
		for (int j = 0; j < 17; j++)
		{

			if (list[i].enroll_date[j] >= '0' && list[i].enroll_date[j] <= '9')
				tmp[cnt++] = list[i].enroll_date[j];
		}
		enrollname tmpn = std::pair<int, char*>(atoi(tmp), (char*)malloc(sizeof(char) * 16));
		strcpy(tmpn.second, list[i].name);
		//members.push_back(std::pair<int, char*>(atoi(tmp), (char*)malloc(sizeof(char) * 16)));
		//strcpy(members[i].second, table[i].name);
		min_heap.push(tmpn);
	}

	std::make_heap(members.begin(), members.end(), greater);
	for (int i = 0; i < num; i++)
	{
		enrollname tmpe = min_heap.top();
		//enrollname tmpe = members.front();
		printf("가장 오래된 회원 %d : %d가입 ", i + 1, tmpe.first);
		std::locale::global(std::locale("ko_KR.UTF-8"));
		printf("%s\n", tmpe.second);
		std::locale::global(std::locale("korean"));
		//std::pop_heap(members.begin(), members.end());
		//members.pop_back();
		min_heap.pop();
	}
}

int hash_func(int tm_year, int age_year)
{
	int idx = (tm_year + 1900 - age_year) / 10;
	if (idx >= 7)
		return 7;
	else return idx;
}
void pt(member_info table)
{
	int pt_age[8][2];
	memset(pt_age, 0, sizeof(pt_age));
	time_t timer = time(NULL);
	struct tm* t = localtime(&timer);
	char age[5];
	int age_year;
	int age20s = 0;
	for (int i = 0; i < table.cnt; i++)
	{
		age[0] = table.list[i].birthday[0];
		age[1] = table.list[i].birthday[1];
		age[4] = '\0';
		age_year = atoi(age);
		if (age_year > 40)
			age_year += 1900;
		else age_year += 2000;

		int idx = hash_func(t->tm_year, age_year);
		int pidx = (strcmp(table.list[i].pt_enroll, "N") == 0) ? 0 : 1;
		pt_age[idx][pidx]++;
		pt_age[0][pidx]++;
	}
	table.pt_age = pt_age;

	//Q2
	double a = (double)(table.pt_age[2][0] + table.pt_age[2][1]) / (table.pt_age[0][0] + table.pt_age[0][1]);
	printf("회원 중에서 20대의 비율은 %d%% 입니다.\n", int(a * 100));

	//Q3
	int max = 1, min = 1;
	for (int i = 1; i <= 7; i++)
	{
		if (table.pt_age[max][1] < table.pt_age[i][1])
			max = i;
		else if (table.pt_age[min][1] > table.pt_age[i][1])
			min = i;
	}
	printf("PT를 가장 많이 이용하는 연령대는 %d0 대이고, 가장 적게 이용하는 연령대는 %d0 대입니다.\n", max, min);
	printf("#10대는 0세부터 19세까지 집계한 결과이고 70대는 70세부터 집계한 결과압입다.\n");
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
