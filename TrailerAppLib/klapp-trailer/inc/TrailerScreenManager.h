/*********************************************************************
    HARDWARE	    :
    MODULE		    :
    VERSION	     	:
    FILE NAME	    :
    FILE DESCRIPTION:
    NOTE			:
*********************************************************************/

#ifndef TRAILERSCREENMANAGER_H
#define TRAILERSCREENMANAGER_H

//## auto_generated
//#include <oxf/oxf.h>
//## auto_generated
//#include <oxf/omreactive.h>
//## auto_generated
//#include <oxf/state.h>
//## auto_generated
//#include <oxf/event.h>
//## auto_generated
#include <kivi.h>
//## auto_generated
#include <stlinc.h>
//## auto_generated
#include <logger.h>
//## auto_generated
#include <kapi-hmicore/ITestableApp.h>
//## auto_generated
#include <kapi-hmicore/IEventHandler.h>
//## auto_generated
#include <kapi-hmicore/IScreenProvider.h>
//## auto_generated
#include <kapi-hmicore/INotificationManager.h>
//## auto_generated
#include <kapi-hmicore/IApplication.h>
//## auto_generated
#include <kapi-hmicore/IPrecedenceManager.h>
//## auto_generated
#include "AppDetails.h"
#include "IHMIF.h"

#include "ITrailerLogicManager.h"
#include "ITrailerScreenManager.h"
#include "TrailerGlobalTypes.h"


class TrailerScreenManager : /*public OMReactive, */public IApplication, public ITrailerScreenManager, public ITestableApp
{
public:
    TrailerScreenManager(DisplayType viewType, ITrailerLogicManager * trailerLogicManager);
    ~TrailerScreenManager();

    unsigned int GetId();

    const ScreenElementsMap& GetScreens();

    const ScreenElementsList&  GetScreenDataId(unsigned int  screenName);

    void Init(IHMIF* hmif);

    void Start();

    void Activate(const bool &isActive);

    bool Stop();

    const AppDetails* GetAppInfo();

    ISimulator* GetSimulation();

    // Dummy Method
    void SetApplicationState(int);

    void SetScreens();

private:

    DisplayType m_ViewType;

    ITrailerLogicManager *m_trailerLogicManager;

    AppDetails *m_AppDetails;

    IPrecedenceManager *m_PrecedenceManager;

    INotificationManager *m_pNotificationManager;

    ScreenElementsMap m_ScreenElementMap;
};
#endif // TRAILERSCREENMANAGER_H
