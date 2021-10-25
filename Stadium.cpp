#include "Stadium.h"

Stadium::Stadium()
{
    
}

Stadium::Stadium(const std::string& adress, const std::string& club, const int& capacity, const int& sectorsAmount, const int& visitors)
{
    adress_ = adress;
    club_ = club;
    capacity_ = capacity;
    sectrorsAmount_ = sectorsAmount;
    visitors_ = visitors;
}

//Stadium::~Stadium()
//{
//    delete 
//}

std::string Stadium::getAdress()
{
    std::string adress = adress_;
    return adress;
}

void Stadium::setAdress(const std::string& adress)
{
    adress_ = adress;
}

std::string Stadium::getClub()
{
    std::string club = club_;
    return club;
}

void Stadium::setClub(const std::string& club)
{
    club_ = club;
}

int Stadium::getCapacity()
{
    int capacity = capacity_;
    return capacity;
}

void Stadium::setCapacity(const int& capacity)
{
    capacity_ = capacity;
}

int Stadium::getSectorsAmount()
{
    int sa = sectrorsAmount_;
    return sa;
}

void Stadium::setSectorsAmount(const int& sa)
{
    sectrorsAmount_ = sa;
}

int Stadium::getAttendance()
{
    int attendance = attendance_;
    return attendance;
}

void Stadium::setAttendance(int attend)
{
    attendance_ = attend;
}

void Stadium::serialize()
{
    std::cout << "Writing file..." << std::endl;
    std::ofstream writeStream;
    writeStream.open("stadiums.txt", std::ios::app);
    if (writeStream.is_open() == false) {
        std::cout << "Ошибка открытия файла!";
    }
    else {
        writeStream << getAdress() << "\n" << getClub() << "\n" << getCapacity() << "\n" << getAttendance() << "\n" 
            << getSectorsAmount() << "\n";
    }
    writeStream.close();
}

void Stadium::serialize(const std::string& filename)
{
    std::cout << "Writing file..." << std::endl;
    std::ofstream writeStream;
    writeStream.open(filename, std::ios::app);
    if (writeStream.is_open() == false) {
        std::cout << "Ошибка открытия файла!";
    }
    else {
        writeStream << getAdress() << "\n" << getClub() << "\n" << getCapacity() << "\n" << getAttendance() << "\n"
            << getSectorsAmount() << "\n";
    }
    writeStream.close();
}

void Stadium::deserialize()
{
    std::cout << "Reading file..." << std::endl;
    std::string line;
    std::ifstream readStream("stadiums.txt");
    if (!readStream.is_open()) {
        std::cout << "Ошибка чтения файла!" << std::endl;
    }
    else {
        while (getline(readStream, line)) {
            std::cout << line << std::endl;
        }
    }
    readStream.close();

}
void Stadium::deserialize(const std::string& filename)
{
    std::cout << "Reading file..." << std::endl;
    std::string line;
    std::ifstream readStream(filename);
    if (!readStream.is_open()) {
        std::cout << "Ошибка чтения файла!" << std::endl;
    }
    else {
        while (getline(readStream, line)) {
            std::cout << line << std::endl;
        }
    }
    readStream.close();

}

void Stadium::GenVisitors()
{
        srand(1337);
        visitors_ = 0 + rand() % capacity_;
        attendCalculate();
        
}

void Stadium::attendCalculate()
{
    attendance_ = (100 * visitors_) / (float)capacity_;
}
 
std::ostream& operator<<(std::ostream& out, const Stadium& point)
{
    out << "Adress: " << point.adress_ << "\n" << "Club: " << point.club_ << "\n" << "Capacity: " << point.capacity_ << "\n" << "Visitors: " << point.visitors_ << "\n"
        << "Attendance: " << point.attendance_ << "%\n" << "Sectors amount: " << point.sectrorsAmount_ << "\n";
    return out;
}
