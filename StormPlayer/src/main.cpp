#include <Storm.h>


class StormPlayer : public Storm::Application
{
public:
	StormPlayer()
	{
		
	};

	~StormPlayer()
	{

	}
};

Storm::Application* Storm::CreateApplication()
{
	return new StormPlayer();
}