#ifndef CGUEST_H
#define CGUEST_H

#include <iostream>
#include <sstream>
#include <iomanip>

class CGuest {
private:
    // ����� ������ �볺���
    int _roomNumber;

    // ��'� �볺���
    std::string _Name;

    // ������� �볺���
    std::string _Surname;

    // ���� �������� �볺��� � ������ �����
    std::string _arrivalDate;

    // ���� ��'���� �볺��� � ������ �����
    std::string _departureDate;

    // ��������� ����� ��� ������������ ����� � ���� (������ ����� ������� ���� ��������� �������)
    static std::tm parseDate(const std::string& dateStr);

    // ��������� ����� ��� ��������� ���� �볺��� �� ����� �������� ��� ��'����
    static bool compareDates(const CGuest& left, const CGuest& right, bool useDeparture);

    // ��������� ����� ��� ��������� ���� ���������� �볺��� (� ����)
    static double getResidenceTime(const CGuest& client);

public:

    // ����������� �� �������������
    CGuest();

    // ����������� � ����������� ��� ����������� �볺���
    CGuest(int roomNumber, std::string Name, std::string Surname, std::string arrivalDate, std::string departureDate);

    // ������ ��� ������������ ������� ���� �����
    void setRoomNumber(int roomNumber);
    void setName(std::string Name);
    void setSurname(std::string Surname);
    void setArrivalDate(std::string arrivalDate);
    void setDepartureDate(std::string departureDate);

    // ����� ��� ������������ ��� ������� ���� ���������
    void setFullInfo(int roomNumber, std::string Name, std::string Surname, std::string arrivalDate, std::string departureDate);

    // ����� ��� ���������� ������ ������
    int getRoomNumber() const;
    // ����� ��� ��������� ��'�
    std::string getName() const;
    // ����� ��� ��������� �������
    std::string getSurname() const;
    // ����� ��� ��������� ���� ��������
    std::string getArrivalDate() const;
    //����� ��� ��������� ���� ��'����
    std::string getDepartureDate() const;

    // �������� ��������� ��� ��������� ���� �볺��� (�� ����� ����-����� � ����)
    friend bool operator>(const CGuest& left, const CGuest& right);

    // ��������� ����� ��� ��������� �볺��� �� ����� ��'����
    static bool compareByDepartureDate(const CGuest& left, const CGuest& right);

    // ��������� ����� ��� ��������� �볺��� �� ����� ����������
    static bool compareByResidenceTime(const CGuest& left, const CGuest& right);

    // �������� �������� ��� ���������� ����� �볺��� � �����
    friend std::istream& operator>>(std::istream& is, CGuest& client);

    // �������� ��������� ��� ������ ����� �볺��� � ����
    friend std::ostream& operator<<(std::ostream& os, const CGuest& client);
};






















#endif // !CGUEST_H

