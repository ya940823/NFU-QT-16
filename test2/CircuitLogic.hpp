#ifndef CIRCUITLOGIC_HPP
#define CIRCUITLOGIC_HPP

#include <QObject>
#include <QGraphicsScene>
#include "CircuitComponent.hpp"

class CircuitLogic : public QObject {
    Q_OBJECT

public:
    explicit CircuitLogic(QGraphicsScene *scene);

public slots:
    void handleComponentClick(CircuitComponent *component);

private:
    CircuitComponent *nfb, *pb1, *ems, *thRy, *x1, *x2, *x3, *mcf, *mcr;
    CircuitLamp *pl1, *pl2, *pl3;

    void resetCircuit();
};

#endif // CIRCUITLOGIC_HPP
