#include "procedures.h"
#include "math.h"
#include "wchar.h"
#include "stdio.h"

#define GetSize(arreglo) static_cast<int>(sizeof(&arreglo)/sizeof(*(arreglo)))

using namespace std;

static int noCommand = 0;
static QStringList disk;
static QStringList letters;
static QList<int> counts;
static QStringList mounts;

void Procedures::clearProcedures()
{
    noCommand=0;
}

void Procedures::writeLine(QString text)
{
    int size = 72 - text.length()%72;

    for (int i =0 ;i < size;i++)
        text.append(' ');

    QStringList lines;

    for (int i=0;i<text.length();i=i+72)
        lines.append(text.mid(i,72));


    for (int i=0;i<lines.length();i++) {
        IOConsole::writeLine("        " + lines[i].toUtf8(),IOConsole::BGBLACK,IOConsole::NORMAL);
    }
}
void Procedures::writeError(QString text)
{
    text = "ERROR: " + text;
    int size = 72 - text.length()%72;

    for (int i =0 ;i < size;i++)
        text.append(' ');

    QStringList lines;

    for (int i=0;i<text.length();i=i+72)
        lines.append(text.mid(i,72));

    for (int i=0;i<lines.length();i++) {
        IOConsole::writeLine("        " + lines[i].toUtf8(),IOConsole::BGRED,IOConsole::FLASHING);
    }
}
void Procedures::writeCommand(QString text)
{
    if(noCommand<9)
        IOConsole::writeLine(QString::number(++noCommand) + ". Instrucción a ejecutar:                                                      ", IOConsole::BGBLUE, IOConsole::YELLOW);
    else if(noCommand<99)
        IOConsole::writeLine(QString::number(++noCommand) + ". Instrucción a ejecutar:                                                     ", IOConsole::BGBLUE, IOConsole::YELLOW);
    else if(noCommand<999)
        IOConsole::writeLine(QString::number(++noCommand) + ". Instrucción a ejecutar:                                                    ", IOConsole::BGBLUE, IOConsole::YELLOW);
    else if(noCommand<9999)
        IOConsole::writeLine(QString::number(++noCommand) + ". Instrucción a ejecutar:                                                   ", IOConsole::BGBLUE, IOConsole::YELLOW);
    else if(noCommand<99999)
        IOConsole::writeLine(QString::number(++noCommand) + ". Instrucción a ejecutar:                                                  ", IOConsole::BGBLUE, IOConsole::YELLOW);

    int size= 72 - text.length()%72;

    for (int i =0 ;i < size;i++)
        text.append(' ');

    QStringList lines;

    for (int i=0;i<text.length();i=i+72)
        lines.append(text.mid(i,72));

    for (int i=0;i<lines.length();i++) {
        IOConsole::writeLine("        " + lines[i].toUtf8(), IOConsole::BGBLUE, IOConsole::NORMAL);
    }
}

void Procedures::createFile(QString path,int size,QString unit)
{
    char KB[1024];
    char MB[1024*1024];

    ifstream exist(path.toUtf8(),ios::in);

    if(!exist.good())
    {
        QStringList extension = path.split('.',QString::SkipEmptyParts);

        ofstream file( path.toUtf8() , ios::out | ios::binary);

        writeLine("Creando el disco espere...");

        if(unit==""||unit.toUpper()=="M")
            for (int i=0;i<size;i++)
                file.write(reinterpret_cast<char*>(&MB),sizeof(MB));
        else if(unit.toUpper()=="K")
            for (int i=0;i<size;i++)
                file.write(reinterpret_cast<char*>(&KB),sizeof(KB));

        file.close();
        writeLine("se creo el disco con éxito" );

        setMBR(path, createMBR(size,unit),0);
    }
    else
    {
        exist.close();
        writeError("Disco ya existe en la ubicación");
    }
}
void Procedures::deleteFile(QString path)
{
    if(remove(path.toUtf8())!=0)
        writeError("Disco no existe en la ubicación");
    else
        writeLine("se elimino el disco con éxito" );
}

MBR Procedures::createMBR(int size, QString unit)
{
    MBR retorno;
    PARTITION nula;
    nula.part_status = '0';
    nula.part_type = '0';
    nula.part_fit = '0';
    nula.part_start = 0;
    nula.part_size = 0;
    for (int i=0;i<16;i++)
        nula.part_name[i]='\0';

    if(unit==""||unit.toUpper()=="M")
        retorno.mbr_tamano = size*1024*1024;
    else if(unit.toUpper()=="K")
        retorno.mbr_tamano = size*1024;

    retorno.mbr_fecha_creacion = time(nullptr);

    srand(static_cast<unsigned int>(time(nullptr)));
    retorno.mbr_disk_signature = qrand();

    retorno.mbr_partition_1 = nula;
    retorno.mbr_partition_2 = nula;
    retorno.mbr_partition_3 = nula;
    retorno.mbr_partition_4 = nula;

    return retorno;
}
void Procedures::setMBR(QString path, MBR mbr,int pos)
{
    ifstream exist(path.toUtf8(),ios::in);

    if(exist.good())
    {

        ofstream file( path.toUtf8(), ios::in | ios::out | ios::binary);


        writeLine("Insertando el MBR espere...");

        file.seekp(pos);
        file.write(reinterpret_cast<char*>(&mbr),sizeof(MBR));
        file.close();
        exist.close();
        writeLine("se inserto el MBR con éxito");
    }
    else
        writeError("Disco no existe en la ubicación");
}
MBR Procedures::getMBR(QString path,int pos){
    MBR retorno;
    ifstream file(path.toUtf8());
    if(file.is_open())
    {
        file.seekg(pos,ios::beg);
        file.read(reinterpret_cast<char*>(&retorno),sizeof(MBR));
        file.close();
    }
    return retorno;
}

void Procedures::setEBR(QString path, EBR ebr,int pos){
    ifstream exist(path.toUtf8(),ios::in);

    if(exist.good())
    {
        ofstream file( path.toUtf8() , ios::in | ios::out | ios::binary);

        writeLine("Insertando el EBR espere...");

        file.seekp(pos);
        file.write(reinterpret_cast<char*>(&ebr),sizeof(EBR));

        file.close();
        exist.close();

        writeLine("se inserto el EBR con éxito");
    }
    else
        writeError("Disco no existe en la ubicación");
}
EBR Procedures::getEBR(QString path,int pos){
    EBR retorno;
    ifstream file(path.toUtf8());
    if(file.is_open())
    {
        file.seekg(pos,ios::beg);
        file.read(reinterpret_cast<char*>(&retorno),sizeof(EBR));
        file.close();
    }
    return retorno;
}

void Procedures::createDirectory(QString path)
{
    QStringList Directorys = path.split('/',QString::SkipEmptyParts);

    QString command;
    QString directorio="";
    DIR *dir;

    for (int i=0;i<Directorys.count()-1;i++)
    {
        if(i!=0)
        {

            directorio += "/" + Directorys.at(i);

            dir = opendir(directorio.toUtf8());

            if(!dir)
            {
                command = "mkdir \'" + directorio + "\'";
                system(command.toUtf8().constData());
                command = "chown victorsdb \'" + directorio + "\'";
                system(command.toUtf8().constData());
            }
        }
        else
        {
            if(path.at(0)=='/')
                directorio = "/"+Directorys.at(i);
            else
                directorio = Directorys.at(i);

            dir = opendir(directorio.toUtf8());

            if(!dir)
            {
                command = "mkdir \'" + directorio + "\'";
                system(command.toUtf8().constData());
                command = "chown victorsdb \'" + directorio + "\'";
                system(command.toUtf8().constData());
            }
        }
    }
}
char* Procedures::generate_mbr_fecha_creacion(time_t mbr_fecha_creacion)
{
    struct tm *tm;
    char* fecha_hora = new char[100];
    tm = localtime(&mbr_fecha_creacion);
    strftime(fecha_hora,100,"%d/%m/%Y %H:%M:%S",tm);
    return fecha_hora;
}

