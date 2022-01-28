#pragma once
#include<queue>
#include<stack>
//Fahad Waheed

using namespace std;

template <typename T>
class BinaryTree
{
	struct Node
	{
		T data;
		Node* left, * right;

		Node() : data(T()), left(NULL), right(NULL) {};

		Node(T data) : data(data), left(NULL), right(NULL) {};
	};

	Node* root;

public:
	BinaryTree() : root(NULL) {};

	BinaryTree(const BinaryTree<T>& obj) : root(NULL)
	{
		if (obj.root)
		{
			queue<Node*> Q;

			Q.push(obj.root);
			Node* currnode = NULL;

			while (!Q.empty())
			{
				currnode = Q.front();
				Q.pop();

				Insert(currnode->data);

				if (currnode->left)
				{
					Q.push(currnode->left);
				}

				if (currnode->right)
				{
					Q.push(currnode->right);
				}
			}
		}
	}

	BinaryTree<T>& operator=(const BinaryTree<T>& obj)
	{
		if (obj.root)
		{
			queue<Node*> Q;

			Q.push(obj.root);
			Node* currnode = NULL;

			while (!Q.empty())
			{
				currnode = Q.front();
				Q.pop();

				Insert(currnode->data);

				if (currnode->left)
				{
					Q.push(currnode->left);
				}

				if (currnode->right)
				{
					Q.push(currnode->right);
				}
			}
		}
	}

	bool isEmpty()
	{
		return root == NULL;
	}

	void Insert(T data)
	{
		if (isEmpty())
		{
			root = new Node(data);
		}
		else
		{
			Node* currnode = root;
			queue<Node*> Q;

			Q.push(currnode);

			while (!Q.empty())
			{
				currnode = Q.front();
				Q.pop();

				if (currnode->left == NULL)
				{
					currnode->left = new Node(data);
					break;
				}
				else if (currnode->right == NULL)
				{
					currnode->right = new Node(data);
					break;
				}
				else
				{
					Q.push(currnode->left);
					Q.push(currnode->right);
				}
			}
		}
	}

	void Replace(T oldData, T newData)
	{
		if (!isEmpty())
		{
			queue<Node*> Q;

			Q.push(root);
			Node* currnode = NULL;

			while (!Q.empty())
			{
				currnode = Q.front();
				Q.pop();

				if (currnode->data == oldData)
				{
					currnode->data = newData;
					return;
				}

				if (currnode->left)
				{
					Q.push(currnode->left);
				}

				if (currnode->right)
				{
					Q.push(currnode->right);
				}
			}
		}
	}

	void Remove(T data)
	{
		if (!isEmpty())
		{
			if (root->data == data && root->left == NULL && root->right == NULL)
			{
				delete root;
				root = NULL;
			}
			else
			{
				queue<Node*> Q;
				Q.push(root);

				Node* currnode = NULL;
				Node* nodeToBeDeleted = NULL;

				while (!Q.empty())
				{
					currnode = Q.front();
					Q.pop();

					if (currnode->data == data)
						nodeToBeDeleted = currnode;

					if (currnode->left)
						Q.push(currnode->left);

					if (currnode->right)
						Q.push(currnode->right);
				}

				if (nodeToBeDeleted)
				{
					nodeToBeDeleted->data = currnode->data;

					nodeToBeDeleted = currnode;
					currnode = NULL;

					Q.push(root);

					while (!Q.empty())
					{
						currnode = Q.front();
						Q.pop();

						if (currnode->left)
						{
							if (currnode->left == nodeToBeDeleted)
							{
								currnode->left = NULL;
								delete nodeToBeDeleted;
								break;
							}
							else
								Q.push(currnode->left);
						}

						if (currnode->right)
						{
							if (currnode->right == nodeToBeDeleted)
							{
								currnode->right = NULL;
								delete nodeToBeDeleted;
								break;
							}
							else
								Q.push(currnode->right);
						}
					}
				}
			}
		}
	}

	class BFIterator
	{
		queue<Node*> Q;

	public:
		BFIterator() {};

		void operator=(Node* node)
		{
			while (!Q.empty())
				Q.pop();
			Q.push(node);
		}

		T operator*()
		{
			return Q.front()->data;
		}

		void operator++()
		{
			Node* currnode = Q.front();
			Q.pop();

			if (currnode->left)
				Q.push(currnode->left);
			if (currnode->right)
				Q.push(currnode->right);
		}

		void operator++(int)
		{
			++(*this);
		}

		bool end()
		{
			return Q.empty();
		}
	};

	class DFIterator//inorder (left --> root --> right)
	{
		stack<Node*> S;

	public:
		DFIterator() {};

		void operator=(Node* node)
		{
			while (!S.empty())
				S.pop();

			Node* currnode = node;
			while (currnode)
			{
				S.push(currnode);
				currnode = currnode->left;
			}
		}

		T operator*()
		{
			return S.top()->data;
		}

		void operator++()
		{
			Node* currnode = S.top()->right;
			S.pop();

			while (currnode)
			{
				S.push(currnode);
				currnode = currnode->left;
			}
		}

		void operator++(int)
		{
			++(*this);
		}

		bool end()
		{
			return S.empty();
		}
	};

	void clear()
	{
		if (!isEmpty())
		{
			queue<Node*> Q;

			Q.push(root);
			Node* currnode = NULL;

			while (!Q.empty())
			{
				currnode = Q.front();
				Q.pop();

				if (currnode->left)
				{
					Q.push(currnode->left);
				}

				if (currnode->right)
				{
					Q.push(currnode->right);
				}

				delete currnode;
			}
		}
	}

	Node* begin()
	{
		return root;
	}

	int calculateheight(Node* Node);

	int Divisionintolinkedlist(Node* Node);

	~BinaryTree()
	{
		clear();
	}
};