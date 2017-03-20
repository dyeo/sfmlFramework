#include "Application.hpp"

#include "Transform.hpp"

int main()
{
	/*Application app;
	app.run();*/

	Transform *t1 = new Transform;
	Transform *t2 = new Transform;
	Transform *t3 = new Transform;
	Transform *t4 = new Transform;
	Transform *t5 = new Transform;

	t1->addChild(t2);
	t2->addChild(t3);
	t3->addChild(t4);
	t4->addChild(t5);

	return 0;
}