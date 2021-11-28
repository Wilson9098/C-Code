#define Max 1000
#define max_name 20
#define max_tele 12
#define max_address 30
#define max_sex 8


struct info
{
	char name[max_name];
	char tele[max_tele];
	char address[max_address];
	char sex[max_sex];
	int age;
};

struct contact
{
	int size;
	struct info data[];
	
};

enum Option
{
	Exit,
	Add,
	Del,
	Modify,
	Sort,
	Show,
	Search
};


#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>


void Initcontact(struct contact** p);
void addinfo(struct contact** p);
void showcontact(const struct contact* p);
void delcontact(struct contact** p);
void search(const struct contact* p);
void mdfcontact(struct contact** p);
void sortcontact(struct contact** p);