#include <SDL\SDL.h>
#include <utility>

/*
Esta clase gestiona todo el imput que va a recibir el juego desde el usuario.
*/

class InputManager {
private:
	

public:
	/*
	Se devuelve la referencia a un struct {bool,int,int} Si se ha pulsado el boton derecho y en que posicion.
	Cuando sea true se deberia comprovar la posicion del raton con la de los botones para ver
	si se han pulsado.
	*/
	std::pair<Uint32,Uint32>* MouseDown(){
		if (SDL_MOUSEBUTTONDOWN) {
			std::pair<Uint32, Uint32> coords;
			/*
			Aqui quiero guardar las coordenadas del raton en el pair. Utilizo punteros porque quiero acceder
			luego desde la clase GameManager para hacer la comparacion de si el click ha sido en algun boton.
			*/
			coords.first = ;
			coords.second = ;
			
			return &coords;
		}
		else return nullptr;
		
	}
};