#include <initializer_list>
#include <iostream>

template <typename T>
class SingleLinkedList
{
private:
    class Node
    {
    private:
        T data;
        Node *next = nullptr;
        Node(T _val){data = _val;}

        friend class SingleLinkedList<T>;
    };
    Node* head = nullptr;
    int size = 0;
    Node* currentPos = nullptr;
    ///内部清除函数
    void _emptyList();
    void _copy(const SingleLinkedList<T> &_l);
public:
    /// 返回当前位置的值
    T getCurrentVal() const;
    /// 设置当前位置的值
    void setCurrentVal(const T &_val);
    /// 如果链表为空，返回 true；否则返回 false
    bool isEmpty() const;

    int getSize() const;
    void emptyList();
    bool find (const T &_val);
    SingleLinkedList(){};
    ~SingleLinkedList(); 
   SingleLinkedList(std::initializer_list<T> _l);      //单链表生成模式1
    void printList() const;
    SingleLinkedList(const SingleLinkedList<T> &_l);    //单链表生成模式2
    SingleLinkedList<T>& operator=(const SingleLinkedList<T> &_l);

    /// 在 currentPos 后面插入一个元素，数据为 _val
    void insert(T _val); 
    /// 如果找到，返回 ture, currentPos 停留在第一个 _val 的位置。
    /// 否则返回 false, currentPos 不动。 
    /// 删除 currentPos 后面的元素
    void remove();                                        
};

template<typename T>
bool SingleLinkedList<T>::find(const T &_val)
{
    Node *p = head;
    while (p != nullptr)
    {
        if (p->data == _val)
        {
            currentPos = p;
            return true;
        }
        p = p->next;    
    }
    return false;
}

template<typename T>
int SingleLinkedList<T>::getSize() const
{
    return size;
}

template <typename T>
SingleLinkedList<T>::SingleLinkedList(std::initializer_list<T> _l)
{
    for (auto i = _l.begin(); i != _l.end(); ++i)
    {
        Node* newNode = new Node(*i);
        if (head == nullptr)
        {
            head = newNode;
            currentPos = head;
        }
        else
        {
            currentPos->next = newNode;
            currentPos = newNode;
        }
        ++size;
    }
}

template <typename T>
void SingleLinkedList<T>::_emptyList()
{
    Node* p = head;
    while (p != nullptr)
    {
        Node* t = p;
        p = p->next; 
        delete t;
    }
}

template <typename T>
void SingleLinkedList<T>::printList() const
{
    Node* p = head;
    while (p != nullptr)
    {
        std::cout << p->data << "\t";
        p = p->next;
    }
    std::cout << std::endl;    
}

template <typename T>
SingleLinkedList<T>::~SingleLinkedList()
{
    _emptyList();
};

template<typename T>
SingleLinkedList<T>::SingleLinkedList(const SingleLinkedList<T> &_l)
{
    _copy(_l);
}

template<typename T>
void SingleLinkedList<T>::emptyList()
{
    _emptyList();
    head = nullptr;
    currentPos = nullptr;
    size = 0;
}

template<typename T>
SingleLinkedList<T>& SingleLinkedList<T>::operator=(const SingleLinkedList<T> &_l)
{
    if (this == &_l)
        return *this;
    emptyList();
    _copy(_l);
    return *this;
}

template <typename T>
void SingleLinkedList<T>::_copy(const SingleLinkedList<T> &_l)
{
    Node *p = _l.head;
    while (p != nullptr)
    {
        Node* newNode = new Node(p->data);
        if (head == nullptr)
        {
            head = newNode;
            currentPos = head;
        }
        else
        {
            currentPos->next = newNode;
            currentPos = newNode;
        }
        ++size;
        p = p->next;
    }
}
//1
template <typename  T>
T SingleLinkedList<T>::getCurrentVal() const
{
    if (currentPos != nullptr){
        return currentPos->data;
    }
    else {
       throw std::runtime_error("Empty current position! Can't get value!");
    }        
}
//2
template <typename T>  
void SingleLinkedList<T>::setCurrentVal(const T &_val){
    if (currentPos != nullptr){
        currentPos->data = _val;
    }
    else{
        throw std::runtime_error("Empty current position! Can't set value!");
    }
}
//3
template <typename T> 
bool SingleLinkedList<T>::isEmpty() const{
    if (head == nullptr){
        return true;
    }
    else{
        return false;
    }
}
//4
template <typename T> 
void SingleLinkedList<T>::insert(T _val){
    Node* newNode = new Node(_val);

    if(head == nullptr){
        head = newNode;
        currentPos = head;
    }
    else{
        newNode->next = currentPos->next;
        currentPos->next = newNode;
        currentPos = newNode ;
    }

    ++size;

}
//5
template <typename T> 
void SingleLinkedList<T>::remove(){
    if(size == 1){
        delete head;
        head = nullptr;
        currentPos = nullptr;
        size = 0;
    }
    else if(currentPos != nullptr && currentPos->next != nullptr){
        Node* del = currentPos->next;
        currentPos->next = del->next;
        delete del;
        --size;
        }
    
    }
    