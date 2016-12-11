#include <SDL\SDL.h>
/*
Esta clase gestiona todo el imput que va a recibir el juego desde el usuario.
*/

class InputManager {
private:
	Uint32 mouseX;
	Uint32 mouseY;
public:
	/*
	Se devuelve la referencia a un struct {bool,int,int} Si se ha pulsado el boton derecho y en que posicion.
	Cuando sea true se deberia comprovar la posicion del raton con la de los botones para ver
	si se han pulsado.
	*/
	bool MouseDown(){
		if (SDL_MOUSEBUTTONDOWN) {
			mouseX = SDL_GetMouseState.x;
			return true;
		}
		else return false;
		
	}
};