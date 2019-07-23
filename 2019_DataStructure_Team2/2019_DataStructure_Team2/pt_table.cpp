#define _CRT_SECURE_NO_WARNINGS
#include "pt_table.h"
#include "member.h"

extern member* table;
extern int pt_age[8][2];
extern int line; // ȸ�� ��

typedef std::pair<int, char*> enrollname; // �������, �̸��� ������ �����ϱ� ���� �ڷᱸ��
bool greater(enrollname& a, enrollname& b) // �켱����ť�� �켱������ ���ϱ� ���� �Լ�
{
	if (a.first < b.first) return true;
	else return false;
}

// �켱����ť stl�� �̿��Ͽ� min heap�� �����Ͽ���.


void Q6(int num)
{
	std::priority_queue<enrollname, std::vector<enrollname>, std::greater<enrollname>> min_heap; // �������, �̸� ���� ������ �ּ� �� �ڷᱸ��
	std::vector<enrollname> members; 

	char tmp[9]; // ������� ���ڿ��� ���ڷ� �ٲپ� �����ϱ� ���� ����
	for (int i = 0; i < line; i++) // ȸ���� ���������� �о �ּ��� ����� �κ�
	{
		int cnt = 0;
		for (int j = 0; j < 17; j++) // ������� ���ڿ��� ���ڸ� �̾Ƴ��� ���� �ݺ���
		{

			if (table[i].enroll_date[j] >= '0' && table[i].enroll_date[j] <= '9')
				tmp[cnt++] = table[i].enroll_date[j];
		} // tmp���� ������ڰ� ����� ������ ���ڿ��� ����Ǿ� �ִ�.

		enrollname tmpn = std::pair<int, char*>(atoi(tmp), (char*)malloc(sizeof(char) * 16)); 
		strcpy(tmpn.second, table[i].name);
		min_heap.push(tmpn);
	}

	std::make_heap(members.begin(), members.end(), greater);

	// ���� ����Ǿ��ִ� ���Ҹ� ���ϴ� ��ŭ(num�� ��ŭ) pop �Ͽ� ����Ѵ�.
	for (int i = 0; i < num; i++)
	{
		std::locale::global(std::locale("korean"));
		enrollname tmpe = min_heap.top();
		printf("���� ������ ȸ�� %d : %d���� ", i + 1, tmpe.first);
		std::locale::global(std::locale("ko_KR.UTF-8"));
		printf("%s\n", tmpe.second);
		std::locale::global(std::locale("korean"));
		min_heap.pop();
	}
}
// pt() �Լ����� �迭�� ���̸� ���� �����ϱ� ���� �ؽ��Լ�
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
	{	// ������� ���ڿ��� �⵵�� �̾Ƽ� ���������� ��ȯ�ϱ� ���� �κ�
		age[0] = table[i].birthday[0];
		age[1] = table[i].birthday[1];
		age[4] = '\0';
		age_year = atoi(age);

		// 1940��� �̸��� �����Ŷ�� ���� �Ͽ� 85��� -> 1995 01��� ->2001 �� �ٲ��ִ� �κ�
		if (age_year > 40)
			age_year += 1900;
		else age_year += 2000;

		int idx = hash_func(t->tm_year, age_year); // ���̴뿡 �´� ���� ����
		int pidx = (strcmp(table[i].pt_enroll, "N") == 0) ? 0 : 1; // pt ��� ���ο� ���� ���� ����
		pt_age[idx][pidx]++;
		pt_age[0][pidx]++;
	}
}
void Q12()
{
	double a = (double)(pt_age[2][0] + pt_age[2][1]) / (pt_age[0][0] + pt_age[0][1]);
	printf("ȸ�� �߿��� 20���� ������ %d%% �Դϴ�.\n", int(a * 100));
}
void Q19()
{ // 0���� pt �ȹ޴� ���, 1���� pt �޴� ��� , 0���� 1������ 7�������� ��, 1��~7���� �� ���̴� ������� ��
	int max = 1, min = 1;
	for (int i = 1; i <= 7; i++)
	{
		if (pt_age[max][1] < pt_age[i][1])
			max = i;
		else if (pt_age[min][1] > pt_age[i][1])
			min = i;
	}
	printf("PT�� ���� ���� �̿��ϴ� ���ɴ�� %d0 ���̰�, ���� ���� �̿��ϴ� ���ɴ�� %d0 ���Դϴ�.\n", max, min);
	printf("# 10��� 10�� �̸� ���ɴ븦 �����Ͽ� �����Ͽ���, 70��� 70�� �̻� ���ɴ븦 �����Ͽ� �����߽��ϴ�.\n");
}