//
// Created by user on 2026/4/4.
//
//繼承關係的多型轉型 深度解說；暫不理解

#include <iostream>
using namespace std;

class Animal {
public:
    virtual void speak() = 0;  // 純虛函式
    virtual ~Animal() {}//virtual 一定要加 不然會記憶體洩漏
    //~ 解構子  ，~ 就是「反轉」的意思，建構子建立物件，~解構子就是反過來，消滅物件！
};

class Dog : public Animal {
public:
    void speak() override { cout << "汪汪！\n"; }
    void fetch()          { cout << "狗狗去撿球！\n"; }
};

class Cat : public Animal {
public:
    void speak() override { cout << "喵喵！\n"; }
    void purr()           { cout << "貓咪在呼嚕...\n"; }
};

void checkAnimal(Animal* a) {
    a->speak();  // 多型，自動呼叫正確的 speak()

    // 嘗試向下轉型成 Dog
    Dog* d = dynamic_cast<Dog*>(a);
    if (d) {
        d->fetch();
    }

    // 嘗試向下轉型成 Cat
    Cat* c = dynamic_cast<Cat*>(a);
    if (c) {
        c->purr();
    }
}

int main() {
    Animal* a1 = new Dog();
    Animal* a2 = new Cat();

    cout << "--- a1 ---\n";
    checkAnimal(a1);

    cout << "--- a2 ---\n";
    checkAnimal(a2);

    delete a1;
    delete a2;
}
