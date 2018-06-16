struct Node{
	int data; 
	Node *next;
}

class list{
	Node *head; 
	Node *tail;
public: 
	list(){
		head = NULL:
		tail = NULL:
	}
}

// Inserting a Node at the end 

void insert(int key){
	Node *n1 = new Node;
	n1->data = key;
	n1->next = NULL;
	if(head == NULL){
		head = n1;
		tail = n1;
		n1 = NULL:
	}else{
		while(tail){
			tail = tail->next;
		} 
		tail->next = n1;
		tail = n1;
	}
}

// Inserting at the start 

void insertStart(int key){
	Node *n1 = new Node;
	n1->data = key;
	n1->next = head;
	head = n1;
}

// Inserting at the k-th position


void insert(int position, int key){
	Node *prev = new Node;
	Node *cur = new Node;
	Node *temp = new Node;
	cur = head;
	for(int i = 1; i < position; i++){
		prev = cur;
		cur = cur->next;
	}
	temp->data = key;
	prev->next = temp;
	temp->next = cur;
}
// Deleting a node at the end of the  singly linked list 

void deleteNode(){
	Node *prev = new Node;
	Node *cur = new Node;
	cur = head;
	while(cur->next != NULL){
		prev = cur;
		cur = cur->next;
	}
	tail = prev;
	tail->next = NULL;
	delete cur;
}


// Deleting a node at a given position

void deletePos(int position){
	Node *prev = new Node;
	Node *cur = new Node;
	cur = head;
	for(int i = 1; i < pos; i++){
		prev = cur;
		cur = cur->next;
	}
	prev->next = cur->next;
	delete cur;
}

// Deleting the Node given: 
void deleteNode(struct Node *head, struct Node *n)
{
    // When node to be deleted is head node
    if(head == n)
    {
        if(head->next == NULL)
        {
            printf("There is only one node. The list can't be made empty ");
            return;
        }
        /* Copy the data of next node to head */
        head->data = head->next->data;
        // store address of next node
        n = head->next;
        // Remove the link of next node
        head->next = head->next->next;
        // free memory
        free(n);
        return;
    }
    // When not first node, follow the normal deletion process
    // find the previous node
    struct Node *prev = head;
    while(prev->next != NULL && prev->next != n)
        prev = prev->next;
    // Check if node really exists in Linked List
    if(prev->next == NULL)
    {
        printf("\n Given node is not present in Linked List");
        return;
    }
    // Remove node from Linked List
    prev->next = prev->next->next;
    // Free memory
    free(n);
    return; 

// Deleting the linked list
void entireListDeleted(Node *head){
	Node *cur = head;
	Node *temp;
	while(cur != NULL){
		temp = cur->next;
		delete(cur);
		cur = temp;
	}
}

// Reverse a linked list 

void reverseList(){
	Node *previous;
	Node *current;
	Node *link;
	previous = NULL;
	current = head;
	while(current != NULL){
		link = current->next; 
		current->next = previous;
		previous = current;
		current = link;
	}
	head = previous;
}


    
// Removing duplicates from an unsorted linked list
void removeDup(LinkedListNode *head){
	std::unordered_set<int> uniqueList;
	Node *previous = NULL;
	while(head != NULL){
		int key = current->data;
		if(uniqueList.count(key) > 0){ // found the key already, remove it
			previous->next = head->next;
		}else{
			uniqueList.emplace_back(key); // Put it into the hashset
			previous = head;
		}
		head = head->next;
	}
}

//follow up: temporary buffer not allowed 
void removeDupNobuffer(LinkedListNode *head){
	Node *current = head;
	while(current != NULL){
		Node *runner = current;
		while(runner->next != NULL){
			if(runner->next->data == current->data){
				runner->next = runner->next->next;
			}
			else{
				runner = runner->next;
			}
		}
		current = current->next;
	}
}

// getting the n-th node in the linked list 

int getNthNode(LinkedListNode *head, int n){
	//Node *previous = head;
	int i = 0;
	while(head != NULL){
		if(i == n){
		return current->data;
		}
		i++;
		head = head->next;
	}
	cerr << "Node n does not exist";
}


// detect loop 
bool detectLoop(struct Node *h)
{
    unordered_set<Node *> s;
    while (h != NULL)
    {
        // If we have already has this node
        // in hashmap it means their is a cycle
        // (Because you we encountering the
        // node second time).
        if (s.find(h) != s.end())
            return true;
 
        // If we are seeing the node for
        // the first time, insert it in hash
        s.insert(h);
 
        h = h->next;
    }
 
    return false;
}

// Delete a node from exactly the middle 
void deleteMiddle(LinkedListNode *n){
	Node *fast;
	Node *slow;
	Node previous;
	fast = n;
	slow = n;
	previous = slow;
	if(n != NULL){
	while(fast != NULL && fast->next != NULL){
		fast = fast->next->next;
		previous = slow;
		slow = slow->next;
		}
	previous->next = slow->next;
	}	
}

// adding two linked lists (7->1->6) + (5->9->2) = 617+295 = 912



// Swap a linked list nodes 


// Given two linked lists, return the intersection of the two lists: i.e. return a list containing only the elements that occur in both of the input lists.
// Forward Order 


// Check if a linked list is a palindrome 


// Merge k Sorted Lists 