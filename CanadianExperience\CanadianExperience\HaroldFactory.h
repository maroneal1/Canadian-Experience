/**
* \file HaroldFactory.h
*
* \author Alexandria Marone
*
* Class that creates harold char
*/


#pragma once
#include <memory>
#include "Actor.h"
#include "ActorFactory.h"

/**
* Factory class that builds the Harold character
*/
class CHaroldFactory :
	public CActorFactory
{
public:
	CHaroldFactory();
	virtual ~CHaroldFactory();
	std::shared_ptr<CActor> Create();
};

