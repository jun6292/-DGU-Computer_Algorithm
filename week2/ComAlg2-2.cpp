#include <iostream>

using namespace std;
template <typename itemType>

class Stack2 {
public:
    Stack2() { 
        head = new node;
        z = head;
    };
    ~Stack2() {
        struct node *tmp;
        tmp = z;
        while (head != tmp) {
            z = z->next;
            delete tmp;
            tmp = z;
        }
        delete tmp;
    };
    void push(itemType v) {
        struct node *new_node = new node;
        new_node->key = v;
        new_node->next = z;
        z = new_node;
    };
    itemType pop() {
        struct node *tmp = z;
        itemType key = z->key;
        z = z->next;
        delete tmp;
        return key;
    };
    int empty() {
        if (z == head) return 1;
        else return 0;
    };
private:
    struct node {
        itemType key;
        struct node *next;
    };
    struct node *head, *z;  // z = top
};

bool isDecimal(double d) {  // 실수인지 정수인지 판별하는 함수
    if (d == (int)d) return false;
    else return true;
}

int main()
{
    char c;
    Stack2<double> acc;
    double x;
    while ((c = cin.get()) != '\n') {
        x = 0;
        while (c == ' ')
            cin.get(c);
        if (c == '+') x = acc.pop() + acc.pop();
        if (c == '*') x = acc.pop() * acc.pop();
        if (c == '-') {
            double tmp1 = acc.pop();
            double tmp2 = acc.pop();
            x = tmp2 - tmp1;
        }
        if (c == '/') {
            double tmp3 = acc.pop();
            double tmp4 = acc.pop();
            x = tmp4 / tmp3;
        }
        while (c >= '0' && c <= '9') {
            x = 10 * x + (c - '0');
            cin.get(c);
        }
        acc.push(x);
    }
    x = acc.pop();
    if (isDecimal(x)) {
        cout << fixed;
        cout.precision(2);  // 소수점 둘째자리까지 출력
        cout << x << '\n';
    }
    else
        cout << x << '\n';
}