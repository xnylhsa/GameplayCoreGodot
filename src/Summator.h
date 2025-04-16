#pragma once
#include <godot_cpp\classes\object.hpp>
using namespace godot;

class Summator : public Object {
	GDCLASS(Summator, Object)
public:
	Summator();
	void Add(int Val);
	void Reset();
	int GetTotal() const;
protected:
	static void _bind_methods();

private:
	int count;
};
