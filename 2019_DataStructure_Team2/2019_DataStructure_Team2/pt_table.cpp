#define _CRT_SECURE_NO_WARNINGS
#include "pt_table.h"
#include "member.h"

extern member* table;
extern int pt_age[8][2];
extern int line; // 회원 수

typedef std::pair<int, char*> enrollname; // 등록일자, 이름을 맵으로 저장하기 위한 자료구조
bool greater(enrollname& a, enrollname& b) // 우선순위큐의 우선순위를 정하기 위한 함수
{
	if (a.first < b.first) return true;
	else return false;
}

// 우선순위큐 stl을 이용하여 min heap을 구현하였다.


void Q6(int num)
{
	std::priority_queue<enrollname, std::vector<enrollname>, std::greater<enrollname>> min_heap; // 등록일자, 이름 맵을 저장할 최소 힙 자료구조
	std::vector<enrollname> members; 

	char tmp[9]; // 등록일자 문자열을 숫자로 바꾸어 저장하기 위한 변수
	for (int i = 0; i < line; i++) // 회원을 순차적으로 읽어서 최소힙 만드는 부분
	{
		int cnt = 0;
		for (int j = 0; j < 17; j++) // 등록일자 문자열중 숫자만 뽑아내기 위한 반복문
		{

			if (table[i].enroll_date[j] >= '0' && table[i].enroll_date[j] <= '9')
				tmp[cnt++] = table[i].enroll_date[j];
		} // tmp에는 등록일자가 년월일 순으로 문자열로 저장되어 있다.

		enrollname tmpn = std::pair<int, char*>(atoi(tmp), (char*)malloc(sizeof(char) * 16)); 
		strcpy(tmpn.second, table[i].name);
		min_heap.push(tmpn);
	}

	std::make_heap(members.begin(), members.end(), greater);

	// 힙에 저장되어있는 원소를 원하는 만큼(num값 만큼) pop 하여 출력한다.
	for (int i = 0; i < num; i++)
	{
		std::locale::global(std::locale("korean"));
		enrollname tmpe = min_heap.top();
		printf("가장 오래된 회원 %d : %d가입 ", i + 1, tmpe.first);
		std::locale::global(std::locale("ko_KR.UTF-8"));
		printf("%s\n", tmpe.second);
		std::locale::global(std::locale("korean"));
		min_heap.pop();
	}
}
// pt() 함수에서 배열에 나이를 빨리 저장하기 위한 해쉬함수
int hash_func(int tm_year, int age_year)
{
	int idx = (tm_year + 1900 - age_year) / 10;
	if (idx >= 7)
		return 7;
	return idx;
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
	{	// 생년월일 문자열을 년도만 뽑아서 정수형으로 변환하기 위한 부분
		age[0] = table[i].birthday[0];
		age[1] = table[i].birthday[1];
		age[4] = '\0';
		age_year = atoi(age);

		// 1940년생 미만은 없을거라는 가정 하에 85년생 -> 1995 01년생 ->2001 로 바꿔주는 부분
		if (age_year > 40)
			age_year += 1900;
		else age_year += 2000;

		int idx = hash_func(t->tm_year, age_year); // 나이대에 맞는 열을 저장
		int pidx = (strcmp(table[i].pt_enroll, "N") == 0) ? 0 : 1; // pt 등록 여부에 대한 행을 저장
		pt_age[idx][pidx]++;
		pt_age[0][pidx]++;
	}
}
void Q12()
{
	double a = (double)(pt_age[2][0] + pt_age[2][1]) / (pt_age[0][0] + pt_age[0][1]);
	printf("회원 중에서 20대의 비율은 %d%% 입니다.\n", int(a * 100));
}
void Q19()
{ // 0행은 pt 안받는 사람, 1행은 pt 받는 사람 , 0열은 1열부터 7열까지의 합, 1열~7열은 각 나이대 사람들의 수
	int max = 1, min = 1;
	for (int i = 1; i <= 7; i++)
	{
		if (pt_age[max][1] < pt_age[i][1])
			max = i;
		else if (pt_age[min][1] > pt_age[i][1])
			min = i;
	}
	printf("PT를 가장 많이 이용하는 연령대는 %d0 대이고, 가장 적게 이용하는 연령대는 %d0 대입니다.\n", max, min);
	printf("# 10대는 10대 미만 연령대를 통합하여 집계하였고, 70대는 70대 이상 연령대를 통합하여 집계했습니다.\n");
}