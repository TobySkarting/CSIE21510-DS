#ifndef _T_BST_H_
#define _T_BST_H_

#include <stdbool.h>

typedef struct node {
	struct node* lchild;
	struct node* rchild;
	int key;
}node_t, *p_node_t;
// 一般型態的節點，以及指標。 內含 key 值， 子樹的位址。

typedef struct {
	p_node_t root;
}bst_t, *p_bst_t;
// 一般結構型態的二元樹，以及指標。

p_node_t CreateNode(int);// 傳入 KEY 值，建立一個新的節點然後回傳位址。
p_bst_t CreateBst(int);// 建立一個新的二元樹，配置好記憶體完成初始化，傳入 key 值，然後回傳位址。
bool Add(p_node_t, int);// 在二元樹中，插入特定 KEY 值的節點。 回傳表 示成功失敗與否。
p_node_t Search(p_node_t, int);// 在二元樹中尋找，符合特定 key 值的節點，符合的話回傳節點位址，不符合的話回傳NULL。
p_node_t ModifySearch(p_node_t, int);// 修改過的 search，回傳可以接節點的位址
bool Remove(p_node_t *, int);// 在二元樹中，刪除某個特定 key 值的節點。回傳表示成功失敗與否。
void ListPreorder(p_node_t);// 以 preorder 方式，將二元樹中的 key 值及位址印出。
void FreeBst(p_bst_t *);// 將二元樹刪除並釋放記憶體

#endif /* _T_BST_H_ */
