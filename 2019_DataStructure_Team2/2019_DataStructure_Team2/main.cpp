#define _CRT_SECURE_NO_WARNINGS
#include <locale>
#include "member.h"
#include "trainer.h"
#include "pt_table.h"


void most_addr(member_info table); //q4문제 해결을 위한 함수 원형 선언
//void most_recommender(member* list);

int main()
{
	member_info table;
	table.init(1000);
	table.load();


	/* 여기서부터 내가 만든 코드*/
	std::locale::global(std::locale("korean"));
	printf("┌─────────────────────────┐\n");
	printf("│            Q01          │\n");
	printf("└─────────────────────────┘\n");
	std::locale::global(std::locale("ko_KR.UTF-8"));
	int t_cnt;
	trainer arr[100];
	t_cnt = trainer_load(arr, table);
	trainer_best(arr, t_cnt);
	trainer_check_print(arr, t_cnt);

	// 6, 12, 19 출력을 위한 코드
	std::locale::global(std::locale("korean"));
	printf("┌─────────────────────────┐\n");
	printf("│            Q06          │\n");
	printf("└─────────────────────────┘\n");
	Q6(10, table);
	printf("┌─────────────────────────┐\n");
	printf("│        Q12  & Q19       │\n");
	printf("└─────────────────────────┘\n");;
	pt(table);

	std::locale::global(std::locale("korean"));
	printf("┌─────────────────────────┐\n");
	printf("│            Q04          │\n");
	printf("└─────────────────────────┘\n");
	std::locale::global(std::locale("ko_KR.UTF-8"));
	most_addr(table); //q4 출력

	//most_recommender(table);

	return 0;
}
void most_addr(member_info table); //q4문제 해결을 위한 함수 원형 선언
//void most_recommender(member* list);

/*int main()
{
	member_info table;
	table.init(1000);
	table.load();


	std::locale::global(std::locale("korean"));
	printf("┌─────────────────────────┐\n");
	printf("│            Q01          │\n");
	printf("└─────────────────────────┘\n");
		/* 여기서부터 내가 만든 코드
	int t_cnt;
	trainer arr[100];
	t_cnt = trainer_load(arr, table);
	trainer_best(arr, t_cnt);
	trainer_check_print(arr, t_cnt);

	std::locale::global(std::locale("korean"));
	printf("┌─────────────────────────┐\n");
	printf("│            Q04          │\n");
	printf("└─────────────────────────┘\n");
	std::locale::global(std::locale("ko_KR.UTF-8"));
	most_addr(table); //q4 출력


	std::locale::global(std::locale("korean"));
	printf("┌─────────────────────────┐\n");
	printf("│            Q06          │\n");
	printf("└─────────────────────────┘\n");
	Q6(10, table);

	pt(table);
	printf("┌─────────────────────────┐\n");
	printf("│            Q12          │\n");
	printf("└─────────────────────────┘\n");
	//Q12();
	printf("┌─────────────────────────┐\n");
	printf("│            Q19          │\n");
	printf("└─────────────────────────┘\n");
	//Q19();

				
	return 0;
	*/