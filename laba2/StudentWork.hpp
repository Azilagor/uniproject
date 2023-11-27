#include <string>
#include <vector>

class StudentWork {
private:
    std::string surname;
    int mark;
    int firstPage, lastPage;

public:
    StudentWork(std::string s, int m, int f, int l);
    StudentWork(std::string s);
    StudentWork& operator+(const StudentWork& other);
    std::vector<StudentWork> splitIntoPages() const;
    bool operator<=>(const StudentWork& other) const;
    void setMark(int m);
    bool hasMark() const;

    friend std::ostream& operator<<(std::ostream& os, const StudentWork& w);
};
