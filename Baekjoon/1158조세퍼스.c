#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable :4996)
typedef struct Node { //노드
	int data;
	struct Node *link;
}Node;

typedef struct Listhead { //노드 헤드 정의
	Node *head;
}Listhead;

Listhead *createNode() { // jose 노드 헤드
	Listhead *jose;
	jose = (Listhead*)malloc(sizeof(Listhead));
	jose->head = NULL;
	return jose;
}
void AddNode(Listhead *jose, int data) { // 노드 생성
	Node *newnode;
	Node *temp;
	newnode = (Node*)malloc(sizeof(Node));
	newnode->data = data;
	if (jose->head == NULL) {
		jose->head = newnode;
		newnode->link = newnode;
		return;
	}
	temp = jose->head;
	while (temp->link != jose->head)
		temp = temp->link;
	newnode->link = temp->link;
	temp->link = newnode;
}
void joseDelNode(Listhead *jose, int data) { //노드 삭제
	Node *pre, *cur;
	int i;
	if (jose->head == NULL) return;
	pre = jose->head;
	cur = jose->head->link;
	if (pre == cur) {
		printf("<%d>\n", cur->data);
		free(cur);
		return;
	}
	while (cur->data != data) {
		pre = cur;
		cur = cur->link;
	}
	pre->link = cur->link;
	if (cur == jose->head)
		jose->head = jose->head->link;
	printf("<%d, ", cur->data);
	free(cur);
	cur = pre->link;
	while (jose->head != NULL)
	{
		if (pre == cur) {
			printf("%d>\n", cur->data);
			free(cur);
			return;
		}
		for (i = 1; i < data; i++)
		{
			pre = cur;
			cur = cur->link;
		}
		pre->link = cur->link;
		if (cur == jose->head)
			jose->head = jose->head->link;
		printf("%d, ", cur->data);
		free(cur);
		cur = pre->link;
	}
}

int main() {
	
	int N, M;
	scanf("%d %d", &N, &M);
	Listhead *jose = createNode();
	for (int data = 1; data <= N; data++)
		AddNode(jose, data);
	joseDelNode(jose, M);

	return 0;
}