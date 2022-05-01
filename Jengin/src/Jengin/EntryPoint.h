#pragma once

extern Jengin::Application* Jengin::CreateApplication();

int main(int argc, char* argv[])
{	
	Jengin::Log::Init();

	JN_INFO("var {}", 6);
	
	auto app = Jengin::CreateApplication();
	app->Run();
	delete app;
}