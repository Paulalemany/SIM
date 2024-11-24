#pragma once
#include "MuelleForeGenerator.h"

class AnclaFG : public MuelleForeGenerator
{
public:
	AnclaFG(Vector3 ori, double k, double descanso, Vector3 anchor_pos);
	~AnclaFG();

	void show() override;
	void hide() override;
};

