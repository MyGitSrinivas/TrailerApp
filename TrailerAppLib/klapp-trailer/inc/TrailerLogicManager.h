/*********************************************************************
    HARDWARE	    :
    MODULE		    :
    VERSION	     	:
    FILE NAME	    :
    FILE DESCRIPTION:
    NOTE			:
*********************************************************************/

#ifndef TRAILERLOGICMANAGER_H
#define TRAILERLOGICMANAGER_H

#include <iostream>
#include <logger.h>
#include "ITrailerLogicManager.h"
//#ifdef PLATFORM_X86
#include "../test/unit/simulation/inc/TrailerSimulation.h"
//#endif

class TrailerLogicManager : public ITrailerLogicManager
{
public:
    TrailerLogicManager();
    ~TrailerLogicManager();

    virtual void Start();
    virtual void Init();

private:
//#ifdef PLATFORM_X86
    // Need to compile only for Host
    TrailerSimulation *mpTrailerInstance;
//#endif
};

#endif // TRAILERLOGICMANAGER_H
