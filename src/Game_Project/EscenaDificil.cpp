#include "ID.hh"
#include "InputManager.hh"
#include "Logger.hh"
#include "SceneManager.hh"
#include "EscenaDificil.hh"
using namespace Logger;

EscenaDificil::EscenaDificil() {
	background = { { 0,0,W.GetWidth(),W.GetHeight() },ObjectID::BG_00 };

}

EscenaDificil::~EscenaDificil() {


}

void EscenaDificil::OnEntry() {
	//Llamado cuando se llama a la escena
}

void EscenaDificil::OnExit() {
	//Cuando se sale de la escena
}

void EscenaDificil::Draw() {


}

void EscenaDificil::Update() {

}
