#pragma once
#include "Scene.hh"
#include "Sprite.hh"
class EscenaFacil :public Scene {
public:
	explicit EscenaFacil() {

	}
	~EscenaFacil() override;

	void OnEntry() override;

	void OnExit() override;

	void Update() override;

	void Draw() override;

private:

	//Aquí iran los sprites
	Sprite background;



};