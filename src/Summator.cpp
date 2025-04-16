#include "Summator.h"

#include <godot_cpp\core\class_db.hpp>

Summator::Summator() {
	count = 0;
}

void Summator::Add(int Val) {
	count += Val;
}

void Summator::Reset() {
	count = 0;
}

int Summator::GetTotal() const {
	return count;
}

void Summator::_bind_methods() {
	ClassDB::bind_method(D_METHOD("add", "Value"), &Summator::Add);
	ClassDB::bind_method(D_METHOD("reset"), &Summator::Reset);
	ClassDB::bind_method(D_METHOD("get_total"), &Summator::GetTotal);

}
