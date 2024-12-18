#include <ctype.h>

#include <PxPhysicsAPI.h>

#include <vector>
#include <iostream>

#include "core.hpp"
#include "RenderUtils.hpp"
#include "callbacks.hpp"

#include "GameMachine.h"

using namespace physx;

#pragma region Inicializacion

PxDefaultAllocator		gAllocator;
PxDefaultErrorCallback	gErrorCallback;

PxFoundation* gFoundation = NULL;
PxPhysics* gPhysics = NULL;


PxMaterial* gMaterial = NULL;

PxPvd* gPvd = NULL;

PxDefaultCpuDispatcher* gDispatcher = NULL;
PxScene* gScene = NULL;
//PxScene* solidScene = NULL;
ContactReportCallback gContactReportCallback;
#pragma endregion

//Scene* scene = nullptr;
GameMachine* gameMachine = nullptr;

//Textos del juego
std::string _name = "Paula Alemany Rodriguez";

std::string _start = " ";
std::string _intro = " ";
std::string _balas = " ";
std::string _ExplicacionS = " ";
std::string _ExplicacionM = " ";
std::string _ExplicacionL = " ";
std::string _selector = " ";
std::string _selector2 = " ";

std::string _nivelFlotacion = " ";
std::string _nivelViento = " ";
std::string _nivelTornado = " ";
std::string _nivelSolidos = " ";
std::string _explicacionContinuar = " ";
std::string _fin = " ";


// Initialize physics engine
void initPhysics(bool interactive)
{
	PX_UNUSED(interactive);

	gFoundation = PxCreateFoundation(PX_FOUNDATION_VERSION, gAllocator, gErrorCallback);

	gPvd = PxCreatePvd(*gFoundation);
	PxPvdTransport* transport = PxDefaultPvdSocketTransportCreate(PVD_HOST, 5425, 10);
	gPvd->connect(*transport,PxPvdInstrumentationFlag::eALL);

	gPhysics = PxCreatePhysics(PX_PHYSICS_VERSION, *gFoundation, PxTolerancesScale(),true,gPvd);

	gMaterial = gPhysics->createMaterial(0.5f, 0.5f, 0.6f);

	// For Solid Rigids +++++++++++++++++++++++++++++++++++++
	PxSceneDesc sceneDesc(gPhysics->getTolerancesScale());
	sceneDesc.gravity = PxVec3(0.0f, -9.8f, 0.0f);
	gDispatcher = PxDefaultCpuDispatcherCreate(2);
	sceneDesc.cpuDispatcher = gDispatcher;
	sceneDesc.filterShader = contactReportFilterShader;
	sceneDesc.simulationEventCallback = &gContactReportCallback;
	gScene = gPhysics->createScene(sceneDesc);

	//Pintando objetos
#pragma region Practica 0
	/*RenderItem* _sphereR = new RenderItem(CreateShape(PxSphereGeometry(5)), new PxTransform(20.0, 0.0, 0.0), Vector4(1, 0.7, 0.8, 1));
	RegisterRenderItem(_sphereR);

	RenderItem* _sphereB = new RenderItem(CreateShape(PxSphereGeometry(5)), new PxTransform(0.0, 20.0, 0.0), Vector4(0.7, 1, 0.7, 1));
	RegisterRenderItem(_sphereB);

	RenderItem* _sphereG = new RenderItem(CreateShape(PxSphereGeometry(5)), new PxTransform(0.0, 0.0, 20.0), Vector4(0.7, 0.7, 1, 1));
	RegisterRenderItem(_sphereG);

	RenderItem* _sphere = new RenderItem(CreateShape(PxSphereGeometry(5)), new PxTransform(0.0, 0.0, 0.0), Vector4(1, 1, 1, 1));
	RegisterRenderItem(_sphere);*/
#pragma endregion

	gameMachine = new GameMachine(gScene, gPhysics);
}


// Function to configure what happens in each step of physics
// interactive: true if the game is rendering, false if it offline
// t: time passed since last call in milliseconds
// Update
void stepPhysics(bool interactive, double t)
{
	PX_UNUSED(interactive);

	gScene->simulate(t);
	gScene->fetchResults(true);
	
	//Movimiento de los proyectiles
	//llamamos al update de la escena y esta se encarga del resto
	if (gameMachine != nullptr) gameMachine->update(t);
	
}

// Function to clean data
// Add custom code to the begining of the function
void cleanupPhysics(bool interactive)
{
	PX_UNUSED(interactive);

	// Rigid Body ++++++++++++++++++++++++++++++++++++++++++
	gScene->release();
	gDispatcher->release();
	// -----------------------------------------------------
	gPhysics->release();	
	PxPvdTransport* transport = gPvd->getTransport();
	gPvd->release();
	transport->release();
	
	gFoundation->release();
	}

// Function called when a key is pressed
void keyPress(unsigned char key, const PxTransform& camera)
{
	PX_UNUSED(camera);

	gameMachine->keyPressed(key, camera);

	switch(toupper(key))
	{
	//case 'B': break;
	//case ' ':	break;
	case ' ':
	{
		break;
	}
	case 'K':
	{
		//La direcci�n habr�a que cambiarla seg�n donde mire la c�mara
		//La posici�n inicial es la misma en todas
		/*scene->addParticle(new Proyectil(camera.p, camera.q.getBasisVector2() * -25,
			Vector3(0, 0, 0), 1));*/

		cout << camera.p.x << " " << camera.p.y << " " << camera.p.z << endl;
		break;
		
	}
	default:
		break;
	}

	
}

//Input del raton
void handleMouseInput(int button, int state, int x, int y) {
	gameMachine->shoot(GetCamera()->getMousePos());
}

void onCollision(physx::PxActor* actor1, physx::PxActor* actor2)
{
	PX_UNUSED(actor1);
	PX_UNUSED(actor2);
}


int main(int, const char*const*)
{
#ifndef OFFLINE_EXECUTION 
	extern void renderLoop();
	renderLoop();
#else
	static const PxU32 frameCount = 100;
	initPhysics(false);
	for(PxU32 i=0; i<frameCount; i++)
		stepPhysics(false);
	cleanupPhysics(false);
#endif

	return 0;
}