void Procedures::createPartition(int size, QString unit, QString path, QString type, QString fit, QString name)
{
    bool insert = false;
    bool extend = false;

    PARTITION partition;

    partition.part_status='1';

    if (type=="" || type.toUpper()=="P")
        partition.part_type='P';
    else if (type.toUpper()=="E")
        partition.part_type='E';
    else if (type.toUpper()=="L")
        partition.part_type='L';

    if (fit.toUpper()=="BF")
        partition.part_fit='B';
    else if (fit.toUpper()=="FF")
        partition.part_fit='F';
    else if (fit=="" || fit.toUpper()=="WF")
        partition.part_fit='W';

    if (unit.toUpper()=="B")
        partition.part_size = size;
    else if(unit=="" || unit.toUpper()=="K")
        partition.part_size = size*1024;
    else if(unit.toUpper()=="M")
        partition.part_size = size*1024*1024;

    for (int i=0;i<16;i++)
        if(i<name.size())
            partition.part_name[i] = name.at(i).toLatin1();
        else
            partition.part_name[i] = '\0';

    MBR tmp = getMBR(path.toUtf8(),0);

    switch(partition.part_type)
    {
    case 'P':
        insert = putPartitionPrincipal(tmp,partition,path);
        break;
    case 'E':
    {

        if(tmp.mbr_partition_1.part_status=='1' && tmp.mbr_partition_1.part_type=='E')
            extend = true;
        if(tmp.mbr_partition_2.part_status=='1' && tmp.mbr_partition_2.part_type=='E')
            extend = true;
        if(tmp.mbr_partition_3.part_status=='1' && tmp.mbr_partition_3.part_type=='E')
            extend = true;
        if(tmp.mbr_partition_4.part_status=='1' && tmp.mbr_partition_4.part_type=='E')
            extend = true;


        if(!extend)
            insert = putPartitionPrincipal(tmp,partition,path);
        else
            writeError("Ya existe una partición Extendida");

    }
        break;
    case 'L':
    {
        EBR ebr;

        ebr.part_status='1';

        if (fit.toUpper()=="BF")
            ebr.part_fit='B';
        else if (fit.toUpper()=="FF")
            ebr.part_fit='F';
        else if (fit=="" || fit.toUpper()=="WF")
            ebr.part_fit='W';

        if (unit.toUpper()=="B")
            ebr.part_size = size;
        else if(unit=="" || unit.toUpper()=="K")
            ebr.part_size = size*1024;
        else if(unit.toUpper()=="M")
            ebr.part_size = size*1024*1024;

        for (int i=0;i<16;i++)
            if(i<name.size())
                ebr.part_name[i] = name.at(i).toLatin1();
            else
                ebr.part_name[i] = '\0';

        insert = putPartitionLogical(tmp,ebr,path);
    }
        break;
    default:
        break;
    }

    if(insert)
        writeLine("Se creo la partición "+name+" con éxito");
    else
        writeError("No se logro crear la partición "+ name);
}
bool Procedures::addPartition(QString unit, QString path, QString name, int add)
{
    writeLine("llego a agregar");
    MBR mbr = getMBR(path,0);

    EBR nulo;
    nulo.part_fit = '\0';
    nulo.part_next = 0;
    nulo.part_size = 0;
    nulo.part_start = 0;
    nulo.part_status = '\0';
    for (int i=0;i<16;i++)
        nulo.part_name[i]='\0';

    int fin;
    int agregar = 0;

    if(unit.toUpper()=="B")
        agregar = add;
    else if(unit.toUpper()=="K" || unit.toUpper()=="")
        agregar = add * 1024 ;
    else if(unit.toUpper()=="M")
        agregar = add * 1024 * 1024;

    if(mbr.mbr_partition_1.part_name==name)
    {
        fin= mbr.mbr_partition_1.part_size+mbr.mbr_partition_1.part_start + agregar - 1;

        if(agregar > 0)
        {
            if(mbr.mbr_partition_2.part_status == '1')
            {
                if(fin<mbr.mbr_partition_2.part_start)
                {
                    mbr.mbr_partition_1.part_size += agregar;
                    setMBR(path,mbr,0);
                    writeLine("Se agrego correctamente la cantidad en la partición");
                    return true;
                }
                else
                {
                    writeError("No se puede agregar esa cantidad en la partición");
                    return false;
                }
            }
            else
            {
                if(fin < mbr.mbr_tamano)
                {
                    mbr.mbr_partition_1.part_size += agregar;
                    setMBR(path,mbr,0);
                    writeLine("Se agrego correctamente la cantidad en la partición");
                    return true;
                }
                else
                {
                    writeError("No se puede agregar esa cantidad en la partición");
                    return false;
                }
            }
        }
        else
        {
            if((mbr.mbr_partition_1.part_size + agregar)>=0)
            {
                mbr.mbr_partition_1.part_size += agregar;
                setMBR(path,mbr,0);
                writeLine("Se quito correctamente la cantidad en la partición");
                return true;
            }
            else
            {
                writeError("No se puede eliminar esa cantidad en la partición");
                return false;
            }
        }
    }

    if(mbr.mbr_partition_2.part_name==name)
    {
        fin= mbr.mbr_partition_2.part_size+mbr.mbr_partition_2.part_start + agregar - 1;

        if(agregar > 0)
        {
            if(mbr.mbr_partition_3.part_status == '1')
            {
                if(fin<mbr.mbr_partition_3.part_start)
                {
                    mbr.mbr_partition_2.part_size += agregar;
                    setMBR(path,mbr,0);
                    writeLine("Se agrego correctamente la cantidad en la partición");
                    return true;
                }
                else
                {
                    writeError("No se puede agregar esa cantidad en la partición");
                    return false;
                }
            }
            else
            {
                if(fin < mbr.mbr_tamano)
                {
                    mbr.mbr_partition_2.part_size += agregar;
                    setMBR(path,mbr,0);
                    writeLine("Se agrego correctamente la cantidad en la partición");
                    return true;
                }
                else
                {
                    writeError("No se puede agregar esa cantidad en la partición");
                    return false;
                }
            }
        }
        else
        {
            if((mbr.mbr_partition_2.part_size + agregar)>=0)
            {
                mbr.mbr_partition_2.part_size += agregar;
                setMBR(path,mbr,0);
                writeLine("Se quito correctamente la cantidad en la partición");
                return true;
            }
            else
            {
                writeError("No se puede eliminar esa cantidad en la partición");
                return false;
            }
        }
    }

    if(mbr.mbr_partition_3.part_name==name)
    {
        fin= mbr.mbr_partition_3.part_size+mbr.mbr_partition_3.part_start + agregar - 1;

        if(agregar > 0)
        {
            if(mbr.mbr_partition_4.part_status == '1')
            {
                if(fin<mbr.mbr_partition_4.part_start)
                {
                    mbr.mbr_partition_3.part_size += agregar;
                    setMBR(path,mbr,0);
                    writeLine("Se agrego correctamente la cantidad en la partición");
                    return true;
                }
                else
                {
                    writeError("No se puede agregar esa cantidad en la partición");
                    return false;
                }
            }
            else
            {
                if(fin < mbr.mbr_tamano)
                {
                    mbr.mbr_partition_3.part_size += agregar;
                    setMBR(path,mbr,0);
                    writeLine("Se agrego correctamente la cantidad en la partición");
                    return true;
                }
                else
                {
                    writeError("No se puede agregar esa cantidad en la partición");
                    return false;
                }
            }
        }
        else
        {
            if((mbr.mbr_partition_3.part_size + agregar)>=0)
            {
                mbr.mbr_partition_3.part_size += agregar;
                setMBR(path,mbr,0);
                writeLine("Se quito correctamente la cantidad en la partición");
                return true;
            }
            else
            {
                writeError("No se puede eliminar esa cantidad en la partición");
                return false;
            }
        }
    }

    if(mbr.mbr_partition_4.part_name==name)
    {
        fin= mbr.mbr_partition_4.part_size+mbr.mbr_partition_4.part_start + agregar - 1;

        if(agregar > 0)
        {
            if(fin < mbr.mbr_tamano)
            {
                mbr.mbr_partition_3.part_size += agregar;
                setMBR(path,mbr,0);
                writeLine("Se agrego correctamente la cantidad en la partición");
                return true;
            }
            else
            {
                writeError("No se puede agregar esa cantidad en la partición");
                return false;
            }

        }
        else
        {
            if((mbr.mbr_partition_4.part_size + agregar)>=0)
            {
                mbr.mbr_partition_4.part_size += agregar;
                setMBR(path,mbr,0);
                writeLine("Se quito correctamente la cantidad en la partición");
                return true;
            }
            else
            {
                writeError("No se puede eliminar esa cantidad en la partición");
                return false;
            }
        }
    }

    int inicio = -1;
    int final = -1;

    EBR tmp = nulo;


    if(mbr.mbr_partition_1.part_status=='1' && mbr.mbr_partition_1.part_type=='E')
    {
        inicio = mbr.mbr_partition_1.part_start;
        final = mbr.mbr_partition_1.part_start + mbr.mbr_partition_1.part_size;
    }
    if(mbr.mbr_partition_2.part_status=='1' && mbr.mbr_partition_2.part_type=='E')
    {
        inicio = mbr.mbr_partition_2.part_start;
        final = mbr.mbr_partition_2.part_start + mbr.mbr_partition_2.part_size;
    }
    if(mbr.mbr_partition_3.part_status=='1' && mbr.mbr_partition_3.part_type=='E')
    {
        inicio = mbr.mbr_partition_3.part_start;
        final = mbr.mbr_partition_3.part_start + mbr.mbr_partition_3.part_size;
    }
    if(mbr.mbr_partition_4.part_status=='1' && mbr.mbr_partition_4.part_type=='E')
    {
        inicio = mbr.mbr_partition_4.part_start;
        final = mbr.mbr_partition_4.part_start + mbr.mbr_partition_4.part_size;
    }

    if(inicio!=-1)
    {
        int pos= inicio;
        tmp = getEBR(path.toUtf8(),pos);
        if( tmp.part_status != '\0')
        {
            do
            {
                if(tmp.part_name==name && tmp.part_status=='1')
                {
                    fin= tmp.part_size+tmp.part_start + agregar - 1;

                    if(agregar > 0)
                    {
                        if(fin < tmp.part_size)
                        {
                            tmp.part_size += agregar;
                            setEBR(path,tmp,tmp.part_start);
                            writeLine("Se agrego correctamente la cantidad en la partición");
                            return true;
                        }
                        else
                        {
                            writeError("No se puede agregar esa cantidad en la partición");
                            return false;
                        }
                    }
                    else
                    {
                        if((tmp.part_size + agregar)>=0)
                        {
                            tmp.part_size += agregar;
                            setEBR(path,tmp,tmp.part_start);
                            writeLine("Se quito correctamente la cantidad en la partición");
                            return true;
                        }
                        else
                        {
                            writeError("No se puede eliminar esa cantidad en la partición");
                            return false;
                        }
                    }
                }

                pos = tmp.part_next;
                tmp = nulo;
                if(pos!=-1)
                    tmp = getEBR(path.toUtf8(),pos);
            }
            while(tmp.part_status != '\0');

        }
    }
    writeError("No se pudo agregar o eliminar ya que no existe la partición");
    return false;
}
bool Procedures::deletePartition(QString path, QString del, QString name)
{
    MBR mbr = getMBR(path,0);

    PARTITION nula;
    nula.part_status = '0';
    nula.part_type = '0';
    nula.part_fit = '0';
    nula.part_start = 0;
    nula.part_size = 0;
    for (int i=0;i>16;i++)
        nula.part_name[i]='\0';

    EBR nulo;
    nulo.part_fit = '\0';
    nulo.part_next = -1;
    nulo.part_size = 0;
    nulo.part_start = 0;
    nulo.part_status = '\0';
    for (int i=0;i<16;i++)
        nulo.part_name[i]='\0';

    if(del.toUpper()=="FAST" || del.toUpper()=="FULL")
    {
        if(QString::fromLatin1(mbr.mbr_partition_1.part_name)==name)
        {
            mbr.mbr_partition_1 = mbr.mbr_partition_2;
            mbr.mbr_partition_2 = mbr.mbr_partition_3;
            mbr.mbr_partition_3 = mbr.mbr_partition_4;
            mbr.mbr_partition_4 = nula;
            setMBR(path,mbr,0);
            return true;
        }
        else if(QString::fromLatin1(mbr.mbr_partition_2.part_name)==name)
        {
            mbr.mbr_partition_2 = mbr.mbr_partition_3;
            mbr.mbr_partition_3 = mbr.mbr_partition_4;
            mbr.mbr_partition_4 = nula;
            setMBR(path,mbr,0);
            return true;
        }
        else if(QString::fromLatin1(mbr.mbr_partition_3.part_name)==name)
        {
            mbr.mbr_partition_3 = mbr.mbr_partition_4;
            mbr.mbr_partition_4 = nula;
            setMBR(path,mbr,0);
            return true;
        }
        else if(QString::fromLatin1(mbr.mbr_partition_4.part_name)==name)
        {
            mbr.mbr_partition_4 = nula;
            setMBR(path,mbr,0);
            return true;
        }

        int inicio = -1;
        int fin = -1;

        if(mbr.mbr_partition_1.part_status=='1' && mbr.mbr_partition_1.part_type=='E')
        {
            inicio = mbr.mbr_partition_1.part_start;
            fin = mbr.mbr_partition_1.part_start + mbr.mbr_partition_1.part_size;
        }
        if(mbr.mbr_partition_2.part_status=='1' && mbr.mbr_partition_2.part_type=='E')
        {
            inicio = mbr.mbr_partition_2.part_start;
            fin = mbr.mbr_partition_2.part_start + mbr.mbr_partition_2.part_size;
        }
        if(mbr.mbr_partition_3.part_status=='1' && mbr.mbr_partition_3.part_type=='E')
        {
            inicio = mbr.mbr_partition_3.part_start;
            fin = mbr.mbr_partition_3.part_start + mbr.mbr_partition_3.part_size;
        }
        if(mbr.mbr_partition_4.part_status=='1' && mbr.mbr_partition_4.part_type=='E')
        {
            inicio = mbr.mbr_partition_4.part_start;
            fin = mbr.mbr_partition_4.part_start + mbr.mbr_partition_4.part_size;
        }

        int pos = inicio;

        if(inicio!=-1)
        {
            pos= inicio;
            EBR tmp = getEBR(path,pos);
            EBR next = nulo;
            bool inicial = true;
            if( tmp.part_status != '\0')
            {
                do
                {
                    next = nulo;
                    if(tmp.part_next!=-1)
                        next = getEBR(path,tmp.part_next);

                    if(inicial)
                    {
                        if(QString::fromLatin1(tmp.part_name)==name && tmp.part_status=='1')
                        {
                            tmp.part_status = '0';
                            setEBR(path,tmp,tmp.part_start);
                            return true;
                        }
                        else if(QString::fromLatin1(next.part_name)==name && next.part_status=='1')
                        {
                            tmp.part_next = next.part_next;
                            setEBR(path,tmp,tmp.part_start);
                            return true;
                        }
                        inicial = false;
                    }
                    else
                    {
                        if(QString::fromLatin1(next.part_name)==name && next.part_status=='1')
                        {
                            tmp.part_next = next.part_next;
                            setEBR(path,tmp,tmp.part_start);
                            return true;
                        }
                    }

                    pos = tmp.part_next;
                    tmp = nulo;
                    if(pos!=-1)
                        tmp = getEBR(path,pos);
                }
                while(tmp.part_status != '\0');
            }
        }
    }
    return false;
}
bool Procedures::existPartition(QString name, QString path)
{
    ifstream exist(path.toUtf8(), ios::in);

    EBR nulo;
    nulo.part_fit = '\0';
    nulo.part_next = 0;
    nulo.part_size = 0;
    nulo.part_start = 0;
    nulo.part_status = '\0';
    for (int i=0;i<16;i++)
        nulo.part_name[i]='\0';

    if(exist.good())
    {
        MBR mbr = getMBR(path.toUtf8(),0);
        char nametmp[16];
        for (int i=0;i<16;i++)
            if(i<name.size())
                nametmp[i] = name.at(i).toLatin1();
            else
                nametmp[i] = '\0';

        if(mbr.mbr_partition_1.part_status=='1' && QString::fromLatin1(mbr.mbr_partition_1.part_name)==QString::fromLatin1(nametmp))
            return true;
        if(mbr.mbr_partition_2.part_status=='1' && QString::fromLatin1(mbr.mbr_partition_2.part_name)==QString::fromLatin1(nametmp))
            return true;
        if(mbr.mbr_partition_3.part_status=='1' && QString::fromLatin1(mbr.mbr_partition_3.part_name)==QString::fromLatin1(nametmp))
            return true;
        if(mbr.mbr_partition_4.part_status=='1' && QString::fromLatin1(mbr.mbr_partition_4.part_name)==QString::fromLatin1(nametmp))
            return true;

        int inicio = -1;
        int fin = -1;

        EBR tmp = nulo;


        if(mbr.mbr_partition_1.part_status=='1' && mbr.mbr_partition_1.part_type=='E')
        {
            inicio = mbr.mbr_partition_1.part_start;
            fin = mbr.mbr_partition_1.part_start + mbr.mbr_partition_1.part_size;
        }
        if(mbr.mbr_partition_2.part_status=='1' && mbr.mbr_partition_2.part_type=='E')
        {
            inicio = mbr.mbr_partition_2.part_start;
            fin = mbr.mbr_partition_2.part_start + mbr.mbr_partition_2.part_size;
        }
        if(mbr.mbr_partition_3.part_status=='1' && mbr.mbr_partition_3.part_type=='E')
        {
            inicio = mbr.mbr_partition_3.part_start;
            fin = mbr.mbr_partition_3.part_start + mbr.mbr_partition_3.part_size;
        }
        if(mbr.mbr_partition_4.part_status=='1' && mbr.mbr_partition_4.part_type=='E')
        {
            inicio = mbr.mbr_partition_4.part_start;
            fin = mbr.mbr_partition_4.part_start + mbr.mbr_partition_4.part_size;
        }

        if(inicio!=-1)
        {
            int pos= inicio;
            tmp = getEBR(path.toUtf8(),pos);
            if( tmp.part_status != '\0')
            {
                do
                {
                    if(tmp.part_status=='1'&&QString::fromLatin1(tmp.part_name)==QString::fromLatin1(nametmp))
                        return true;
                    pos = tmp.part_next;
                    tmp = nulo;
                    if(pos!=-1)
                        tmp = getEBR(path.toUtf8(),pos);
                }
                while(tmp.part_status != '\0');
            }
        }


    }
    else
        return false;

    return false;
}

bool Procedures::comprobateName(QString name, QString path)
{
    ifstream exist(path.toUtf8(), ios::in);

    EBR nulo;
    nulo.part_fit = '\0';
    nulo.part_next = 0;
    nulo.part_size = 0;
    nulo.part_start = 0;
    nulo.part_status = '\0';
    for (int i=0;i<16;i++)
        nulo.part_name[i]='\0';

    if(exist.good())
    {
        MBR mbr = getMBR(path.toUtf8(),0);
        char nametmp[16];
        for (int i=0;i<16;i++)
            if(i<name.size())
                nametmp[i] = name.at(i).toLatin1();
            else
                nametmp[i] = '\0';

        if(mbr.mbr_partition_1.part_status=='1' && QString::fromLatin1(mbr.mbr_partition_1.part_name)==QString::fromLatin1(nametmp))
            return false;
        if(mbr.mbr_partition_2.part_status=='1' && QString::fromLatin1(mbr.mbr_partition_2.part_name)==QString::fromLatin1(nametmp))
            return false;
        if(mbr.mbr_partition_3.part_status=='1' && QString::fromLatin1(mbr.mbr_partition_3.part_name)==QString::fromLatin1(nametmp))
            return false;
        if(mbr.mbr_partition_4.part_status=='1' && QString::fromLatin1(mbr.mbr_partition_4.part_name)==QString::fromLatin1(nametmp))
            return false;


        int inicio = -1;
        int fin = -1;

        EBR tmp = nulo;


        if(mbr.mbr_partition_1.part_status=='1' && mbr.mbr_partition_1.part_type=='E')
        {
            inicio = mbr.mbr_partition_1.part_start;
            fin = mbr.mbr_partition_1.part_start + mbr.mbr_partition_1.part_size;
        }
        if(mbr.mbr_partition_2.part_status=='1' && mbr.mbr_partition_2.part_type=='E')
        {
            inicio = mbr.mbr_partition_2.part_start;
            fin = mbr.mbr_partition_2.part_start + mbr.mbr_partition_2.part_size;
        }
        if(mbr.mbr_partition_3.part_status=='1' && mbr.mbr_partition_3.part_type=='E')
        {
            inicio = mbr.mbr_partition_3.part_start;
            fin = mbr.mbr_partition_3.part_start + mbr.mbr_partition_3.part_size;
        }
        if(mbr.mbr_partition_4.part_status=='1' && mbr.mbr_partition_4.part_type=='E')
        {
            inicio = mbr.mbr_partition_4.part_start;
            fin = mbr.mbr_partition_4.part_start + mbr.mbr_partition_4.part_size;
        }

        if(inicio!=-1)
        {
            int pos= inicio;
            tmp = getEBR(path.toUtf8(),pos);
            if( tmp.part_status != '\0')
            {
                do
                {
                    if(tmp.part_status=='1' && QString::fromLatin1(tmp.part_name)==QString::fromLatin1(nametmp))
                        return false;

                    pos = tmp.part_next;
                    tmp = nulo;
                    if(pos!=-1)
                        tmp = getEBR(path.toUtf8(),pos);
                }
                while(tmp.part_status != '\0');
            }
        }


    }
    else
        return false;

    return true;
}

