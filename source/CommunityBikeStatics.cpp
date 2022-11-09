//------------------------------------------------------------------------------
// CommunityBikeStatics.cpp : 
// 
//	- allocates memory for and initializes static class members
//	- prevents app code access to private static members
//------------------------------------------------------------------------------
#include "CommunityBike.h"

//------------------------------------------------------------------------------
int CommunityBike::ms_bikeCount = 0;
int CommunityBike::ms_hourlyRate = 5;
//------------------------------------------------------------------------------
