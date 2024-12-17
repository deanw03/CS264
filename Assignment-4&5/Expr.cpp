#include "Expr.h"
#include "Visitor.h"

/**
 * Constructor for ConstExpr
 * Initializes the constant expression with a numerical value
 * @param val Constant value
 */
ConstExpr::ConstExpr( double val) :value(val){}
/**
 * Retrieve the constant value of the expression
 * @return The value stored in this expression
 */
double ConstExpr:: getValue() const{
    return value;
}
/**
 * Evaluate the constant expression using a visitor
 * @param visitor pointer to the visitor that performs the evaluation
 * @return The constant value as a double
 */
double ConstExpr::eval( Visitor*visitor) {
    return visitor->visit (this);
}
/**
 * Constructor for AddExpr
 * Initializes an addition expression with two sub-expressions
 * @param l pointer to the left sub-expression
 * @param r Pointer to the right sub-expression
 */
AddExpr:: AddExpr(Expr*l,Expr* r) :left(l), right(r){}

/**
 * Retrieve the left sub-expression
 * @return A pointer to the left sub-expression
 */
Expr* AddExpr::getLeft()const {
    return left;
}
/**
 * Retrieve the right sub-expression
 * @return A pointer to the right sub-expression
 */
Expr*AddExpr:: getRight()const{
    return right;
}
/**
 * Evaluate the addition expression using a visitor
 * @param visitor A pointer to the visitor that performs the evaluation
 * @return The result of the addition as a double
 */
double AddExpr::eval(Visitor* visitor) {
    return visitor->visit(this);

}