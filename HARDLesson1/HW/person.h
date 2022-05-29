#pragma once

struct Person;

std::ostream& operator<< (std::ostream& out, const Person& p) {}

bool operator<(const Person& p1, const Person& p2) {}

bool operator==(const Person& p1, const Person& p2) {}