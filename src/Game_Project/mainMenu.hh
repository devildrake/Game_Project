#pragma once
#include "Scene.hh"
#include "Sprite.hh"
class mainMenu :public Scene {
public:
	explicit mainMenu() {

	}
	~mainMenu() override;

	void OnEntry() override;

	void OnExit() override;

	void Update() override;

	void Draw() override;

private:

	//Aquí iran los sprites
	Sprite background;



};