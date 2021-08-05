/*
Что нужно сделать

Реализуйте программу чтения информации из ведомости по учёту выплат.
 Сама ведомость представляет собой следующую таблицу:

    имя и фамилия человека;
    количество денег, которые были выплачены лицу;
    дата выплаты в формате ДД.ММ.ГГГГ.

На основе данных из ведомости следует подсчитать общее количество выплаченных средств и
 определить человека с максимальной суммой выплат.
*/
#include <iostream>
#include <string>
#include <fstream>

int main() {
    std::ifstream TextFile("../sheet.txt");
    std::string FirstName, LastName, DateOfSalary, MaxFirstName, MaxLastName;
    int Salary=0, MaxSalary=0, TotalSalary=0;
    while(!TextFile.eof()){
        TextFile >> FirstName >> LastName >> Salary >> DateOfSalary;
        if(Salary > MaxSalary) {
            MaxSalary = Salary;
            MaxFirstName = FirstName;
            MaxLastName = LastName;
        }
        TotalSalary += Salary;
    }
    TextFile.close();
    std::cout << "Total salary = " << TotalSalary << " Rub" << std::endl;
    std::cout << MaxFirstName <<  " " << MaxLastName << " received the highest salary. It is " << MaxSalary << " Rub" << std::endl;
    return 0;
}
