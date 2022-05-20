#include <iostream>
#include <optional>
#include <tuple>

struct PhoneNumber {
	int codeCountry;
	int codeCity;
	std::string number;
	std::optional<int> extensionNumber;
};

std::ostream& operator<< (std::ostream& out, const PhoneNumber& p) {
	out << "Phone number: +" << p.codeCountry << "(" << p.codeCity << ")" <<
		p.number;
	if (p.extensionNumber.has_value()) {
		out << p.extensionNumber.value();
	} else {
		out << "";
	}
	return out;
}

bool operator<(const PhoneNumber& p1, const PhoneNumber& p2) {
	return std::tie(p1.codeCountry, p1.codeCity, p1.number, p1.extensionNumber) <
		   std::tie(p2.codeCountry, p2.codeCity, p2.number, p2.extensionNumber);
}

bool operator==(const PhoneNumber& p1, const PhoneNumber& p2) {
	return std::tie(p1.codeCountry, p1.codeCity, p1.number, p1.extensionNumber) == 
		   std::tie(p2.codeCountry, p2.codeCity, p2.number, p2.extensionNumber);
}