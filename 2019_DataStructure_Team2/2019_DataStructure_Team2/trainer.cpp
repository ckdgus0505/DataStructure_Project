#include"member.h"
#include"trainer.h"

int trainer_load(trainer* arr, member* brr, int line) {
	int i = 0;
	int m;
	for (int j = 0; j < line; j++) {
		if (strcmp(brr[j].trainer, "-") == 0) {
			continue;
		}
		if (i == 0) {
			arr[i].t_name = brr[j].trainer;
			arr[i].m_cnt = 0;
			arr[i].m_arr = (int*)calloc(100, sizeof(int));
			arr[i].m_arr[arr[i].m_cnt] = j;
			arr[i].m_cnt++;
			i++;
			continue;
		}
		m = i;
		int k;
		for (k = 0; k < m; k++) {
			if (strcmp(arr[k].t_name, brr[j].trainer) == 0) {
				arr[k].m_arr[arr[k].m_cnt] = j;
				arr[k].m_cnt++;
				break;
			}
		}
		if(k == m) {
			arr[i].t_name = brr[j].trainer;
			arr[i].m_cnt = 0;
			arr[i].m_arr = (int*)calloc(100, sizeof(int));
			arr[i].m_arr[arr[i].m_cnt] = j;
			arr[i].m_cnt++;
			i++;
		}
			
	}
	return i;
}

void trainer_best(trainer* arr, int cnt) {
	int k = 0;
	for (int i = 0; i < cnt; i++) {
		if (k < arr[i].m_cnt) k = arr[i].m_cnt;
	}
	for (int i = 0; i < cnt; i++) if (arr[i].m_cnt == k) std::cout << arr[i].t_name << '\n';
}

void trainer_check_print(trainer* arr,member *table, int cnt) {
	for (int i = 0; i < cnt; i++) {
		std::cout << arr[i].t_name << '\n';
		for (int j = 0; j < arr[i].m_cnt; j++) std::cout << arr[i].m_arr[j] << ' ';
		std::cout << '\n';
	}
}
