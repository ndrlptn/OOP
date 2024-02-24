#pragma once

#ifndef HEADER_H
#define HEADER_H

#include <iostream>
const unsigned int MAX_SIZE = 10;

struct Node
{
    int val;
    Node* next;

    Node() {}
    Node(int _val) :val(_val), next(nullptr) {}

    Node(Node& a)
    {
        this->val = a.val;
        this->next = a.next;
    }
};

class myList
{
private:
    Node* first = nullptr;

public:
    bool operator ==(const myList& b)
    {
        Node* arrow_a = this->first;
        Node* arrow_b = b.first;

        while (arrow_a && arrow_b)
        {
            if (arrow_a->val == arrow_b->val)
            {
                arrow_a = arrow_a->next;
                arrow_b = arrow_b->next;
            }
            else
                return false;
        }
        if (arrow_a || arrow_b)
            return false;
        else return true;

    }

    myList& operator =(const myList& b)
    {
        Node* arrow_;
        Node* arrow1;

        arrow_ = this->first; //a.first
        arrow1 = b.first;

        if (arrow_) // если есть элементы в "a"
        {
            while (arrow1->next && arrow_->next) //если в обоих есть элементы
            {
                arrow_->val = arrow1->val;

                arrow_ = arrow_->next;
                arrow1 = arrow1->next;
            }

            if (arrow_->next)       // если элементы "b" закончились
            {
                Node* nextNode = arrow_->next;
                arrow_->next = nullptr;
                arrow_->val = arrow1->val;

                while (nextNode)
                {
                    Node* temp = nextNode;
                    nextNode = nextNode->next;
                    delete(temp);
                }
                
            }

            if (arrow1->next)      // если элементы "a" закончились
            {
                arrow_->val = arrow1->val;
                arrow1 = arrow1->next;

                while (arrow1)
                {
                    this->push(arrow1->val);
                    arrow1 = arrow1->next;
                }
            }
        }
        else
        {
            while (arrow1)      // если нет элементов  в "a"
            {
                this->push(arrow1->val);
                arrow1 = arrow1->next;
            }
        }


        return *this;
    }

    size_t size()
    {
        int size = 0;
        Node* arrow = this->first;

        while (arrow)
        {
            ++size;
            arrow = arrow->next;
        }

        return size;
    }
    
    size_t  max_size()
    {
        return MAX_SIZE;
    }

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

        std::cout << '\n';

    }

    void delete_elements(int _val)
    {
        if (!empty())
        {
            Node* left = first;
            Node* arrow = left->next;
            Node* memory = nullptr;

            while (first && (first->val == _val))
            {
                memory = first;
                first = first->next;
                delete(memory);

                left = first;
                if (left) arrow = left->next;
            }
            while (arrow)
            {
                if (arrow->val == _val)
                {
                    memory = arrow;
                    left->next = arrow->next;
                    delete(memory);

                    if (left) arrow = left->next;
                }
                else
                {
                    left = left->next;
                    if (left) arrow = left->next;
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

    void swap(myList& b)
    {
        if (this->size() != b.size())
        {
            Node* arrow_a = this->first;
            Node* arrow_b = b.first;
            myList temp;
            temp = myList(b);
            b = *this;
            *this = temp;
        }
        else // if (a.size() == b.size)
        {
            Node* arrow_a = this->first;
            Node* arrow_b = b.first;
            int temp = 0;

            while (arrow_a && arrow_b)
            {
                temp = arrow_a->val;
                arrow_a->val = arrow_b->val;
                arrow_b->val = temp;

                arrow_a = arrow_a->next;
                arrow_b = arrow_b->next;
            }
        }
    }

    

    myList() {}

    myList(myList& l)
    {
        Node* arrow;
        arrow = l.first;

        while (arrow)
        {
            this->push(arrow->val);
            arrow = arrow->next;

        }
    }

    ~myList()
    {
        Node* arrow = this->first;
        Node* memory;

        while (arrow)
        {
            memory = arrow;
            arrow = arrow->next;
            delete(memory);
        }

        this->first = nullptr;
    }
};

void swap(myList& a, myList& b)
{
    a.swap(b);
}

#endif
