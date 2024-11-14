#include "CHotel.h"

// ����������� ����� CHotel, �� ���� �볺��� �� ������
CHotel::CHotel(CGuest& client) {
    addClient(client);
}

CHotel::CHotel(const std::list<CGuest>& clients) : clients(clients) {}

// ����������� ��������� ��� CHotel, ����� ������ �볺��� � ������ ��'����
CHotel::CHotel(const CHotel& other) : clients(other.clients) {}

// ���� �볺��� �� ������
void CHotel::addClient(CGuest& client) {
    clients.push_back(client);
}

// ����� �볺��� �� ������� ������
void CHotel::sortByRoom(int ascending) {
    clients.sort([ascending](const CGuest& a, const CGuest& b) {
        return ascending ? (a.getRoomNumber() > b.getRoomNumber()) : (a.getRoomNumber() < b.getRoomNumber());
    });
}

// ���������� �� ����� ��������
void CHotel::sortByArrivalDate(int ascending) {
    clients.sort([ascending](const CGuest& a, const CGuest& b) {
        return ascending ? a > b : b > a;
    });
}

// ���������� �� ����� �䒿���
void CHotel::sortByDepartureDate(int ascending) {
    clients.sort([ascending](const CGuest& a, const CGuest& b) {
        return ascending ? CGuest::compareByDepartureDate(a, b) : CGuest::compareByDepartureDate(b, a);
    });
}

// ���������� �� ����� ����������
void CHotel::sortByResidenceTime(int ascending) {
    clients.sort([ascending](const CGuest& a, const CGuest& b) {
        return ascending ? CGuest::compareByResidenceTime(a, b) : CGuest::compareByResidenceTime(b, a);
    });
}

// ������� ������ �볺��� � ���������� ������� ������
CHotel CHotel::getClientsByRoomNumber(int roomNumber) const {
    std::list<CGuest> matchedClients;
    for (const auto& client : clients) {
        if (client.getRoomNumber() == roomNumber) {
            matchedClients.push_back(client);
        }
    }
    return CHotel(matchedClients);
}

// ������� ������ �볺��� � ���������� ������
CHotel CHotel::getClientsByName(const std::string& Name) const {
    std::list<CGuest> matchedClients;
    for (const auto& client : clients) {
        if (client.getName() == Name) {
            matchedClients.push_back(client);
        }
    }
    return CHotel(matchedClients);
}

// ������� ������ �볺��� � ���������� ��������
CHotel CHotel::getClientsBySurname(const std::string& Surname) const {
    std::list<CGuest> matchedClients;
    for (const auto& client : clients) {
        if (client.getSurname() == Surname) {
            matchedClients.push_back(client);
        }
    }
    return CHotel(matchedClients);
}

// ������� ������ ��� �볺���
std::list<CGuest>& CHotel::getClients() {
    return clients;
}

// ������� ������ �������� ����������� �볺���, � ������� GuestNumber
CHotel CHotel::longestLiving(int GuestNumber) {
    std::list<CGuest> guests = clients;
    // ������� �� ����� ����������
    guests.sort(CGuest::compareByResidenceTime);

    // ���� �������� ����� ������ �����, �� � � ������, �������� ����
    if (GuestNumber > guests.size()) {
        GuestNumber = guests.size();
    }

    // ��������� ����� ������ �� ������ GuestNumber ��������
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

// ��������, �� ��� �볺��� ������� (������� ������ ����)
bool CHotel::clientExists(const CGuest& client) {
    for (const auto& existingClient : clients) {
        if (isClientEqual(existingClient, client)) {
            return true;
        }
    }
    // �������� �������� �볺��� � ���� logs.txt
    std::ifstream logs("logs.txt");
    CGuest fileClient;

    while (logs >> fileClient) {
        if (isClientEqual(fileClient, client)) {
            return true;
        }
    }

    return false;
}

// ������� �������� ������� �����, �������� �볺�����
int CHotel::getTotalRooms() const {
    return clients.size();
}

// ������� �볺��� �� ������� ������ �� ������� ���� ��'���
CGuest CHotel::removeClient(int roomNumber) {
    auto it = std::find_if(clients.begin(), clients.end(), [&](const CGuest& client) {
        return client.getRoomNumber() == roomNumber;
        });

    if (it != clients.end()) {
        CGuest removedClient = *it;
        clients.erase(it);
        return removedClient;
    }
    return CGuest(); // ������� �볺��, ���� �� ��������
}

// ������� ����������� �볺��� � ������
CGuest CHotel::removeClient(const CGuest& clientToRemove) {
    auto it = std::find_if(clients.begin(), clients.end(), [&](const CGuest& client) {
        return isClientEqual(client, clientToRemove);
        });

    if (it != clients.end()) {
        CGuest removedClient = *it;
        clients.erase(it);
        return removedClient;
    }
    return CGuest(); // ������� ��'���, ���� �볺��� �� ��������
}

// ����� ���� ������ �볺��� ������
void CHotel::clearHotel() {
    clients.clear();
}

// ��������, �� ������ ������� (���� �볺���)
bool CHotel::isEmpty() const{
    return clients.empty();
}

// �������������� ��������� ��������� ��� CHotel
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

// �������������� ��������� �������� ��� CHotel
std::istream& operator>>(std::istream& is, CHotel& hotel) {
    CGuest client;
    while (is >> client) {
        // ��������, �� �볺�� �� ����, ���� �� �������� ����
        if (!hotel.clientExists(client)) {
            hotel.saveClientToFile(client);
        }
        hotel.addClient(client);
    }
    return is;
}

// ������ �볺��� � ���� logs.txt
void CHotel::saveClientToFile(const CGuest& client) {
    std::ofstream outFile("logs.txt", std::ios::app);
    if (!outFile.is_open()) {
        throw std::runtime_error("��������� ������� ���� ��� ������.");
    }
    outFile << client << std::endl;
    outFile.close();
}