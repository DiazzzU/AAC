#ifndef LITERAL_H
#define LITERAL_H

#include <string>
#include <vector>

class Literal {
public:
    std::string type;


    Literal() {
        type = "Literal";
    }

    virtual std::vector <Literal*> getListVal(){
         return std::vector<Literal*>();
    }
    virtual int getIntVal(){
        return 0;
    }
    virtual double getRealVal(){
        return 0;
    }
    virtual bool getBooleanVal(){
        return 0;
    }
    virtual std::string getStringVal(){
        return "";
    }
    virtual std::string getType(){
        return type;
    }   
    virtual std::vector <Literal*> getArrayVal() {
        return std::vector<Literal*>();
    }
    virtual std::map < std::string, Literal*> getRecordVal() {
        return std::map < std::string, Literal*>();
    }


    virtual void setIntVal(int x){

    }
    virtual void setRealVal(double x){

    }
    virtual void setBooleanVal(bool x){

    }
     virtual void setStringVal(std::string x){
       
    }
    virtual void addListVal(Literal* x){

    }
    virtual void setType(std::string x){
        
    }
    virtual void addArrayVal(Literal* val){

    }
    virtual void addRecordVal(std::string key, Literal* val){

    }


    virtual void print() {

    }
};

#endif