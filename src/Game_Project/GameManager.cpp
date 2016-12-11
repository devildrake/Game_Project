#include "InputManager.cpp"
#include "GameEngine.cpp"
#include "Renderer.cpp"

/*
Esta clase controla el InputManager, GameEngine y el Renderer.
*/

static class GameManager {
private:
	InputManager IM;
	GameEngine GE;
	Renderer R;
	bool finished = false;
	bool mouseDown;
public:
	void GameLoop() {
		while (!finished){
			mouseDown = IM.MouseDown();
			if (mouseDown) {

			}
			R.Draw();
		}
	}
};