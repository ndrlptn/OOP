#pragma once

#ifndef HEADER_H
#define HEADER_H

#include <iostream>

struct Node
{
    int val;
    Node* next;

    Node() {}
    Node(int _val) :val(_val), next(nullptr) {}
};

class myList
{
private:
    Node* first = nullptr;

public:
    unsigned int MAX_SIZE = 10;

    bool empty()
    {
        return first == nullptr;
    }

    void push(int val)
    {
        Node* ptr = new Node(val);

        if (empty())
        {
            first = ptr;
        }//endif
        else
        {
            Node* arrow = first;
            if (ptr->val <= arrow->val)
            {
                ptr->next = first;
                first = ptr;
            }//endif
            else
            {
                Node* left = first;
                arrow = left->next;
                while (arrow)
                {
                    if (arrow->val >= ptr->val)
                    {
                        left->next = ptr;
                        ptr->next = arrow;
                        break;
                    }
                    left = left->next;
                    arrow = arrow->next;
                }
                if ((arrow == nullptr) && (left->val < ptr->val))
                {
                    arrow = ptr;
                    left->next = arrow;
                    arrow->next = nullptr;
                }
            }
        }

    }

    Node* searchVal(int _val)
    {
        Node* arrow = first;
        while (arrow && (arrow->val != _val))
            return arrow;
        if (!arrow)
            return nullptr;
    }

    void print()
    {
        int i = 1;
        Node* arrow = first;
        while (arrow)
        {
            std::cout << i << ". " << arrow->val << '\n';
            ++i;
            arrow = arrow->next;
        }
    }

    void delete_elements(int _val)
    {
        if (!empty())
        {
            Node* left = first;
            Node* arrow = left->next;
            Node* memory;

            while (first && (first->val == _val))
            {
                memory = first;
                first = first->next;
                delete(memory);

                left = first;
                if (left)
                    arrow = left->next;
            }
            while (arrow)
            {
                if (arrow->val == _val)
                {
                    memory = arrow;
                    left->next = arrow->next;
                    delete(memory);

                    if (left)
                        arrow = left->next;
                }
                else
                {
                    left = left->next;
                    if (left)
                        arrow = left->next;
                }
            }
        }
    }

    void deleteList()
    {
        Node* arrow = first->next;
        Node* memory = arrow;

        while (arrow)
        {
            memory = arrow;
            arrow = arrow->next;
            delete(memory);
        }
        first = nullptr;
    };

    myList &operator =(myList b)
    {
        Node* arrow = new Node();
        Node* arrow1 = new Node();

        arrow = this->first;
        arrow1 = b.first;

        while (arrow)
        {
            if (arrow1 && arrow) //если в обоих есть элементы
            {
                if (arrow->val != arrow1->val)
                    arrow->val = arrow1->val;
                arrow = arrow->next;
                arrow1 = arrow1->next;
            }
            while (arrow)       // если элементы "b" закончились
            {
                this->delete_elements(arrow->val);
                arrow = arrow->next;
            }
            while (arrow1)      // если элементы "a" закончились
            {
                this->push(arrow1->val);
                arrow1 = arrow1->next;
            }
        }
        
        return *this;
    }

    myList() {}

    myList(myList& l)
    {
        Node* arrow = new Node();
        arrow = l.first;

        while (arrow)
        {
            this->push(arrow->val);
            arrow = arrow->next;

        }
    }

    /*~myList()
    {
        Node* arrow = first;
        Node* memory = arrow;

        while (arrow)
        {
            memory = arrow;
            arrow = arrow->next;
            delete(memory);
        }
        first = nullptr;
    }*/
};

#endif
