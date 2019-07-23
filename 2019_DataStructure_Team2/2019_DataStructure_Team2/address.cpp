#include <stdio.h>
#include <string>
#include "address.h"
#include "member.h"
#pragma warning(disable : 4996)

extern int line;
void most_addr(member* list)
{
	address address;
	address.init(1000);
	for (int i = 0; i < line; i++)
		address.insert(list[i].addr);
	address.sort();
	address.print();
	address.result();
}

void element::set(char* name_) {

	name = (char*)malloc(16);
	strcpy(name, name_);
	n_mem = 0;
}

void address::init(int n)
{
	this->n = n;
	cnt = 0;
	addr = (element*)calloc(n, sizeof(element));
}
void address::insert(char* name)
{
	for (int i = 0; i < cnt; i++) {
		if (strcmp(addr[i].name, name) == 0) {
			addr[i].n_mem++;
			return;
		}
	}
	addr[cnt++].set(name);
}
void swap(element& a, element& b) {
	element x;
	x = a;
	a = b;
	b = x;
}
void address::sort()
{
	int i, j;
	for (i = 0; i < cnt - 1; i++) {
		for (j = cnt - 1; j > i; j--) {
			if (addr[j - 1].n_mem < addr[j].n_mem)
				swap(addr[j - 1], addr[j]);
		}
	}
}
void address::print()
{
	for (int i = 0; i < cnt; i++)
		printf("%s %d\n", addr[i].name, addr[i].n_mem);
}
void address::result()
{
	printf("%s has the largest number of members with %d.\n%s has the fewest number of members with %d.\n",
		addr[0].name, addr[0].n_mem, addr[cnt - 1].name, addr[cnt - 1].n_mem);
}