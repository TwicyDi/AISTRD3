#pragma once
#include <iostream>
#include "Iterator.h"
#include "List.h"

using namespace std;

template <class item> class queue
{
	item *Queue; int head, tail, size_, Max;
public:
	queue(int maxQ) : head(0), tail(0), Max(maxQ), size_(0), Queue(new item[maxQ + 1]) {}
	~queue();
	bool empty() const { return (head % Max) == tail; }
	int size() const { return size_; }
	void push(item & item) { Queue[tail++] = item; tail %= Max; ++size_; }
	item front() const { return Queue[head % Max]; }
	void pop() { head++; head %= Max; --size_; }
};

template <class item>
queue<item>::~queue()
{
	free(Queue);
}

template <typename T >
class map 
{
private:

	class node
	{

	public:
		node(T key, node * next1 = nullptr, node * next2 = nullptr) {
			this->next_left = next1;
			this->next_right = next2;
			this->key = key;
			this->parent = nullptr;
			this->color = 1;
			this->frequancy = 0;
			this->code = {};

		};
		bool color;
		size_t frequancy;
		string code;
		T key;
		node * next_right, *next_left, *parent;
		~node();

	};

	node * root;
	size_t size;
public:
	map();
	~map();

	void set_code(string str, char data) { find(data)->code = str; };
	string get_code(char data) { return find(data)->code; };
	class TreeIterator : public Iterator<T> {
	protected:
		node *current;
		TreeIterator(node* root) : current(root) { }

	public:
		bool operator==(const nullptr_t) const override { return current == nullptr; }
		bool operator!=(const nullptr_t) const override { return !operator==(nullptr); }
		size_t operator*() const override
		{
			return current->frequancy;
		}
		T current_key()
		{
			return current->key;
		}
		bool current_color() { return current->color; }
		T current_code()
		{
			return current->code;
		}
		node *get_cur() { return current; }
	};



	class BftIterator : public TreeIterator {
	private:
		queue<node*> nodes;
	public:
		BftIterator(node *root, size_t size) : TreeIterator(root), nodes(size) {}
		void operator++(int) override;
	};

	void reset_list();
	node *get_successor(node *);
	void add_first(T);
	void remove(T);
	void delfix(node*);
	node * find(T);
	List <T> get_keys();
	void get_value();
	void clear();
	void insert(T);
	void insertfix(node *&t);
	void leftrotate(node *);
	void rightrotate(node *);
	BftIterator create_bft_iterator() { return BftIterator(root, size); }
};



template<typename T>
void map<T>::BftIterator::operator++(int)
{
	if (this->current->next_left != nullptr)
		nodes.push(this->current->next_left);
	if (this->current->next_right != nullptr)
		nodes.push(this->current->next_right);
	if (nodes.size() > 0) {
		this->current = nodes.front();
		nodes.pop();
	}
	else
		this->current = nullptr;
}
