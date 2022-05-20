#include <iostream>
#include <string>
#include <optional>
#include <tuple>

struct Person {
	std::string name, surname;;
	std::optional<std::string> patronymic;
};

std::ostream& operator<< (std::ostream& out, const Person& p) {
	out << p.surname << " " << p.name;
	if (p.patronymic.has_value()) {
		out << p.patronymic.value();
	} else {
		out << "";
	}
	return out;
}

bool operator<(const Person& p1, const Person& p2) {
	return std::tie(p1.name, p1.surname, p1.patronymic) < std::tie(p2.name, p2.surname, p2.patronymic);
}

bool operator==(const Person& p1, const Person& p2) {
	return std::tie(p1.name, p1.surname, p1.patronymic) == std::tie(p2.name, p2.surname, p2.patronymic);
}

