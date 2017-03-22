#pragma once

#include "ISystem.hpp"

class ResourceManager : public ISystem
{
	CLASS_INTROSPECTION(ResourceManager)

public:

	ResourceManager(Application &app);

	~ResourceManager();

	virtual void onStart() override;

	virtual void onUpdate(sf::Time) override;

	virtual void onQuit() override;

	virtual void onRender() override;

	virtual void onPause() override;

	virtual void onResume() override;

	virtual void onProcessEvents(sf::Event) override;

};