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
	n->data = *x; //데이터
	n->left = left; //왼쪽 자식 노드에 대한 포인터
	n->right = right; //오른쪽 자식 노드에 대한 포인터
}

BinNode* Search(BinNode* p, const Member* x)
{
	int cond;
	if (p == NULL) return NULL;
	else if (cond < 0) Search(p->left, x);
	else Search(p->right, x);
}

/* 1. p에 루트 포인터를 대입합니다 (루트를 선택)
   2. 삽입할 키 key와 p의 키 값을 비교합니다. 값이 같다면 삽입에 실패합니다(종료)
   -> 값이 같지 않은 경우 key 값이 삽입할 값보다 작으면 : 왼쪽 자식노드가 없는 경우 노드 삽입, 왼쪽 자식 노드가 있는 경우 선택한 노드 왼쪽 자식 노드 포인터 대입
   -> key 값이 삽입할 값보다 크면 : */
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
/*--- 최소 키 값을 가지는 노드를 검색 ---*/
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

/*--- 최대 키 값을 가지는 노드를 검색 ---*/
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

