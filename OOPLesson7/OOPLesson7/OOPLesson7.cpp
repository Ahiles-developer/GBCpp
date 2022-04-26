#include <iostream>

class Date {
private:
    int day, month, year;
public:
    Date(int d = 1, int m = 1, int y = 1) : day(d), month(m), year(y) {}
    ~Date();
    int getDay() { return day; }
    int getMonth() { return month; }
    int getYear() { return year; }
    void setDay(int d) { day = d; }
    void setMonth(int m) { month = m; }
    void setYear(int y) { year = y; }

    friend std::ostream& operator<<(std::ostream& out, const Date& date);
};

std::ostream& operator<< (std::ostream& out, const Date& date) {
    out << "Date: " << date.day << ". " << date.month << ". " << date.year << "\n";
    return out;
}

int main()
{
    Date date(24, 04, 2022);
    std::cout << date;

    return 0;
}


