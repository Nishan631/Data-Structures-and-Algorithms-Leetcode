class MyLinkedList {
public:
    MyLinkedList() {}

    struct ListNode {
        int val;
        ListNode* next;

        ListNode(int x) {
            val = x;
            next = nullptr;
        }
    };

    ListNode* head = NULL;
    int current_size = 0;

    int get(int index) {
        if (index < 0 || index >= current_size)
            return -1;

        ListNode* curr = head;
        for (int i = 0; i < index; i++) {
            curr = curr->next;
        }
        return curr->val;
    }

    void addAtHead(int val) {
        if (head == nullptr)
            head = new ListNode(val);

        else {
            ListNode* curr = new ListNode(val);
            curr->next = head;
            head = curr;
        }
        current_size++;
    }

    void addAtTail(int val) {
        if (head == nullptr)
            head = new ListNode(val);

        else {
            ListNode* tail = head;

            while (tail->next != NULL) {
                tail = tail->next;
            }

            tail->next = new ListNode(val);
        }
        current_size++;
    }

    void addAtIndex(int index, int val) {
        if (index < 0 || index > current_size)
            return;
        if (index == 0) {
            addAtHead(val);
            return;
        }
        if (index == current_size) {
            addAtTail(val);
            return;
        }

        ListNode* curr = head;
        for (int i = 0; i < index - 1; i++) {
            curr = curr->next;
        }
        ListNode* next = curr->next;
        curr->next = new ListNode(val);
        curr->next->next = next;
        current_size++;
    }

    void deleteAtIndex(int index) {
        if (index < 0 || index >= current_size)
            return;

        if (index == 0) {
            ListNode* toDelete = head;
            head = head->next;
            delete toDelete;
            current_size--;
            return;
        }

        ListNode* curr = head;
        ListNode* prev = NULL;

        for (int i = 0; i < index; i++) {
            prev = curr;
            curr = curr->next;
        }
        prev->next = curr->next;
        delete curr;
        current_size--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */