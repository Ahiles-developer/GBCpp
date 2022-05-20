#include <iostream>
#include <optional>

struct PhoneNumber {
	int codeCountry;
	int codeCity;
	std::string number;
	std::optional<int> extensionNumber;
};

std::ostream& operator<<(std::ostream out, const PhoneNumber& pN) {
	return out << "Phone number: +" << pN.codeCountry << "(" << pN.codeCity << ")"
		<< pN.number << " " << pN.extensionNumber << "\n";
}