bool Procedures::putPartitionPrincipal(MBR mbr,PARTITION partition,QString path)
{
    MBR tmp;

    PARTITION nula;
    nula.part_status = '0';
    nula.part_type = '0';
    nula.part_fit = '0';
    nula.part_start = 0;
    nula.part_size = 0;
    for (int i=0;i>16;i++)
        nula.part_name[i]='\0';

    bool EXITO = true;

    int inicio = static_cast<int>(sizeof(MBR));
    int fin = mbr.mbr_tamano-1;
    int FF=-1,BF=-1,WF=-1;

    int libres[5][3]={{-1,-1,-1},{-1,-1,-1},{-1,-1,-1},{-1,-1,-1},{-1,-1,-1}};

    int indice=0;

    //NOTE Determinando espacios libres en el disco.
    if(mbr.mbr_partition_1.part_status=='1')
    {
        if((mbr.mbr_partition_1.part_start-inicio)>0)
        {
            libres[indice][0]=inicio;
            libres[indice][1]=mbr.mbr_partition_1.part_start - inicio;
            libres[indice][2]= libres[indice][1] - partition.part_size ;
            indice++;
        }

        if(mbr.mbr_partition_2.part_status=='0')
        {
            if(mbr.mbr_partition_3.part_status=='0')
            {
                if(mbr.mbr_partition_4.part_status=='0')
                {
                    libres[indice][0]=mbr.mbr_partition_1.part_start + mbr.mbr_partition_1.part_size;
                    libres[indice][1]=fin-libres[indice][0];
                    libres[indice][2]= libres[indice][1] - partition.part_size ;
                    indice++;
                }
                else
                {
                    libres[indice][0]=mbr.mbr_partition_1.part_start + mbr.mbr_partition_1.part_size;
                    libres[indice][1]=mbr.mbr_partition_4.part_start-libres[indice][0];
                    libres[indice][2]= libres[indice][1] - partition.part_size ;
                    indice++;
                }
            }
            else
            {
                libres[indice][0]=mbr.mbr_partition_1.part_start + mbr.mbr_partition_1.part_size;
                libres[indice][1]=mbr.mbr_partition_3.part_start-libres[indice][0];
                libres[indice][2]= libres[indice][1] - partition.part_size ;
                indice++;
            }
        }
        else
        {
            libres[indice][0]= mbr.mbr_partition_1.part_start + mbr.mbr_partition_1.part_size;
            libres[indice][1]= mbr.mbr_partition_2.part_start-libres[indice][0];
            libres[indice][2]= libres[indice][1] - partition.part_size ;
            indice++;
        }
    }else
    {
        if(mbr.mbr_partition_2.part_status=='0')
        {
            if(mbr.mbr_partition_3.part_status=='0')
            {
                if(mbr.mbr_partition_4.part_status=='0')
                {
                    libres[indice][0]=inicio;
                    libres[indice][1]=fin - inicio;
                    libres[indice][2]= libres[indice][1] - partition.part_size ;
                    indice++;
                }
                else
                {
                    libres[indice][0]=inicio;
                    libres[indice][1]=mbr.mbr_partition_4.part_start - inicio;
                    libres[indice][2]= libres[indice][1] - partition.part_size ;
                    indice++;
                }
            }
            else
            {
                libres[indice][0]=inicio;
                libres[indice][1]=mbr.mbr_partition_3.part_start - inicio;
                libres[indice][2]= libres[indice][1] - partition.part_size ;
                indice++;
            }
        }
        else
        {
            libres[indice][0]=inicio;
            libres[indice][1]=mbr.mbr_partition_2.part_start - inicio;
            libres[indice][2]= libres[indice][1] - partition.part_size ;
            indice++;
        }
    }

    if(mbr.mbr_partition_2.part_status=='1')
    {
        if(mbr.mbr_partition_3.part_status=='0')
        {
            if(mbr.mbr_partition_4.part_status=='0')
            {
                libres[indice][0]=mbr.mbr_partition_2.part_start + mbr.mbr_partition_2.part_size;
                libres[indice][1]=fin-libres[indice][0];
                libres[indice][2]= libres[indice][1] - partition.part_size ;
                indice++;
            }
            else
            {
                libres[indice][0]=mbr.mbr_partition_2.part_start + mbr.mbr_partition_2.part_size;
                libres[indice][1]=mbr.mbr_partition_4.part_start-libres[indice][0];
                libres[indice][2]= libres[indice][1] - partition.part_size ;
                indice++;
            }
        }
        else
        {
            libres[indice][0]=mbr.mbr_partition_2.part_start + mbr.mbr_partition_2.part_size;
            libres[indice][1]=mbr.mbr_partition_3.part_start-libres[indice][0];
            libres[indice][2]= libres[indice][1] - partition.part_size ;
            indice++;
        }
    }


    if(mbr.mbr_partition_3.part_status=='1')
    {
        if(mbr.mbr_partition_4.part_status=='0')
        {
            libres[indice][0]=mbr.mbr_partition_3.part_start + mbr.mbr_partition_3.part_size;
            libres[indice][1]=fin-libres[indice][0];
            libres[indice][2]= libres[indice][1] - partition.part_size ;
            indice++;
        }
        else
        {
            libres[indice][0]= mbr.mbr_partition_3.part_start + mbr.mbr_partition_3.part_size;
            libres[indice][1]= mbr.mbr_partition_4.part_start-libres[indice][0];
            libres[indice][2]= libres[indice][1] - partition.part_size ;
            indice++;
        }
    }


    if(mbr.mbr_partition_4.part_status=='1')
    {
        libres[indice][0]= mbr.mbr_partition_4.part_start + mbr.mbr_partition_4.part_size;
        libres[indice][1]= fin-libres[indice][0];
        libres[indice][2]= libres[indice][1] - partition.part_size ;
        indice++;
    }


    //NOTE Determinando la posición FF
    for (int i=0;i<5;i++)
    {
        if(libres[i][2]>=0)
        {
            FF = i;
            break;
        }
    }
    //NOTE Determinando la posición BF
    for (int i=0;i<5;i++)
    {
        if(BF!=-1)
        {
            if(libres[i][2]>0 && libres[i][2] < libres[BF][2] )
                BF = i;
        }
        else
        {
            if(libres[i][2]>=0 )
                BF = i;
        }
    }
    //NOTE Determinando la posición WF
    for (int i=0;i<5;i++)
    {
        if(WF!=-1)
        {
            if(libres[i][2]>0 && libres[i][2] > libres[WF][2] )
                WF = i;
        }
        else
        {
            if(libres[i][2]>=0 )
                WF = i;
        }
    }

    int AJUSTE=-1;
    //NOTE Determinando el Fit del Ajuste
    switch (partition.part_fit)
    {
    case 'W':
        AJUSTE = WF;
        break;
    case 'B':
        AJUSTE = BF;
        break;
    case 'F':
        AJUSTE = FF;
        break;
    }


    if(AJUSTE!=-1)
    {
        partition.part_start =libres[AJUSTE][0];
    }

    //NOTE Realizando Rotaciones para la inserción.
    if(mbr.mbr_partition_1.part_status=='1' && mbr.mbr_partition_2.part_status=='1' && mbr.mbr_partition_3.part_status=='1'  && mbr.mbr_partition_4.part_status=='1')
    {
        EXITO = false;
        tmp.mbr_partition_1 = mbr.mbr_partition_1;
        tmp.mbr_partition_2 = mbr.mbr_partition_2;
        tmp.mbr_partition_3 = mbr.mbr_partition_3;
        tmp.mbr_partition_4 = mbr.mbr_partition_4;
        writeError("Ya no hay particiones disponibles");
    }
    else if(mbr.mbr_partition_1.part_start+mbr.mbr_partition_1.part_size==libres[AJUSTE][0] && AJUSTE!=-1 && mbr.mbr_partition_1.part_status=='1')
    {
        tmp.mbr_partition_1 = mbr.mbr_partition_1;
        tmp.mbr_partition_2 = partition;

        int i=3;
        if(mbr.mbr_partition_2.part_status == '1')
        {
            switch (i)
            {
            case 3:
                tmp.mbr_partition_3 = mbr.mbr_partition_2;
                i++;
                break;
            case 4:
                tmp.mbr_partition_4 = mbr.mbr_partition_2;
                i++;
                break;
            }
        }
        if(mbr.mbr_partition_3.part_status == '1')
        {
            switch (i)
            {
            case 3:
                tmp.mbr_partition_3 = mbr.mbr_partition_3;
                i++;
                break;
            case 4:
                tmp.mbr_partition_4 = mbr.mbr_partition_3;
                i++;
                break;
            }
        }
        if(mbr.mbr_partition_4.part_status == '1')
        {
            switch (i)
            {
            case 3:
                tmp.mbr_partition_3 = mbr.mbr_partition_3;
                i++;
                break;
            case 4:
                tmp.mbr_partition_4 = mbr.mbr_partition_3;
                i++;
                break;
            }
        }
        if(i<5)
        {
            for (int j = i;j<5;j++)
            {
                switch (j)
                {
                case 3:
                    tmp.mbr_partition_3 = nula;
                    i++;
                    break;
                case 4:
                    tmp.mbr_partition_4 = nula;
                    i++;
                    break;
                }
            }
        }
    }
    else if (mbr.mbr_partition_2.part_start+mbr.mbr_partition_2.part_size==libres[AJUSTE][0] && AJUSTE!=-1 && mbr.mbr_partition_2.part_status=='1')
    {
        tmp.mbr_partition_1 = mbr.mbr_partition_1;
        tmp.mbr_partition_2 = mbr.mbr_partition_2;
        tmp.mbr_partition_3 = partition;

        if(mbr.mbr_partition_3.part_status == '1')
            tmp.mbr_partition_4 = mbr.mbr_partition_3;
        else if(mbr.mbr_partition_4.part_status == '1')
            tmp.mbr_partition_4 = mbr.mbr_partition_4;
        else
            tmp.mbr_partition_4 = nula;

    }
    else if (mbr.mbr_partition_3.part_start+mbr.mbr_partition_3.part_size==libres[AJUSTE][0] && AJUSTE!=-1 && mbr.mbr_partition_3.part_status=='1')
    {
        tmp.mbr_partition_1 = mbr.mbr_partition_1;
        tmp.mbr_partition_2 = mbr.mbr_partition_2;
        tmp.mbr_partition_3 = mbr.mbr_partition_3;
        tmp.mbr_partition_4 = partition;
    }
    else if (inicio==libres[AJUSTE][0] && AJUSTE!=-1)
    {
        tmp.mbr_partition_1 = partition;

        int i=2;
        if(mbr.mbr_partition_1.part_status == '1')
        {
            tmp.mbr_partition_2 = mbr.mbr_partition_1;
            i++;
        }
        if(mbr.mbr_partition_2.part_status == '1')
        {
            switch (i)
            {
            case 2:
                tmp.mbr_partition_2 = mbr.mbr_partition_2;
                i++;
                break;
            case 3:
                tmp.mbr_partition_3 = mbr.mbr_partition_2;
                i++;
                break;
            case 4:
                tmp.mbr_partition_4 = mbr.mbr_partition_2;
                i++;
                break;
            }
        }
        if(mbr.mbr_partition_3.part_status == '1')
        {
            switch (i) {
            case 2:
                tmp.mbr_partition_2 = mbr.mbr_partition_3;
                i++;
                break;
            case 3:
                tmp.mbr_partition_3 = mbr.mbr_partition_3;
                i++;
                break;
            case 4:
                tmp.mbr_partition_4 = mbr.mbr_partition_3;
                i++;
                break;
            }
        }

        if(mbr.mbr_partition_4.part_status == '1')
        {
            switch (i) {
            case 2:
                tmp.mbr_partition_2 = mbr.mbr_partition_4;
                i++;
                break;
            case 3:
                tmp.mbr_partition_3 = mbr.mbr_partition_4;
                i++;
                break;
            case 4:
                tmp.mbr_partition_4 = mbr.mbr_partition_4;
                i++;
                break;
            }
        }

        if(i<5){
            for (int j = i;j<5;j++)
            {
                switch (j)
                {
                case 2:
                    tmp.mbr_partition_2 = nula;
                    i++;
                    break;
                case 3:
                    tmp.mbr_partition_3 = nula;
                    i++;
                    break;
                case 4:
                    tmp.mbr_partition_4 = nula;
                    i++;
                    break;
                }
            }
        }
    }

    tmp.mbr_tamano = mbr.mbr_tamano;
    tmp.mbr_fecha_creacion = mbr.mbr_fecha_creacion;
    tmp.mbr_disk_signature =mbr.mbr_disk_signature;

    setMBR(path,tmp,0);
    return EXITO;
}
bool Procedures::putPartitionLogical(MBR mbr,EBR ebr,QString path)
{
    int inicio = -1;
    int fin = -1;
    int FF=-1,BF=-1,WF=-1;

    EBR tmp;

    EBR nulo;
    nulo.part_fit = '\0';
    nulo.part_next = 0;
    nulo.part_size = 0;
    nulo.part_start = 0;
    nulo.part_status = '\0';
    for (int i=0;i<16;i++)
        nulo.part_name[i]='\0';

    QList<int*> libres;

    //NOTE buscando partición extendida
    if(mbr.mbr_partition_1.part_status=='1' && mbr.mbr_partition_1.part_type=='E')
    {
        inicio = mbr.mbr_partition_1.part_start;
        fin = mbr.mbr_partition_1.part_start + mbr.mbr_partition_1.part_size + 1;
    }
    if(mbr.mbr_partition_2.part_status=='1' && mbr.mbr_partition_2.part_type=='E')
    {
        inicio = mbr.mbr_partition_2.part_start;
        fin = mbr.mbr_partition_2.part_start + mbr.mbr_partition_2.part_size + 1;
    }
    if(mbr.mbr_partition_3.part_status=='1' && mbr.mbr_partition_3.part_type=='E')
    {
        inicio = mbr.mbr_partition_3.part_start;
        fin = mbr.mbr_partition_3.part_start + mbr.mbr_partition_3.part_size + 1;
    }
    if(mbr.mbr_partition_4.part_status=='1' && mbr.mbr_partition_4.part_type=='E')
    {
        inicio = mbr.mbr_partition_4.part_start;
        fin = mbr.mbr_partition_4.part_start + mbr.mbr_partition_4.part_size + 1;
    }

    int pos = inicio;
    int libre [3] = {-1,-1,-1};
    //FIXME Corregir insertar particion al inicio.
    //NOTE Buscando espacios libres en partición.
    if(inicio!=-1)
    {
        pos= inicio;
        tmp = getEBR(path,pos);
        if( tmp.part_status != '\0'){
            do
            {
                libre[0] = -1;
                libre[1] = -1;
                libre[2] = -1;

                if(tmp.part_status=='0')
                {
                    if(libres.count()>0)
                    {
                        if((libres[libres.count()-1][0]+libres[libres.count()-1][1])==tmp.part_start)
                        {
                            libres[libres.count()-1][1] = tmp.part_next - libres[libres.count()-1][0];
                            libres[libres.count()-1][2] = libres[libres.count()-1][1] - ebr.part_size;
                        }
                        else
                        {
                            libre[0]= tmp.part_start;
                            libre[1]= tmp.part_size;
                            libre[2]= libre[1] - ebr.part_size ;
                            libres.append(libre);
                        }
                    }
                    else
                    {
                        libre[0]= tmp.part_start;
                        libre[1]= tmp.part_size;
                        libre[2]= libre[1] - ebr.part_size ;
                        if((libre[0]+libre[1])<fin)
                            libres.append(libre);
                    }

                }else if(tmp.part_status=='1')
                {
                    if(tmp.part_next!=-1)
                    {
                        if((tmp.part_size+tmp.part_start+ebr.part_size) < tmp.part_next)
                        {
                            libre[0]= tmp.part_start + tmp.part_size;
                            libre[1]= tmp.part_next - libre[0];
                            libre[2]= libre[1] - ebr.part_size ;
                            libres.append(libre);
                        }
                    }
                    else
                    {
                        if((tmp.part_size+tmp.part_start+ebr.part_size) < fin)
                        {
                            libre[0]= tmp.part_start + tmp.part_size;
                            libre[1]= fin - libre[0];
                            libre[2]= libre[1] - ebr.part_size ;
                            libres.append(libre);
                        }
                    }
                }


                pos = tmp.part_next;
                tmp = nulo;
                if(pos!=-1)
                    tmp = getEBR(path,pos);
            }
            while(tmp.part_status != '\0');

        }
        else
        {
            if((inicio+ebr.part_size) < fin)
            {
                libre[0]= inicio ;
                libre[1]= fin - libre[0];
                libre[2]= libre[1] - ebr.part_size ;
                libres.append(libre);
            }
        }
    }

    for (int i=0;i<libres.count();i++)
    {
        if(libres[i][2]>=0)
        {
            FF = i;
            break;
        }
    }

    for (int i=0;i<libres.count();i++)
    {
        if(BF!=-1)
        {
            if(libres[i][2]>0 && libres[i][2] < libres[BF][2] )
                BF = i;
        }
        else
        {
            if(libres[i][2]>=0 )
                BF = i;
        }
    }

    for (int i=0;i<libres.count();i++)
    {
        if(WF!=-1)
        {
            if(libres[i][2]>0 && libres[i][2] > libres[WF][2] )
                WF = i;
        }
        else
        {
            if(libres[i][2]>=0 )
                WF = i;
        }
    }

    int AJUSTE=-1;

    switch (ebr.part_fit)
    {
    case 'W':
        AJUSTE = WF;
        break;
    case 'B':
        AJUSTE = BF;
        break;
    case 'F':
        AJUSTE = FF;
        break;
    }


    if(inicio!=-1)
    {
        if(AJUSTE!=-1)
        {
            pos= inicio;
            tmp = getEBR(path,pos);
            if( tmp.part_status != '\0')
            {

                do
                {
                    if(tmp.part_start+tmp.part_size==libres[AJUSTE][0] && AJUSTE!=-1 && tmp.part_status=='1')
                    {
                        ebr.part_next = tmp.part_next;
                        tmp.part_next = libres[AJUSTE][0];
                        ebr.part_start = libres[AJUSTE][0];
                        setEBR(path,ebr,ebr.part_start);
                        setEBR(path,tmp,tmp.part_start);
                        return true;
                    }
                    pos = tmp.part_next;
                    tmp = nulo;
                    if(pos!=-1)
                        tmp = getEBR(path,pos);
                }
                while(tmp.part_status != '\0');

            }
            else
            {
                ebr.part_start = libres[AJUSTE][0];
                ebr.part_next =-1;
                setEBR(path,ebr,ebr.part_start);
                return true;
            }
        }
        else
        {
            if(libres.count()>0)
            {
                ebr.part_start = inicio;
                ebr.part_next = -1;
                setEBR(path,ebr,ebr.part_start);
                return true;
            }
        }

    }

    return false;
}

