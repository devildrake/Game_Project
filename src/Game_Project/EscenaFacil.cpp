#include "ID.hh"
#include "InputManager.hh"
#include "Logger.hh"
#include "SceneManager.hh"
#include "EscenaFacil.hh"
using namespace Logger;

EscenaFacil::EscenaFacil() {
	background = { { 0,0,W.GetWidth(),W.GetHeight() },ObjectID::BG_00 };

}

EscenaFacil::~EscenaFacil() {


}

void EscenaFacil::OnEntry() {
	//Llamado cuando se llama a la escena
}

void EscenaFacil::OnExit() {
	//Cuando se sale de la escena
}

void EscenaFacil::Draw() {
	

}

void EscenaFacil::Update() {

}
