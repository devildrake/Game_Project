#include "mainMenu.hh"
#include "ID.hh"
#include "InputManager.hh"
#include "Logger.hh"
#include "SceneManager.hh"
#include "EscenaFacil.hh"
#include "EscenaMedio.hh"
#include "EscenaDificil.hh"

using namespace Logger;

mainMenu::mainMenu(){
	background = { {0,0,W.GetWidth(),W.GetHeight()},ObjectID::BG_00 };

}

mainMenu::~mainMenu() {


}

void mainMenu::OnEntry() {
	//Llamado cuando se llama a la escena
}

void mainMenu::OnExit() {
	//Cuando se sale de la escena
}

void mainMenu::Draw() {
	background.Draw();

}

void mainMenu::Update() {
	static MouseCoords coordenadasMouse(0, 0);

	if (IM.IsMouseDown<MOUSE_BUTTON_LEFT>()) {
		coordenadasMouse = IM.GetMouseCoords();
		if ((coordenadasMouse.x >= 425 && coordenadasMouse.x <= 615) && (coordenadasMouse.y >= 430 && coordenadasMouse.y <= 490)) {
			SM.SetCurScene<EscenaFacil>();

		}
		//Para el exit 
		//SetState<SceneState::EXIT>();
	}
}