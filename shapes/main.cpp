
#include "Source.h"



int main()
{
	Info();

	std::thread t(WaitingInput);
	t.join();

	return 0;	
}