bool Procedures::mountPartition(QString path, QString name){
    bool encontrado=false;
    if(existPartition(name,path))
    {
        for(int i =0;i < mounts.size();i++)
        {
            QStringList datos = mounts.at(i).split(',', QString::SkipEmptyParts);
            if(datos.at(0)==path&&datos.at(1)==name)
            {
                encontrado=true;
                writeError("Se monto anteriormente esta particion");
            }
        }
        if(!encontrado)
        {
            QString id = getId(path);
            mounts.append(path + "," + name + "," + id);
            writeLine("Partición montada éxitosamente.");
        }
    }
    else
    {
        Procedures::writeError("Partición no existe en disco");
    }

    return !encontrado;
}
void Procedures::unmountPartition(QString id)
{
    bool ENCONTRADO=false;
    for(int i =0;i < mounts.size();i++)
    {
        QStringList datos = mounts.at(i).split(',', QString::SkipEmptyParts);
        if(datos.at(2)==id)
        {
            mounts.removeAt(i);
            ENCONTRADO = true;
            writeLine("Se desmonto correctamente esta particion");
        }
    }

    if(!ENCONTRADO)
        writeError("No existia partición para desmontar");
}
void Procedures::writeMountPartition()
{
    writeLine("Particiones Montadas");
    for (int i =0;i<mounts.size();i++)
    {
        QStringList datos = mounts.at(i).split(',', QString::SkipEmptyParts);
        writeLine("        -Path: "+datos.at(0) + " -Name: "+datos.at(1) + " -Id: " + datos.at(2));
    }
}
QString Procedures::getId(QString path)
{
    letters.clear();
    letters  << "a" << "b" << "c" << "d" << "e"
             << "f" << "g" << "h" << "i" << "j"
             << "k" << "l" << "m" << "n" << "o"
             << "p" << "q" << "r" << "s" << "t"
             << "u" << "v" << "w" << "x" << "y"
             << "z";

    if(!disk.contains(path))
    {
        disk.append(path);
        counts.append(0);
    }

    for (int i=0;i<disk.size();i++)
        if(disk[i]==path)
            return  "vd" + letters[i] + QString::number(++counts[i]);

    return "";
}

int Procedures::comprobatePNGPDF(QString path)
{
    QStringList Directorys = path.split('/',QString::SkipEmptyParts);
    QString extension = Directorys.at(Directorys.count()-1).split('.',QString::SkipEmptyParts).at(1);
    if(extension.toUpper()=="PNG")
        return 1;
    else if(extension.toUpper()=="PDF")
        return 2;
    else if(extension.toUpper()=="JPG")
        return 3;
    else if(extension.toUpper()=="JPEG")
        return 4;
    else
        return  0;
}

void Procedures::generateRep(QString dot, QString path)
{
    QString strgComand;
    int tipo = comprobatePNGPDF(path);
    switch (tipo) {
    case 1:
        strgComand = "dot -Tpng "+dot+" -o " + path;
        system(strgComand.toUtf8().constData());
        break;
    case 2:
        strgComand = "dot -Tpdf "+dot+" -o " + path;
        system(strgComand.toUtf8().constData());
        break;
    case 3:
        strgComand = "dot -Tjpg "+dot+" -o " + path;
        system(strgComand.toUtf8().constData());
        break;
    case 4:
        strgComand = "dot -Tjpeg "+dot+" -o " + path;
        system(strgComand.toUtf8().constData());
        break;
    default:
        writeError("Formato no admitido por graphviz");
        break;
    }
}

QString Procedures::getDotBM(QString titulo, char* bitmap){

    int espacios = 20 - (strlen(bitmap) % 20);

    QString grapho="digraph structs {\n";
    grapho += "    bitmap [\n";
    grapho += "        shape = none;\n";
    grapho += "        label = <\n";
    grapho += "            <table border=\"0\" cellborder=\"2\" cellspacing=\"2\" color=\"cyan4\">\n";
    grapho += "                <tr><td colspan=\"20\">"+titulo+"</td></tr>\n";
    grapho += "                <tr>";

    for (int i=0;i<static_cast<int>(strlen(bitmap));i++){
        if((i+1)%20==0){
            grapho += "<td>"+QString::number(bitmap[i]-48)+"</td></tr>\n";
            grapho += "                <tr>";
        }
        else{
            grapho += "<td>"+QString::number(bitmap[i]-48)+"</td>";
        }

        if(i==static_cast<int>(strlen(bitmap))-1){

            for (int i=0;i<espacios;i++)
                grapho += "<td> </td>  ";

            grapho += "</tr>\n";
        }
    }

    grapho += "            </table>\n";
    grapho += "        >\n";
    grapho += "    ];\n";
    grapho += "}\n";


    return grapho;
}

