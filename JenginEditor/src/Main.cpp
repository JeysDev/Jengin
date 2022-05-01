//simple hello world
#include "Jengin.h"
namespace JN = Jengin;

class Sandbox : public JN::Application
{
public:
	Sandbox()
	{
		JN_TRACE("HIa");
	}

	~Sandbox()
	{

	}
};

JN::Application* JN::CreateApplication() {
	return new Sandbox();
}