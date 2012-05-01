#include "cellule.h"

cellule::cellule()
{

       frame = new QLabel(this);
       frame->setGeometry(0, 0, 15, 15);
       frame->setFrameShape(QFrame::Box);


}