bool Procedures::generateRepMBR(QString path, QString id)
{
    createDirectory(path);
    QString grafo="";

    EBR nulo;
    nulo.part_fit = '\0';
    nulo.part_next = 0;
    nulo.part_size = 0;
    nulo.part_start = 0;
    nulo.part_status = '\0';
    for (int i=0;i<16;i++)
        nulo.part_name[i]='\0';

    for(int i =0;i < mounts.size();i++)
    {
        QStringList datos = mounts.at(i).split(',', QString::SkipEmptyParts);
        if(datos.at(2)==id)
        {
            MBR mbr = getMBR(datos.at(0).toUtf8(),0);
            grafo += "digraph D{\n";
            grafo += "graph [pad=\"0.5\", nodesep=\"0.5\", ranksep=\"2\"];\n";
            grafo += "node [shape=plain]\n";
            grafo += "rankdir=LR;\n";
            grafo += "arset [label=<\n";
            grafo += "<table border=\"0\" cellborder=\"1\" color=\"white\" cellspacing=\"0\" >\n";
            grafo += "<tr><td>\n";

            grafo += "<table>\n";

            grafo += "<tr><td bgcolor = \"steelblue\" align = \"left\"> <font color = \"white\">mbr_tamano</font></td><td bgcolor = \"whitesmoke\" align = \"left\">"+QString::number(mbr.mbr_tamano)+"</td></tr>\n";
            grafo += "<tr><td bgcolor = \"steelblue\" align = \"left\"> <font color = \"white\">mbr_fecha_creacion</font></td><td bgcolor = \"whitesmoke\" align = \"left\">"+QString::fromLatin1(generate_mbr_fecha_creacion(mbr.mbr_fecha_creacion))+"</td></tr>\n";
            grafo += "<tr><td bgcolor = \"steelblue\" align = \"left\"> <font color = \"white\">mbr_disk_signature</font></td><td bgcolor = \"whitesmoke\" align = \"left\">"+QString::number(mbr.mbr_disk_signature)+"</td></tr>\n";

            if(mbr.mbr_partition_1.part_status=='1')
            {
                grafo += "<tr><td bgcolor = \"forestgreen\" align = \"left\"> <font color = \"white\">part_status_1</font></td><td bgcolor = \"whitesmoke\" align = \"left\">"+QString::fromLatin1(&mbr.mbr_partition_1.part_status,sizeof (mbr.mbr_partition_1.part_status))+"</td></tr>\n";
                grafo += "<tr><td bgcolor = \"forestgreen\" align = \"left\"> <font color = \"white\">part_type_1</font></td><td bgcolor = \"whitesmoke\" align = \"left\">"+QString::fromLatin1(&mbr.mbr_partition_1.part_type,sizeof (mbr.mbr_partition_1.part_type))+"</td></tr>\n";
                grafo += "<tr><td bgcolor = \"forestgreen\" align = \"left\"> <font color = \"white\">part_fit_1</font></td><td bgcolor = \"whitesmoke\" align = \"left\">"+QString::fromLatin1(&mbr.mbr_partition_1.part_fit,sizeof (mbr.mbr_partition_1.part_fit))+"</td></tr>\n";
                grafo += "<tr><td bgcolor = \"forestgreen\" align = \"left\"> <font color = \"white\">part_start_1</font></td><td bgcolor = \"whitesmoke\" align = \"left\">"+QString::number(mbr.mbr_partition_1.part_start)+"</td></tr>\n";
                grafo += "<tr><td bgcolor = \"forestgreen\" align = \"left\"> <font color = \"white\">part_size_1</font></td><td bgcolor = \"whitesmoke\" align = \"left\">"+QString::number(mbr.mbr_partition_1.part_size)+"</td></tr>\n";
                grafo += "<tr><td bgcolor = \"forestgreen\" align = \"left\"> <font color = \"white\">part_name_1</font></td><td bgcolor = \"whitesmoke\" align = \"left\">"+QString::fromLatin1(mbr.mbr_partition_1.part_name)+"</td></tr>\n";
            }
            if(mbr.mbr_partition_2.part_status=='1')
            {
                grafo += "<tr><td bgcolor = \"gold\" align = \"left\"> <font color = \"white\">part_status_2</font></td><td bgcolor = \"whitesmoke\" align = \"left\">"+QString::fromLatin1(&mbr.mbr_partition_2.part_status,sizeof (mbr.mbr_partition_2.part_status))+"</td></tr>\n";
                grafo += "<tr><td bgcolor = \"gold\" align = \"left\"> <font color = \"white\">part_type_2</font></td><td bgcolor = \"whitesmoke\" align = \"left\">"+QString::fromLatin1(&mbr.mbr_partition_2.part_type,sizeof (mbr.mbr_partition_2.part_type))+"</td></tr>\n";
                grafo += "<tr><td bgcolor = \"gold\" align = \"left\"> <font color = \"white\">part_fit_2</font></td><td bgcolor = \"whitesmoke\" align = \"left\">"+QString::fromLatin1(&mbr.mbr_partition_2.part_fit,sizeof (mbr.mbr_partition_2.part_fit))+"</td></tr>\n";
                grafo += "<tr><td bgcolor = \"gold\" align = \"left\"> <font color = \"white\">part_start_2</font></td><td bgcolor = \"whitesmoke\" align = \"left\">"+QString::number(mbr.mbr_partition_2.part_start)+"</td></tr>\n";
                grafo += "<tr><td bgcolor = \"gold\" align = \"left\"> <font color = \"white\">part_size_2</font></td><td bgcolor = \"whitesmoke\" align = \"left\">"+QString::number(mbr.mbr_partition_2.part_size)+"</td></tr>\n";
                grafo += "<tr><td bgcolor = \"gold\" align = \"left\"> <font color = \"white\">part_name_2</font></td><td bgcolor = \"whitesmoke\" align = \"left\">"+QString::fromLatin1(mbr.mbr_partition_2.part_name)+"</td></tr>\n";
            }
            if(mbr.mbr_partition_3.part_status=='1')
            {
                grafo += "<tr><td bgcolor = \"darkorange\" align = \"left\"> <font color = \"white\">part_status_3</font></td><td bgcolor = \"whitesmoke\" align = \"left\">"+QString::fromLatin1(&mbr.mbr_partition_3.part_status,sizeof (mbr.mbr_partition_3.part_status))+"</td></tr>\n";
                grafo += "<tr><td bgcolor = \"darkorange\" align = \"left\"> <font color = \"white\">part_type_3</font></td><td bgcolor = \"whitesmoke\" align = \"left\">"+QString::fromLatin1(&mbr.mbr_partition_3.part_type,sizeof (mbr.mbr_partition_3.part_type))+"</td></tr>\n";
                grafo += "<tr><td bgcolor = \"darkorange\" align = \"left\"> <font color = \"white\">part_fit_3</font></td><td bgcolor = \"whitesmoke\" align = \"left\">"+QString::fromLatin1(&mbr.mbr_partition_3.part_fit,sizeof (mbr.mbr_partition_3.part_fit))+"</td></tr>\n";
                grafo += "<tr><td bgcolor = \"darkorange\" align = \"left\"> <font color = \"white\">part_start_3</font></td><td bgcolor = \"whitesmoke\" align = \"left\">"+QString::number(mbr.mbr_partition_3.part_start)+"</td></tr>\n";
                grafo += "<tr><td bgcolor = \"darkorange\" align = \"left\"> <font color = \"white\">part_size_3</font></td><td bgcolor = \"whitesmoke\" align = \"left\">"+QString::number(mbr.mbr_partition_3.part_size)+"</td></tr>\n";
                grafo += "<tr><td bgcolor = \"darkorange\" align = \"left\"> <font color = \"white\">part_name_3</font></td><td bgcolor = \"whitesmoke\" align = \"left\">"+QString::fromLatin1(mbr.mbr_partition_3.part_name)+"</td></tr>\n";
            }
            if(mbr.mbr_partition_4.part_status=='1')
            {
                grafo += "<tr><td bgcolor = \"royalblue\" align = \"left\"> <font color = \"white\">part_status_4</font></td><td bgcolor = \"whitesmoke\" align = \"left\">"+QString::fromLatin1(&mbr.mbr_partition_4.part_status,sizeof (mbr.mbr_partition_4.part_status))+"</td></tr>\n";
                grafo += "<tr><td bgcolor = \"royalblue\" align = \"left\"> <font color = \"white\">part_type_4</font></td><td bgcolor = \"whitesmoke\" align = \"left\">"+QString::fromLatin1(&mbr.mbr_partition_4.part_type,sizeof (mbr.mbr_partition_4.part_type))+"</td></tr>\n";
                grafo += "<tr><td bgcolor = \"royalblue\" align = \"left\"> <font color = \"white\">part_fit_4</font></td><td bgcolor = \"whitesmoke\" align = \"left\">"+QString::fromLatin1(&mbr.mbr_partition_4.part_fit,sizeof (mbr.mbr_partition_4.part_fit))+"</td></tr>\n";
                grafo += "<tr><td bgcolor = \"royalblue\" align = \"left\"> <font color = \"white\">part_start_4</font></td><td bgcolor = \"whitesmoke\" align = \"left\">"+QString::number(mbr.mbr_partition_4.part_start)+"</td></tr>\n";
                grafo += "<tr><td bgcolor = \"royalblue\" align = \"left\"> <font color = \"white\">part_size_4</font></td><td bgcolor = \"whitesmoke\" align = \"left\">"+QString::number(mbr.mbr_partition_4.part_size)+"</td></tr>\n";
                grafo += "<tr><td bgcolor = \"royalblue\" align = \"left\"> <font color = \"white\">part_name_4</font></td><td bgcolor = \"whitesmoke\" align = \"left\">"+QString::fromLatin1(mbr.mbr_partition_4.part_name)+"</td></tr>\n";
            }

            grafo += "</table>\n";
            grafo += "</td>\n";
            int inicio = -1;
            int fin = -1;

            EBR tmp = nulo;


            if(mbr.mbr_partition_1.part_status=='1' && mbr.mbr_partition_1.part_type=='E')
            {
                inicio = mbr.mbr_partition_1.part_start;
                fin = mbr.mbr_partition_1.part_start + mbr.mbr_partition_1.part_size;
            }
            if(mbr.mbr_partition_2.part_status=='1' && mbr.mbr_partition_2.part_type=='E')
            {
                inicio = mbr.mbr_partition_2.part_start;
                fin = mbr.mbr_partition_2.part_start + mbr.mbr_partition_2.part_size;
            }
            if(mbr.mbr_partition_3.part_status=='1' && mbr.mbr_partition_3.part_type=='E')
            {
                inicio = mbr.mbr_partition_3.part_start;
                fin = mbr.mbr_partition_3.part_start + mbr.mbr_partition_3.part_size;
            }
            if(mbr.mbr_partition_4.part_status=='1' && mbr.mbr_partition_4.part_type=='E')
            {
                inicio = mbr.mbr_partition_4.part_start;
                fin = mbr.mbr_partition_4.part_start + mbr.mbr_partition_4.part_size;
            }

            if(inicio!=-1)
            {
                int pos= inicio;
                tmp = getEBR(datos.at(0).toUtf8(),pos);
                if( tmp.part_status != '\0')
                {
                    int nebr=0;
                    do
                    {
                        if(tmp.part_status=='1')
                        {
                            grafo += "<td>\n";
                            grafo += "<table>\n";
                            grafo += "<tr><td colspan = \"2\" align = \"left\"> EBR_"+QString::number(++nebr)+" </td></tr>\n";
                            grafo += "<tr><td bgcolor = \"royalblue\" align = \"left\"> <font color = \"white\">part_status</font></td><td bgcolor = \"whitesmoke\" align = \"left\">"+QString::fromLatin1(&tmp.part_status,sizeof (tmp.part_status))+"</td></tr>\n";
                            grafo += "<tr><td bgcolor = \"royalblue\" align = \"left\"> <font color = \"white\">part_fit</font></td><td bgcolor = \"whitesmoke\" align = \"left\">"+QString::fromLatin1(&tmp.part_fit,sizeof (tmp.part_fit))+"</td></tr>\n";
                            grafo += "<tr><td bgcolor = \"royalblue\" align = \"left\"> <font color = \"white\">part_start</font></td><td bgcolor = \"whitesmoke\" align = \"left\">"+QString::number(tmp.part_start)+"</td></tr>\n";
                            grafo += "<tr><td bgcolor = \"royalblue\" align = \"left\"> <font color = \"white\">part_size</font></td><td bgcolor = \"whitesmoke\" align = \"left\">"+QString::number(tmp.part_size)+"</td></tr>\n";
                            grafo += "<tr><td bgcolor = \"royalblue\" align = \"left\"> <font color = \"white\">part_next</font></td><td bgcolor = \"whitesmoke\" align = \"left\">"+QString::number(tmp.part_next)+"</td></tr>\n";
                            grafo += "<tr><td bgcolor = \"royalblue\" align = \"left\"> <font color = \"white\">part_name_4</font></td><td bgcolor = \"whitesmoke\" align = \"left\">"+QString::fromLatin1(tmp.part_name)+"</td></tr>\n";
                            grafo += "</table>\n";
                            grafo += "</td>\n";
                        }
                        pos = tmp.part_next;
                        tmp = nulo;
                        if(pos!=-1)
                            tmp = getEBR(datos.at(0).toUtf8(),pos);
                    }
                    while(tmp.part_status != '\0');
                }
            }
            grafo += "</tr>\n";
            grafo+="</table>\n";
            grafo+=">]\n}";

            QFile qFile("repMBR.dot");
            if(qFile.open(QIODevice::WriteOnly))
            {
                QTextStream out(&qFile);
                out << grafo;
                qFile.close();
            }

            generateRep("repMBR.dot",path);
            writeLine("Se genero el reporte correctamente");
            return true;
        }
    }

    writeError("No se genero el reporte correctamente");
    return false;
}
bool Procedures::generateRepFile(QString path, QString id, QString ruta)
{

}
bool Procedures::generateRepDisk(QString path, QString id)
{
    QString grafo="";
    createDirectory(path);
    PARTITION tmp;

    EBR nulo;
    nulo.part_fit = '\0';
    nulo.part_next = 0;
    nulo.part_size = 0;
    nulo.part_start = 0;
    nulo.part_status = '\0';
    for (int i=0;i<16;i++)
        nulo.part_name[i]='\0';

    int libre = 0;
    for(int i =0;i < mounts.size();i++)
    {
        QStringList datos = mounts.at(i).split(',', QString::SkipEmptyParts);
        if(datos.at(2)==id)
        {
            MBR mbr = getMBR(datos.at(0).toUtf8(),0);
            grafo += "digraph D{\n";
            grafo += "graph [pad=\"0.5\", nodesep=\"0.5\", ranksep=\"2\"];\n";
            grafo += "node [shape=plain]\n";
            grafo += "rankdir=LR;\n";
            grafo += "arset [label=<\n";
            grafo += "<table border=\"0\" cellborder=\"1\" color=\"white\" cellspacing=\"0\" >\n";
            grafo += "<tr>\n";
            grafo += "<td bgcolor = \"dodgerblue\"> MBR <br/>" + QString::number(sizeof(MBR))+" bytes</td>\n";

            for (int i=0;i<4;i++)
            {
                switch (i)
                {
                case 0:
                    libre = 0;
                    tmp= mbr.mbr_partition_1;

                    if(tmp.part_status == '1' && (tmp.part_start-static_cast<int>(sizeof(MBR)))>0)
                        grafo += "<td bgcolor = \"gray\"> ESPACIO LIBRE <br/>"+QString::number(static_cast<double>(tmp.part_start-static_cast<int>(sizeof(MBR)))/static_cast<double>(mbr.mbr_tamano)*static_cast<double>(100),'f',2)+"% <br/>"+QString::number(tmp.part_start-static_cast<int>(sizeof(MBR)))+" bytes</td>\n";

                    if(tmp.part_status == '1' && (tmp.part_start+tmp.part_size)<mbr.mbr_partition_2.part_start)
                        libre = mbr.mbr_partition_2.part_start - (tmp.part_start+tmp.part_size);
                    else if( mbr.mbr_partition_2.part_status == '0' &&(tmp.part_start+tmp.part_size)<mbr.mbr_tamano)
                        libre = mbr.mbr_tamano - (tmp.part_start+tmp.part_size);

                    break;
                case 1:
                    tmp= mbr.mbr_partition_2;
                    if(tmp.part_status == '1' && (tmp.part_start+tmp.part_size)<mbr.mbr_partition_3.part_start)
                        libre = mbr.mbr_partition_3.part_start - (tmp.part_start+tmp.part_size);
                    else if( mbr.mbr_partition_3.part_status == '0' &&(tmp.part_start+tmp.part_size)<mbr.mbr_tamano)
                        libre = mbr.mbr_tamano - (tmp.part_start+tmp.part_size);

                    break;
                case 2:
                    tmp= mbr.mbr_partition_3;
                    if(tmp.part_status == '1' && (tmp.part_start+tmp.part_size)<mbr.mbr_partition_4.part_start)
                        libre = mbr.mbr_partition_4.part_start - (tmp.part_start+tmp.part_size);
                    else if( mbr.mbr_partition_4.part_status == '0' &&(tmp.part_start+tmp.part_size)<mbr.mbr_tamano)
                        libre = mbr.mbr_tamano - (tmp.part_start+tmp.part_size);

                    break;
                case 3:
                    tmp= mbr.mbr_partition_4;
                    if( (tmp.part_start+tmp.part_size)<mbr.mbr_tamano)
                        libre = mbr.mbr_tamano - (tmp.part_start+tmp.part_size);
                    break;
                default:
                    break;
                }

                if(tmp.part_status=='1')
                {
                    if(tmp.part_type=='E')
                    {
                        grafo += "<td>\n"
                                 "<table border=\"0\" cellborder=\"1\" color=\"white\" cellspacing=\"0\" >\n";

                        QString extendida;
                        int ext = 0;
                        int inicio = -1;
                        int fin = -1;

                        inicio = tmp.part_start;
                        fin = tmp.part_start + tmp.part_size;

                        EBR ebr = nulo;

                        if(inicio!=-1)
                        {
                            int pos= inicio;
                            ebr = getEBR(datos.at(0).toUtf8(),pos);
                            if( ebr.part_status != '\0')
                            {
                                extendida += "<tr>\n";
                                do
                                {
                                    if(ebr.part_status=='1')
                                    {
                                        extendida += "<td bgcolor = \"forestgreen\"> EBR <br/>" + QString::number(sizeof(EBR))+" bytes</td>\n";
                                        extendida += "<td bgcolor = \"gold\">"+ QString::fromLatin1(ebr.part_name) + "<br/> (LÓGICA) <br/>" + QString::number(static_cast<double>(ebr.part_size)/static_cast<double>(mbr.mbr_tamano)*static_cast<double>(100),'f',2)+"%<br/>"+QString::number(ebr.part_size)+" bytes</td>\n";
                                        ext++;
                                        ext++;
                                    }
                                    if(ebr.part_next!=-1)
                                    {
                                        if((ebr.part_next-(ebr.part_start+ebr.part_size))>0)
                                        {
                                            extendida += "<td bgcolor = \"gray\"> ESPACIO LIBRE <br/>"+QString::number(static_cast<double>(ebr.part_next-(ebr.part_start+ebr.part_size))/static_cast<double>(mbr.mbr_tamano)*static_cast<double>(100),'f',2)+"% <br/>"+QString::number(ebr.part_next-(ebr.part_start+ebr.part_size))+" bytes</td>\n";
                                            ext++;
                                        }

                                    }
                                    else
                                    {
                                        if(((tmp.part_size+tmp.part_start)-(ebr.part_start+ebr.part_size))>0)
                                        {
                                            extendida += "<td bgcolor = \"gray\"> ESPACIO LIBRE <br/>"+QString::number(static_cast<double>((tmp.part_size+tmp.part_start)-(ebr.part_start+ebr.part_size))/static_cast<double>(mbr.mbr_tamano)*static_cast<double>(100),'f',2)+"% <br/>"+QString::number((tmp.part_size+tmp.part_start)-(ebr.part_start+ebr.part_size))+" bytes</td>\n";
                                            ext++;
                                        }
                                    }

                                    pos = ebr.part_next;
                                    ebr = nulo;
                                    if(pos!=-1)
                                        ebr = getEBR(datos.at(0).toUtf8(),pos);
                                }
                                while(ebr.part_status != '\0');

                                extendida += "</tr>\n";

                            }
                        }

                        grafo += "<tr><td colspan =\""+QString::number(ext)+"\"  bgcolor = \"orangered\">" + QString::fromLatin1(tmp.part_name) + "<br/> (EXTENDIDA) <br/>" + QString::number(static_cast<double>(tmp.part_size)/static_cast<double>(mbr.mbr_tamano)*static_cast<double>(100),'f',2)+"%<br/>"+QString::number(tmp.part_size)+" bytes</td></tr>\n";
                        grafo += extendida;
                        grafo += "</table>\n"
                                 "</td>\n";

                    }
                    else if(tmp.part_type=='P')
                    {
                        grafo += "<td bgcolor = \"purple\">" + QString::fromLatin1(tmp.part_name) + "<br/> (PRINCIPAL) <br/>" + QString::number(static_cast<double>(tmp.part_size)/static_cast<double>(mbr.mbr_tamano)*static_cast<double>(100),'f',2)+"%<br/>"+QString::number(tmp.part_size)+" bytes</td>\n";
                    }

                    if(libre > 0)
                        grafo += "<td bgcolor = \"gray\"> ESPACIO LIBRE <br/>"+QString::number(static_cast<double>(libre)/static_cast<double>(mbr.mbr_tamano)*static_cast<double>(100),'f',2)+"% <br/>"+QString::number(libre)+" bytes</td>\n";
                }

            }



            grafo += "</tr>\n";
            grafo+="</table>\n";
            grafo+=">]\n}";

            QFile qFile("repDISK.dot");
            if(qFile.open(QIODevice::WriteOnly))
            {
                QTextStream out(&qFile);
                out << grafo;
                qFile.close();
            }

            generateRep("repDISK.dot",path);
            writeLine("Se genero el reporte correctamente");
            return true;
        }
    }
    writeError("No se genero el reporte correctamente");
    return false;
}
bool Procedures::generateRepInode(QString path, QString id)
{

}
bool Procedures::generateRepSb(QString path, QString id)
{

}
bool Procedures::generateRepBm_Arbdir(QString path, QString id)
{
    createDirectory(path);

    MOUNTEDPARTITION mountedPartition = getMountedPartition(id);
    QString pathmountedPartition = getPathMountedPartition(id);

    SUPERBOOT sb = getSuperBoot(pathmountedPartition, mountedPartition.part_start);

    char* bitmap = getBitMap(pathmountedPartition, sb.sb_arbol_virtual_count, sb.sb_ap_bitmap_arbol_directorio);

    QFile qFile("repBM_DIRECTORIO.dot");
    if(qFile.open(QIODevice::WriteOnly))
    {
        QTextStream out(&qFile);
        out << getDotBM("Bit Map Arbol Directorio",bitmap);
        qFile.close();
    }

    generateRep("repBM_DIRECTORIO.dot",path);
    writeLine("Se genero el reporte correctamente");
    return true;
}
bool Procedures::generateRepBm_Detdir(QString path, QString id)
{
    createDirectory(path);

    MOUNTEDPARTITION mountedPartition = getMountedPartition(id);
    QString pathmountedPartition = getPathMountedPartition(id);

    SUPERBOOT sb = getSuperBoot(pathmountedPartition, mountedPartition.part_start);

    char* bitmap = getBitMap(pathmountedPartition, sb.sb_detalle_directory_count, sb.sb_ap_bitmap_detalle_directory);

    QFile qFile("repBM_DETALLE.dot");
    if(qFile.open(QIODevice::WriteOnly))
    {
        QTextStream out(&qFile);
        out << getDotBM("Bit Map Detalle de Directorio",bitmap);
        qFile.close();
    }

    generateRep("repBM_DETALLE.dot",path);
    writeLine("Se genero el reporte correctamente");
    return true;
}
bool Procedures::generateRepBm_Inode(QString path, QString id)
{
    createDirectory(path);

    MOUNTEDPARTITION mountedPartition = getMountedPartition(id);
    QString pathmountedPartition = getPathMountedPartition(id);

    SUPERBOOT sb = getSuperBoot(pathmountedPartition, mountedPartition.part_start);

    char* bitmap = getBitMap(pathmountedPartition, sb.sb_inodos_count, sb.sb_ap_bitmap_table_inodo);

    QFile qFile("repBM_INODO.dot");
    if(qFile.open(QIODevice::WriteOnly))
    {
        QTextStream out(&qFile);
        out << getDotBM("Bit Map de Inodos",bitmap);
        qFile.close();
    }

    generateRep("repBM_INODO.dot",path);
    writeLine("Se genero el reporte correctamente");
    return true;
}
bool Procedures::generateRepBm_Block(QString path, QString id)
{
    createDirectory(path);

    MOUNTEDPARTITION mountedPartition = getMountedPartition(id);
    QString pathmountedPartition = getPathMountedPartition(id);

    SUPERBOOT sb = getSuperBoot(pathmountedPartition, mountedPartition.part_start);

    char* bitmap = getBitMap(pathmountedPartition, sb.sb_bloques_count, sb.sb_ap_bitmap_bloques);

    QFile qFile("repBM_BLOCK.dot");
    if(qFile.open(QIODevice::WriteOnly))
    {
        QTextStream out(&qFile);
        out << getDotBM("Bit Map de bloques",bitmap);
        qFile.close();
    }

    generateRep("repBM_BLOCK.dot",path);
    writeLine("Se genero el reporte correctamente");
    return true;
}
bool Procedures::generateRepBitacora(QString path, QString id)
{

}

