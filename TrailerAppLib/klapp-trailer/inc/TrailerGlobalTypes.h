/*********************************************************************
    HARDWARE	    :
    MODULE		    :
    VERSION	     	:
    FILE NAME	    :
    FILE DESCRIPTION:
    NOTE			:
*********************************************************************/

#ifndef TRAILERGLOBALTYPES_H
#define TRAILERGLOBALTYPES_H

// Dummy ID for Trailer App
#define TRAILERMODULEID					    133

// Screens for Trailer App
#define SC_TRAILER_LOW_RADIO_MAIN_SCREEN    1133001
#define SC_TRAILER_LIGHT_TEST_ON            1133002
#define SC_TRAILER_LIGHT_TEST_STOPPED	    1133003

// Contacted events with Renderer
#define evG_TrailerLighting_Start    	    3133001
#define evG_TrailerLighting_Stop	        3133002
#define evG_TrailerLighting_Failure	        3133003
#define evG_Trailer_CancelTrailerLightTest	3133004

#endif // TRAILERGLOBALTYPES_H
