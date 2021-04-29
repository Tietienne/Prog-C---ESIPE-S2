#ifndef __NODE__
#define __NODE__

typedef struct node{
	char* word;
	struct node* next;
} node, *List;

typedef struct _table {
	node **bucket;
	int M; // Size of the table
	int distinct; // total distinct words
} table;

#endif