#include "CGuest.h"

// Конструктор за замовчуванням
// Ініціалізує об'єкт CGuest з порожніми значеннями для всіх атрибутів
CGuest::CGuest() : _roomNumber(0), _Name(""), _Surname(""), _arrivalDate(""), _departureDate("") {}

// Конструктор з параметрами для ініціалізації об'єкта CGuest із заданими значеннями
CGuest::CGuest(int roomNumber, std::string Name, std::string Surname, std::string arrivalDate, std::string departureDate) :
    _roomNumber(roomNumber), _Name(Name), _Surname(Surname), _arrivalDate(arrivalDate), _departureDate(departureDate) {}

// Метод для встановлення номера кімнати
void CGuest::setRoomNumber(int roomNumber) {
    _roomNumber = roomNumber;
}

// Метод для встановлення імені гостя
void CGuest::setName(std::string Name) {
    _Name = Name;
}

// Метод для встановлення прізвища гостя
void CGuest::setSurname(std::string Surname) {
    _Surname = Surname;
}

// Метод для встановлення дати прибуття
void CGuest::setArrivalDate(std::string arrivalDate) {
    _arrivalDate = arrivalDate;
}

// Метод для встановлення дати від'їзду
void CGuest::setDepartureDate(std::string departureDate) {
    _departureDate = departureDate;
}

// Метод для одночасного встановлення всіх параметрів об'єкта
void CGuest::setFullInfo(int roomNumber, std::string Name, std::string Surname, std::string arrivalDate, std::string departureDate) {
    _roomNumber = roomNumber;
    _Name = Name;
    _Surname = Surname;
    _arrivalDate = arrivalDate;
    _departureDate = departureDate;
}

// Геттер для номера кімнати
int CGuest::getRoomNumber() const {
    return _roomNumber;
}

// Геттер для імені гостя
std::string CGuest::getName() const {
    return _Name;
}

// Геттер для прізвища гостя
std::string CGuest::getSurname() const {
    return _Surname;
}

// Геттер для дати прибуття
std::string CGuest::getArrivalDate() const {
    return _arrivalDate;
}

// Геттер для дати від'їзду
std::string CGuest::getDepartureDate() const {
    return _departureDate;
}

// Статичний метод для парсингу дати з рядка в структуру std::tm
std::tm CGuest::parseDate(const std::string& dateStr) {
    std::tm tm = {};
    std::istringstream ss(dateStr);
    ss >> std::get_time(&tm, "%d/%m/%Y");

    // Якщо парсинг не вдався, кидається виняток
    if (ss.fail()) {
        throw std::runtime_error("Помилка приведення дати");
    }

    return tm;
}

// Статичний метод для порівняння двох клієнтів за датою прибуття або від'їзду
bool CGuest::compareDates(const CGuest& left, const CGuest& right, bool useDeparture) {
    const std::string& dateLeft = useDeparture ? left.getDepartureDate() : left.getArrivalDate();
    const std::string& dateRight = useDeparture ? right.getDepartureDate() : right.getArrivalDate();

    std::tm tmLeft = parseDate(dateLeft);
    std::tm tmRight = parseDate(dateRight);

    // Порівнюються дати у форматі time_t
    return std::mktime(&tmLeft) > std::mktime(&tmRight);
}

// Статичний метод для розрахунку часу перебування клієнта в готелі (в секундах)
double CGuest::getResidenceTime(const CGuest& client) {
    std::tm arrival = parseDate(client.getArrivalDate());
    std::tm departure = parseDate(client.getDepartureDate());

    time_t timeArrival = mktime(&arrival);
    time_t timeDeparture = mktime(&departure);

    return difftime(timeDeparture, timeArrival);
}

// Перевантажений оператор порівняння для перевірки, чи більша дата прибуття одного клієнта за іншого
bool operator>(const CGuest& left, const CGuest& right) {
    return CGuest::compareDates(left, right, false); // false означає використання дати прибуття
}

// Статичний метод для порівняння клієнтів за датою від'їзду
bool CGuest::compareByDepartureDate(const CGuest& left, const CGuest& right) {
    return CGuest::compareDates(left, right, true); // true означає використання дати від'їзду
}

// Статичний метод для порівняння клієнтів за часом перебування
bool CGuest::compareByResidenceTime(const CGuest& left, const CGuest& right) {
    return getResidenceTime(left) > getResidenceTime(right);
}

// Оператор введення для зчитування інформації про клієнта з файлу
std::istream& operator>>(std::istream& is, CGuest& client) {
    std::string name, surname, arrivalDate, departureDate;
    int roomNumber;

    // Якщо введення вдалося, то встановлюємо значення для клієнта
    if (is >> roomNumber >> name >> surname >> arrivalDate >> departureDate) {
        client.setFullInfo(roomNumber, name, surname, arrivalDate, departureDate);
    }
    return is;
}

// Оператор виведення для запису інформації про клієнта в файл
std::ostream& operator<<(std::ostream& os, const CGuest& client) {
    os << client.getRoomNumber() << " "
        << client.getName() << " "
        << client.getSurname() << " "
        << client.getArrivalDate() << " "
        << client.getDepartureDate();
    return os;
}