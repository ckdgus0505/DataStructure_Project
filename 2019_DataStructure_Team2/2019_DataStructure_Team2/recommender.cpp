#include "forest.h"

void forest::init(int max_size)
{
	ntree = 0;
	size = max_size;
	root = (nptr*)calloc(size, sizeof(nptr));
}
void forest::forest_insert(int member_id, int rmember_id)
{
	for (int i = 0; i < ntree; i++) {
		int idx = forest_search(member_id);
		//루트가 아닌데 루트에 없어서 -1을 받았는데 트리 안에 있으면 에ㅔ러ㅓㅓ
		if (idx == -1 && root[i]->search(member_id)) {
			printf("error\n");
			return;
		}
		//내가 루트인데 나를 추천한 사람이 나옴 내가 그 밑으로 들어가야됨
		if (idx != -1) {
			root[ntree] = (nptr)malloc(sizeof(node));
			root[ntree]->set(rmember_id);
			root[ntree]->nchild++;
			root[ntree]->childs[0] = (nptr)malloc(sizeof(node));
			root[ntree++]->childs[0] = root[idx];
			remove(idx);
			return;
		}
		if (root[i]->search(rmember_id)) {
			root[i]->insert(member_id, rmember_id);
			return;
		}
	}
	root[ntree] = (nptr)malloc(sizeof(node));
	root[ntree]->init();
	root[ntree++]->insert(member_id, rmember_id);
}
void forest::print(member_info table)
{
	for (int i = 0; i < ntree; i++) {
		printf("root %d : %s\n", i, table.list[root[i]->get_member_ID()].name);
		root[i]->traversal(table);
	}
}
int forest::forest_search(int member_id)
{
	for (int i = 0; i < ntree; i++)
		if (root[i]->get_member_ID() == member_id)
			return i;
	return -1;
}
void forest::remove(int idx)
{
	for (int j = idx + 1; j < ntree; j++)
		root[j - 1] = root[j];
	ntree--;
}

void node::init()
{
	member_ID = -1;
	nchild = 0;
	childs = NULL;
}
void node::traversal(member_info table)
{
	printf("[ %s ] ", table.list[member_ID].name);
	for (int i = 0; i < nchild; i++)
		printf("%s ", table.list[childs[i]->member_ID].name);
	printf("\n");
	for (int i = 0; i < nchild; i++)
		childs[i]->traversal(table);
}
int node::is_empty()
{
	return member_ID == -1;
}

int node::insert(int member_id, int rmember_id)
{
	if (this->member_ID == -1) {
		this->set(rmember_id);
		this->nchild++;
		childs[nchild - 1] = (nptr)malloc(sizeof(node));
		this->childs[nchild - 1]->set(member_id);
		return 1;
	}
	if (rmember_id == this->member_ID) {
		this->nchild++;
		childs[nchild - 1] = (nptr)malloc(sizeof(node));
		this->childs[nchild - 1]->set(member_id);
		return 1;
	}
	for (int i = 0; i < nchild; i++) {
		if (childs[i]->insert(member_id, rmember_id))
			return 1;
	}
	return 0;
}
void node::remove(int member_id)
{

}
void node::set(int member_id)
{
	member_ID = member_id;
	nchild = 0;
	childs = (nptr*)calloc(300, sizeof(nptr));
}

int node::search(int member_id)
{
	if (this->member_ID == member_id)
		return 1;
	for (int i = 0; i < nchild; i++)
		if (childs[i]->get_member_ID() == member_id)
			return 1;
	for (int i = 0; i < nchild; i++)
		childs[i]->search(member_id);
	return 0;
}
int node::get_member_ID()
{
	return member_ID;
}


void most_recommender(member_info table)
{
	forest forest;
	forest.init(table.cnt);
	int mm, rm;
	for (int i = 0; i < table.cnt; i++) {
		mm = i;
		rm = table.search(table.list[i].recommender);
		if (rm != -1)
			forest.forest_insert(mm, rm);
	}
	forest.print(table);
}