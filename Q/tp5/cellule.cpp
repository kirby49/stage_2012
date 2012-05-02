#include "cellule.h"

cellule::cellule()
{

       frame = new QLabel(this);
       frame->setGeometry(0, 0, 10,10);
       frame->setFrameShape(QFrame::Box);


}
