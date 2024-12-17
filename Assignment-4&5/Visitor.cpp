#include "Visitor.h"
//visit a constant expression
double NumVisitor:: visit(ConstExpr*expr){
    return expr->getValue ();
}

//visit an addition expression
double NumVisitor::visit(AddExpr*expr) {
    return expr ->getLeft()->eval (this) + expr-> getRight()->eval(this);
}

//visit a subtraction expression
double NumVisitor::visit(SubExpr*expr){
    return expr->getLeft()->eval(this)- expr->getRight ()->eval(this);
}

//visit a multiplication expression
double NumVisitor::visit (MulExpr* expr){
    return expr->getLeft()->eval(this) *expr->getRight()->eval(this);
}

//visit a division expression
double NumVisitor::visit (DivExpr* expr) {
    double denominator = expr->getRight()->eval(this);
    if (denominator == 0) {
        throw std::invalid_argument("Division by zero");
    }
    return expr->getLeft()->eval(this) / denominator;
}

//visit a modulo expression
double NumVisitor:: visit(ModExpr* expr){
    double denominator = expr-> getRight()->eval(this);
    if (denominator == 0) {
        throw std::invalid_argument( "Modulo by zero");
    }
    return static_cast<int>(expr->getLeft()->eval(this)) %static_cast<int> (denominator);
}

