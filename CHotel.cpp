#include "CHotel.h"

// Конструктор класу CHotel, що додає клієнта до списку
CHotel::CHotel(CGuest& client) {
    addClient(client);
}

CHotel::CHotel(const std::list<CGuest>& clients) : clients(clients) {}

// Конструктор копіювання для CHotel, копіює список клієнтів з іншого об'єкта
CHotel::CHotel(const CHotel& other) : clients(other.clients) {}

// Додає клієнта до списку
void CHotel::addClient(CGuest& client) {
    clients.push_back(client);
}

// Сортує клієнтів за номером кімнати
void CHotel::sortByRoom(int ascending) {
    clients.sort([ascending](const CGuest& a, const CGuest& b) {
        return ascending ? (a.getRoomNumber() > b.getRoomNumber()) : (a.getRoomNumber() < b.getRoomNumber());
    });
}

// Сортування за датою прибуття
void CHotel::sortByArrivalDate(int ascending) {
    clients.sort([ascending](const CGuest& a, const CGuest& b) {
        return ascending ? a > b : b > a;
    });
}

// Сортування за датою від’їзду
void CHotel::sortByDepartureDate(int ascending) {
    clients.sort([ascending](const CGuest& a, const CGuest& b) {
        return ascending ? CGuest::compareByDepartureDate(a, b) : CGuest::compareByDepartureDate(b, a);
    });
}

// Сортування за часом проживання
void CHotel::sortByResidenceTime(int ascending) {
    clients.sort([ascending](const CGuest& a, const CGuest& b) {
        return ascending ? CGuest::compareByResidenceTime(a, b) : CGuest::compareByResidenceTime(b, a);
    });
}

// Повертає список клієнтів з конкретним номером кімнати
CHotel CHotel::getClientsByRoomNumber(int roomNumber) const {
    std::list<CGuest> matchedClients;
    for (const auto& client : clients) {
        if (client.getRoomNumber() == roomNumber) {
            matchedClients.push_back(client);
        }
    }
    return CHotel(matchedClients);
}

// Повертає список клієнтів з конкретним іменем
CHotel CHotel::getClientsByName(const std::string& Name) const {
    std::list<CGuest> matchedClients;
    for (const auto& client : clients) {
        if (client.getName() == Name) {
            matchedClients.push_back(client);
        }
    }
    return CHotel(matchedClients);
}

// Повертає список клієнтів з конкретним прізвищем
CHotel CHotel::getClientsBySurname(const std::string& Surname) const {
    std::list<CGuest> matchedClients;
    for (const auto& client : clients) {
        if (client.getSurname() == Surname) {
            matchedClients.push_back(client);
        }
    }
    return CHotel(matchedClients);
}

// Повертає список всіх клієнтів
std::list<CGuest>& CHotel::getClients() {
    return clients;
}

// Повертає список найдовше проживаючих клієнтів, в кількості GuestNumber
CHotel CHotel::longestLiving(int GuestNumber) {
    std::list<CGuest> guests = clients;
    // Сортуємо за часом проживання
    guests.sort(CGuest::compareByResidenceTime);

    // Якщо запитане число гостей більше, ніж є в списку, обмежуємо його
    if (GuestNumber > guests.size()) {
        GuestNumber = guests.size();
    }

    // Створюємо новий список із перших GuestNumber елементів
    std::list<CGuest> result;
    auto it = guests.begin();
    for (int i = 0; i < GuestNumber; ++i, ++it) {
        result.push_back(*it);
    }

    return CHotel(result);
}

bool CHotel::isClientEqual(const CGuest& c1, const CGuest& c2) const {
    return c1.getRoomNumber() == c2.getRoomNumber() &&
        c1.getName() == c2.getName() &&
        c1.getSurname() == c2.getSurname() &&
        c1.getArrivalDate() == c2.getArrivalDate() &&
        c1.getDepartureDate() == c2.getDepartureDate();
}

// Перевіряє, чи два клієнти однакові (порівнює основні поля)
bool CHotel::clientExists(const CGuest& client) {
    for (const auto& existingClient : clients) {
        if (isClientEqual(existingClient, client)) {
            return true;
        }
    }
    // Перевіряє наявність клієнта у файлі logs.txt
    std::ifstream logs("logs.txt");
    CGuest fileClient;

    while (logs >> fileClient) {
        if (isClientEqual(fileClient, client)) {
            return true;
        }
    }

    return false;
}

// Повертає загальну кількість кімнат, зайнятих клієнтами
int CHotel::getTotalRooms() const {
    return clients.size();
}

// Видаляє клієнта за номером кімнати та повертає його об'єкт
CGuest CHotel::removeClient(int roomNumber) {
    auto it = std::find_if(clients.begin(), clients.end(), [&](const CGuest& client) {
        return client.getRoomNumber() == roomNumber;
        });

    if (it != clients.end()) {
        CGuest removedClient = *it;
        clients.erase(it);
        return removedClient;
    }
    return CGuest(); // Порожній клієнт, якщо не знайдено
}

// Видаляє конкретного клієнта з готелю
CGuest CHotel::removeClient(const CGuest& clientToRemove) {
    auto it = std::find_if(clients.begin(), clients.end(), [&](const CGuest& client) {
        return isClientEqual(client, clientToRemove);
        });

    if (it != clients.end()) {
        CGuest removedClient = *it;
        clients.erase(it);
        return removedClient;
    }
    return CGuest(); // Порожній об'єкт, якщо клієнта не знайдено
}

// Очищає весь список клієнтів готелю
void CHotel::clearHotel() {
    clients.clear();
}

// Перевіряє, чи готель порожній (немає клієнтів)
bool CHotel::isEmpty() const{
    return clients.empty();
}

// Перевантаження оператора виведення для CHotel
std::ostream& operator<<(std::ostream& os, const CHotel& hotel) {
    for (const auto& client : hotel.clients) {
        os << client.getRoomNumber() << " "
            << client.getName() << " "
            << client.getSurname() << " "
            << client.getArrivalDate() << " "
            << client.getDepartureDate() << " " << "\n";
    }
    return os;
}

// Перевантаження оператора введення для CHotel
std::istream& operator>>(std::istream& is, CHotel& hotel) {
    CGuest client;
    while (is >> client) {
        // Перевіряє, чи клієнт не існує, перш ніж додавати його
        if (!hotel.clientExists(client)) {
            hotel.saveClientToFile(client);
        }
        hotel.addClient(client);
    }
    return is;
}

// Зберігає клієнта у файл logs.txt
void CHotel::saveClientToFile(const CGuest& client) {
    std::ofstream outFile("logs.txt", std::ios::app);
    if (!outFile.is_open()) {
        throw std::runtime_error("Неможливо відкрити файл для запису.");
    }
    outFile << client << std::endl;
    outFile.close();
}