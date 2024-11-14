#ifndef CHOTEL_H
#define CHOTEL_H

#include <list>
#include <algorithm>
#include <fstream>
#include "CGuest.h"

class CHotel {
private:
    // ������ �볺���, ���� ������ ��� ������������� �볺��� ������
    std::list<CGuest> clients;

    // ��������� ����� ��� ��������, �� � ��� �볺��� ����������
    bool isClientEqual(const CGuest& c1, const CGuest& c2) const;

public:
    // ����������� �� �������������, ���� �������� ������� ������
    CHotel() = default;

    // �����������, ���� �������� ������ � ������ �볺���
    CHotel(CGuest& client);

    CHotel::CHotel(const std::list<CGuest>& clients);

    // ����������� ��������� ��� ��������� ��ﳿ ������
    CHotel(const CHotel& other);

    // ����� ��� ��������� �������� ������� ����� � ����� (�� �볺���)
    int getTotalRooms() const;

    // ����� ��� ��������, �� ������� ������ (���� �볺���)
    bool isEmpty() const;

    // ����� ��� ��������� �볺��� � ������
    void addClient(CGuest& client);

    // ����� ��� ���������� �볺��� �� ������� ������
    void sortByRoom(int ascending);

    // ����� ��� ���������� �볺��� �� ����� ��������
    void sortByArrivalDate(int ascending);

    // ����� ��� ���������� �볺��� �� ����� ��'����
    void sortByDepartureDate(int ascending);

    // ����� ��� ���������� �볺��� �� ����� ����������� � �����
    void sortByResidenceTime(int ascending);

    // ����� ��� ��������� ������ �볺��� �� ������� ������
    CHotel getClientsByRoomNumber(int roomNumber) const;

    // ����� ��� ��������� ������ �볺��� �� ������
    CHotel getClientsByName(const std::string& Name) const;

    // ����� ��� ��������� ������ �볺��� �� ��������
    CHotel getClientsBySurname(const std::string& Surname) const;

    // ����� ��� ��������� ������� �� ������ �볺���
    std::list<CGuest>& getClients();

    // ����� ��� ��������� ������� ������������ �볺��� (������� ������� �볺���)
    CHotel longestLiving(int GuestNumber);

    // ����� ��� ��������, �� ���� �볺�� � �����
    bool clientExists(const CGuest& client);

    // ����� ��� ��������� �볺��� �� ������� ������
    CGuest removeClient(int roomNumber);

    // ����� ��� ��������� �볺��� �� ������� ������
    CGuest removeClient(const CGuest& clientToRemove);

    // ����� ��� �������� ������ (��������� ��� �볺���)
    void clearHotel();

    // �������� ��������� ��� ������ ���������� ��� ������ � ����
    friend std::ostream& operator<<(std::ostream& os, const CHotel& hotel);

    // �������� �������� ��� ���������� ���������� ��� ������ � �����
    friend std::istream& operator>>(std::istream& is, CHotel& hotel);

    // ����� ��� ���������� ����� ��� �볺��� � ����
    void saveClientToFile(const CGuest& client);
};


#endif // !CHOTEL_H

