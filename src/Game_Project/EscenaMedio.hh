#pragma once
#include "Scene.hh"
#include "Sprite.hh"
class EscenaMedio :public Scene {
public:
	explicit EscenaMedio() {

	}
	~EscenaMedio() override;

	void OnEntry() override;

	void OnExit() override;

	void Update() override;

	void Draw() override;

private:

	//Aquí iran los sprites
	Sprite background;



};