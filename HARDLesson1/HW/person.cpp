#include <iostream>
#include <string>
#include <optional>
#include <tuple>

struct Person {
	std::string name, surname;;
	std::optional<std::string> patronymic;

};

std::ostream& operator<< (std::ostream& out, const Person& p) {
	return out << p.surname << " " << p.name << " " << p.patronymic << "\n";
}

std::string operator<(const Person& p1, const Person& p2) {
	return std::tie(p1.name, p1.surname) < (p2.name, p2.surname);
}

Person operator==(const Person& p) {}

