#include "MainMenu.cpp"
/*
Esta clase gestiona todo lo que se pinta por pantalla.
*/

class Renderer {
private:
	MainMenu M;

public:
	void Start() {
		M.Start();
	}
	void Draw() {
		M.Draw();
	}
};