QString Procedures::getDotAVD(QString path, AVD root, int inicioAVD, int n){

    QString grapho="";

    grapho += "    AVD"+QString::number(n)+" [\n";
    grapho += "        shape = none;\n";
    grapho += "        label = <\n";
    grapho += "            <table border=\"0\" cellborder=\"2\" cellspacing=\"2\" color=\"cyan4\">\n";
    grapho += "                <tr><td colspan=\"8\" bgcolor=\"white\" >"+QString::fromLatin1(root.avd_nombre_directorio).remove('\000')+"</td></tr>\n";
    grapho += "                <tr>\n";

    if(root.avd_ap_array_subdirectorios[0]!=-1)
    grapho += "                    <td bgcolor = \"lightskyblue1\">"+QString::number(root.avd_ap_array_subdirectorios[0])+"</td>\n";
    else
    grapho += "                    <td bgcolor = \"lightcyan\"> &nbsp; </td>\n";

    if(root.avd_ap_array_subdirectorios[1]!=-1)
    grapho += "                    <td bgcolor = \"lightskyblue1\">"+QString::number(root.avd_ap_array_subdirectorios[1])+"</td>\n";
    else
    grapho += "                    <td bgcolor = \"lightcyan\"> &nbsp; </td>\n";

    if(root.avd_ap_array_subdirectorios[2]!=-1)
    grapho += "                    <td bgcolor = \"lightskyblue1\">"+QString::number(root.avd_ap_array_subdirectorios[2])+"</td>\n";
    else
    grapho += "                    <td bgcolor = \"lightcyan\"> &nbsp; </td>\n";

    if(root.avd_ap_array_subdirectorios[3]!=-1)
    grapho += "                    <td bgcolor = \"lightskyblue1\">"+QString::number(root.avd_ap_array_subdirectorios[3])+"</td>\n";
    else
    grapho += "                    <td bgcolor = \"lightcyan\"> &nbsp; </td>\n";

    if(root.avd_ap_array_subdirectorios[4]!=-1)
    grapho += "                    <td bgcolor = \"lightskyblue1\">"+QString::number(root.avd_ap_array_subdirectorios[4])+"</td>\n";
    else
    grapho += "                    <td bgcolor = \"lightcyan\"> &nbsp; </td>\n";

    if(root.avd_ap_array_subdirectorios[5]!=-1)
    grapho += "                    <td bgcolor = \"lightskyblue1\">"+QString::number(root.avd_ap_array_subdirectorios[5])+"</td>\n";
    else
    grapho += "                    <td bgcolor = \"lightcyan\"> &nbsp; </td>\n";

    if(root.avd_ap_detalle_directorio!=-1)
    grapho += "                    <td bgcolor = \"cyan3\">"+QString::number(root.avd_ap_detalle_directorio)+"</td>\n";
    else
    grapho += "                    <td bgcolor = \"cyan3\"> &nbsp; </td>\n";

    if(root.avd_ap_arbol_virtual_directorio!=-1)
    grapho += "                    <td bgcolor = \"greenyellow\">"+QString::number(root.avd_ap_arbol_virtual_directorio)+"</td>\n";
    else
    grapho += "                    <td bgcolor = \"greenyellow\"> &nbsp; </td>\n";

    grapho += "                </tr>\n";
    grapho += "            </table>\n";
    grapho += "        >\n";
    grapho += "    ];\n\n";

    for (int i=0; i<6;i++)
        if(root.avd_ap_array_subdirectorios[i]!=-1){

            grapho += "AVD"+QString::number(n)+"->AVD"+QString::number(root.avd_ap_array_subdirectorios[i])+"{label="+QString::number(root.avd_ap_array_subdirectorios[i])+"};\n";
            AVD directo = getAVD(path, inicioAVD, root.avd_ap_array_subdirectorios[i]);

            grapho += getDotAVD(path, directo, inicioAVD, root.avd_ap_array_subdirectorios[i]);
        }

    if(root.avd_ap_arbol_virtual_directorio!=-1){
        grapho += "AVD"+QString::number(n)+"->AVD"+QString::number(root.avd_ap_arbol_virtual_directorio)+"{label="+QString::number(root.avd_ap_arbol_virtual_directorio)+"};\n";
        AVD indirecto = getAVD(path, inicioAVD, root.avd_ap_arbol_virtual_directorio);

        grapho += getDotAVD(path, indirecto, inicioAVD, root.avd_ap_arbol_virtual_directorio);
    }

    return grapho;
}

QString Procedures::getDotAVD2(QString path, AVD root, int inicioAVD, int n){

    QString grapho="";

    grapho += "AVD"+QString::number(n)+" [shape=record fillcolor=ivory label=\"";
    grapho += "{";
    grapho += QString::fromLatin1(root.avd_nombre_directorio).remove('\000')+"|";
    grapho += "{";

    if(root.avd_ap_array_subdirectorios[0]!=-1)
    grapho += "<ap0>"+QString::number(root.avd_ap_array_subdirectorios[0])+"|";
    else
    grapho += " |";

    if(root.avd_ap_array_subdirectorios[1]!=-1)
    grapho += "<ap1>"+QString::number(root.avd_ap_array_subdirectorios[1])+"|";
    else
    grapho += " |";

    if(root.avd_ap_array_subdirectorios[2]!=-1)
    grapho += "<ap2>"+QString::number(root.avd_ap_array_subdirectorios[2])+"|";
    else
    grapho += " |";

    if(root.avd_ap_array_subdirectorios[3]!=-1)
    grapho += "<ap3>"+QString::number(root.avd_ap_array_subdirectorios[3])+"|";
    else
    grapho += " |";

    if(root.avd_ap_array_subdirectorios[4]!=-1)
    grapho += "<ap4>"+QString::number(root.avd_ap_array_subdirectorios[4])+"|";
    else
    grapho += " |";

    if(root.avd_ap_array_subdirectorios[5]!=-1)
    grapho += "<ap5>"+QString::number(root.avd_ap_array_subdirectorios[5])+"|";
    else
    grapho += " |";

    if(root.avd_ap_detalle_directorio!=-1)
    grapho += QString::number(root.avd_ap_detalle_directorio)+"|";
    else
    grapho += " |";

    if(root.avd_ap_arbol_virtual_directorio!=-1)
    grapho += "<ap7>"+QString::number(root.avd_ap_arbol_virtual_directorio);
    else
    grapho += " ";

    grapho += "}";
    grapho += "}\"";
    grapho += "];\n";

    for (int i=0; i<6;i++)
        if(root.avd_ap_array_subdirectorios[i]!=-1){

            grapho += "AVD"+QString::number(n)+":<ap"+QString::number(i)+">->AVD"+QString::number(root.avd_ap_array_subdirectorios[i])+";\n";
            AVD directo = getAVD(path, inicioAVD, root.avd_ap_array_subdirectorios[i]);

            grapho += getDotAVD2(path, directo, inicioAVD, root.avd_ap_array_subdirectorios[i]);
        }

    if(root.avd_ap_arbol_virtual_directorio!=-1){
        grapho += "AVD"+QString::number(n)+":<ap7>->AVD"+QString::number(root.avd_ap_arbol_virtual_directorio)+";\n";
        AVD indirecto = getAVD(path, inicioAVD, root.avd_ap_arbol_virtual_directorio);

        grapho += getDotAVD2(path, indirecto, inicioAVD, root.avd_ap_arbol_virtual_directorio);
    }

    return grapho;
}

bool Procedures::generateRepDirectorio(QString path, QString id)
{
    createDirectory(path);
    QStringList carpetas = path.split('/', QString::SkipEmptyParts);

    MOUNTEDPARTITION mountedPartition = getMountedPartition(id);
    QString pathmountedPartition = getPathMountedPartition(id);

    SUPERBOOT sb = getSuperBoot(pathmountedPartition, mountedPartition.part_start);

    AVD root = getAVD(pathmountedPartition,sb.sb_ap_arbol_directory,0);

    QString grapho = "digraph structs {\n";
    grapho += "splines = ortho\n";
    grapho += getDotAVD2(pathmountedPartition,root,sb.sb_ap_arbol_directory,0);
    grapho += "}\n";

    QFile qFile("repDIRECTORIO.dot");
    if(qFile.open(QIODevice::WriteOnly))
    {
        QTextStream out(&qFile);
        out << grapho;
        qFile.close();
    }

    generateRep("repDIRECTORIO.dot",path);
    writeLine("Se genero el reporte correctamente");
    return true;
}
bool Procedures::generateRepTreeFile(QString path, QString id)
{

}
bool Procedures::generateRepTreeDirectorio(QString path, QString id)
{

}
bool Procedures::generateRepTreeComplete(QString path, QString id)
{

}
bool Procedures::generateRepLs(QString path, QString id, QString ruta)
{

}

int Procedures::getN(int size)
{
    return ( size - static_cast<int>(2*sizeof(SUPERBOOT)))/static_cast<int>( 27 + sizeof(AVD) + sizeof(DD) + 5*sizeof(INODO) + 20*sizeof(BLOCK_DATA) + sizeof(BITACORA));
}

QString Procedures::getPathMountedPartition(QString id)
{
    for(int i =0;i < mounts.size();i++)
    {
        QStringList datos = mounts.at(i).split(',', QString::SkipEmptyParts);
        if(datos[2]==id)
        {
            return datos[0];
        }
    }
    return "";
}

MOUNTEDPARTITION Procedures::getMountedPartition(QString id)
{

    MBR mbr;
    EBR nulo;
    nulo.part_fit = '\0';
    nulo.part_next = 0;
    nulo.part_size = 0;
    nulo.part_start = 0;
    nulo.part_status = '\0';

    MOUNTEDPARTITION retornonulo;
    retornonulo = toMountedPartition(nulo,"");

    for (int i=0;i<16;i++)
        nulo.part_name[i]='\0';

    for(int i =0;i < mounts.size();i++)
    {
        QStringList datos = mounts.at(i).split(',', QString::SkipEmptyParts);
        if(datos[2]==id)
        {
            mbr = getMBR(datos[0],0);


            QStringList directorios = datos[0].split('/', QString::SkipEmptyParts);

            QString hd = directorios.at(directorios.length()-1).split('.', QString::SkipEmptyParts)[0];

            if(QString::fromLatin1(mbr.mbr_partition_1.part_name,sizeof(mbr.mbr_partition_1.part_name)).remove('\000')==datos[1])
                return toMountedPartition(mbr.mbr_partition_1, hd);
            else if(QString::fromLatin1(mbr.mbr_partition_2.part_name,sizeof(mbr.mbr_partition_2.part_name)).remove('\000')==datos[1])
                return toMountedPartition(mbr.mbr_partition_2, hd);
            else if(QString::fromLatin1(mbr.mbr_partition_3.part_name,sizeof(mbr.mbr_partition_3.part_name)).remove('\000')==datos[1])
                return toMountedPartition(mbr.mbr_partition_3, hd);
            else if(QString::fromLatin1(mbr.mbr_partition_4.part_name,sizeof(mbr.mbr_partition_4.part_name)).remove('\000')==datos[1])
                return toMountedPartition(mbr.mbr_partition_4, hd);

            int inicio = -1;
            int fin = -1;

            EBR tmp = nulo;

            if(mbr.mbr_partition_1.part_status=='1' && mbr.mbr_partition_1.part_type=='E')
            {
                inicio = mbr.mbr_partition_1.part_start;
                fin = mbr.mbr_partition_1.part_start + mbr.mbr_partition_1.part_size;
            }
            if(mbr.mbr_partition_2.part_status=='1' && mbr.mbr_partition_2.part_type=='E')
            {
                inicio = mbr.mbr_partition_2.part_start;
                fin = mbr.mbr_partition_2.part_start + mbr.mbr_partition_2.part_size;
            }
            if(mbr.mbr_partition_3.part_status=='1' && mbr.mbr_partition_3.part_type=='E')
            {
                inicio = mbr.mbr_partition_3.part_start;
                fin = mbr.mbr_partition_3.part_start + mbr.mbr_partition_3.part_size;
            }
            if(mbr.mbr_partition_4.part_status=='1' && mbr.mbr_partition_4.part_type=='E')
            {
                inicio = mbr.mbr_partition_4.part_start;
                fin = mbr.mbr_partition_4.part_start + mbr.mbr_partition_4.part_size;
            }

            if(inicio!=-1)
            {
                int pos= inicio;
                tmp = getEBR(datos.at(0).toUtf8(),pos);
                if( tmp.part_status != '\0')
                {
                    do
                    {
                        if(QString::fromLatin1(tmp.part_name,sizeof(tmp.part_name)).remove('\000') ==  datos[1])
                        {
                            return toMountedPartition(tmp, hd);
                        }
                        pos = tmp.part_next;
                        tmp = nulo;
                        if(pos!=-1)
                            tmp = getEBR(datos.at(0).toUtf8(),pos);
                    }
                    while(tmp.part_status != '\0');
                }
            }
        }
    }
    return retornonulo;
}
MOUNTEDPARTITION Procedures::toMountedPartition(PARTITION partition, QString hd)
{
    MOUNTEDPARTITION retorno;

    for (int i=0;i<16;i++)
        if(i<hd.size())
            retorno.hd[i]= hd.at(i).toLatin1();
        else
            retorno.hd[i] = '\0';

    retorno.part_fit = partition.part_fit;
    retorno.part_size = partition.part_size;
    retorno.part_type = partition.part_type;
    retorno.part_start = partition.part_start;
    retorno.part_status = partition.part_status;

    return retorno;
}
MOUNTEDPARTITION Procedures::toMountedPartition(EBR ebr, QString hd){
    MOUNTEDPARTITION retorno;

    for (int i=0;i<16;i++)
        if(i<hd.size())
            retorno.hd[i]= hd.at(i).toLatin1();
        else
            retorno.hd[i] = '\0';

    retorno.part_fit = ebr.part_fit;
    retorno.part_size = ebr.part_size - static_cast<int>(sizeof(EBR));
    retorno.part_type = 'L';
    retorno.part_start = ebr.part_start  + static_cast<int>(sizeof(EBR));
    retorno.part_status = ebr.part_status;

    return retorno;
}

