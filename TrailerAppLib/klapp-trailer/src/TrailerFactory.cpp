//## auto_generated
#include "TrailerFactory.h"
//## package TrailerFactory
/*********************************************************************
    HARDWARE	    :
    MODULE		    :
    VERSION	     	:
    FILE NAME	    :
    FILE DESCRIPTION:
    NOTE			:
*********************************************************************/

//#[ ignore
#include <kapi-hmicore/HMIFTypes.h>
#include "TrailerScreenManager.h"
#include "TrailerLogicManager.h"
#include "ITrailerLogicManager.h"
#include <iostream>

extern "C" {

ITrailerLogicManager *trailerLogicManager = NULL;
TrailerScreenManager *trailerScreenManager = NULL;

IApplication* CreateApp(DisplayType viewType)
{
    LOG1((TEXT("Trailer Factory:: Create Trailer App Native..\n")));
    std::cout << "Create App called !!!" << "\n";

    if(NULL == trailerLogicManager) {
        trailerLogicManager = new TrailerLogicManager();
    }

    if(NULL == trailerScreenManager) {
        trailerScreenManager = new TrailerScreenManager(viewType, trailerLogicManager);
    }
    return trailerScreenManager;
}

void DeleteApp(IApplication* App)
{
    LOG1((TEXT("Trailer Factory:: Delete Trailer App Native..\n")));

    if(NULL != trailerLogicManager) {
        delete trailerLogicManager;
        trailerLogicManager = NULL;
    }

    // Screen Manager Instance Deletion
    if(NULL != App) {
        delete App;
        App = NULL;
    }
}
}
//#]
