#define MAX_TREE_SIZE
#include "HUffmanTree.h"
typedef struct
{
	int weight;
	int parent, lch, rch;
}HTNode, * HUffmanTree;
typedef struct
{
	int i;
	HUffmanTree Node[MAX_TREE_SIZE];
}*HuffmanTree;
HTNode HT[MAX_TREE_SIZE];
//HUffmanTree GT[MAX_TREE_SIZE];
int cmp_HT_weight(const void* e1, const void* e2)
{
	return (*(HUffmanTree*)e1)->weight - (*(HUffmanTree*)e2)->weight;//升序
}
void Select(HUffmanTree* HT, int q)
{
	int sz = sizeof(HT) / sizeof(HT[0]);
	for (int i = 0; i < q; i++)
	{
		if (HT[i]->parent == 0)
			continue;
		else
		{
			for (int j = i + 1; i < q; i++)
			{
				HT[i]->weight = HT[j + 1]->weight;
			}
		}
	}
	qsort(HT, sz, sizof(HT[0]), cmp_HT_weight);
}
void CreatHUffmanTree(HUffmanTree HT, int n)
{
	int i = 0;
	if (n < 1)
		return;
	int m = 2 * n - 1;
	HT = (HUffmanTree*)malloc(m + 1 * sizeof(HUffmanTree));
	for (i = 1; i <= m; i++)
	{
		HT[i].weight = 0;
		HT[i].lch = 0;
		HT[i].rch = 0;
		HT[i].parent = 0;
	}
	for (int i = 1; i <= n; ++i)
	{
		scanf_s("%d", HT[i].weight);
	}
	//哈弗曼树初始化
	for (i = n + 1; i <= m; i++)
	{
		Select(HT, i - 1);
		HT[0].parent = i;
		HT[1].parent = i;
		HT[i].lch = 0;
		HT[i].rch = 1;
		HT[i].weight = HT[0].weight + HT[1].weight;
	}
}
void main()
{
	HUffmanTree GT = NULL;
	int arr[10] = { 0,1,2 };
	arr[2] = 3;
	int n = NULL;
	n = 8;
	HuffmanTree H;
	//GT = (HUffmanTree*)malloc(sizeof(HUffmanTree));
	for (int i = n + 1; i <= 2 * n - 1; i++)
	{
		H->Node[i]->parent = H->Node[i + 1];
	}
	for (int i = n + 1; i <= 2 * n - 1; i++)
	{
		HT[i].parent = HT[i].parent;
	}
	HT[n] = HT[n + 1];
	CreatHUffmanTree(GT, n);
	//GT[n]->parent = GT[n]->parent;
}
//我特么的学的跟傻逼一样,给这找区别呢,我去你妈的