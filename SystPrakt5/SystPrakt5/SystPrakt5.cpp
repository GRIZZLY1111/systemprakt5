// SystPrakt5.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
struct Node {
    int data;
    Node* next;
    Node* prev;

    Node(int value) : data(value), next(nullptr), prev(nullptr) {}
};
class DoubleLinkedList {
    public:
        Node* head;
        Node* tail;
        
        DoubleLinkedList() {
            head = nullptr;
            tail = nullptr;
        }

        void push_front(int value) {
            Node* newn = new Node(value);
            if (head == nullptr) {
                head = newn;
                tail = newn;
            }
            else {
                newn->next = head;
                head->prev = newn;
                head = newn;
            }
        }

        void push_back(int value) {
            Node* newn = new Node(value);
            if (tail == nullptr) {
                head = newn;
                tail = newn;
            }
            else {
                tail->next = newn;
                newn->prev = tail;
                tail = newn;
            }
        }

        void pop_front() {
            if (head == nullptr) {
                std::cout << "Список пустой"<<std::endl;
            }
            else {
                Node* newn = head;
                head = head->next;
                head->prev = nullptr;
                if (head == nullptr)
                    tail = nullptr;
                delete newn;
            }
        }

        void pop_back() {
            if (tail == nullptr) {
                std::cout << "Список пустой" << std::endl;
            }
            else {
                Node* newn = tail;
                tail = tail->prev;
                tail->next = nullptr;
                if (tail == nullptr)
                    head = nullptr;
                delete newn;
            }
        }

        void display() {
            if (head == nullptr) {
                std::cout << "Список пустой";
            }
            else {
                Node* newn = head;
                while (newn != nullptr) {
                    std::cout << newn->data << " ";
                    newn = newn->next;
                }
            }
            std::cout << std::endl;
        }

        void bubble_sort() {
            if (head == nullptr) {
                return;
            }
            bool f=true;
            Node* end = nullptr;//Указывает на последний отсортированный элемент за который можно не заходить
            while (f){
                f = false;
                Node* newn = head;
                while (newn->next != end) {
                    if (newn->data > newn->next->data) {
                        int x = newn->data;
                        newn->data = newn->next->data;
                        newn->next->data = x;
                        f = true;
                    }
                    newn = newn->next;
                }
                end = newn;
            }
        }

        void remove_duplicates() {
            if (head == nullptr) {
                std::cout << "Список пустой" << std::endl;
                return;
            }
            Node* newn = head;
            while (newn != nullptr) {
                int value = newn->data;
                Node* runner = newn->next;
                while (runner != nullptr) {
                    Node* next_runner = runner->next;
                    if (runner->data == value) {
                        if (runner->prev != nullptr) {
                            runner->prev->next = runner->next;
                        }
                        if (runner->next != nullptr) {
                            runner->next->prev = runner->prev;
                        }
                        if (runner == tail) {
                        }
                        delete runner;
                    }
                    runner = next_runner;
                }
                newn = newn->next;
            }
            std::cout << "Дубликаты удалены" << std::endl;
        }
 };

int main()
{
    setlocale(0, "rus");
    int n,x;
    DoubleLinkedList spisok;
    while(true){
        std::cout << "Выберите один из предложенных вариантов" << std::endl;
        std::cout << "1 - Добавить элемент в начало списка" << std::endl;
        std::cout << "2 - Добавить элемент в конец списка" << std::endl;
        std::cout << "3 - Удалить элемент с начала списка" << std::endl;
        std::cout << "4 - Удалить элемент с конца списка" << std::endl;
        std::cout << "5 - Вывести все элементы на экран" << std::endl;
        std::cout << "6 - Сортировать список" << std::endl;
        std::cout << "7 - Удалить дубликаты" << std::endl;
        std::cout << "8 - Выход" << std::endl;
        std::cin >> n;
        if (n == 8) {
            break;
        }
        else {
            switch (n) {
            case 1:
                std::cout << "Введите элемент" << std::endl;
                std::cin >> x;
                spisok.push_front(x);
                break;
            case 2:
                std::cout << "Введите элемент" << std::endl;
                std::cin >> x;
                spisok.push_back(x);
                break;
            case 3:
                spisok.pop_front();
                break;
            case 4:
                spisok.pop_back();
                break;
            case 5:
                spisok.display();
                break;
            case 6:
                spisok.bubble_sort();
                break;
            case 7:
                spisok.remove_duplicates();
                break;
            default:
                std::cout << "Ошибка ввода такого элемента выбора не существует" << std::endl;
                break;
            }
        }
    }
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
