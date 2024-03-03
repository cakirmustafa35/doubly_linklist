//Doubly linklistlere giriş yapılmıştı linklist nasıl oluşutuulur ile başlandı 
//node yazmasını öğrendik 
//şimdi de sondaki node'u nasıl silinir o öğrenilecek 

#include <iostream>
using namespace std;

class Node {
public:
    int deger;
    Node* next;
    Node* prev;
    /*doubly linklistler çift yönlü olduklarından dolayı geriyede gösteren bir
    pointer ataması yapılmalıdır*/
    Node(int deger) {
        this->deger = deger;
        next = NULL;
        prev = NULL;
        /*linklistlerde ilerlediklerinde next yapıldığında tail'den sonrası nasıl null gösteriyorsa
        prev yapıldığında head'den sonrası null göstermelidir sonuçta bir değer olmadığı ve 
        atanmadığı için NULL göstermeliidr.
        */
    }
};

class DoublyLinkedList {
private:
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
    void deleteLastNode() {
        if (count == 0) 
            return;
        
        Node* temp = tail;
        
        if (count != 1) {
            tail = tail->prev;
            tail->next = NULL;

            delete temp;
            count--;
        }
        else if (count == 1) {
            head = NULL;
            tail = NULL;
        }




    }

};



int main()
{
    DoublyLinkedList* doublyLinkedList1 = new DoublyLinkedList(12);




    doublyLinkedList1->getCount();
    doublyLinkedList1->printHead();
    doublyLinkedList1->printTail();
    doublyLinkedList1->PrintList();

    doublyLinkedList1->appendList(5);
    doublyLinkedList1->appendList(24);
    doublyLinkedList1->appendList(8);
    doublyLinkedList1->appendList(21);
   
    doublyLinkedList1->PrintList();//elemanlarının ilk hali

    doublyLinkedList1->deleteLastNode();
    doublyLinkedList1->deleteLastNode();
    doublyLinkedList1->deleteLastNode();

    doublyLinkedList1->PrintList();//elemanlarının son hali
    delete doublyLinkedList1;
    return 0;
}

