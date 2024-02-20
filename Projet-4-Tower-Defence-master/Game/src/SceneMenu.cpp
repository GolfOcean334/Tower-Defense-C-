﻿#include "Button.h"
#include "Scenes.h"

int SceneMenu::LoopGame(sf::RenderWindow* window, bool pause) {
	Scene scene;
	EventFunctionsMenu eventFunctionsMenu;

	if (pause && !shapeAlpha)
	{
		//window->clear(sf::Color(100, 100, 100, 100));
		scene.CreateShape(ObjectName::ShapeName, sf::Color(100, 100, 100, 3), sf::Vector2f(800, 800));
		shapeAlpha = true;
	}

	Button buttonClass;

	GameObject* buttonPlay = buttonClass.createButtonObj(&scene, "Play"); 
	GameObject* buttonOption = buttonClass.createButtonObj(&scene, "Option");
	GameObject* buttonAch = buttonClass.createButtonObj(&scene, "Ach");
	GameObject* buttonQuit = buttonClass.createButtonObj(&scene, "Quit");

	if (buttonPlay == nullptr || buttonOption == nullptr || buttonAch == nullptr || buttonQuit == nullptr) {
		return -1;
	}
	

	eventFunctionsMenu.buttonList.push_back(buttonPlay);
	eventFunctionsMenu.buttonList.push_back(buttonOption);
	eventFunctionsMenu.buttonList.push_back(buttonAch); 
	eventFunctionsMenu.buttonList.push_back(buttonQuit);

	int sceneOn = 0;
	while (sceneOn == 0)
	{
		sceneOn = eventFunctionsMenu.loopEvent(window); 																	 
							

		
		if (!pause) {
			window->clear(); 
		}
		
		scene.Render(window);
		window->display();
	}
	return sceneOn;
}