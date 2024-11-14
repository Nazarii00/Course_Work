#ifndef CHOTEL_H
#define CHOTEL_H

#include <list>
#include <algorithm>
#include <fstream>
#include "CGuest.h"

class CHotel {
private:
    // Список клієнтів, який містить усіх зареєстрованих клієнтів готелю
    std::list<CGuest> clients;

    // Приватний метод для перевірки, чи є два клієнти однаковими
    bool isClientEqual(const CGuest& c1, const CGuest& c2) const;

public:
    // Конструктор за замовчуванням, який ініціалізує порожній готель
    CHotel() = default;

    // Конструктор, який ініціалізує готель з одного клієнта
    CHotel(CGuest& client);

    CHotel::CHotel(const std::list<CGuest>& clients);

    // Конструктор копіювання для створення копії готелю
    CHotel(const CHotel& other);

    // Метод для отримання загальної кількості кімнат у готелі (не клієнтів)
    int getTotalRooms() const;

    // Метод для перевірки, чи порожній готель (немає клієнтів)
    bool isEmpty() const;

    // Метод для додавання клієнта в готель
    void addClient(CGuest& client);

    // Метод для сортування клієнтів за номером кімнати
    void sortByRoom(int ascending);

    // Метод для сортування клієнтів за датою прибуття
    void sortByArrivalDate(int ascending);

    // Метод для сортування клієнтів за датою від'їзду
    void sortByDepartureDate(int ascending);

    // Метод для сортування клієнтів за часом перебування в готелі
    void sortByResidenceTime(int ascending);

    // Метод для отримання списку клієнтів за номером кімнати
    CHotel getClientsByRoomNumber(int roomNumber) const;

    // Метод для отримання списку клієнтів за іменем
    CHotel getClientsByName(const std::string& Name) const;

    // Метод для отримання списку клієнтів за прізвищем
    CHotel getClientsBySurname(const std::string& Surname) const;

    // Метод для отримання доступу до списку клієнтів
    std::list<CGuest>& getClients();

    // Метод для отримання найбільш довгоживучих клієнтів (потрібна кількість клієнтів)
    CHotel longestLiving(int GuestNumber);

    // Метод для перевірки, чи існує клієнт у готелі
    bool clientExists(const CGuest& client);

    // Метод для видалення клієнта за номером кімнати
    CGuest removeClient(int roomNumber);

    // Метод для видалення клієнта за повними даними
    CGuest removeClient(const CGuest& clientToRemove);

    // Метод для очищення готелю (видалення всіх клієнтів)
    void clearHotel();

    // Оператор виведення для запису інформації про готель у файл
    friend std::ostream& operator<<(std::ostream& os, const CHotel& hotel);

    // Оператор введення для зчитування інформації про готель з файлу
    friend std::istream& operator>>(std::istream& is, CHotel& hotel);

    // Метод для збереження даних про клієнта в файл
    void saveClientToFile(const CGuest& client);
};


#endif // !CHOTEL_H

