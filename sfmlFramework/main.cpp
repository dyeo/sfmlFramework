#include "Application.hpp"

int main()
{
	Application app;
	
	EventManager *em = new EventManager(&app);
	ResourceManager *rm = new ResourceManager(&app);
	StateManager *sm = new StateManager(&app);

	app.addSystem(em);
	app.addSystem(rm);
	app.addSystem(sm);

	app.run();

	return 0;
}