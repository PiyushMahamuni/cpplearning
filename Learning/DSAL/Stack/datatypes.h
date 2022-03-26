#ifndef _DATATYPE_H_
#define _DATATYPE_H_
#include <string>
#include <cctype>

template <typename T>
std::string datatype(){
    std::string tmplt{typeid(T).name()}, type;
    if(tmplt == std::string{typeid(std::string).name()}) return "std::string";
//    std::cout << tmplt << " ";
    bool is_ptr{tmplt[0]=='P'};
    bool is_const{tmplt[1]=='K'};
    size_t ind{0};
    if(is_ptr) ind++;
    if(is_const) ind++;
    bool is_ud{ tmplt[ind] >= '0' && tmplt[ind] <= '9' };
    if(is_ud){
        bool is_tmplt_class { tmplt[tmplt.size()-1] == 'E' };
        if(is_tmplt_class){
            size_t i{ind+1};
            for(; tmplt[i]!='I' && i < tmplt.size(); i++){
                type += tmplt[i];
            }
            i++;
            type += "<";
            bool is_ptr{tmplt[i] == 'P'};
            if(is_ptr) i++;
            bool is_const{tmplt[i] == 'K'};
            if(is_const){
                type += "const ";
                i++;
            }
            if(tmplt[i] >= '0' && tmplt[i] <= '9'){
                for(++i; tmplt[i]!='E' && i<tmplt.size(); i++){
                    type += tmplt[i];
                }
            }
            else{
                switch(tmplt[i]){
                    case 'i':
                    type += "int";
                    break;
                    case 'c':
                    type += "char";
                    break;
                    case 'f':
                    type += "float";
                    break;
                    case 'd':
                    type += "double";
                    break;
                    case 'l':
                    type += "long";
                    break;
                    case 'j':
                    type += "unsigned";
                    break;
                    case 'm':
                    type += "unsigned long";
                    break;
                    case 'e':
                    type += "long double";
                    break;
                    case 's':
                    type += "short";
                    break;
                }
            }
            if(is_ptr) type += "*";
            type += ">";
        }
        else{
            for(size_t i{ind+1} ; i < tmplt.size(); i++){
                type += tmplt[i];
            }
        }
    }
    else{
        size_t ind{0};
        if(is_ptr) ind++;
        if(is_const) ind++;
        switch(tmplt[ind]){
            case 'i':
            type = "int";
            break;
            case 'c':
            type = "char";
            break;
            case 'f':
            type = "float";
            break;
            case 'd':
            type = "double";
            break;
            case 'l':
            type = "long";
            break;
            case 'j':
            type = "unsigned";
            break;
            case 'm':
            type = "unsigned long";
            break;
            case 'e':
            type = "long double";
            break;
            case 's':
            type = "short";
            break;
        }
    }
    if(is_const) type = "const " + type + "*";
    else if(is_ptr) type += "*";
//    std::cout << type << std::endl;
    return type;
}
#endif