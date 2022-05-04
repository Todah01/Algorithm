#if 1
#include <stdio.h>
#include <stdlib.h>
#include "11_member.h"
#include "10_tree.h"

static BinNode* AllocBinNode(void)
{
	return calloc(1, sizeof(BinNode));
}

static void SetBinNode(BinNode* n, const Member* x, const BinNode* left, const BinNode* right)
{
	n->data = *x; //������
	n->left = left; //���� �ڽ� ��忡 ���� ������
	n->right = right; //������ �ڽ� ��忡 ���� ������
}

BinNode* Search(BinNode* p, const Member* x)
{
	int cond;
	if (p == NULL) return NULL;
	else if ((cond = MemberNoCmp(x, &p->data)) == 0) return p;
	else if (cond < 0) Search(p->left, x);
	else Search(p->right, x);
}

BinNode* Add(BinNode* p, const Member* x)
{
	int cond;
	if (p == NULL)
	{
		p = AllocBinNode();
		SetBinNode(p, x, NULL, NULL);
	}
	else if ((cond = MemberNoCmp(x, &p->data)) == 0) printf("�����߻� %d�� �̹� ��ϵǾ� �ֽ��ϴ�\n", x->no);
	else if (cond < 0) p->left = Add(p->left, x);
	else p->right = Add(p->right, x);
}

void PrintTree(const BinNode* p)
{
	if (p != NULL)
	{
		PrintTree(p->left);
		PrintLnMember(&p->data);
		PrintTree(p->right);
	}
}
/* 1. p�� ��Ʈ �����͸� �����մϴ� (��Ʈ�� ����)
   2. ������ Ű key�� p�� Ű ���� ���մϴ�. ���� ���ٸ� ���Կ� �����մϴ�(����)
   -> ���� ���� ���� ��� key ���� ������ ������ ������ : ���� �ڽĳ�尡 ���� ��� ��� ����, ���� �ڽ� ��尡 �ִ� ��� ������ ��� ���� �ڽ� ��� ������ ����
   -> key ���� ������ ������ ũ�� : */
#endif

//Q1
#if 1
void PrintTreeReverse(const BinNode *p)
{
	if (p != NULL) {
		PrintTreeReverse(p->right);
		PrintLnMember(&p->data);
		PrintTreeReverse(p->left);
	}
}
#endif

#if 0
/*--- �ּ� Ű ���� ������ ��带 �˻� ---*/
BinNode *GetMinNode(const BinNode *p)
{
	if (p == NULL)
		return NULL;
	else {
		while (p->left != NULL)
			p = p->left;
		return p;
	}
}

/*--- �ִ� Ű ���� ������ ��带 �˻� ---*/
BinNode *GetMaxNode(const BinNode *p)
{
	if (p == NULL)
		return NULL;
	else {
		while (p->right != NULL)
			p = p->right;
		return p;
	}
}
#endif

//1��
#if 0
#include <stdio.h>
int arr[26][2];

void pre(int x) {
	if (x < 0) return;

	printf("%c", x + 65);
	pre(arr[x][0]);
	pre(arr[x][1]);

	return;
}

void in(int x) {
	if (x < 0) return;

	in(arr[x][0]);
	printf("%c", x + 65);
	in(arr[x][1]);

	return;
}

void post(int x) {
	if (x < 0) return;

	post(arr[x][0]);
	post(arr[x][1]);
	printf("%c", x + 65);

	return;
}

int main() {
	int n;
	char a, b, c;

	scanf("%d", &n);

	for (int i = 0;i < n;i++) {
		scanf("\n%c \n%c \n%c", &a, &b, &c);

		arr[a - 65][0] = b - 65;
		arr[a - 65][1] = c - 65;
	}

	pre(0); printf("\n");
	in(0); printf("\n");
	post(0); printf("\n");

	return 0;
}
#endif

//1��__
#if 0
#include <stdio.h>
#include "10_tree.h"
#include "11_member.h"
#pragma warning(disable : 4996)

int main()
{
	int n;
	char x, y, z;
	BinNode* temp = NULL;

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		scanf("%c %c %c", &x, &y, &z);
		Add(temp, &x);
	}
}
#endif

//2��
#if 1

#endif

//3��
#if 0
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

int n, u, v, cost;
int node, ans;
bool visit[100001];
vector<pair<int, int>> graph[100001];

void DFS(int x, int dist)
{
	visit[x] = true;

	if (dist > ans)
	{
		ans = dist;
		node = x;
	}

	for (int i = 0; i < graph[x].size(); i++)
	{
		int next_node = graph[x][i].first;
		int next_dist = graph[x][i].second + dist;
		if (!visit[next_node])
		{
			visit[next_node] = true;
			DFS(next_node, next_dist);
			visit[next_node] = false;
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 1; i < n; i++)
	{
		cin >> u >> v >> cost;
		graph[u].push_back({ v,cost });
		graph[v].push_back({ u,cost });
	}

	DFS(1, 0);
	ans = 0;
	for (int i = 1; i <= n; i++)
		visit[i] = false;
	DFS(node, 0);
	cout << ans << '\n';
}
#endif