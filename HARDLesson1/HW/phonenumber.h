#pragma once

struct PhoneNumber;

std::ostream& operator<< (std::ostream& out, const PhoneNumber& p) {}

bool operator<(const PhoneNumber& p1, const PhoneNumber& p2) {}

bool operator==(const PhoneNumber& p1, const PhoneNumber& p2) {}