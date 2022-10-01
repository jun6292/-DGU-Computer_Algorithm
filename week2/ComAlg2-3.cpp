#include <iostream>
#include <random>
#include <ctime>
#define RANGE 90

using namespace std;

template <typename itemType>
class Stack3 {
public:
    Stack3() {
        head = new node;
        z = head;
    };
    ~Stack3() {
        struct node *tmp;
        tmp = z;
        while (head != tmp) {
            z = z->next;
            delete tmp;
            tmp = z;
        }
        delete tmp;
    };
    itemType top() {
        return z -> key;
    }
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

template <typename itemType>
class bt {
private:
    struct node {
        itemType value;
        struct node *left;
        struct node *right;
    };
    struct node *root;
public:
    bt() {
        root = NULL;
    };
    ~bt() {
        remove_node(root);
    };
    void insert(itemType key) {
        insert_node(root, key);
    };  
    void insert_node(node*& root, itemType key) {   // 포인터 참조를 활용하여 루트노드에 접근
        if (root == NULL) { // 트리가 비어있다면
            root = new node;
            root -> left = NULL;
            root -> right = NULL;
            root -> value = key;
        }
        else if (key < root -> value)   // 넣고자 하는 값이 루트 노드와 비교해서 작다면
            insert_node(root -> left, key);  // 왼쪽 자식에 삽입
        else if (key > root -> value)   // 넣고자 하는 값이 루트 노드와 비교해서 크다면
            insert_node(root -> right, key); // 오른쪽 자식에 삽입
        else                            // 넣고자 하는 값이 중복되었다면 리턴
            return;
    };
    void remove_node(node* n) {
        if (n == NULL)
            return;
        remove_node(n -> left);
        remove_node(n -> right);
        delete n;
    };
    void inorder_impl(Stack3<int>& stk) {
        inorder(root, stk);
    }
    void inorder(node* curr, Stack3<int>& stk)
	{   // 중위 순회하여 오름차순으로 스택에 push
		if (curr) {
			inorder(curr->left, stk);
			stk.push(curr->value);
			inorder(curr->right, stk);
		}
	};
};

int main()
{  
    srand((unsigned)time(NULL));    // 난수의 값을 바꾸기 위해 현재시간을 seed값으로 설정
    int n, m;
    cin >> n >> m;
    Stack3<int> A, B;
    bt<int> Atree, Btree;
    // 이진트리를 구성
    // m, n >= 10
    for (int i = 0; i < n; i++)
        Atree.insert(rand() % RANGE);
    for (int i = 0; i < m; i++)
        Btree.insert(rand() % RANGE);
    Atree.inorder_impl(A);  // 중위순회하여 스택에 삽입, top 연산 시 가장 큰 수를 반환
    Btree.inorder_impl(B);  // 중위순회하여 스택에 삽입, top 연산 시 가장 큰 수를 반환
    while (!A.empty() || !B.empty()) {  // 합집합 출력
        if (A.empty() && !B.empty()) {
            while (!B.empty()) {
                cout << B.top() << ' ';
                B.pop();
            }
        }
        else if (B.empty() && !A.empty()) {
            while (!A.empty()) {
                cout << A.top() << ' ';
                A.pop();
            }
        }
        else {
            if (A.top() == B.top()) {
                cout << A.top() << ' ';
                A.pop(); B.pop();
            }
            else if (A.top() > B.top()) {
                cout << A.top() << ' ';
                A.pop();
            }
            else if (A.top() < B.top()) {
                cout << B.top() << ' ';
                B.pop();
            }
        }
        
    }
    cout << '\n';
    Atree.inorder_impl(A); 
    Btree.inorder_impl(B);
    while (!A.empty() && !B.empty()) {  // 교집합 출력
        if (A.top() == B.top()) {
            cout << A.top() << ' ';
            A.pop(); B.pop();
        }
        else if (A.top() > B.top())
            A.pop();
        else
            B.pop();
    }
    cout << '\n';
    return 0;
}