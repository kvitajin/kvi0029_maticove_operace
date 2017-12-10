

#ifndef SEM_2_OUT_H
#define SEM_2_OUT_H
char        whereToSaveFinalSolution();
void        terminalFinalSolution   ();
void        fileFinalCSVSolution    (std::string &out, std::string &outFilename);
void        fileFinalHTMLSolution   (std::string &out, std::string &outFilename);
void        prepareString           (std::string &out,
                                     char where,
                                     int what,
                                     long int &determ,
                                     std::vector<std::vector<double> > &triangle,
                                     std::vector<double> &roots);

#endif //SEM_2_OUT_H