char* Procedures::createBM(int n){
    char* BM= new char[n];
    for (int i=0; i<n;i++)
        BM[i] = '0';

    return BM;
}
void Procedures::setBitMap(QString path, char* bitmap, int pos)
{
    ifstream exist(path.toUtf8(),ios::in);

    if(exist.good())
    {
        ofstream file( path.toUtf8(), ios::in | ios::out | ios::binary);

        writeLine("Insertando el BITMAP espere...");

        file.seekp(pos);
        file.write(reinterpret_cast<char*>(&bitmap), static_cast<int>(strlen(bitmap)));

        file.close();
        exist.close();
        writeLine("se inserto el BITMAP con éxito");
    }
    else
        writeError("Disco no existe en la ubicación");
}
char* Procedures::getBitMap(QString path, int n, int pos)
{
    char* retorno = new char[n];

    ifstream file(path.toUtf8());
    if(file.is_open())
    {
        file.seekg(pos,ios::beg);
        file.read(reinterpret_cast<char*>(&retorno),static_cast<int>(strlen(retorno)));
        file.close();
    }

    return retorno;
}
int Procedures::getFirstFreeBM(char* bitmap){
    for (int i=0;i<static_cast<int>(strlen(bitmap));i++)
        if(bitmap[i]=='0')
            return i;

    return -1;
}

SUPERBOOT Procedures::createSuperBoot(MOUNTEDPARTITION mountedPartition){
    SUPERBOOT retorno;
    int n = getN(mountedPartition.part_size);

    strcpy(retorno.sb_nombre_hd,mountedPartition.hd);

    retorno.sb_arbol_virtual_count = n;
    retorno.sb_detalle_directory_count = n;
    retorno.sb_inodos_count = 5*n;
    retorno.sb_bloques_count = 20*n;
    retorno.sb_arbol_virtual_free = n;
    retorno.sb_detalle_directory_free = n;
    retorno.sb_inodos_free = 5*n;
    retorno.sb_bloques_free = 20*n;
    retorno.sb_date_creacion = time(nullptr);
    retorno.sb_date_ultimo_montaje = time(nullptr);
    retorno.sb_montaje_count = 0;
    retorno.sb_ap_bitmap_arbol_directorio = mountedPartition.part_start + static_cast<int>(sizeof(SUPERBOOT));
    retorno.sb_ap_arbol_directory = mountedPartition.part_start + static_cast<int>(sizeof(SUPERBOOT)) + n ;
    retorno.sb_ap_bitmap_detalle_directory = mountedPartition.part_start + static_cast<int>(sizeof(SUPERBOOT)) + n + n*static_cast<int>(sizeof(AVD));
    retorno.sb_ap_detalle_directory = mountedPartition.part_start + static_cast<int>(sizeof(SUPERBOOT)) + n + n*static_cast<int>(sizeof(AVD)) + n;
    retorno.sb_ap_bitmap_table_inodo = mountedPartition.part_start + static_cast<int>(sizeof(SUPERBOOT)) + n + n*static_cast<int>(sizeof(AVD)) + n + n*static_cast<int>(sizeof(DD));
    retorno.sb_ap_table_inodo = mountedPartition.part_start + static_cast<int>(sizeof(SUPERBOOT)) + n + n*static_cast<int>(sizeof(AVD)) + n + n*static_cast<int>(sizeof(DD)) + 5*n;
    retorno.sb_ap_bitmap_bloques = mountedPartition.part_start + static_cast<int>(sizeof(SUPERBOOT)) + n + n*static_cast<int>(sizeof(AVD)) + n + n*static_cast<int>(sizeof(DD)) + 5*n + 5*n*static_cast<int>(sizeof(INODO));
    retorno.sb_ap_bloques = mountedPartition.part_start + static_cast<int>(sizeof(SUPERBOOT)) + n + n*static_cast<int>(sizeof(AVD)) + n + n*static_cast<int>(sizeof(DD)) + 5*n + 5*n*static_cast<int>(sizeof(INODO)) + 20*n;
    retorno.sb_ap_log = mountedPartition.part_start + static_cast<int>(sizeof(SUPERBOOT)) + n + n*static_cast<int>(sizeof(AVD)) + n + n*static_cast<int>(sizeof(DD)) + 5*n + 5*n*static_cast<int>(sizeof(INODO)) + 20*n + 20*n*static_cast<int>(sizeof(BLOCK_DATA));
    retorno.size_struct_arbol_directorio = static_cast<int>(sizeof(AVD));
    retorno.size_struct_detalle_directorio = static_cast<int>(sizeof(DD));
    retorno.size_struct_inodo = static_cast<int>(sizeof(INODO));
    retorno.size_struct_bloque = static_cast<int>(sizeof(BLOCK_DATA));
    retorno.sb_first_free_bit_arbol_directorio = 0;
    retorno.sb_first_free_bit_detalle_directorio = 0;
    retorno.sb_first_free_bit_tabla_inodo = 0;
    retorno.sb_first_free_bit_bloques = 0;
    retorno.sb_magic_num = 201113915;

    return retorno;
}
void Procedures::setSuperBoot(QString path, SUPERBOOT superblock, int pos)
{
    ifstream exist(path.toUtf8(),ios::in);

    if(exist.good())
    {
        ofstream file( path.toUtf8(), ios::in | ios::out | ios::binary);

        writeLine("Insertando el SUPERBOOT espere...");

        file.seekp(pos);
        file.write(reinterpret_cast<char*>(&superblock),sizeof(SUPERBOOT));

        file.close();

        exist.close();
        writeLine("se inserto el SUPERBOOT con éxito");
    }
    else
        writeError("Disco no existe en la ubicación");
}
SUPERBOOT Procedures::getSuperBoot(QString path, int pos)
{
    SUPERBOOT retorno;
    ifstream file(path.toUtf8());
    if(file.is_open())
    {
        file.seekg(pos,ios::beg);
        file.read(reinterpret_cast<char*>(&retorno),sizeof(SUPERBOOT));
        file.close();
    }
    return retorno;
}

AVD Procedures::createAVD(QString name, int det, int usr){
    AVD retorno;

    retorno.avd_fecha_creacion = time(nullptr);

    for (int i=0;i<20;i++)
        if(i<name.size())
            retorno.avd_nombre_directorio[i] = name.at(i).toLatin1();
        else
            retorno.avd_nombre_directorio[i] = '\0';

    for (int i=0; i<6; i++) {
        retorno.avd_ap_array_subdirectorios[i] =-1;
    }

    retorno.avd_ap_detalle_directorio = det;
    retorno.avd_ap_arbol_virtual_directorio = -1;
    retorno.avd_proper = usr;

    return retorno;
}
void Procedures::setAVD(QString path, AVD avd, int start, int n)
{
    ifstream exist(path.toUtf8(),ios::in);

    if(exist.good())
    {
        ofstream file( path.toUtf8(), ios::in | ios::out | ios::binary);

        writeLine("Insertando el AVD espere...");

        file.seekp(start + n*static_cast<int>(sizeof(AVD)));
        file.write(reinterpret_cast<char*>(&avd),sizeof(AVD));

        file.close();

        exist.close();
        writeLine("se inserto el AVD con éxito");
    }
    else
        writeError("Disco no existe en la ubicación");
}
AVD Procedures::getAVD(QString path, int start, int n)
{
    AVD retorno;
    ifstream file(path.toUtf8());
    if(file.is_open())
    {
        file.seekg(start + n*static_cast<int>(sizeof(AVD)),ios::beg);
        file.read(reinterpret_cast<char*>(&retorno),sizeof(AVD));
        file.close();
    }
    return retorno;
}

BLOCK_FILE Procedures::createBlockFile(QString name, int ap_inodo){
    BLOCK_FILE retorno;

    for (int i=0;i<20;i++)
        if(i<name.size())
            retorno.dd_file_nombre[i] = name.at(i).toLatin1();
        else
            retorno.dd_file_nombre[i] = '\0';

    retorno.dd_file_ap_inodo = ap_inodo;

    retorno.dd_file_date_creation = time(nullptr);
    retorno.dd_file_date_modificacion = time(nullptr);

    return retorno;
}

DD Procedures::createDD(){
    DD retorno;

    for (int i=0; i<5;i++)
        retorno.dd_array_files[i] = createBlockFile("",-1);

    retorno.dd_ap_detalle_directorio = -1;

    return retorno;
}
void Procedures::setDD(QString path, DD dd, int start, int n)
{
    ifstream exist(path.toUtf8(),ios::in);

    if(exist.good())
    {
        ofstream file( path.toUtf8(), ios::in | ios::out | ios::binary);

        writeLine("Insertando el DD espere...");

        file.seekp(start + n*static_cast<int>(sizeof(DD)));
        file.write(reinterpret_cast<char*>(&dd),sizeof(DD));

        file.close();

        exist.close();
        writeLine("se inserto el DD con éxito");
    }
    else
        writeError("Disco no existe en la ubicación");
}
DD Procedures::getDD(QString path, int start, int n)
{
    DD retorno;
    ifstream file(path.toUtf8());
    if(file.is_open())
    {
        file.seekg(start + n*static_cast<int>(sizeof(DD)),ios::beg);
        file.read(reinterpret_cast<char*>(&retorno),sizeof(DD));
        file.close();
    }
    return retorno;
}

INODO Procedures::createInodo(int inodo, int size, int proper){
    INODO retorno;

    retorno.i_count_inodo = inodo;
    retorno.i_size_archivo = size;
    retorno.i_count_bloques_asignados = 0;

    for (int i=0; i<4; i++)
        retorno.i_array_bloques[i]=-1;

    retorno.i_ap_indirecto = -1;
    retorno.I_id_proper = proper;

    return retorno;
}
void Procedures::setInodo(QString path, INODO inodo, int start, int n)
{
    ifstream exist(path.toUtf8(),ios::in);

    if(exist.good())
    {
        ofstream file( path.toUtf8(), ios::in | ios::out | ios::binary);

        writeLine("Insertando el INODO espere...");

        file.seekp(start + n*static_cast<int>(sizeof(INODO)));
        file.write(reinterpret_cast<char*>(&inodo),sizeof(INODO));

        file.close();

        exist.close();
        writeLine("se inserto el INODO con éxito");
    }
    else
        writeError("Disco no existe en la ubicación");
}
INODO Procedures::getInodo(QString path, int start, int n)
{
    INODO retorno;
    ifstream file(path.toUtf8());
    if(file.is_open())
    {
        file.seekg(start + n*static_cast<int>(sizeof(INODO)),ios::beg);
        file.read(reinterpret_cast<char*>(&retorno),sizeof(INODO));
        file.close();
    }
    return retorno;
}

BLOCK_DATA Procedures::createBlockData(QString block){
    BLOCK_DATA retorno;

    for (int i=0;i<25;i++)
        if(i<block.size())
            retorno.bd_data[i] = block.at(i).toLatin1();
        else
            retorno.bd_data[i] = '\0';

    return retorno;
}
void Procedures::setBlockData(QString path, BLOCK_DATA blockdata, int start, int n)
{
    ifstream exist(path.toUtf8(),ios::in);

    if(exist.good())
    {
        ofstream file( path.toUtf8(), ios::in | ios::out | ios::binary);

        writeLine("Insertando el BLOCK_DATA espere...");

        file.seekp(start + n*static_cast<int>(sizeof(BLOCK_DATA)));
        file.write(reinterpret_cast<char*>(&blockdata),sizeof(BLOCK_DATA));

        file.close();

        exist.close();
        writeLine("se inserto el BLOCK_DATA con éxito");
    }
    else
        writeError("Disco no existe en la ubicación");
}
BLOCK_DATA Procedures::getBlockData(QString path, int start, int n)
{
    BLOCK_DATA retorno;
    ifstream file(path.toUtf8());
    if(file.is_open())
    {
        file.seekg(start + n*static_cast<int>(sizeof(BLOCK_DATA)),ios::beg);
        file.read(reinterpret_cast<char*>(&retorno),sizeof(BLOCK_DATA));
        file.close();
    }
    return retorno;
}

BITACORA Procedures::createBitacora(MOUNTEDPARTITION mountedPartition){
    BITACORA retorno;

    return retorno;
}
void Procedures::setBitacora(QString path, BITACORA bitacora, int start, int n)
{
    ifstream exist(path.toUtf8(),ios::in);

    if(exist.good())
    {
        ofstream file( path.toUtf8(), ios::in | ios::out | ios::binary);

        writeLine("Insertando el BITACORA espere...");

        file.seekp(start + n*static_cast<int>(sizeof(BITACORA)));
        file.write(reinterpret_cast<char*>(&bitacora),sizeof(BITACORA));

        file.close();

        exist.close();
        writeLine("se inserto el BITACORA con éxito");
    }
    else
        writeError("Disco no existe en la ubicación");
}
BITACORA Procedures::getBitacora(QString path, int start, int n)
{
    BITACORA retorno;
    ifstream file(path.toUtf8());
    if(file.is_open())
    {
        file.seekg(start + n*static_cast<int>(sizeof(BITACORA)),ios::beg);
        file.read(reinterpret_cast<char*>(&retorno),sizeof(BITACORA));
        file.close();
    }
    return retorno;
}

