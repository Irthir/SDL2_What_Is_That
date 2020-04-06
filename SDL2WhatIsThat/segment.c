#include "segment.h"

tSegment CreatSegment(tPoint pA,tPoint pB)
//BUT : Créer un segment à partir de ses points.
//ENTREE : Les points du segment.
//SORTIE : Le segment de type tSegment créé.
{
    tSegment sSegment;
    sSegment.pA=pA;
    sSegment.pB=pB;
    return sSegment;
}

void tSegmentSetA(tSegment *pSegment, tPoint pA)
//BUT : Changer la valeur du point A d'un segment.
//ENTREE : Le segment et un point qui remplacera son point A.
//SORTIE : Le segment actualisé.
{
    pSegment->pA=pA;
}

void tSegmentSetB(tSegment *pSegment, tPoint pB)
//BUT : Changer la valeur du point B d'un segment.
//ENTREE : Le segment et un point qui remplacera son point B.
//SORTIE : Le segment actualisé.
{
    pSegment->pB=pB;
}

tPoint tSegmentGetA(tSegment sSegment)
//BUT : Récupérer le point A d'un segment.
//ENTREE : Le segment dont on souhaite le point A.
//SORTIE : Le point A du segment.
{
    return sSegment.pA;
}

tPoint tSegmentGetB(tSegment sSegment)
//BUT : Récupérer le point B d'un segment.
//ENTREE : Le segment dont on souhaite le point B.
//SORTIE : Le point B du segment.
{
    return sSegment.pB;
}

int tSegmentGetLongueur(tSegment sSegment)
//BUT : Récupérer la longueur d'un segment.
//ENTREE : Le segment dont on souhaite la longueur.
//SORTIE : La longueur du segment, sous la forme d'un entier car on fonctionne en pixel et qu'un demi pixel n'existe pas à ma connaissance.
{
	//Formule pour calculer une longueur AB  : Racine de ((xB-xA)²+(yB-yA)²).
	int nLongueur=(int)round(sqrt((sSegment.pB.nX-sSegment.pA.nX)*(sSegment.pB.nX-sSegment.pA.nX)+(sSegment.pB.nY-sSegment.pA.nY)*(sSegment.pB.nY-sSegment.pA.nY)));
	return nLongueur;
}
