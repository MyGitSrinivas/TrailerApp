/*********************************************************************
    HARDWARE	    :
    MODULE		    :
    VERSION	     	:
    FILE NAME	    :
    FILE DESCRIPTION:
    NOTE			:
*********************************************************************/

#ifndef TRAILER_H
#define TRAILER_H

#include <iostream>

#include <logger.h>
#include "IFeatureSimulater.h"


enum TrailerLightingSetting
{
    NO_ACTION = 0x00,
    OFF = 0x01,
    ON = 0x02
};

class TrailerSimulation : public IFeatureSimulater
{
public:
    ~TrailerSimulation();
    void InitSimulation(IUpdatableView* pTestDataPtr);
    void SystemEventHandler(string systemEvent);
    void UpdateDataHandler(unsigned int key, string value);
    static TrailerSimulation *getTrailerSimulationPtr();
    static void releaseTrailerSimulationPtr();

private:
    TrailerSimulation();
    static TrailerSimulation* mpTrailerInstance;
    void ChangeTrailerLightingSetting(unsigned int SenderHandle, TrailerLightingSetting status);
};
#endif // TRAILER_H
