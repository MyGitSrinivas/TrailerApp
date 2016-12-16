/*********************************************************************
    HARDWARE	    :
    MODULE		    :
    VERSION	     	:
    FILE NAME	    :
    FILE DESCRIPTION:
    NOTE			:
*********************************************************************/

#include "TrailerSimulation.h"

TrailerSimulation* TrailerSimulation::mpTrailerInstance = NULL;

TrailerSimulation::TrailerSimulation()
{
    LOG4((TEXT("Trailer App Simulation Constructor\n")));
    cout << " Trailer App Simulation Constructor";
}

TrailerSimulation::~TrailerSimulation()
{
    LOG4((TEXT("Trailer App Simulation Destructor\n")));
    cout << " Trailer App Simulation Destructor";
}

void TrailerSimulation::InitSimulation(IUpdatableView *pTestDataPtr)
{

}

void TrailerSimulation::SystemEventHandler(string systemEvent)
{

}

void TrailerSimulation::UpdateDataHandler(unsigned int key, string value)
{

}

TrailerSimulation *TrailerSimulation::getTrailerSimulationPtr()
{
    cout << " Inside getTrailerSimulationPtr";
    if(NULL == mpTrailerInstance)
    {
          mpTrailerInstance = new TrailerSimulation();

    }
    return mpTrailerInstance;
}

void TrailerSimulation::releaseTrailerSimulationPtr()
{
    cout << "releaseTrailerSimulationPtr";
    if(NULL != mpTrailerInstance)
    {
        delete mpTrailerInstance;
        mpTrailerInstance = NULL;
    }
}

void TrailerSimulation::ChangeTrailerLightingSetting(unsigned int SenderHandle, TrailerLightingSetting status)
{
// CallBack to application suggesting testing is ON.
// Renderer has to Populate screen with STOP button which suggests testing is on going.
// Have to cover various use cases with Switch case.
}
