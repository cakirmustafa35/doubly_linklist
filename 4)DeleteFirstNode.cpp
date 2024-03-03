//Doubly linklistlere giriş yapılmıştı linklist nasıl oluşutuulur ile başlandı 
//node yazmasını öğrendik 
//sondaki node'u silmeyi öğrendik
//başa node eklemeyi öğrendik
//şimdi de baştaki node'u silmeyi öğrendik

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
    void deleteLastNode() {//sondaki node silmek
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

    void addFirst(int deger) {//başa node eklenmesi 
        Node* newNode = new Node(deger);

        if (count == 0) {
            head = newNode;
            tail = newNode;
        }
        else {
            newNode->next = head;
            head->prev = newNode;//yeni değerin olduğundan dolayı null göstermez
            head = newNode;
        }

        count++;
    }

    void deleteFirstNode() {
        if (count == 0)
            return;

        Node* temp = head;
        if (count != 0) {
            head = head->next;
            head->prev = NULL;

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
    doublyLinkedList1->PrintList();//ilk halini gösteriyor

    doublyLinkedList1->deleteFirstNode();


    doublyLinkedList1->PrintList();//son halini gösteriyor 
    delete doublyLinkedList1;
    return 0;
}

