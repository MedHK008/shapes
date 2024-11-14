
#ifndef LOZENGE_FACTORY_H
#define LOZENGE_FACTORY_H

#include "ShapeFactory.h"
#include "Lozenge.h"

class LozengeFactory : public ShapeFactory {
public:
    Lozenge* create(double diagonal) {
        return new Lozenge(diagonal);
    }
};

#endif // LOZENGE_FACTORY_H