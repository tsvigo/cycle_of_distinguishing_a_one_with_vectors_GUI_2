// cycle_of_distinguishing_a_one_with_vectors_GUI_2
#include "dialog.h"
#include "ui_dialog.h"
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// \brief Dialog::Dialog
/// \param parent
#include <QTextStream>
#include <QFile>
#include <fstream>

#include <iostream>
using namespace std;
#include <QFileDialog>
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
QString    Nazvaniye_fayla_s_neyronami_i_signalom="";
long long variable_error;
int var ;
int variable_synapse_index_counter=0;
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
Dialog::Dialog(QWidget *parent)
     : QDialog(parent)
     , ui(new Ui::Dialog)
     {
          ui->setupUi(this);
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////    
          // выведем название программы
           std::cout << "  cycle_of_distinguishing_a_one_with_vectors_GUI_2 " << std::endl;
        
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//QString firstLine;
//QFile file("/home/viktor/my_projects_qt_2/Funktsiya_Resheniya_2/название файла с нейронами и сигналами.txt");
//if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
//    QTextStream in(&file);
//    firstLine = Nazvaniye_fayla_s_neyronami_i_signalom=in.readLine();
//    file.close();
//} else {
//    // Обработка ошибки открытия файла
//}    
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//QString filePath = QFileDialog::getOpenFileName(this, tr("Выберите файл txt"),
// //QDir::homePath()
// "/home/viktor/my_projects_qt_2/Sgenerirovannye_fayly/Edinitsy_iz_shriftov_posle_pereustanovki_Debiana/"
// , tr("Все файлы txt (*.txt)"));
//if (!filePath.isEmpty()) {
//    // filePath содержит полный путь выбранного файла
//    Nazvaniye_fayla_s_neyronami_i_signalom=filePath;
//}

Nazvaniye_fayla_s_neyronami_i_signalom="/home/viktor/my_scripts_4/kraynie_znacheniya/neyrony_0.txt";
//"/home/viktor/my_scripts_4/kraynie_znacheniya/neyrony_2147483647.txt";

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  /// Читает нейроны и сигнал из файла в вектор.
    std::ifstream is(
          Nazvaniye_fayla_s_neyronami_i_signalom.toUtf8().constData()
        );
    std::istream_iterator<unsigned long long> start(is), end;
    std::vector<unsigned long long> list_of_neurons(start, end);
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
   /// читает синапсы из файла в вектор
    std::ifstream is2(
   //   "/home/viktor/my_projects_qt_2/Funktsiya_Resheniya_2/synapses.txt"
     "/home/viktor/my_scripts_4/kraynie_znacheniya/sinapsy_2147483647.txt"
   // "/home/viktor/my_scripts_4/kraynie_znacheniya/sinapsy_1.txt"
    );
    std::istream_iterator<unsigned long long> start2(is2), end2;
    std::vector<unsigned long long> list_of_synapses(start2, end2);
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// считаем ошибку
list_of_neurons[200]=list_of_neurons[200]-1073741923; // поправка
variable_error     =   1073741824-list_of_neurons[200] ;
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
    if 
        (list_of_neurons[200]<=1073741824 ) 
    {ui->label->setText("Программа считает что это 1.");} 
    else {        ui->label->setText("Программа считает что это не 1.");    } 
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    if (variable_error<=0) // тут видимо надо менять на если ошибка = или > то на выход то есть ошибка пропадает если становится > 0
        goto d;
  std::cout << "variable_error = " << variable_error<< std::endl;
     std::cout << "Variable error = 1073741824-list_of_neurons[200] = " << 1073741824-list_of_neurons[200]<< std::endl;
    std::cout << "list_of_neurons[200]  = " << list_of_neurons[200]  << std::endl; 
 b:
////////////////////////////////////////////// Solution function ////////////////////////////////////////////////////////////
    for ( var = 100; var < 200; ++var) // This is the range of neurons
    {
        for (int neuron_index = 0, synapse_index = 0;   neuron_index < 200, synapse_index < 10100;   ++neuron_index, synapse_index = synapse_index + 100)
        
        {
            
            list_of_neurons[var]=list_of_neurons[var]+  (list_of_neurons[neuron_index]/ list_of_synapses[synapse_index]);    
        } // складываем нейроны
    }
// вычисляем последний решающий нейрон:
    for (int   neuron_index = 100, synapse_index = 10000; neuron_index < 200;   ++neuron_index, ++synapse_index)
    {
        list_of_neurons[200] = list_of_neurons[200] + (list_of_neurons[neuron_index] / list_of_synapses[synapse_index]);
    }
// считаем ошибку:
     variable_error     =   1073741824-list_of_neurons[200] ;    
//
    if (variable_error<=0) // to the exit
        goto c;
//
    if (list_of_synapses[10100]==1) // to the exit
    {
        std::cout << "The values of all synapses are minimal and equal to 1." << std::endl;
        goto d;
    }
    // 115 строка     
 e:
    if (list_of_synapses[variable_synapse_index_counter] >1)
        list_of_synapses[variable_synapse_index_counter]  =  list_of_synapses[variable_synapse_index_counter]-1;
    //     
    // 
    if (list_of_synapses[variable_synapse_index_counter] ==1)
    {
        variable_synapse_index_counter = variable_synapse_index_counter+1;
        goto e;
    }
    //
    if (variable_synapse_index_counter<10100)
        variable_synapse_index_counter=variable_synapse_index_counter+1;
        // c начала вычитаем по 1 int variable_synapse_index_counter=0;
    else
        variable_synapse_index_counter=0;
        
         goto b;
         
                  
               
 c:
     std::cout << "The error has disappeared. Variable error = " << variable_error<< std::endl;
    std::cout << "list_of_neurons[200] = " << list_of_neurons[200]<< std::endl;
 ;;    
 d:
 // записываем синапсы:
     fstream file2;
    file2.open("/home/viktor/my_projects_qt_2/Funktsiya_Resheniya_2/synapses.txt",ios_base::out);
    
    vector<unsigned long long>::iterator itr;
    
    for(itr=list_of_synapses.begin();itr!=list_of_synapses.end();itr++)
    {
        file2<<*itr<<endl;
    }
    
    file2.close();
 ;;
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
    std::cout << "The error has disappeared. Variable error = " << variable_error<< ". Это выход. "<<std::endl;
            std::cout << "list_of_neurons[200] = " << list_of_neurons[200]<< std::endl; 
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
    if 
        (list_of_neurons[200]>=1073741824 ) 
    {ui->label->setText("Программа считает что это 1.");} 
    else {        ui->label->setText("Программа считает что это не 1.");    } 
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
       // надо записать название файла с сигналоми нейронами в файл
/*----------------------------------------------------------------------------------------------------------------------*/
QFile file3("/home/viktor/my_projects_qt_2/Funktsiya_Resheniya_2/название файла с нейронами и сигналами.txt");
// самый новый файл с нейронами и сигналами записываем
if (!file3.open(QIODevice::WriteOnly | QIODevice::Text))
    return;
QTextStream out(&file3);
out << Nazvaniye_fayla_s_neyronami_i_signalom;
file3.close();
/*----------------------------------------------------------------------------------------------------------------------*/
    
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////     
     }

Dialog::~Dialog()
     {
          delete ui;
     }

