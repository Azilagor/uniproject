#include "StudentWork.hpp"
#include <stack>

class WorkStack {
private:
    std::stack<StudentWork> works;

public:
    WorkStack(const std::vector<StudentWork>& initialWorks);
    WorkStack& operator+=(const StudentWork& w);
    StudentWork pop();
    bool isEmpty() const;
    void combineWorks();
    void splitAllWorks();
    StudentWork getNextWorkWithoutMark();
    size_t size() const;
};
