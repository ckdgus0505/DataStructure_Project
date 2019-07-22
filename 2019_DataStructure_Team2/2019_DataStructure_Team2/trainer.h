class trainer {
public:
	char* t_name;
	int m_cnt;
	int *m_arr;
};


int trainer_load(trainer*, member*, int);
void trainer_best(trainer*, int);
void trainer_check_print(trainer*, member*, int);