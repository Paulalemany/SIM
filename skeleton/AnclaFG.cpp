#include "AnclaFG.h"

AnclaFG::AnclaFG(Vector3 ori, double k, double descanso, Vector3 anchor_pos)
 : MuelleForeGenerator(ori, k, descanso, nullptr)
{
	//Creamos el ancla con un cubo para que se diferencie
	par = new Particle(anchor_pos);
	
}

AnclaFG::~AnclaFG()
{
	delete par;
}

void AnclaFG::show()
{
	par->setVisibility(true);
	ForceGenerator::show();
}

void AnclaFG::hide()
{
	par->setVisibility(false);
	ForceGenerator::hide();
}
