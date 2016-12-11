#pragma once
#include "Scene.hh"
#include "Sprite.hh"
class EscenaDificil :public Scene {
public:
	explicit EscenaDificil() {

	}
	~EscenaDificil() override;

	void OnEntry() override;

	void OnExit() override;

	void Update() override;

	void Draw() override;

private:

	//Aquí iran los sprites
	Sprite background;



};