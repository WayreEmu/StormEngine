#include "EntryPoint.h"

int main(int argc, char** argv)
{
	auto storm = Storm::CreateApplication();
	storm->Run();
	delete storm;
}
