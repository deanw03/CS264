#ifndef VISITOR_H
#define VISITOR_H

#include "Expr.h"
//forward declarations of expressions
class ConstExpr;
class AddExpr;
class SubExpr;
class MulExpr;
class DivExpr;
class ModExpr;

//base class for all visitors
class Visitor{
public:
    virtual ~Visitor()= default;
    //visit a constant expression
    virtual double visit(ConstExpr*expr) = 0;
    //visit an addition expression
    virtual double visit(AddExpr* expr) = 0;
    //visit a subtraction expression
    virtual double visit(SubExpr* expr) = 0;
    //visit a multiplication expression
    virtual double visit(MulExpr* expr) = 0;
    //visit a division expression
    virtual double visit(DivExpr* expr) = 0;
    //visit a modulus expression
    virtual double visit(ModExpr* expr) = 0;
};
//NumVisitor class for evaluating numerical expressions
class NumVisitor : public Visitor{
public:
    double visit(ConstExpr*expr)override;
    double visit(AddExpr* expr) override;
    double visit(SubExpr* expr) override;
    double visit(MulExpr* expr) override;
    double visit(DivExpr* expr) override;
    double visit(ModExpr* expr) override;
};
#endif
