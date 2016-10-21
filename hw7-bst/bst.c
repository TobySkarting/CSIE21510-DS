#include "bst.h"
#include <stdio.h>
#include <stdlib.h>

p_node_t CreateNode(int key)
{
	p_node_t newNode = (p_node_t)malloc(sizeof(node_t));
	newNode->key = key;
	newNode->lchild = newNode->rchild = NULL;
	return newNode;
}

p_bst_t CreateBst(int key)
{
	p_bst_t newBst = (p_bst_t)malloc(sizeof(bst_t));
	newBst->root = CreateNode(key);
	return newBst;
}

bool Add(p_node_t node, int key)
{
	p_node_t tmp = ModifySearch(node, key);
	if (!tmp)
		return false;
	if (key < tmp->key)
		tmp->lchild = CreateNode(key);
	else
		tmp->rchild = CreateNode(key);
	return true;
}

p_node_t Search(p_node_t node, int key)
{
	if (!node)
		return NULL;
	if (key == node->key)
		return node;
	if (key < node->key)
		return Search(node->lchild, key);
	else
		return Search(node->rchild, key);
}

p_node_t ModifySearch(p_node_t node, int key)
{
	if (key == node->key)
		return NULL;
	if (key < node->key)
		if (!node->lchild)
			return node;
		else
			return ModifySearch(node->lchild, key);
	else
		if (!node->rchild)
			return node;
		else
			return ModifySearch(node->rchild, key);
}

bool Remove(p_node_t *pnode, int key)
{
	bool applePen, pineApplePen;
	p_node_t diamond, papa, node = *pnode;
	if (!node)
		return false;
	
	applePen = !!node->lchild, pineApplePen = !!node->rchild;
	if (key < node->key)
	{
		if (applePen)
			return Remove(&node->lchild, key);
		else
			return false;
	}
	else if (key > node->key)
	{
		if (pineApplePen)
			return Remove(&node->rchild, key);
		else
			return false;
	}
	else
	{
		if (applePen && pineApplePen)
		{
			for (papa = node, diamond = node->lchild; diamond->rchild != NULL; papa = diamond, diamond = diamond->rchild);
			node->key = diamond->key;
			if (papa->lchild == diamond)
				papa->lchild = diamond->rchild;
			else if (papa->rchild == diamond)
				papa->rchild = diamond->rchild;
			free(diamond);
		}
		else if (applePen)
		{
			diamond = node->lchild;
			node->key = diamond->key;
			node->lchild = diamond->lchild;
			free(diamond);
		}
		else if (pineApplePen)
		{
			diamond = node->rchild;
			node->key = diamond->key;
			node->rchild = diamond->rchild;
			free(diamond);
		}
		else
		{
			free(node);
			*pnode = NULL;
		}
	}
	return true;
}

void ListPreorder(p_node_t node)
{
	if (!node)
		return;
	printf("%d:(%p) ", node->key, node);
	ListPreorder(node->lchild);
	ListPreorder(node->rchild);
}

void FreeNode(p_node_t node)
{
	if (!node)
		return;
	FreeNode(node->lchild);
	FreeNode(node->rchild);
	free(node);
}

void FreeBst(p_bst_t *bst)
{
	if (!*bst)
		return;
	FreeNode((*bst)->root);
	free(*bst);
	*bst = NULL;
}
