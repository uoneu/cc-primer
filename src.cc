#include <iostream>
#include <string>
#include <iostream>
#include <stdexcept>
#include <vector>
#include <cassert>
#include <string>
#include <algorithm>
#include <stack>

#include "src.h"

namespace c1 {
    std::istream& operator>> (std::istream &is, Sales_item &book) {
        is >> book.bookNo;
        return is;
    }

    std::ostream& operator<< (std::ostream &os, const Sales_item &book) {
        os << book.bookNo << " " << book.soldNum << " ";
        if (book.soldNum == 0)
           os << "0.0";
        else
            os << book.revenue / book.soldNum;

        return os;
    }

    Sales_item operator+(const Sales_item &lhs, const Sales_item &rhs) {

        Sales_item ret(lhs);

        return (ret += rhs);
    }


}


namespace c2 {
    int j = 9;
    constexpr int *p = &j;

}



namespace c3 {
    Sigletion *Sigletion::p = new Sigletion();
    Sigletion * Sigletion::getInst() {
        return p;
    }
}

namespace c6 {

    auto retList() -> std::vector<int>
    {
        return {1, 2, 3};
    }
    constexpr size_t foo(size_t x) {
        return x * 2;
    }

    int add (int a, int b) {
        return a+b;
    }
    

    void test() {
        using namespace std;

        B b;


    }

}


namespace c7 {
    Sales_item::Sales_item() = default;
    std::istream& operator>> (std::istream &is, Sales_item &book) {
        double prices = 0.0;
        is >> book.bookNo >> book.soldNum >> prices;
        book.revenue = book.soldNum * prices;
        return is;
    }

    std::ostream& operator<< (std::ostream &os, const Sales_item &book) {
        os << book.bookNo << " " << book.soldNum << " ";
        if (book.soldNum == 0)
           os << "0.0";
        else
            os << book.revenue / book.soldNum;

        return os;
    }

    Sales_item operator+(const Sales_item &lhs, const Sales_item &rhs) {

        Sales_item ret(lhs);

        return (ret += rhs);
    }

}

namespace c10 {
    A foo() {
        std::cout << "foo\n";
        return A();
    }

    void Permutation(std::string &s, int beg) {
        if (beg >= s.size()) {
            std::cout << s << "\n";
        }

        for (int i=beg; i<s.size(); ++i) {
            std::swap(s[beg], s[i]);
            Permutation(s,beg+1);
            std::swap(s[beg], s[i]);
        }

    }
    void out(std::vector<int> &v) {
        for (auto x : v)
            std::cout << x << " ";
        std::cout << "\n";
    }

    void combine(const std::vector<int> &arr, int beg, int r, std::vector<int> &v) {
        if (r == 0) {
            out(v);
            return;
        }else if (r > arr.size()-beg)
            return;

        for (int i=beg; i<arr.size(); ++i) {
            v.push_back(arr[i]);
            combine(arr, i+1, r-1, v);
            v.pop_back();
            //combine(arr,i+1, r, v);
        }


    }

    void test() {
        using namespace std;
        vector<int> arr{1, 2, 3, 4};
        vector<int> v;
        for (int i=1; i<=4; ++i) {
            combine(arr, 0, i, v);
        }


    }








}

