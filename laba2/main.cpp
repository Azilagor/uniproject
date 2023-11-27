/// g++ main.cpp StudentWork.cpp WorkStack.cpp -o output ./output
#include "StudentWork.hpp"
#include "WorkStack.hpp"
#include <iostream>
#include "cstring"

int main() {
    int n;
    std::cout << "Enter the number of student works: ";
    std::cin >> n;

    std::vector<StudentWork> initialWorks;
    for (int i = 0; i < n; ++i) {
        std::string surname;
        int mark, firstPage, lastPage;
        std::cout << "Enter surname for work #" << i+1 << ": ";
        std::cin >> surname;
        std::cout << "Enter mark for work (enter 0 if no mark): ";
        std::cin >> mark;
        std::cout << "Enter first page: ";
        std::cin >> firstPage;
        std::cout << "Enter last page: ";
        std::cin >> lastPage;
        initialWorks.push_back(StudentWork(surname, mark, firstPage, lastPage));
    }

    WorkStack stack(initialWorks);
    std::cout << "\nInitial stack size: " << stack.size() << std::endl;

    char choice;
    do {
        std::cout << "\nMenu:\n";
        std::cout << "1. Combine works\n";
        std::cout << "2. Split all works\n";
        std::cout << "3. Get next work without mark\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter choice: ";
        std::cin >> choice;

        switch (choice) {
            case '1':
                stack.combineWorks();
                std::cout << "Works combined.\n";
                break;
            case '2':
                stack.splitAllWorks();
                std::cout << "All works split.\n";
                break;
            case '3':
                {
                    auto workWithoutMark = stack.getNextWorkWithoutMark();
                    std::cout << "\nNext work without mark: " << workWithoutMark << std::endl;
                }
                break;
            case '4':
                std::cout << "Exiting...\n";
                break;
            default:
                std::cout << "Invalid choice. Try again.\n";
        }

    } while (choice != '4');

    return 0;
}
