#ifndef _T_BST_H_
#define _T_BST_H_

#include <stdbool.h>

typedef struct node {
	struct node* lchild;
	struct node* rchild;
	int key;
}node_t, *p_node_t;
// �@�뫬�A���`�I�A�H�Ϋ��СC ���t key �ȡA �l�𪺦�}�C

typedef struct {
	p_node_t root;
}bst_t, *p_bst_t;
// �@�뵲�c���A���G����A�H�Ϋ��СC

p_node_t CreateNode(int);// �ǤJ KEY �ȡA�إߤ@�ӷs���`�I�M��^�Ǧ�}�C
p_bst_t CreateBst(int);// �إߤ@�ӷs���G����A�t�m�n�O���駹����l�ơA�ǤJ key �ȡA�M��^�Ǧ�}�C
bool Add(p_node_t, int);// �b�G���𤤡A���J�S�w KEY �Ȫ��`�I�C �^�Ǫ� �ܦ��\���ѻP�_�C
p_node_t Search(p_node_t, int);// �b�G���𤤴M��A�ŦX�S�w key �Ȫ��`�I�A�ŦX���ܦ^�Ǹ`�I��}�A���ŦX���ܦ^��NULL�C
p_node_t ModifySearch(p_node_t, int);// �ק�L�� search�A�^�ǥi�H���`�I����}
bool Remove(p_node_t *, int);// �b�G���𤤡A�R���Y�ӯS�w key �Ȫ��`�I�C�^�Ǫ�ܦ��\���ѻP�_�C
void ListPreorder(p_node_t);// �H preorder �覡�A�N�G���𤤪� key �ȤΦ�}�L�X�C
void FreeBst(p_bst_t *);// �N�G����R��������O����

#endif /* _T_BST_H_ */
