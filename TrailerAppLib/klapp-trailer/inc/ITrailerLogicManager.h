/*********************************************************************
    HARDWARE	    :
    MODULE		    :
    VERSION		    :
    FILE NAME	    :
    FILE DESCRIPTION:
    NOTE			:
*********************************************************************/

#ifndef ITRAILERLOGICMANAGER_H
#define ITRAILERLOGICMANAGER_H

class ITrailerLogicManager
{
public:

    /* Contructor of the ITrailerLogicManager interface class */
    ITrailerLogicManager();

    /* Destructor of the ITrailerLogicManager interface class */
    virtual ~ITrailerLogicManager() = 0;

    virtual void Start() = 0;
    virtual void Init() = 0;
};
#endif // ITRAILERLOGICMANAGER_H
