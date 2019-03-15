#ifndef SRC_H_
#define SRC_H_

#include <iostream>
#include <string>
#include <iostream>
#include <vector>
#include <stdexcept>
#include <initializer_list>
#include <sstream>
#include <list>
#include <initializer_list>
#include <algorithm>
#include <forward_list>
#include <memory>


namespace c1 {
    class Sales_item {
    public:
        friend std::istream& operator>> (std::istream &is, Sales_item &book);
        friend std::ostream& operator<< (std::ostream &os, const Sales_item &book);
        friend Sales_item operator+(const Sales_item &lhs, const Sales_item &rhs);//const左值引用可以绑定右值

        Sales_item() = default;
        Sales_item(const std::string &s, unsigned cnt, double price) {
            // 初始化 赋值含义不同，成员的初始化发生在进入构造函数体之前
            // 使用列表初始化
            bookNo = s;
            soldNum = cnt;
            revenue = cnt * price;
        }

        const std::string& isbn() const { //只能返回常量引用
            return bookNo;
        }

        Sales_item & operator+=(const Sales_item &rhs){
            if (bookNo != rhs.isbn())
                throw std::logic_error("+ the bookNo is different!");
            soldNum += rhs.soldNum;
            revenue += rhs.revenue;

            return *this;
        }


    private:
        std::string bookNo;
        unsigned soldNum = 0;
        double revenue = 0.0; //类内初始化
    };

    std::istream& operator>> (std::istream &is, Sales_item &book);
    std::ostream& operator<< (std::ostream &os, const Sales_item &book);
    Sales_item operator+(const Sales_item &lhs, const Sales_item &rhs);


    inline void test() {
        using namespace std;

        Sales_item b1("oux", 2, 12.0);
        Sales_item b2("oux", 3, 23.0);
        //Sales_item s = b1+b2;
        cout << (b1+b2);

    }

}


namespace c2 {
    /*
    初始化不是赋值P39，赋值是把当前对象的值擦除，而以一个新值取代
    建议初始化每一个内置数据类型

    */
    class A{
    public:
        A(int i) { }

    };

    inline void test() {
        using namespace std;

        vector<A> aa(10, 1);




    }

}


namespace c3 {

    class Sigletion final {
    /*
        饿汉式实现单例模式
        单例子模式
            1、单例类只能有一个实例。
            2、单例类必须自己创建自己的唯一实例。
            3、单例类必须给所有其他对象提供这一实例。
        懒汉式、饿汉式
        饿汉式天生线程安全

    */
    public:
        static Sigletion * getInst();
    private:
        Sigletion() = default;
        Sigletion & operator=(Sigletion &) = delete;
        Sigletion(const Sigletion &) = delete;
        ~Sigletion() {}
        static Sigletion *p;
    };


    inline void test() {
        using namespace std;
        Sigletion *b = Sigletion::getInst();

    }

}


namespace c5 {

    inline void test() {
        using namespace std;

        string s("a--a\n");
        try {
            throw runtime_error(s);
        }
        catch (const runtime_error &p){
            cout << p.what();

        }
    }
}




namespace c6 {
    class A {
    public:
        A() {
            std::cout << "A\n";
            log();
        }
        virtual void log() const { std::cout << "A-log()\n"; };
        virtual ~A() { }
    };

    class B : public A {
    public:
        B() { std::cout << "B\n"; }
        virtual void log() const  { }

    };


    void test();
}



namespace c7 {

 class Sales_item {
        friend std::istream &operator>> (std::istream &is, Sales_item &book);
        friend std::ostream &operator<< (std::ostream &os, const Sales_item &book);
        friend Sales_item operator+(const Sales_item &lhs, const Sales_item &rhs);//const左值引用可以绑定右值

    public:
        Sales_item();
        Sales_item(const std::string &s, unsigned n, double price):bookNo(s),soldNum(n), revenue(n * price) {
            // 初始化 赋值含义不同，成员的初始化发生在进入构造函数体之前
            // 使用列表初始化
        }

        const std::string &isbn() const { //只能返回常量引用
            return bookNo;
        }

        Sales_item &operator+=(const Sales_item &rhs){
            if (bookNo != rhs.isbn())
                throw std::logic_error("+ the bookNo is different!");
            soldNum += rhs.soldNum;
            revenue += rhs.revenue;

            return *this;
        }

    private:
        std::string bookNo;
        unsigned soldNum = 0; // 书的销售数量
        double revenue = 0.0; //书的总收益
    };

    std::istream &operator>> (std::istream &is, Sales_item &book);
    std::ostream &operator<< (std::ostream &os, const Sales_item &book);
    Sales_item operator+(const Sales_item &lhs, const Sales_item &rhs);



    class A {
    public:
        friend void pp();  //友元声明作用是访问权限，不是普通意义下的声明
        void cc() { // pp(); 在此处pp()是未声明的
        };
    };

    //void pp();
    class B {
    public:
        B() = default;
        bool operator > (const B &e) { return true; }
        friend bool operator <(const B& e, const B& d) { return true; }
        bool operator ==(const B& d) { return true; }
        bool operator <=(const B& d) { return true; }
        friend bool operator == (const B& lhs, const B& rhs){ return true; }
    };

    bool operator==(const B& lhs, const B& rhs);
    bool operator < (const B& e, const B& d);

    inline void test() {
        using namespace std;

        Sales_item b1("xitong", 2, 12.0);
        Sales_item b2("xitong", 3, 23.0);
        Sales_item s = b1+b2;
        cout << (b1+b2);
    



    }
}




namespace c10 {
    class A {
    public:
        A() { std::cout << "A()\n"; }
        A(const A &b) { std::cout << "&\n"; }
        A(A &&b) { std::cout << "&&\n"; }
        A operator=(const A &e) { std::cout << "=\n"; }
        void pp() { std::cout << "woen\n";}
        ~A() { std::cout << "~"; }
    private:

    };

    A foo();

    void test();

}




namespace c12 {
    
    class CC {
        public :
        virtual CC () {

        }
    };
    
    inline void test(void) {
        using namespace std;
        unique_ptr<string[]> up(new string[10]);
        up[1] = "123";


        cout << up[1].size();
    }
}

































#endif
