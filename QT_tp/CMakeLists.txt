PROJECT (tp)
FIND_PACKAGE (Qt4 REQUIRED)

SET (projet_SOURCES main.cpp calculatrice.cpp moteur.cpp)
SET (projet_HEADERS calculatrice.h moteur.h)

QT4_WRAP_CPP( calculatrice_HEADERS_MOC ${projet_HEADERS})

INCLUDE (${QT_USE_FILE})
ADD_DEFINITIONS(-g ${QT_DEFINITIONS})

ADD_EXECUTABLE(calculatrice ${projet_SOURCES} ${calculatrice_HEADERS_MOC})
TARGET_LINK_LIBRARIES(calculatrice ${QT_LIBRARIES})

#Pour compiler : cmake . -G "générateur"
