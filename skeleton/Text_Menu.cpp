#include "Text_Menu.h"

Text_Menu::Text_Menu(PxScene* _scene, PxPhysics* _physics)
	:SolidScene(scene, physics)
{
	sistemas.push_back(new ParticleSystemBrillitos({ 0,0,0 }, { 0,0,0 }, 500, 1));
}

void Text_Menu::init(int i)
{
	switch (i)
	{
	case N_FLOTACION:
		_nivelFlotacion = "___¡Cuidado con el agua!___";
		break;

	case N_VIENTO:
		_nivelViento = "___Pulsa 'v' para activar/desactivar viento___";
		break;

	case N_TORNADO:
		_nivelTornado = "___¡Oh no un tornado!___";
		break;

	case N_SOLIDOS:
		_nivelSolidos = "___Aqui las paredes rebotan___";
		break;

	case NIVELES:
		break;

	case START:
		_fin = "___FELICIDADES!!!! GRACIAS POR JUGAR___";
		break;
	default:
		break;
	}
}

void Text_Menu::quit()
{
	_fin = " ";
	_nivelFlotacion = "";
	_nivelViento = "";
	_nivelTornado = "";
	_nivelSolidos = "";

	SolidScene::quit();
}