int Procedures::existCarpetaAVD(QString path, int start, AVD root, QString name)
{
    for (int i=0;i<6;i++)
        if(root.avd_ap_array_subdirectorios[i]!=-1)
            if( QString::fromLatin1(getAVD(path, start, root.avd_ap_array_subdirectorios[i]).avd_nombre_directorio).remove('\000') == name)
                return root.avd_ap_array_subdirectorios[i];

    if(root.avd_ap_arbol_virtual_directorio!=-1)
        return existCarpetaAVD(path, start, getAVD(path, start, root.avd_ap_arbol_virtual_directorio), name);

    return -1;
}
AVD Procedures::getCarpetaAVD(QString path, int start, AVD root, QString name)
{
    AVD nulo = createAVD("",-1,0);

    for (int i=0;i<6;i++)
        if(root.avd_ap_array_subdirectorios[i]!=-1)
            if( QString::fromLatin1(getAVD(path, start, root.avd_ap_array_subdirectorios[i]).avd_nombre_directorio).remove('\000') == name)
                return getAVD(path, start, root.avd_ap_array_subdirectorios[i]);

    if(root.avd_ap_arbol_virtual_directorio!=-1)
        return getCarpetaAVD(path, start, getAVD(path, start, root.avd_ap_arbol_virtual_directorio), name);

    return nulo;
}
bool Procedures::insertarCarpetaAVD(QString path, SUPERBOOT sb, AVD root, int ap_root, QString name, int usr){
    //TODO Hacerla despacio recordar manejar bien los bitmap y agregar el detalle. Y si se crea un nuevo AVD verificar bien lo que se esta realizando.

    for (int i=0; i<6;i++)
        if(root.avd_ap_array_subdirectorios[i]==-1){
            char* BMINODO = getBitMap(path, sb.sb_inodos_count, sb.sb_ap_bitmap_table_inodo);
            char* BMBLOCK = getBitMap(path, sb.sb_bloques_count, sb.sb_ap_bitmap_bloques);
            char* BMDD = getBitMap(path, sb.sb_detalle_directory_count, sb.sb_ap_bitmap_detalle_directory);
            char* BMAVD = getBitMap(path, sb.sb_arbol_virtual_count, sb.sb_ap_bitmap_arbol_directorio);

            int bit_free_DD = getFirstFreeBM(BMDD);
            int bit_free_AVD = getFirstFreeBM(BMAVD);

            root.avd_ap_array_subdirectorios[i] = bit_free_AVD;

            sb.sb_detalle_directory_free--;
            sb.sb_arbol_virtual_free--;

            BMDD[bit_free_DD] = '1';
            BMAVD[bit_free_AVD] = '1';

            DD dd_nuevaCarpeta = createDD();
            AVD nuevaCarpeta = createAVD(name,bit_free_DD, usr);

            setDD(path,dd_nuevaCarpeta,sb.sb_ap_detalle_directory,bit_free_DD);
            setAVD(path, nuevaCarpeta, sb.sb_ap_arbol_directory,bit_free_AVD);
            setAVD(path, root, sb.sb_ap_arbol_directory, ap_root);

            setData(path, sb.sb_ap_bitmap_arbol_directorio - static_cast<int>( sizeof (SUPERBOOT)), sb, BMAVD, BMDD, BMINODO, BMBLOCK);
            return true;
        }

    if(root.avd_ap_arbol_virtual_directorio!=-1)
        return insertarCarpetaAVD(path,sb,getAVD(path,sb.sb_ap_arbol_directory,root.avd_ap_arbol_virtual_directorio),root.avd_ap_arbol_virtual_directorio,name,usr);
    else{
        char* BMINODO = getBitMap(path, sb.sb_inodos_count, sb.sb_ap_bitmap_table_inodo);
        char* BMBLOCK = getBitMap(path, sb.sb_bloques_count, sb.sb_ap_bitmap_bloques);
        char* BMDD = getBitMap(path, sb.sb_detalle_directory_count, sb.sb_ap_bitmap_detalle_directory);
        char* BMAVD = getBitMap(path, sb.sb_arbol_virtual_count, sb.sb_ap_bitmap_arbol_directorio);

        int bit_free_AVD = getFirstFreeBM(BMAVD);

        sb.sb_arbol_virtual_free--;

        BMAVD[bit_free_AVD] = '1';

        root.avd_ap_arbol_virtual_directorio = bit_free_AVD;

        AVD indirectoAVD = createAVD(root.avd_nombre_directorio, -1, usr);

        setAVD(path, indirectoAVD, sb.sb_ap_arbol_directory, bit_free_AVD);
        setAVD(path, root, sb.sb_ap_arbol_directory, ap_root);

        setData(path, sb.sb_ap_bitmap_arbol_directorio - static_cast<int>( sizeof (SUPERBOOT)), sb, BMAVD, BMDD, BMINODO, BMBLOCK);

        insertarCarpetaAVD(path, sb, indirectoAVD, bit_free_AVD, name,usr);
    }

    return false;
}

bool Procedures::existArchivoDD(QString path, int start, DD root, QString name){

}
int Procedures::insertarArchivoDD(QString path, SUPERBOOT sb, DD root, QString name, int size, QString cont){
    //TODO Hacerla despacio recordar manejar bien los bitmap y los apuntatadores del detalle. Verificar bien lo que se esta realizando.
}

void Procedures::setData(QString path , int startsb, SUPERBOOT sb, char* BMAVD, char*BMDD, char* BMINODO, char* BMBLOCK){

    sb.sb_first_free_bit_arbol_directorio = getFirstFreeBM(BMAVD);
    sb.sb_first_free_bit_detalle_directorio = getFirstFreeBM(BMDD);
    sb.sb_first_free_bit_tabla_inodo =getFirstFreeBM(BMINODO);
    sb.sb_first_free_bit_bloques = getFirstFreeBM(BMBLOCK);

    setSuperBoot(path, sb, startsb);

    setBitMap(path, BMAVD, sb.sb_ap_bitmap_arbol_directorio);
    setBitMap(path, BMDD, sb.sb_ap_bitmap_detalle_directory);
    setBitMap(path, BMINODO, sb.sb_ap_bitmap_table_inodo);
    setBitMap(path, BMBLOCK, sb.sb_ap_bitmap_bloques);

    setSuperBoot(path,sb, sb.sb_ap_log + sb.sb_arbol_virtual_count * static_cast<int>(sizeof(BITACORA)));

}

void Procedures::formatPartition(QString id, QString type)
{
    MOUNTEDPARTITION mountedPartition =  getMountedPartition(id);
    QString pathmountedPartition = getPathMountedPartition(id);

    if((mountedPartition.part_type == 'P')||(mountedPartition.part_type == 'L')){

        SUPERBOOT sb = createSuperBoot(mountedPartition);

        AVD avd = createAVD("/",0,1);

        DD dd = createDD();
        dd.dd_array_files[0]= createBlockFile("user.txt",0);

        INODO usertxt = createInodo(0,0,1);
        usertxt.i_array_bloques[0]=0;
        usertxt.i_array_bloques[0]=1;

        BLOCK_DATA bduser1 = createBlockData("1, G, root \n 1, U, root,");
        BLOCK_DATA bduser2 = createBlockData(" root, 201113915 \n");

        sb.sb_inodos_free--;
        sb.sb_arbol_virtual_free--;
        sb.sb_detalle_directory_free--;
        sb.sb_bloques_free--;
        sb.sb_bloques_free--;

        char* BMAVD = createBM(sb.sb_arbol_virtual_count);
        char* BMDD = createBM(sb.sb_detalle_directory_count);
        char* BMINODO = createBM(sb.sb_inodos_count);
        char* BMBLOCK = createBM(sb.sb_bloques_count);

        BMAVD[0] = '1';
        BMDD[0] = '1';
        BMINODO[0] = '1';
        BMBLOCK[0] = '1';
        BMBLOCK[1] = '1';

        setSuperBoot(pathmountedPartition, sb, mountedPartition.part_start);

        setAVD(pathmountedPartition, avd, sb.sb_ap_arbol_directory, 0);

        setDD(pathmountedPartition, dd,sb.sb_ap_detalle_directory, 0);

        setInodo(pathmountedPartition, usertxt, sb.sb_ap_table_inodo, 0);

        setBlockData(pathmountedPartition, bduser1, sb.sb_ap_bloques, 0);
        setBlockData(pathmountedPartition, bduser2, sb.sb_ap_bloques, 1);

        //TODO agregar log crearcarpeta "/" y archivo "/users.txt"

        setData(pathmountedPartition, mountedPartition.part_start, sb, BMAVD, BMDD, BMINODO,BMBLOCK);

        writeLine("Se formateo la partición con éxito.");
    }
    else if (mountedPartition.part_type == 'E')
    {
        writeError("No se puede formatear una partición extendida.");
    }
    else if (mountedPartition.part_type == '\0')
    {
        writeError("La partición que se busca no esta montada aun.");
    }

}
bool Procedures::inicioSesion(QString usr, QString pwd, QString id)
{

}
void Procedures::cerrarSesion()
{

}
void Procedures::removerGrupo(QString name)
{

}
void Procedures::crearUsuario(QString usr, QString pwd, QString grp)
{

}
void Procedures::removerUsuario(QString usr)
{

}
void Procedures::cambiarPermisos(QString path, QString ugo, bool r)
{

}
int Procedures::crearArchivoNuevo(QString id, QString path, bool p, int size, QString cont)
{
    QStringList carpetas = path.split('/', QString::SkipEmptyParts);

    MOUNTEDPARTITION mountedPartition = getMountedPartition(id);
    QString pathmountedPartition = getPathMountedPartition(id);

    SUPERBOOT sb = getSuperBoot(pathmountedPartition, mountedPartition.part_start);

    int pos = 0;
    int ap_root = 0;

    AVD root = getAVD(pathmountedPartition, sb.sb_ap_arbol_directory, ap_root);

    if (p == true){
        while(pos<carpetas.length()){

            if(pos<carpetas.length()-1)
            {
                if(!(existCarpetaAVD(pathmountedPartition, sb.sb_ap_arbol_directory, root, carpetas[pos])!=-1)){//TODO Revisar este procedimiento ya que no funciona.
                    insertarCarpetaAVD(pathmountedPartition, sb, root, ap_root, carpetas[pos], 1);//user 1 cambiar al validad login
                    root = getAVD(pathmountedPartition, sb.sb_ap_arbol_directory, ap_root);
                }
                ap_root = existCarpetaAVD(pathmountedPartition, sb.sb_ap_arbol_directory, root, carpetas[pos]);
                root = getCarpetaAVD(pathmountedPartition, sb.sb_ap_arbol_directory, root, carpetas[pos]);
                pos++;
            }else if (pos == carpetas.length() -1){
                if(!existArchivoDD(pathmountedPartition, sb.sb_ap_arbol_directory, getDD(pathmountedPartition,sb.sb_ap_detalle_directory,root.avd_ap_detalle_directorio), carpetas[pos])){
                    insertarArchivoDD(pathmountedPartition, sb, getDD(pathmountedPartition,sb.sb_ap_detalle_directory,root.avd_ap_detalle_directorio), carpetas[pos], size, cont);
                    //FIXME AP DETALLE DIRECTORIO
                    pos++;
                    return EXITO;
                }else{
                    return EXISTE;
                }
            }
        }
    }else{
        while(pos<carpetas.length()){

            if(pos<carpetas.length()-1)
            {
                if(!(existCarpetaAVD(pathmountedPartition, sb.sb_ap_arbol_directory, root, carpetas[pos])!=-1))
                    return FALLO;
                ap_root = existCarpetaAVD(pathmountedPartition, sb.sb_ap_arbol_directory, root, carpetas[pos]);
                root = getCarpetaAVD(pathmountedPartition, sb.sb_ap_arbol_directory, root, carpetas[pos]);
                pos++;
            }else if (pos == carpetas.length() -1){
                if(!existArchivoDD(pathmountedPartition, sb.sb_ap_arbol_directory, getDD(pathmountedPartition,sb.sb_ap_detalle_directory,root.avd_ap_detalle_directorio), carpetas[pos])){
                    insertarArchivoDD(pathmountedPartition, sb, getDD(pathmountedPartition,sb.sb_ap_detalle_directory,root.avd_ap_detalle_directorio), carpetas[pos], size, cont);
                    //FIXME AP DETALLE DIRECTORIO
                    pos++;
                    return EXITO;
                }else{
                    return EXISTE;
                }
            }
        }
    }
    return FALLO;
}
void Procedures::mostrarContenido(QString archive)
{

}
void Procedures::eliminar(QString path)
{

}
void Procedures::editarArchivo(QString path, QString cont)
{

}
void Procedures::renombrar(QString path, QString name)
{

}
int Procedures::crearCarpetaNueva(QString id, QString path, bool p)
{
    QStringList carpetas = path.split('/', QString::SkipEmptyParts);

    MOUNTEDPARTITION mountedPartition = getMountedPartition(id);
    QString pathmountedPartition = getPathMountedPartition(id);

    SUPERBOOT sb = getSuperBoot(pathmountedPartition, mountedPartition.part_start);

    int pos = 0;
    int ap_root = 0;

    AVD root = getAVD(pathmountedPartition, sb.sb_ap_arbol_directory, ap_root);

    if (p == true){
        while(pos<carpetas.length()){

            if(pos<carpetas.length()-1)
            {
                if(!(existCarpetaAVD(pathmountedPartition, sb.sb_ap_arbol_directory, root, carpetas[pos])!=-1)){//TODO Revisar este procedimiento ya que no funciona.
                    insertarCarpetaAVD(pathmountedPartition, sb, root, ap_root, carpetas[pos], 1);//user 1 cambiar al validad login
                    root = getAVD(pathmountedPartition, sb.sb_ap_arbol_directory, ap_root);
                }
                ap_root = existCarpetaAVD(pathmountedPartition, sb.sb_ap_arbol_directory, root, carpetas[pos]);
                root = getCarpetaAVD(pathmountedPartition, sb.sb_ap_arbol_directory, root, carpetas[pos]);
                pos++;
            }else if (pos == carpetas.length() -1){
                if(!(existCarpetaAVD(pathmountedPartition, sb.sb_ap_arbol_directory, root, carpetas[pos])!=-1)){
                    insertarCarpetaAVD(pathmountedPartition, sb, root, ap_root, carpetas[pos], 1);//user 1 cambiar al validad login
                    pos++;
                    return EXITO;
                }
                else
                    return EXISTE;
            }
        }
    }else{
        while(pos<carpetas.length()){

            if(pos<carpetas.length()-1)
            {
                if(!(existCarpetaAVD(pathmountedPartition, sb.sb_ap_arbol_directory, root, carpetas[pos])!=-1))
                    return FALLO;
                ap_root = existCarpetaAVD(pathmountedPartition, sb.sb_ap_arbol_directory, root, carpetas[pos]);
                root = getCarpetaAVD(pathmountedPartition, sb.sb_ap_arbol_directory, root, carpetas[pos]);
                pos++;
            }else if (pos == carpetas.length() -1){
                if(!(existCarpetaAVD(pathmountedPartition, sb.sb_ap_arbol_directory, root, carpetas[pos])!=-1)){
                    insertarCarpetaAVD(pathmountedPartition, sb, root, ap_root, carpetas[pos], 1);//user 1 cambiar al validad login
                    pos++;
                    return EXITO;
                }else{
                    return EXISTE;
                }
            }
        }
    }
    return FALLO;
}
void Procedures::copiar(QString path, QString dest)
{

}
void Procedures::mover(QString path, QString dest)
{

}
void Procedures::buscar(QString path, QString name)
{

}
void Procedures::cambiarPropietario(QString path, QString usr, bool r)
{

}
void Procedures::cambiarGrupo(QString usr, QString grp)
{

}
void Procedures::perdida(QString id)
{

}
void Procedures::recuperacion(QString id)
{

}
