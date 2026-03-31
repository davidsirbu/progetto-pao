#ifndef VISITOR_H
#define VISITOR_H

class impegno;
class scadenza;
class routine;

class visitor {
    public:
        ~visitor() = default;
        virtual void visit(impegno& i) = 0;
        virtual void visit(scadenza& s) = 0;
        virtual void visit(routine& r) = 0;
};

#endif