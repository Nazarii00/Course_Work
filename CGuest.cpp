#include "CGuest.h"

// ����������� �� �������������
// �������� ��'��� CGuest � �������� ���������� ��� ��� ��������
CGuest::CGuest() : _roomNumber(0), _Name(""), _Surname(""), _arrivalDate(""), _departureDate("") {}

// ����������� � ����������� ��� ����������� ��'���� CGuest �� �������� ����������
CGuest::CGuest(int roomNumber, std::string Name, std::string Surname, std::string arrivalDate, std::string departureDate) :
    _roomNumber(roomNumber), _Name(Name), _Surname(Surname), _arrivalDate(arrivalDate), _departureDate(departureDate) {}

// ����� ��� ������������ ������ ������
void CGuest::setRoomNumber(int roomNumber) {
    _roomNumber = roomNumber;
}

// ����� ��� ������������ ���� �����
void CGuest::setName(std::string Name) {
    _Name = Name;
}

// ����� ��� ������������ ������� �����
void CGuest::setSurname(std::string Surname) {
    _Surname = Surname;
}

// ����� ��� ������������ ���� ��������
void CGuest::setArrivalDate(std::string arrivalDate) {
    _arrivalDate = arrivalDate;
}

// ����� ��� ������������ ���� ��'����
void CGuest::setDepartureDate(std::string departureDate) {
    _departureDate = departureDate;
}

// ����� ��� ����������� ������������ ��� ��������� ��'����
void CGuest::setFullInfo(int roomNumber, std::string Name, std::string Surname, std::string arrivalDate, std::string departureDate) {
    _roomNumber = roomNumber;
    _Name = Name;
    _Surname = Surname;
    _arrivalDate = arrivalDate;
    _departureDate = departureDate;
}

// ������ ��� ������ ������
int CGuest::getRoomNumber() const {
    return _roomNumber;
}

// ������ ��� ���� �����
std::string CGuest::getName() const {
    return _Name;
}

// ������ ��� ������� �����
std::string CGuest::getSurname() const {
    return _Surname;
}

// ������ ��� ���� ��������
std::string CGuest::getArrivalDate() const {
    return _arrivalDate;
}

// ������ ��� ���� ��'����
std::string CGuest::getDepartureDate() const {
    return _departureDate;
}

// ��������� ����� ��� �������� ���� � ����� � ��������� std::tm
std::tm CGuest::parseDate(const std::string& dateStr) {
    std::tm tm = {};
    std::istringstream ss(dateStr);
    ss >> std::get_time(&tm, "%d/%m/%Y");

    // ���� ������� �� ������, �������� �������
    if (ss.fail()) {
        throw std::runtime_error("������� ���������� ����");
    }

    return tm;
}

// ��������� ����� ��� ��������� ���� �볺��� �� ����� �������� ��� ��'����
bool CGuest::compareDates(const CGuest& left, const CGuest& right, bool useDeparture) {
    const std::string& dateLeft = useDeparture ? left.getDepartureDate() : left.getArrivalDate();
    const std::string& dateRight = useDeparture ? right.getDepartureDate() : right.getArrivalDate();

    std::tm tmLeft = parseDate(dateLeft);
    std::tm tmRight = parseDate(dateRight);

    // ����������� ���� � ������ time_t
    return std::mktime(&tmLeft) > std::mktime(&tmRight);
}

// ��������� ����� ��� ���������� ���� ����������� �볺��� � ����� (� ��������)
double CGuest::getResidenceTime(const CGuest& client) {
    std::tm arrival = parseDate(client.getArrivalDate());
    std::tm departure = parseDate(client.getDepartureDate());

    time_t timeArrival = mktime(&arrival);
    time_t timeDeparture = mktime(&departure);

    return difftime(timeDeparture, timeArrival);
}

// �������������� �������� ��������� ��� ��������, �� ����� ���� �������� ������ �볺��� �� ������
bool operator>(const CGuest& left, const CGuest& right) {
    return CGuest::compareDates(left, right, false); // false ������ ������������ ���� ��������
}

// ��������� ����� ��� ��������� �볺��� �� ����� ��'����
bool CGuest::compareByDepartureDate(const CGuest& left, const CGuest& right) {
    return CGuest::compareDates(left, right, true); // true ������ ������������ ���� ��'����
}

// ��������� ����� ��� ��������� �볺��� �� ����� �����������
bool CGuest::compareByResidenceTime(const CGuest& left, const CGuest& right) {
    return getResidenceTime(left) > getResidenceTime(right);
}

// �������� �������� ��� ���������� ���������� ��� �볺��� � �����
std::istream& operator>>(std::istream& is, CGuest& client) {
    std::string name, surname, arrivalDate, departureDate;
    int roomNumber;

    // ���� �������� �������, �� ������������ �������� ��� �볺���
    if (is >> roomNumber >> name >> surname >> arrivalDate >> departureDate) {
        client.setFullInfo(roomNumber, name, surname, arrivalDate, departureDate);
    }
    return is;
}

// �������� ��������� ��� ������ ���������� ��� �볺��� � ����
std::ostream& operator<<(std::ostream& os, const CGuest& client) {
    os << client.getRoomNumber() << " "
        << client.getName() << " "
        << client.getSurname() << " "
        << client.getArrivalDate() << " "
        << client.getDepartureDate();
    return os;
}