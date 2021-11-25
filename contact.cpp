#define _CRT_SECURE_NO_WARNINGS 1

#include "contact.h"


void Initcontact(struct contact* p)
{
	assert(p);
	memset(p->data, 0, sizeof(p->data));
	p->size = 0;
}

void addinfo(struct contact* p)
{
	assert(p);
	if (Max == p->size)
		printf("Not enough storage");
	printf("Please input name: ");
	scanf("%s", p->data[p->size].name);
	printf("Please input phone number: ");
	scanf("%s", p->data[p->size].tele);
	printf("Please input address: ");
	scanf("%s", p->data[p->size].address);
	printf("Please input sex: ");
	scanf("%s", p->data[p->size].sex);
	printf("Please input age: ");
	scanf("%d", &(p->data[p->size].age));

	p->size++;
	printf("completed\n");
}

void showcontact(const struct contact* p)
{
	assert(p);
	int i = 0;
	if (!(p->size))
		printf("No data");
	else
	{
		printf("%-20s\t%-12s\t%-30s\t%-8s\t%-3s\n",
			"Name",
			"Number",
			"Address",
			"Sex",
			"Age");
		for(i=0;i<p->size; i++)
		{
			printf("%-20s\t%-12s\t%-30s\t%-8s\t%-3d\n",
				p->data[i].name,
				p->data[i].tele,
				p->data[i].address,
				p->data[i].sex,
				p->data[i].age);
		}
	}
}