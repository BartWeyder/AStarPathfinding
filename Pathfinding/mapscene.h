#ifndef MAPSCENE_H
#define MAPSCENE_H

#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QDir>
#include <QString>
#include <QMessageBox>
#include <QPointF>
#include <QGraphicsSceneMouseEvent>
#include <list>
#include "astar.h"
#include "fixinclude.h"

#ifndef NULL
#define NULL 0
#endif

#ifndef UINT
#define UINT unsigned int
#endif

class MapScene : public QGraphicsScene
{
    AStar astar;

    MapNode **map;

    list<pair<UINT, UINT> > path;
    list<list<NodeState> > steps;
    list<list<NodeState> >::iterator stepsIt;

    QString freeNodeImgPath;
    QString dirtNodeImgPath;
    QString openedNodeImgPath[8];
    QString closedNodeImgPath;
    QString wallNodeImgPath;
    QString pathNodeImgPath;
    QString startNodeImgPath;
    QString endNodeImgPath;

    ToSetState toSetState;

    UINT mapWidth;
    UINT mapHeight;

    UINT itemSize;
    UINT itemScale;

    bool pathOnScreen;

    void freeNodes();
    void destroyMap();
    void drawPath();
    void obtainPath(bool saveChanges = false);
    void reDrawStartEndNodes();

public:
    MapScene(QObject * parent = 0);
    ~MapScene();

    void setMap(UINT mapWidth, UINT mapHeight);
    void showPath();
    void showNextStep();
    void showSteps();
    void setHeuristics(AStarHeuristics heuristic);
    void setScale(UINT scale);
    void setStart(UINT x, UINT y);
    void setEnd(UINT x, UINT y);
    void setToSetState(ToSetState toSetState);
	void saveToFile(const char * path);
	void loadFromFile(const char * path);

protected:
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
    void wheelEvent(QGraphicsSceneWheelEvent *event);

private:
	void loadPoint(UINT i, UINT j, NodeType nodeType, UINT expandCost);
};

#endif // MAPSCENE_H
