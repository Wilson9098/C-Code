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
	struct info data[Max];
	int size;
};


#include <stdio.h>
#include <string.h>
#include <assert.h>


void Initcontact(struct contact* p);
void addinfo(struct contact* p);
void showcontact(const struct contact* p);