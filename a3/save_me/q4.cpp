#include <iostream>

struct tree
{
	tree *r; // right branch
	tree *l; // left branch
	int val;
	tree(int v):r(nullptr),l(nullptr),val(v)
	{
	}
};

void print(tree *root)
{
	if (root!=nullptr)
	{
		print(root->l);
		std::cout << root->val << std::endl;
		print(root->r);
	}
}

void insert(tree *root, tree *node)
{
	if (root->val > node->val)
	{
		if (root->r == nullptr)
		{ 
			root->r = node;
		}
		else
		{
			insert(root->r,node);
		}
	}
	else
	{
		if (root->l == nullptr)
		{
			root->l = node;
		}
		else
		{
			insert(root->l,node);
		}
	}
}

int main()
{
	tree* root = new tree(3);
	insert(root,new tree(2));
	insert(root,new tree(4));
	insert(root,new tree(5));
	// find the maximum value in the tree,
	// with the lambda below
	auto max = [root]()
	{
		auto t =  0;
		auto node = root;
		while (node)
		{
			t += node->val;
			node = node->r;
		}
	        return t;
	};
	print(root);
	std::cout << std::endl;
	std::cout << max() << std::endl;	
	std::cout << root << std::endl;
	return 0;
}
