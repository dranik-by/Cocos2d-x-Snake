/*
Bullet Continuous Collision Detection and Physics Library
Copyright (c) 2013 Erwin Coumans  http://bulletphysics.org

This software is provided 'as-is', without any express or implied warranty.
In no event will the authors be held liable for any damages arising from the use of this software.
Permission is granted to anyone to use this software for any purpose, 
including commercial applications, and to alter it and redistribute it freely, 
subject to the following restrictions:

1. The origin of this software must not be misrepresented; you must not claim that you wrote the original software. If you use this software in a product, an acknowledgment in the product documentation would be appreciated but is not required.
2. Altered source versions must be plainly marked as such, and must not be misrepresented as being the original software.
3. This notice may not be removed or altered from any source distribution.
*/

#ifndef BT_FIXED_CONSTRAINT_H
#define BT_FIXED_CONSTRAINT_H

#include "btTypedConstraint.h"

ATTRIBUTE_ALIGNED16(class) btFixedConstraint : public btTypedConstraint
{
    btVector3 m_pivotInA;
    btVector3 m_pivotInB;
    btQuaternion m_relTargetAB;

public:
    btFixedConstraint(btRigidBody &rbA, btRigidBody &rbB, const btTransform &frameInA, const btTransform &frameInB);

    virtual ~btFixedConstraint();

    virtual void getInfo1(btConstraintInfo1* info);

    virtual void getInfo2(btConstraintInfo2* info);

    virtual void setParam(int num, btScalar value, int axis = -1)
    {
        btAssert(0);
    }

    virtual btScalar getParam(int num, int axis = -1) const
    {
        btAssert(0);
        return 0.f;
    }

};

#endif //BT_FIXED_CONSTRAINT_H
