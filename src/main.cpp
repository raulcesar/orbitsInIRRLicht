#include <iostream>
#include <irrlicht.h>

using namespace irr;


using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;



int main(int, char**)
{
	const int SCREEN_WIDTH  = 640;
	const int SCREEN_HEIGHT = 480;

	IrrlichtDevice *device =
	    createDevice( video::EDT_SOFTWARE,
	                  dimension2d<u32>(SCREEN_WIDTH,
	                                   SCREEN_HEIGHT),
	                  16,
	                  false,
	                  false,
	                  false,
	                  0);

	if (!device)
		return 1;

	device->setWindowCaption(L"Hello World! - Irrlicht Engine Demo");
	IVideoDriver* driver = device->getVideoDriver();
	ISceneManager* smgr = device->getSceneManager();
	IGUIEnvironment* guienv = device->getGUIEnvironment();


	guienv->addStaticText(L"Hello World! This is the Irrlicht Software renderer!",
	                      rect<s32>(10, 10, 260, 22), true);
	IAnimatedMesh* mesh = smgr->getMesh("./res/SimpleMan.dae");
	if (!mesh)
	{
		device->drop();
		return 1;
	}
	IAnimatedMeshSceneNode* node = smgr->addAnimatedMeshSceneNode( mesh, 0, -1, vector3df(0,0,0), vector3df(0,0,0), 
		vector3df(3.0,3.0,3.0) );
	if (node)
	{
		node->setMaterialFlag(EMF_LIGHTING, true);
		// node->setMD2Animation(scene::EMAT_STAND);
		// node->setMaterialTexture( 0, driver->getTexture("./res/sydney.bmp") );
	}

	smgr->addCameraSceneNode(0, vector3df(0,0,-40), vector3df(0,0,0));



	while (device->run())
	{
		driver->beginScene(true, true, SColor(255, 100, 101, 140));

		smgr->drawAll();
		guienv->drawAll();

		driver->endScene();
	}

	device->drop();
	return 0;
}
