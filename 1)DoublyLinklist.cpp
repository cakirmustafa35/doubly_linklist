//Doubly linklistlere giriş yapılmıştı linklist nasıl oluşutuulur ile başlandı 
//node yazmasını öğrendik 
#include <iostream>
using namespace std;

class Node {
    public :
        int deger;
        Node* next;
        Node* prev;
        /*doubly linklistler çift yönlü olduklarından dolayı geriyede gösteren bir
        pointer ataması yapılmalıdır*/
        Node(int deger) {
            this->deger = deger;
            next = NULL;
            prev = NULL;
           /*linklistlerde ilerlediklerinde next yani tail olduğunda nasıl null gösteriyorsa 
           */
        }
};

class DoublyLinkedList {
    private :
        Node* head;
        Node* tail;
        int count;

    public:
        DoublyLinkedList(int deger) {
            Node* node = new Node(deger);
            head = node;
            tail = node;
            count = 1;
        }

        void PrintList() {
            Node* tmp = head;
            while (tmp != NULL) {
                cout << tmp->deger << " ,";
                tmp = tmp->next;

            }
            cout << endl;

        
        }

        void printHead() {
            if (head != NULL) 
                cout << "Head: " << head->deger << endl;
        }
        void printTail() {
            if (tail != NULL)
                cout << "Tail: " << tail->deger << endl;
        }
        void getCount() {
            cout << "List Count: " << this->count << endl;
        }

        void appendList(int deger) {
            Node* node = new Node(deger);

            if (count == 0) {
                head = node;
                tail = node;

            }
            else {
                tail->next = node;
                node->prev = tail;
                tail = node;

            }
            count++;

        }

};



int main()
{
    DoublyLinkedList* doublyLinkedList1 = new DoublyLinkedList(12);
   
    
    
    
    doublyLinkedList1->getCount();
    doublyLinkedList1->printHead();
    doublyLinkedList1->printTail();
    doublyLinkedList1->PrintList();

    doublyLinkedList1->appendList(2);
    doublyLinkedList1->appendList(5);
    doublyLinkedList1->appendList(3);
    doublyLinkedList1->appendList(9);

    doublyLinkedList1->PrintList();
    delete doublyLinkedList1;
    return 0;
}

