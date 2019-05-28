struct ListNode {
	int val;
	ListNode *next;
	ListNode *prev;
	ListNode(int x) :val(x), next(nullptr), prev(nullptr) {}
};

class MyLinkedList {

	ListNode *head = nullptr;
	ListNode *tail = nullptr;
	int size;

public:

	/** Initialize your data structure here. */
	MyLinkedList() {
		head = new ListNode(0);
		tail = new ListNode(1001);
		head->next = tail;
		tail->prev = head;
		size = 0;
	}

	/** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
	int get(int index) {
		if (index >= size || size<0) return -1;
		ListNode *curr = nullptr;
		if (index * 2 >= size) {
			curr = tail->prev;
			for (int i = 0; i<size - 1 - index; ++i) {
				curr = curr->prev;
			}
		}
		else {
			curr = head->next;
			for (int i = 0; i<index; ++i) {
				curr = curr->next;
			}
		}
		return curr->val;
	}

	/** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
	void addAtHead(int val) {
		ListNode *tmp = head->next;
		ListNode *p = new ListNode(val);
		head->next = p;
		p->prev = head;
		p->next = tmp;
		tmp->prev = p;
		++size;
	}

	/** Append a node of value val to the last element of the linked list. */
	void addAtTail(int val) {
		ListNode *tmp = tail->prev;
		ListNode *p = new ListNode(val);
		p->next = tail;
		tail->prev = p;
		tmp->next = p;
		p->prev = tmp;
		++size;
	}

	/** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
	void addAtIndex(int index, int val) {
		if (index > size || size < 0) return;
		ListNode *curr;
		if (index * 2 >= size) {
			curr = head;
			for (int i = 0; i<index; ++i) {
				curr = curr->next;
			}
			ListNode *tmp = curr->next;
			ListNode *p = new ListNode(val);
			curr->next = p;
			p->prev = curr;
			p->next = tmp;
			tmp->prev = p;
		}
		else {
			curr = tail;
			for (int i = 0; i < size - index; ++i) {
				curr = curr->prev;
			}
			ListNode *tmp = curr->prev;
			ListNode *p = new ListNode(val);
			curr->prev = p;
			p->next = curr;
			p->prev = tmp;
			tmp->next = p;
		}
		++size;
	}

	/** Delete the index-th node in the linked list, if the index is valid. */
	void deleteAtIndex(int index) {
		if (index >= size || size < 0) return;
		ListNode *curr;
		if (index * 2 >= size) {
			curr = head;
			for (int i = 0; i<index; ++i) {
				curr = curr->next;
			}
			ListNode *tmp = curr->next;
			curr->next = tmp->next;
			tmp->next->prev = curr;
			delete tmp;
		}
		else {
			curr = tail;
			for (int i = 0; i<size - 1 - index; ++i) {
				curr = curr->prev;
			}
			ListNode *tmp = curr->prev;
			curr->prev = tmp->prev;
			tmp->prev->next = curr;
			delete tmp;
		}
		--size;
	}
};

/**
* Your MyLinkedList object will be instantiated and called as such:
* MyLinkedList obj = new MyLinkedList();
* int param_1 = obj.get(index);
* obj.addAtHead(val);
* obj.addAtTail(val);
* obj.addAtIndex(index,val);
* obj.deleteAtIndex(index);
*/