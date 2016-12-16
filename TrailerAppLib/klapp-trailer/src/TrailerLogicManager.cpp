/*********************************************************************
    HARDWARE	    :
    MODULE		    :
    VERSION	     	:
    FILE NAME	    :
    FILE DESCRIPTION:
    NOTE			:
*********************************************************************/
#include "TrailerLogicManager.h"

TrailerLogicManager::TrailerLogicManager() {
    std::cout << "TrailerLogicManager" << "\n";
    LOG1((TEXT("TrailerLogicManager :: Constructor \n")));

#ifdef PLATFORM_X86
    mpTrailerInstance = NULL;
#endif
}

TrailerLogicManager::~TrailerLogicManager() {
    //std::cout << "~TrailerLogicManager" << "\n";
    LOG1((TEXT("TrailerLogicManager :: Destructor \n")));


#ifdef PLATFORM_X86
    if (NULL != mpTrailerInstance)
    {
        TrailerSimulation::releaseTrailerSimulationPtr();
    }
#endif
}

void TrailerLogicManager::Start()
{
    LOG1((TEXT("TrailerApp SM:Enter in Start\n")));
}

void TrailerLogicManager::Init()
{
    cout << "Init Method Called";
#ifdef PLATFORM_X86
    // For Host compilation
    if (NULL == mpTrailerInstance)
    {
        mpTrailerInstance = TrailerSimulation::getTrailerSimulationPtr();
    }
    cout << "Instance : " << mpTrailerInstance;
#endif
}
