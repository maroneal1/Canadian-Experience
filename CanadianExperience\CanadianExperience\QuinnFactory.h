/**
* \file QuinnFactory.h
*
* \author Alexandria Marone
*
* Class that creates Quinn char
*/


#include <memory>
#include "Actor.h"
#include "ActorFactory.h"

/**
* Factory class that builds the Quinn  character
*/
class CQuinnFactory :
	public CActorFactory
{
public:
	CQuinnFactory();
	virtual ~CQuinnFactory();
	std::shared_ptr<CActor> Create();
};

