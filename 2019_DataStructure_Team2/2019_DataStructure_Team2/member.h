#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <ctime>
#include <vector>
#include <fstream>
#include <sstream>
#include <time.h>
#include<algorithm>
#include<queue>

class member {
public: // 18개 항목
	int ID; // 회원번호
	char* name; // 이름
	char* addr; // 주거지
	char* phone; // 전화번호
	char* recommender; // 추천인
	char* birthday; //생년월일
	char* ticket; // 구매상품
	char* pt_enroll; // pt등록여부
	char* trainer; // 담당 트레이너
	double BMIfirst; // 첫 BMI지수
	double BMInow; // 현재 BMI지수
	double BMIgoal; // 목표 BMI지수
	int locker; // 사용 라커
	char* enroll_date; // 최초 등록일
	int exer_cnt; // 누적 운동
	int pt_cnt; // 누적 PT 횟수
	char* latest; // 가장 최근 운동일
	char* finish; // 상품권 말소 시기

};

class member_info {
public:
	member* list;
	int(*pt_age)[2];
	int n;
	int cnt;
	void init(int max_size);
	void load();
};

std::vector<std::string> split(std::string str, char delimiter);
