#include "StudentWork.hpp"
#include <iostream>
#include<cstring>
    StudentWork(std::string s, int m, int f, int l) : surname(s), mark(m), firstPage(f), lastPage(l) {}

    StudentWork(std::string s) : surname(s), firstPage(1), lastPage(1) {}

    StudentWork& operator+(const StudentWork& other) {
        if(this->surname == other.surname && this->lastPage + 1 == other.firstPage) {
            this->lastPage = other.lastPage;
        }
        return *this;
    }

    std::vector<StudentWork> splitIntoPages() const {
        std::vector<StudentWork> result;
        for(int i = firstPage; i <= lastPage; ++i) {
            result.push_back(StudentWork(surname, 0, i, i));
        }
        return result;
    }

    bool operator<=>(const StudentWork& other) const {
        if(this->surname == other.surname) {
            return this->firstPage <=> other.firstPage;
        }
        return this->surname <=> other.surname;
    }

    void setMark(int m) {
        if(firstPage == 1 && m >= 2 && m <= 5) {
            mark = m;
        } else {
            std::cout << "Cannot set mark for this work!" << std::endl;
        }
    }

    bool hasMark() const {
        return mark != 0;
    }

std::ostream& operator<<(std::ostream& os, const StudentWork& w) {
    os << "Student: " << w.surname << ", Pages: " << w.firstPage << "-" << w.lastPage;
    if(w.mark != 0) {
        os << ", Mark: " << w.mark;
    }
    return os;
}
