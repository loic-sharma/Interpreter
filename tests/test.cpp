#include "vm/Interpreter.h"

int main()
{
	Interpreter i;

	return i.return2() == 2 ? 0 : 1;
}
