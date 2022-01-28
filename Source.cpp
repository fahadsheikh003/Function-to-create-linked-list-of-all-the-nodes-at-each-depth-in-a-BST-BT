#include<iostream>
#include"BinaryTree.h"
#include<list>

template <typename QT>
void copyqueue(queue<QT>& Q1, queue<QT> Q2)
{
	while (!Q2.empty())
	{
		Q1.push(Q2.front());
		Q2.pop();
	}
}

//global function to display elements of stl based list
template <typename T>
void displaylist(list<T> L)
{
	typename list <T> ::iterator it;
	for (it = L.begin(); it != L.end(); ++it)
		cout << "  " << *it;//dereferencing current iterator
	cout << '\n';
}

template <typename T>
int BinaryTree<T>::calculateheight(Node* Node)//function to calculate height of BST
{
	if (Node == NULL)
		return -1;
	else
	{
		int leftsubheight = calculateheight(Node->left);
		int rightsubheight = calculateheight(Node->right);

		if (leftsubheight > rightsubheight)
			return leftsubheight + 1;
		else
			return rightsubheight + 1;
	}
}

template <typename T>
int BinaryTree<T>::Divisionintolinkedlist(Node* node)
{
	if (!isEmpty())
	{
		/*
		using two queues, one to hold all nodes that will be used to create
		linked list and second to fill first one again with all the childrens
		of nodes that are in second queue
		*/
		queue<Node*> Q1, Q2;

		int size = calculateheight(node) + 1;//calculating height of Tree

		list<T>* array = new list<T>[size];//creating an array of linked list
		Node* currnode = NULL;

		Q1.push(node);
		Q2.push(node);

		for (int i = 0; i < size; i++)
		{
			//entering data into linked list
			while (!Q2.empty())
			{
				currnode = Q2.front();
				Q2.pop();

				array[i].push_back(currnode->data);
			}

			//again populating nodes into second that will be then used to enter data into linked list
			while (!Q1.empty())
			{
				currnode = Q1.front();
				Q1.pop();

				if (currnode->left != NULL)
				{
					Q2.push(currnode->left);
				}

				if (currnode->right != NULL)
				{
					Q2.push(currnode->right);
				}
			}

			copyqueue<Node*>(Q1, Q2);//copying queue Q2 into Q1
		}

		//displaying linked lists
		for (int i = 0; i < size; i++)
		{
			cout << "Linked List #" << i + 1 << ": ";
			displaylist<T>(array[i]);
		}

		//deleting array of list
		delete[] array;

		//return size of array of linked list
		return size;
	}
	return -1;
}

int main()
{
	BinaryTree<int> BT;

	for (int i = 0; i < 7; i++)
		BT.Insert(i + 1);

	cout << "Binary Tree: \n";
	BinaryTree<int>::BFIterator it;

	for (it = BT.begin(); !it.end(); it++)
		cout << *it << endl;

	cout << "Number of Linked Lists: " << BT.Divisionintolinkedlist(BT.begin()) << endl;
}