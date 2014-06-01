#include <iostream>
#include <limits>
#define maxint numeric_limits<int>::max()
using namespace std;
class ttreapnode
{
	public:
		int key;
		int tot;
		int count;
		int priority;
		ttreapnode *leftnode, *rightnode;
};
class ttreap
{
	public:
		ttreapnode *rootnode, *nullnode, *tmpnode;
		int answer;
		void initialize();
		void update(ttreapnode *&);
		void leftrotate(ttreapnode *&);
		void rightrotate(ttreapnode *&);
		void insert(ttreapnode *&, int);
		void Delete(ttreapnode *&, int);
		void findmax();
		void findmin();
};
void ttreap::initialize()
{
	srand(time(NULL));
	nullnode = new ttreapnode;
	nullnode->key = 0;
	nullnode->tot = 0;
	nullnode->count = 0;
	nullnode->priority = maxint;
	rootnode = nullnode;
}
void ttreap::update(ttreapnode *&curnode)
{
	curnode->tot = curnode->leftnode->tot + curnode->rightnode->tot + curnode->count;
}
void ttreap::leftrotate(ttreapnode *&curnode)
{
	tmpnode = curnode->leftnode;
	curnode->leftnode = tmpnode->rightnode;
	tmpnode->rightnode = curnode;
	update(curnode);
	update(tmpnode);
	curnode = tmpnode;
}
void ttreap::rightrotate(ttreapnode *&curnode)
{
	tmpnode = curnode->rightnode;
	curnode->rightnode = tmpnode->leftnode;
	tmpnode->leftnode = curnode;
	update(curnode);
	update(tmpnode);
	curnode = tmpnode;
}
void ttreap::insert(ttreapnode *&curnode, int key)
{
	if (curnode == nullnode)
	{
		curnode = new ttreapnode;
		curnode->key = key;
		curnode->count = 1;
		curnode->tot = 1;
		curnode->priority = rand();
		curnode->leftnode = nullnode;
		curnode->rightnode = nullnode;
		return;
	}
	if (curnode->key > key)
	{
		insert(curnode->leftnode, key);
		if (curnode->leftnode->priority < curnode->priority)
			leftrotate(curnode);
	}
	else if (curnode->key < key)
	{
		insert(curnode->rightnode, key);
	 	if (curnode->rightnode->priority < curnode->priority)
			rightrotate(curnode);
	}
	else curnode->count++;
	update(curnode);
}
void ttreap::Delete(ttreapnode *&curnode, int key)
{
	if (curnode->key > key)
		Delete(curnode->leftnode, key);
	else if (curnode->key < key)
		Delete(curnode->rightnode, key);
	else if (curnode->count > 1)
		curnode->count--;
	else
	{
		if ((curnode->leftnode == nullnode) && (curnode->rightnode == nullnode))
		{
			delete curnode;
			curnode = nullnode;
			return;
		}
		if (curnode->leftnode->priority < curnode->rightnode->priority)
			leftrotate(curnode);
		else
			rightrotate(curnode);
		Delete(curnode, key);
	}
	update(curnode);
}
void ttreap::findmax()
{
	tmpnode = rootnode;
	answer = -maxint;
	while (tmpnode->rightnode != nullnode)
		tmpnode = tmpnode->rightnode;
	answer = tmpnode->key;
}
void ttreap::findmin()
{
	tmpnode = rootnode;
	answer = -maxint;
	while (tmpnode->leftnode != nullnode)
		tmpnode = tmpnode->leftnode;
	answer = tmpnode->key;
}
int main()
{
	ttreap tree;
	char ch;
	int key;
	tree.initialize();
	while (cin >> ch)
	{
		switch (ch)
		{
			case 'I':
				cin.ignore();
				cin >> key;
				tree.insert(tree.rootnode, key);
				break;
			case 'D':
				cin.ignore();
				cin >> key;
				tree.Delete(tree.rootnode, key);
				break;
			case 'X':
				tree.findmax();
				cout << tree.answer << endl;
				break;
			case 'N':
				tree.findmin();
				cout << tree.answer << endl;
				break;
			default:
				cout << "Wrong input!\n";
				return 0;
		}
	}
	return 0;
}
