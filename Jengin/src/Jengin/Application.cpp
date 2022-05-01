#include "jnpch.h"

#include "Application.h"
#include "Jengin/Log.h"
#include "Jengin/Events/ApplicationEvent.h"

namespace Jengin {
	Application::Application() {
		
	}
	Application::~Application() {
		
	}
	void Application::Run() {

		WindowResizeEvent e(1280, 720);
		JN_CORE_INFO(e);
		if (e.IsInCategory(EventCategoryApplication)) {
			JN_TRACE(e);
		}
		if (e.IsInCategory(EventCategoryInput)) {
			JN_WARN(e);
		}
		while (true) {
		}
	}
}