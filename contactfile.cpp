#define _CRT_SECURE_NO_WARNINGS 1

#include "contactfile.h"


 static int find_by_name(const struct contact* p, char* name)
{
	int i = 0;
	for (i = 0; i < p->size; i++)
	{
		if (!strcmp(p->data[i].name, name))
			return i;
	}
	return -1;
}

 static int compare(const void* a, const void* b)
 {
	 return strcmp(((struct info*)a)->name,
		 ((struct info*)b)->name);
 }

void Initcontact(struct contact** p)
{
	assert((*p));
	/*memset(p->data, 0, sizeof(p->data));*/
	*p = (struct contact*)malloc(2 * sizeof(int) +
		default_size * sizeof(struct info));
	if (*p == NULL)
	{
		printf("%s", strerror(errno));
		return;
	}
	(*p)->capacity = default_size;
	(*p)->size = 0;
	Loadcontact(p);
}

void Loadcontact(struct contact** p)
{
	struct info tmp = { 0 };
	FILE* pfread = fopen("contact.txt", "rb");
	if (pfread == NULL)
	{
		printf("%s\n", strerror(errno));
		return;
	}

	while (fread(&tmp, sizeof(struct info),
		1, pfread))
	{
		if ((*p)->size == (*p)->capacity)
		{
			Add_capacity(p);
		}
		(*p)->data[(*p)->size] = tmp;
		((*p)->size)++;
	}

	fclose(pfread);
	pfread = NULL;
}

void Add_capacity(struct contact** p)
{
	struct contact* ptr = (struct contact*)realloc(*p, 8 +
		((*p)->size + 2) * sizeof(struct info));
	if (ptr != NULL)
	{
		*p = ptr;
		(*p)->capacity += 2;
		printf("capacity expanded\n");
	}
	else
	{
		printf("Expansion failed");
	}

}

void addinfo(struct contact** p)
{
	assert((*p));
	if (Max == (*p)->size)
		printf("Not enough storage");
	if ((*p)->capacity == (*p)->size)
	{
		Add_capacity(p);
	}

	printf("Please input name: ");
	scanf("%s", (*p)->data[(*p)->size].name);
	printf("Please input phone number: ");
	scanf("%s", (*p)->data[(*p)->size].tele);
	printf("Please input address: ");
	scanf("%s", (*p)->data[(*p)->size].address);
	printf("Please input sex: ");
	scanf("%s", (*p)->data[(*p)->size].sex);
	printf("Please input age: ");
	scanf("%d", &((*p)->data[(*p)->size].age));

	(*p)->size++;
	printf("Added\n");
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

void delcontact(struct contact** p)
{
	assert((*p));
	char name[max_name] = { 0 };
	if (!((*p)->size))
		printf("No contact\n");
	else
	{
		printf("Please input a name: ");
		scanf("%s", &name);
		int ret = find_by_name((*p), name);
		if (-1 == ret)
		{
			printf("Can't find it\n");
		}
		else
		{
			//DEL
			int j = 0;
			for (j = ret; j < (*p)->size - 1; j++)
			{
				(*p)->data[j] = (*p)->data[j + 1];
			}
			(*p)->size--;
			printf("Deleted\n");
		}
	}
	
}

void search(const struct contact* p)
{
	assert(p);
	char name[max_name] = { 0 };
	if (!(p->size))
		printf("No contact\n");
	else
	{
		printf("Please input a name: ");
		scanf("%s", &name);
		int ret = find_by_name(p, name);
		if (-1 == ret)
			printf("Can't find it\n");
		else
		{
			printf("%-20s\t%-12s\t%-30s\t%-8s\t%-3s\n",
				"Name",
				"Number",
				"Address",
				"Sex",
				"Age");
			printf("%-20s\t%-12s\t%-30s\t%-8s\t%-3d\n",
				p->data[ret].name,
				p->data[ret].tele,
				p->data[ret].address,
				p->data[ret].sex,
				p->data[ret].age);
		}
	}
}

void mdfcontact(struct contact** p)
{
	assert((*p));
	char name[max_name] = { 0 };
	if (!((*p)->size))
		printf("No contact\n");
	else
	{
		printf("Please input a name: ");
		scanf("%s", &name);
		int ret = find_by_name((*p), name);
		if (-1 == ret)
			printf("Can't find it\n");
		else
		{
			printf("Change name to: ");
			scanf("%s", (*p)->data[ret].name);
			printf("Change number to: ");
			scanf("%s", (*p)->data[ret].tele);
			printf("Change address tos: ");
			scanf("%s", (*p)->data[ret].address);
			printf("Change sex to: ");
			scanf("%s", (*p)->data[ret].sex);
			printf("Change age to: ");
			scanf("%d", &((*p)->data[ret].age));
		}
	}
}

void sortcontact(struct contact** p)
{
	assert((*p));
	if (!((*p)->size))
		printf("No contact\n");
	else
	{
		qsort((*p)->data, (*p)->size, sizeof(struct info), compare);
	}
}

void destroycontact(struct contact** p)
{
	free(*p);
	*p = NULL; 
}

void savecontact(struct contact** p)
{
	FILE* pfwrite = fopen("contact.txt", "wb");
	if (pfwrite == NULL)
	{
		printf("%s\n", strerror(errno));
		return;
	}

	int i = 0;
	for (i = 0; i < (*p)->size; i++)
	{
			fwrite(&((*p)->data[i]), sizeof(struct info),
				1, pfwrite);
	}

	fclose(pfwrite);
	pfwrite = NULL;
}