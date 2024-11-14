#ifndef CGUEST_H
#define CGUEST_H

#include <iostream>
#include <sstream>
#include <iomanip>

class CGuest {
private:
    // Номер кімнати клієнта
    int _roomNumber;

    // Ім'я клієнта
    std::string _Name;

    // Прізвище клієнта
    std::string _Surname;

    // Дата прибуття клієнта у вигляді рядка
    std::string _arrivalDate;

    // Дата від'їзду клієнта у вигляді рядка
    std::string _departureDate;

    // Приватний метод для перетворення рядка в дату (формат рядка повинен бути правильно заданий)
    static std::tm parseDate(const std::string& dateStr);

    // Приватний метод для порівняння двох клієнтів за датою прибуття або від'їзду
    static bool compareDates(const CGuest& left, const CGuest& right, bool useDeparture);

    // Приватний метод для отримання часу проживання клієнта (в днях)
    static double getResidenceTime(const CGuest& client);

public:

    // Конструктор за замовчуванням
    CGuest();

    // Конструктор з параметрами для ініціалізації клієнта
    CGuest(int roomNumber, std::string Name, std::string Surname, std::string arrivalDate, std::string departureDate);

    // Методи для встановлення значень полів класу
    void setRoomNumber(int roomNumber);
    void setName(std::string Name);
    void setSurname(std::string Surname);
    void setArrivalDate(std::string arrivalDate);
    void setDepartureDate(std::string departureDate);

    // Метод для встановлення всіх значень полів одночасно
    void setFullInfo(int roomNumber, std::string Name, std::string Surname, std::string arrivalDate, std::string departureDate);

    // Метод для отриманння номеру кімнати
    int getRoomNumber() const;
    // метод для отримання ім'я
    std::string getName() const;
    // метод для отримання прізвища
    std::string getSurname() const;
    // метод для отримання дати прибуття
    std::string getArrivalDate() const;
    //метод для отримання дати від'їзду
    std::string getDepartureDate() const;

    // Оператор порівняння для порівняння двох клієнтів (на основі будь-якого з полів)
    friend bool operator>(const CGuest& left, const CGuest& right);

    // Статичний метод для порівняння клієнтів за датою від'їзду
    static bool compareByDepartureDate(const CGuest& left, const CGuest& right);

    // Статичний метод для порівняння клієнтів за часом проживання
    static bool compareByResidenceTime(const CGuest& left, const CGuest& right);

    // Оператор введення для зчитування даних клієнта з файлу
    friend std::istream& operator>>(std::istream& is, CGuest& client);

    // Оператор виведення для запису даних клієнта у файл
    friend std::ostream& operator<<(std::ostream& os, const CGuest& client);
};






















#endif // !CGUEST_H

