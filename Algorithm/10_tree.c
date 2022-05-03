#if 0
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
	else if (cond < 0) Search(p->left, x);
	else Search(p->right, x);
}

/* 1. p�� ��Ʈ �����͸� �����մϴ� (��Ʈ�� ����)
   2. ������ Ű key�� p�� Ű ���� ���մϴ�. ���� ���ٸ� ���Կ� �����մϴ�(����)
   -> ���� ���� ���� ��� key ���� ������ ������ ������ : ���� �ڽĳ�尡 ���� ��� ��� ����, ���� �ڽ� ��尡 �ִ� ��� ������ ��� ���� �ڽ� ��� ������ ����
   -> key ���� ������ ������ ũ�� : */
#endif

//Q1
#if 0
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

