
#include "funkce.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>

char    whereToSaveFinalSolution(){
    char tmp;
    std::cout   <<  "================================="<< std::endl;
    std::cout   <<  "Kde chcete vysledek?"<< std::endl;
    std::cout   <<  "T - terminal"<< std::endl;
    std::cout   <<  "C - pro .csv soubor"<< std::endl;
    std::cout   <<  "H - pro .html soubor"<< std::endl;
    std::cout   <<  "================================="<< std::endl;
    std::cin    >>  tmp;
    if (std::cin.fail()){
        return 'X';
    }
    else if (tmp=='T'   ||  tmp=='t'){
        return 'T';
    }
    else if (tmp=='C'   ||  tmp=='c'){
        return 'C';
    }
    else if (tmp=='H'   ||  tmp=='h') {
        return 'H';
    }else{
        return 'X';
    }
}


void    prepareString           (std::string &out,
                                 char where,
                                 int what,
                                 long int &determ,
                                 std::vector<std::vector<double> > &triangle,
                                 std::vector<std::vector<double> > &matrix,
                                 std::vector<double> &roots){
    //std::cout   <<  std::setprecision(2);
    std::stringstream str;
    str<<std::setprecision(2);
    if (where=='C'){                        ///CSV branch
        if (what==1 || what==3 || what==5 ||what==7){
            for (int i = 0; i < matrix.size(); ++i) {
                for (int j = 0; j < matrix.size()+1; ++j) {
                    str <<  triangle[i][j]  <<  "\t";
                    if (j==matrix.size()-1){
                        str <<  "|\t";
                    }
                }
                str <<   "\n";
            }
        }
        if (what==2 || what==3 || what==6 || what==7){
            //out+="Determinant= ";
            str <<  determ  <<  "\n";
        }
        if (what==4 || what==5 || what==6 || what==7){
            auto g=(int)roots.size();
            int i;
            char tmp;
            //out+="Koreny: ";
            for (int k = 0; k < g+1; ++k) {
                i=('a'+k);
                tmp= char(i);
                //std::cout <<    tmp<<std::endl<<std::endl;
                str <<  tmp <<  "= "    <<  roots[g-k]  <<  "\n";
            }
        }
    }
    else if (where=='H'){
        str <<  std::setprecision(3);
        str <<  "<!DOCTYPE html>\n"
                "<html lang=\"cs\" dir=\"ltr\">\n"
                "  <head>\n"
                "    <meta charset=\"UTF-8\">\n"
                "    <title>Vypocty nad maticemi</title>\n"
                "  </head>\n"
                "  <body>\n";
        if (what==1 || what==3 || what==5 ||what==7) {
            str << "<h3>Trojuhelnikovy tvar matice:</h3>\n";
            str <<   "<table style=\"width:42%\"><h4>";

            for (int i = 0; i < triangle.size(); ++i) {
                str << "<tr>";
                for (int j = 0; j < triangle.size() + 1; ++j) {
                    str << "<th>" << triangle[i][j] << "</th>";
                    if (j == triangle.size() - 1) {
                        str << "<th>" << "| " << "</th>";
                    }
                }
                str << "</tr>\n";
            }
            str << "</table>\n";
        }
            if (what==2 || what==3 || what==6 || what==7){
                str <<  "</h4><h3>Determinant= " <<  determ  <<  "</h3><h4>";
            }
            if (what==4 || what==5 || what==6 || what==7){
                auto g=(int)roots.size();
                int i;
                char tmp;
                str<<"</h4><h3>Koreny: </h3><h4>";
                for (int k = 0; k < g+1; ++k) {
                    i=('a'+k);
                    tmp= char(i);
                    //std::cout <<    tmp<<std::endl<<std::endl;
                    str <<std::fixed<<  tmp <<  "= "    <<  roots[g-k]  <<  "</br>\n";
                }
            }
        str <<  "</h4></body></html>";


    } else{
        if (what==1 || what==3 || what==5 ||what==7){
            out="Trojuhelnikovy tvar matice:\n";
            for (int i = 0; i < matrix.size(); ++i) {
                for (int j = 0; j < matrix.size()+1; ++j) {
                    str <<  triangle[i][j]  <<  "\t\t";
                    if (j==matrix.size()-1){
                        str <<  "|\t";
                    }
                }
                str <<  "\n";
            }
        }
        if (what==2 || what==3 || what==6 || what==7){
            str <<  "Determinant= " <<  determ  <<  "\n";
        }
        if (what==4 || what==5 || what==6 || what==7){
            auto g=(int)roots.size();
            char tmp;
            int i;
            str <<  std::fixed  <<  std::setprecision(3)    <<  "Koreny: \n";
            for (int k = 0; k < g+1; ++k) {
                i=('a'+k);
                tmp= char(i);
                //std::cout <<    tmp<<std::endl<<std::endl;
                str <<  tmp <<  "= "    <<  roots[g-k]  <<  "\n";
            }
        }
    }
    out=str.str();
}



int makeFinalSolution           (std::string &out,
                                 std::string outFileName,
                                 char where){
    if(where=='C'){
        outFileName+=".csv";
    }
    else if (where=='H'){
        outFileName+=".html";
        }
    std::ofstream ofs;
    ofs.open(outFileName.c_str());
    if (ofs){
        ofs <<  out;
        ofs.close();
        return 0;
    } else{
        std::cout   <<  "Nepovedlo se zapsat"   <<  std::endl;
        return 1;
    }
}

