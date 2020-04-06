#ifndef SEGMENT_H_INCLUDED
#define SEGMENT_H_INCLUDED
#pragma once

#include "point.h"
#include <math.h>

typedef struct tSegment
//Un segment se définit par deux points.
{
    tPoint pA;
    tPoint pB;
}tSegment;

extern tSegment CreatSegment(tPoint pA,tPoint pB);
extern void tSegmentSetA(tSegment *pSegment, tPoint pA);
extern void tSegmentSetB(tSegment *pSegment, tPoint pB);
extern tPoint tSegmentGetA(tSegment sSegment);
extern tPoint tSegmentGetB(tSegment sSegment);
extern int tSegmentGetLongueur(tSegment sSegment);

#endif
