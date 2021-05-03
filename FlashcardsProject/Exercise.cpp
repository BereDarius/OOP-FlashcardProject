#include "Exercise.h"

ostream& operator<<(ostream& os, Exercise& e)
{
	e.print(os);
	return os;
}
