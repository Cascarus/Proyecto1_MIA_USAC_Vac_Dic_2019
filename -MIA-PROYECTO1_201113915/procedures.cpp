#include "procedures.h"
#include "math.h"
#include "wchar.h"
#include "stdio.h"

#define GetSize(arreglo) static_cast<int>(sizeof(&arreglo)/sizeof(*(arreglo)))

using namespace std;


static int noCommand;
static QStringList disk;
static QStringList letters;
static QList<int> counts;
static QStringList mounts;
static USER userlogin;
static QList<USER> users;
static QList<GROUP> grps;

PERMISOS Procedures::getPermisos(int perm){


    int userPerm = perm / 100;
    int groupPerm = (perm - userPerm*100) /10;
    int otherPerm = perm - userPerm*100 - groupPerm*10;

    PERMISOS permisos;

    permisos.user.ejecucion = userPerm%2;
    permisos.user.escritura = static_cast<int>(userPerm/2)%2;
    permisos.user.lectura = static_cast<int>(static_cast<int>(userPerm/2)/2)%2;

    permisos.group.ejecucion = groupPerm%2;
    permisos.group.escritura = static_cast<int>(groupPerm/2)%2;
    permisos.group.lectura = static_cast<int>(static_cast<int>(groupPerm/2)/2)%2;

    permisos.other.ejecucion = otherPerm%2;
    permisos.other.escritura = static_cast<int>(otherPerm/2)%2;
    permisos.other.lectura = static_cast<int>(static_cast<int>(otherPerm/2)/2)%2;

    return permisos;
}
USER Procedures::getUser(int id){
    USER nulo = createUser(-1,-1,"","","","");
    for (int i=0; i<users.length(); i++)
        if(users[i].usr==id)
            return users[i];

    return nulo;
}
bool Procedures::getPermisoLectura(int userProper, int user, PERMISOS perm){
    if(userProper == user)
        return perm.user.lectura;
    else if (getUser(user).grp==getUser(userProper).grp)
        return perm.group.lectura;
    else
        return perm.other.lectura;
}
bool Procedures::getPermisoEscritura(int userProper, int user, PERMISOS perm){
    if(userProper == user)
        return perm.user.escritura;
    else if (getUser(user).grp==getUser(userProper).grp)
        return perm.group.escritura;
    else
        return perm.other.escritura;
}

USER Procedures::getUserLogin(){
    return userlogin;
}

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

QString Procedures::createBitMap(int n){
    QString bitmap = "";
    for (int i=0; i<n;i++)
        bitmap.append('0');

    return bitmap;
}
void Procedures::setBitMap(QString path, QString bitmap, int pos)
{

    char caracter = ' ';
    ifstream exist(path.toUtf8(),ios::in);

    if(exist.good())
    {
        ofstream file( path.toUtf8(), ios::in | ios::out | ios::binary);

        writeLine("Insertando el BITMAP espere...");



        for (int i=0;i<bitmap.length();i++){
            file.seekp(pos+i);
            caracter = bitmap[i].toLatin1();
            int size = sizeof (caracter);
            file.write(reinterpret_cast<char*>(&caracter), sizeof (caracter));
        }
        file.close();
        exist.close();
        writeLine("se inserto el BITMAP con éxito");
    }
    else
        writeError("Disco no existe en la ubicación");
}
QString Procedures::getBitMap(QString path, int n, int pos)
{
    QString retorno = "";
    char caracter=' ';

    ifstream file(path.toUtf8());
    if(file.is_open())
    {


        for (int i=0;i<n;i++) {
            file.seekg(pos+i,ios::beg);
            file.read(reinterpret_cast<char*>(&caracter), sizeof(caracter));
            retorno.append(caracter);
        }

        file.close();
    }

    return retorno;
}
int Procedures::getFirstFreeBM(QString bitmap){
    for (int i=0; i<bitmap.length(); i++)
        if(bitmap[i]=='0')
            return i;

    return -1;
}

SUPERBOOT Procedures::createSuperBoot(MOUNTEDPARTITION mountedPartition){
    SUPERBOOT retorno;
    int n = getN(mountedPartition.part_size);

    for (int i=0;i<16;i++)
        if(mountedPartition.hd[i]!='\000')
            retorno.sb_nombre_hd[i] = mountedPartition.hd[i];
        else
            retorno.sb_nombre_hd[i] = '\000';

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

AVD Procedures::createAVD(QString name, int det, int usr,int perm){
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
    retorno.avd_perm = perm;

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

INODO Procedures::createInodo(int inodo, int size, int proper, int perm){
    INODO retorno;

    retorno.i_count_inodo = inodo;
    retorno.i_size_archivo = size;
    retorno.i_count_bloques_asignados = 0;

    for (int i=0; i<4; i++)
        retorno.i_array_bloques[i]=-1;

    retorno.i_ap_indirecto = -1;
    retorno.i_id_proper = proper;
    retorno.i_perm = perm;

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

BITACORA Procedures::createBitacora(int tipo_operacion, int tipo, QString nombre, QString contenido, time_t fecha, QString id, bool recursividad){
    BITACORA retorno;

    retorno.log_tipo_operacion = tipo_operacion;
    retorno.log_tipo = tipo;

    for (int i=0; i<256; i++)
        if(i<nombre.length())
            retorno.log_nombre[i] = nombre[i].toLatin1();
        else
            retorno.log_nombre[i] = '\000';

    for (int i=0; i<256; i++)
        if(i<contenido.length())
            retorno.log_contenido[i] = contenido[i].toLatin1();
        else
            retorno.log_contenido[i] = '\000';

    for (int i=0; i<10; i++)
        if(i<id.length())
            retorno.id[i] = id[i].toLatin1();
        else
            retorno.id[i] = '\000';



    retorno.log_fecha = fecha;
    retorno.recursividad = recursividad;

    return retorno;
}
void Procedures::setBitacora(QString path, BITACORA bitacora, int start,int cantidad)
{
    ifstream exist(path.toUtf8(),ios::in);

    if(exist.good())
    {
        ofstream file( path.toUtf8(), ios::in | ios::out | ios::binary);

        int n = 0;

        for (int i= 0; i<cantidad;i++) {
            BITACORA tmp = getBitacora(path,start,i);

            if(QString::fromLatin1(tmp.log_nombre,256).remove('\000')==""){
                n=i;
                break;
            }

        }

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

USER Procedures::createUser(int usr, int grp, QString namegrp, QString nameusr, QString pwd, QString id)
{
    USER retorno;

    retorno.usr = usr;
    retorno.grp = grp;
    retorno.pwd = pwd;
    retorno.usr = usr;
    retorno.name = nameusr;
    retorno.namegrp = namegrp;
    retorno.id = id;

    return retorno;
}
GROUP Procedures::createGrp(int grp, QString name){
    GROUP retorno;
    retorno.grp = grp;
    retorno.name = name;
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

//Generar QString para .dot
QString Procedures::getDotBitMap(QString titulo, QString bitmap){

    int espacios = 20 - ( bitmap.length() % 20);

    QString grapho="digraph structs {\n";
    grapho += "    bitmap [\n";
    grapho += "        shape = none;\n";
    grapho += "        label = <\n";
    grapho += "            <table border=\"0\" cellborder=\"2\" cellspacing=\"2\" color=\"cyan4\">\n";
    grapho += "                <tr><td colspan=\"20\">"+titulo+"</td></tr>\n";
    grapho += "                <tr>";

    for (int i=0;i<bitmap.length();i++){
        if((i+1)%20==0){
            grapho += "<td>"+bitmap[i]+"</td></tr>\n";
            grapho += "                <tr>";
        }
        else{
            grapho += "<td>"+bitmap[i]+"</td>";
        }

        if(i==bitmap.length()-1){

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
QString Procedures::getDotAVD(QString path, AVD root, int inicioAVD, int n, QString color){

    QString grapho="";

    grapho += "    AVD"+QString::number(n)+" [\n";
    grapho += "        shape = none;\n";
    grapho += "        label = <\n";
    grapho += "            <table border=\"0\" cellborder=\"2\" cellspacing=\"2\" color=\"cyan4\">\n";
    grapho += "                <tr><td colspan=\"8\" bgcolor=\""+color+"\" >"+QString::fromLatin1(root.avd_nombre_directorio).remove('\000')+"</td></tr>\n";
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

    if(root.avd_ap_arbol_virtual_directorio!=-1)
        grapho += "                    <td bgcolor = \"cyan3\">"+QString::number(root.avd_ap_arbol_virtual_directorio)+"</td>\n";
    else
        grapho += "                    <td bgcolor = \"cyan3\"> &nbsp; </td>\n";

    if(root.avd_ap_detalle_directorio!=-1)
        grapho += "                    <td bgcolor = \"greenyellow\">"+QString::number(root.avd_ap_detalle_directorio)+"</td>\n";
    else
        grapho += "                    <td bgcolor = \"greenyellow\"> &nbsp; </td>\n";



    grapho += "                </tr>\n";
    grapho += "            </table>\n";
    grapho += "        >\n";
    grapho += "    ];\n\n";

    for (int i=0; i<6;i++)
        if(root.avd_ap_array_subdirectorios[i]!=-1){

            grapho += "AVD"+QString::number(n)+"->AVD"+QString::number(root.avd_ap_array_subdirectorios[i])+";\n";
            AVD directo = getAVD(path, inicioAVD, root.avd_ap_array_subdirectorios[i]);

            grapho += getDotAVD(path, directo, inicioAVD, root.avd_ap_array_subdirectorios[i],"white");
        }

    if(root.avd_ap_arbol_virtual_directorio!=-1){
        grapho += "AVD"+QString::number(n)+"->AVD"+QString::number(root.avd_ap_arbol_virtual_directorio)+";\n";
        AVD indirecto = getAVD(path, inicioAVD, root.avd_ap_arbol_virtual_directorio);

        grapho += getDotAVD(path, indirecto, inicioAVD, root.avd_ap_arbol_virtual_directorio, "lawngreen");
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

    createDirectory(path);
    MOUNTEDPARTITION mountedPartition = getMountedPartition(id);
    QString pathmountedPartition = getPathMountedPartition(id);

    SUPERBOOT sb = getSuperBoot(pathmountedPartition, mountedPartition.part_start);

    QString grafo = "digraph D{\n";
    grafo += "graph [pad=\"0.5\", nodesep=\"0.5\", ranksep=\"2\"];\n";
    grafo += "node [shape=plain]\n";
    grafo += "rankdir=LR;\n";
    grafo += "arset [label=<\n";
    grafo += "<table border=\"0\" cellborder=\"1\" color=\"dodgerblue3\" cellspacing=\"0\">\n";
    grafo += "<tr> <td colspan=\"2\" bgcolor=\"dodgerblue\"> Reporte SB </td> </tr>\n";
    grafo += "<tr> <td bgcolor=\"dodgerblue\"> DATO EN LA ESTRUCTURA </td><td  bgcolor=\"dodgerblue\"> DESCRIPCIÓN </td> </tr>";
    grafo += "<tr> <td bgcolor=\"lightskyblue1\"> sb_nombre_hd: </td><td bgcolor=\"lightskyblue1\">" + QString::fromLatin1(sb.sb_nombre_hd, 16).remove('\000') + "</td></tr>\n";
    grafo += "<tr> <td> sb_arbol_virtual_count: </td><td>" + QString::number(sb.sb_arbol_virtual_count) + "</td></tr>\n";
    grafo += "<tr> <td bgcolor=\"lightskyblue1\"> sb_detalle_directory_count: </td><td bgcolor=\"lightskyblue1\">" + QString::number(sb.sb_detalle_directory_count) + "</td></tr>\n";
    grafo += "<tr> <td> sb_inodos_count: </td><td>" + QString::number(sb.sb_inodos_count) + "</td></tr>\n";
    grafo += "<tr> <td bgcolor=\"lightskyblue1\"> sb_bloques_count: </td><td bgcolor=\"lightskyblue1\">" + QString::number(sb.sb_bloques_count) + "</td></tr>\n";
    grafo += "<tr> <td> sb_arbol_virtual_free: </td><td>" + QString::number(sb.sb_arbol_virtual_free) + "</td></tr>\n";
    grafo += "<tr> <td bgcolor=\"lightskyblue1\"> sb_detalle_directory_free: </td><td bgcolor=\"lightskyblue1\">" + QString::number(sb.sb_detalle_directory_free) + "</td></tr>\n";
    grafo += "<tr> <td> sb_inodos_free: </td><td>" + QString::number(sb.sb_inodos_free) + "</td></tr>\n";
    grafo += "<tr> <td bgcolor=\"lightskyblue1\"> sb_bloques_free: </td><td bgcolor=\"lightskyblue1\">" + QString::number(sb.sb_bloques_free) + "</td></tr>\n";
    grafo += "<tr> <td> sb_date_creacion: </td><td>" + QString::fromLatin1(generate_mbr_fecha_creacion(sb.sb_date_creacion)) + "</td></tr>\n";
    grafo += "<tr> <td bgcolor=\"lightskyblue1\"> sb_date_ultimo_montaje: </td><td bgcolor=\"lightskyblue1\">" + QString::fromLatin1(generate_mbr_fecha_creacion(sb.sb_date_ultimo_montaje)) + "</td></tr>\n";
    grafo += "<tr> <td> sb_montaje_count: </td><td>" + QString::number(sb.sb_montaje_count) + "</td></tr>\n";
    grafo += "<tr> <td bgcolor=\"lightskyblue1\"> sb_ap_bitmap_arbol_directorio: </td><td bgcolor=\"lightskyblue1\">" + QString::number(sb.sb_ap_bitmap_arbol_directorio) + "</td></tr>\n";
    grafo += "<tr> <td> sb_ap_arbol_directory: </td><td>" + QString::number(sb.sb_ap_arbol_directory) + "</td></tr>\n";
    grafo += "<tr> <td bgcolor=\"lightskyblue1\"> sb_ap_bitmap_detalle_directory: </td><td bgcolor=\"lightskyblue1\">" + QString::number(sb.sb_ap_bitmap_detalle_directory) + "</td></tr>\n";
    grafo += "<tr> <td> sb_ap_detalle_directory: </td><td>" + QString::number(sb.sb_ap_detalle_directory) + "</td></tr>\n";
    grafo += "<tr> <td bgcolor=\"lightskyblue1\"> sb_ap_bitmap_table_inodo: </td><td bgcolor=\"lightskyblue1\">" + QString::number(sb.sb_ap_bitmap_table_inodo) + "</td></tr>\n";
    grafo += "<tr> <td> sb_ap_table_inodo: </td><td>" + QString::number(sb.sb_ap_table_inodo) + "</td></tr>\n";
    grafo += "<tr> <td bgcolor=\"lightskyblue1\"> sb_ap_bitmap_bloques: </td><td bgcolor=\"lightskyblue1\">" + QString::number(sb.sb_ap_bitmap_bloques) + "</td></tr>\n";
    grafo += "<tr> <td> sb_ap_bloques: </td><td>" + QString::number(sb.sb_ap_bloques) + "</td></tr>\n";
    grafo += "<tr> <td bgcolor=\"lightskyblue1\"> sb_ap_log: </td><td bgcolor=\"lightskyblue1\">" + QString::number(sb.sb_ap_log) + "</td></tr>\n";
    grafo += "<tr> <td> size_struct_arbol_directorio: </td><td>" + QString::number(sb.size_struct_arbol_directorio) + "</td></tr>\n";
    grafo += "<tr> <td bgcolor=\"lightskyblue1\"> size_struct_detalle_directorio: </td><td bgcolor=\"lightskyblue1\">" + QString::number(sb.size_struct_detalle_directorio) + "</td></tr>\n";
    grafo += "<tr> <td> size_struct_inodo: </td><td>" + QString::number(sb.size_struct_inodo) + "</td></tr>\n";
    grafo += "<tr> <td bgcolor=\"lightskyblue1\"> size_struct_bloque: </td><td bgcolor=\"lightskyblue1\">" + QString::number(sb.size_struct_bloque) + "</td></tr>\n";
    grafo += "<tr> <td> sb_first_free_bit_arbol_directorio: </td><td>" + QString::number(sb.sb_first_free_bit_arbol_directorio) + "</td></tr>\n";
    grafo += "<tr> <td bgcolor=\"lightskyblue1\"> sb_first_free_bit_detalle_directorio: </td><td bgcolor=\"lightskyblue1\">" + QString::number(sb.sb_first_free_bit_detalle_directorio) + "</td></tr>\n";
    grafo += "<tr> <td> sb_first_free_bit_tabla_inodo: </td><td>" + QString::number(sb.sb_first_free_bit_tabla_inodo) + "</td></tr>\n";
    grafo += "<tr> <td bgcolor=\"lightskyblue1\"> sb_first_free_bit_bloques: </td><td bgcolor=\"lightskyblue1\">" + QString::number(sb.sb_first_free_bit_bloques) + "</td></tr>\n";
    grafo += "<tr> <td> sb_magic_num: </td><td>" + QString::number(sb.sb_magic_num) + "</td></tr>\n";
    grafo += "</table>\n";
    grafo+=">]\n}";
    QFile qFile("repSB.dot");
    if(qFile.open(QIODevice::WriteOnly))
    {
        QTextStream out(&qFile);
        out << grafo;
        qFile.close();
    }

    generateRep("repSB.dot",path);
    writeLine("Se genero el reporte correctamente");
    return true;
}

POINTER Procedures::createPointer(QString name, int pointer){
    POINTER retorno;

    retorno.name = name;
    retorno.pointer = pointer;

    return retorno;
}

QList<POINTER> Procedures::getCarpetasAVD(QString path, int start_avd, AVD avd)
{
    QList<POINTER> list;
    list.clear();
    for (int i=0; i<6; i++) {
        if(avd.avd_ap_array_subdirectorios[i]!=-1){
            AVD carpeta = getAVD(path, start_avd, avd.avd_ap_array_subdirectorios[i]);
            list.append(createPointer(QString::fromLatin1(carpeta.avd_nombre_directorio).remove('\000'), avd.avd_ap_array_subdirectorios[i]));
        }
    }

    if(avd.avd_ap_arbol_virtual_directorio != -1)
    {
        AVD carpeta = getAVD(path, start_avd, avd.avd_ap_arbol_virtual_directorio);
        QList<POINTER> indirecto = getCarpetasAVD(path, start_avd, carpeta);

        for (int i=0; i<indirecto.length(); i++)
            list.append(indirecto[i]);
    }
    return list;
};

QString Procedures::getDotTreeDirectory(QString path, DD detalle, int ap_dd, int start_dd){
    QString color;

    QString grapho = "";
    grapho += "    DD"+QString::number(ap_dd)+" [\n";
    grapho += "        shape = none;\n";
    grapho += "        label = <\n";
    grapho += "            <table border=\"0\" cellborder=\"2\" cellspacing=\"2\" color=\"cyan4\">\n";
    grapho += "                <tr><td colspan=\"2\" bgcolor=\"dodgerblue\" >Detalle "+QString::number(ap_dd)+"</td></tr>\n";
    for (int i=0; i<5; i++) {

        if(i%2)
            color = "deepskyblue";
        else
            color = "lightskyblue1";

        if(detalle.dd_array_files[i].dd_file_ap_inodo!=-1){
            grapho += "                <tr>\n";
            grapho += "                    <td bgcolor=\""+color+"\">"+ QString::fromLatin1(detalle.dd_array_files[i].dd_file_nombre).remove('\000')+"</td>\n";
            grapho += "                    <td bgcolor=\""+color+"\">"+ QString::number(detalle.dd_array_files[i].dd_file_ap_inodo)+"</td>\n";
            grapho += "                </tr>\n";

        }
        else
        {
            grapho += "<tr><td bgcolor=\""+color+"\"> </td><td bgcolor=\""+color+"\"> </td></tr>\n";
        }
    }
    if(detalle.dd_ap_detalle_directorio!=-1){
        grapho += "                <tr>\n";
        grapho += "                    <td colspan=\"2\" bgcolor=\"greenyellow\">"+ QString::number(detalle.dd_ap_detalle_directorio) +"</td>\n";
        grapho += "                </tr>\n";
    }
    else
    {
        grapho += "<tr><td colspan=\"2\" bgcolor=\"greenyellow\"> </td></tr>\n";
    }
    grapho += "            </table>\n";
    grapho += "        >\n";
    grapho += "    ];\n\n";

    if(detalle.dd_ap_detalle_directorio!=-1){
        grapho += "DD"+QString::number(ap_dd)+"->DD"+QString::number(detalle.dd_ap_detalle_directorio)+";\n";
        grapho += getDotTreeDirectory(path, getDD(path, start_dd, detalle.dd_ap_detalle_directorio), detalle.dd_ap_detalle_directorio, start_dd);
    }
    return grapho;
}

QString Procedures::getDotInodo(QString path, INODO archivo, int start_inodos, int ap_inodo, int start_bloques)
{
    QString grapho="";

    grapho =+ "\n";

    grapho += "    INODO"+QString::number(ap_inodo)+" [\n";
    grapho += "        shape = none;\n";
    grapho += "        label = <\n";
    grapho += "            <table border=\"0\" cellborder=\"2\" cellspacing=\"2\" color=\"cyan4\">\n";
    grapho += "                <tr><td bgcolor=\"dodgerblue\" >Inodo"+QString::number(ap_inodo)+"</td></tr>\n";

    for (int i=0; i<4; i++)
    {
        if(archivo.i_array_bloques[i] != -1)
        {
            grapho += "<tr><td>"+QString::number(archivo.i_array_bloques[i])+"</td></tr>\n";
        }
        else
        {
            grapho += "<tr><td> </td></tr>\n";
        }

    }

    if(archivo.i_ap_indirecto!=-1){
        grapho += "<tr><td>"+QString::number(archivo.i_ap_indirecto)+"</td></tr>\n";
    }
    else
    {
        grapho += "<tr><td> </td></tr>\n";
    }
    grapho += "            </table>\n";
    grapho += "        >\n";
    grapho += "    ];\n\n";

    for (int i=0; i<4; i++)
    {
        if(archivo.i_array_bloques[i] != -1)
        {
            grapho += "    INODO"+QString::number(ap_inodo)+"->BLOCK"+QString::number(archivo.i_array_bloques[i])+";\n";
            BLOCK_DATA bloque = getBlockData(path, start_bloques, archivo.i_array_bloques[i]);

            grapho += "BLOCK"+QString::number(archivo.i_array_bloques[i])+"[shape=\"box\" label=\""+QString::fromLatin1(bloque.bd_data,25).remove('\000')+"\"]\n";

        }

    }

    if(archivo.i_ap_indirecto!=-1){
        grapho += "INODO"+QString::number(ap_inodo)+"->INODO"+QString::number(archivo.i_ap_indirecto)+";\n";
        grapho += getDotInodo(path,getInodo(path,start_inodos,archivo.i_ap_indirecto),start_inodos,archivo.i_ap_indirecto,start_bloques);
    }
    return grapho;
}

QString Procedures::getDotTreeComplete(QString path, AVD root, int inicioAVD, int n, QString color, int start_dd, int start_inodes, int start_bloques){
    QString grapho="";

    grapho += "    AVD"+QString::number(n)+" [\n";
    grapho += "        shape = none;\n";
    grapho += "        label = <\n";
    grapho += "            <table border=\"0\" cellborder=\"2\" cellspacing=\"2\" color=\"cyan4\">\n";
    grapho += "                <tr><td colspan=\"8\" bgcolor=\""+color+"\" >"+QString::fromLatin1(root.avd_nombre_directorio).remove('\000')+"</td></tr>\n";
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

    if(root.avd_ap_arbol_virtual_directorio!=-1)
        grapho += "                    <td bgcolor = \"cyan3\">"+QString::number(root.avd_ap_arbol_virtual_directorio)+"</td>\n";
    else
        grapho += "                    <td bgcolor = \"cyan3\"> &nbsp; </td>\n";

    if(root.avd_ap_detalle_directorio!=-1)
        grapho += "                    <td bgcolor = \"greenyellow\">"+QString::number(root.avd_ap_detalle_directorio)+"</td>\n";
    else
        grapho += "                    <td bgcolor = \"greenyellow\"> &nbsp; </td>\n";



    grapho += "                </tr>\n";
    grapho += "            </table>\n";
    grapho += "        >\n";
    grapho += "    ];\n\n";

    for (int i=0; i<6;i++){
        if(root.avd_ap_array_subdirectorios[i]!=-1){

            grapho += "AVD"+QString::number(n)+"->AVD"+QString::number(root.avd_ap_array_subdirectorios[i])+";\n";
            AVD directo = getAVD(path, inicioAVD, root.avd_ap_array_subdirectorios[i]);

            grapho += getDotTreeComplete(path, directo, inicioAVD, root.avd_ap_array_subdirectorios[i],"white", start_dd, start_inodes, start_bloques);
        }
    }

    if(root.avd_ap_arbol_virtual_directorio!=-1){
        grapho += "AVD"+QString::number(n)+"->AVD"+QString::number(root.avd_ap_arbol_virtual_directorio)+";\n";
        AVD indirecto = getAVD(path, inicioAVD, root.avd_ap_arbol_virtual_directorio);
        grapho += getDotTreeComplete(path, indirecto, inicioAVD, root.avd_ap_arbol_virtual_directorio, "lawngreen", start_dd, start_inodes, start_bloques);
    }

    if(root.avd_ap_detalle_directorio!=-1){
        grapho += "AVD"+QString::number(n)+"->DD"+QString::number(root.avd_ap_detalle_directorio)+";\n";
        grapho += getDotDetalleTreeComplete(path,getDD(path,start_dd,root.avd_ap_detalle_directorio), root.avd_ap_detalle_directorio, start_dd, start_inodes, start_bloques);
    }

    return grapho;
}

QString Procedures::getDotDetalleTreeComplete( QString path, DD detalle, int ap_dd, int start_dd, int start_inodes, int start_bloques)
{
    QString color;

    QString grapho = "";
    grapho += "    DD"+QString::number(ap_dd)+" [\n";
    grapho += "        shape = none;\n";
    grapho += "        label = <\n";
    grapho += "            <table border=\"0\" cellborder=\"2\" cellspacing=\"2\" color=\"cyan4\">\n";
    grapho += "                <tr><td colspan=\"2\" bgcolor=\"dodgerblue\" >Detalle "+QString::number(ap_dd)+"</td></tr>\n";
    for (int i=0; i<5; i++) {

        if(i%2)
            color = "deepskyblue";
        else
            color = "lightskyblue1";

        if(detalle.dd_array_files[i].dd_file_ap_inodo!=-1){
            grapho += "                <tr>\n";
            grapho += "                    <td bgcolor=\""+color+"\">"+ QString::fromLatin1(detalle.dd_array_files[i].dd_file_nombre).remove('\000')+"</td>\n";
            grapho += "                    <td bgcolor=\""+color+"\">"+ QString::number(detalle.dd_array_files[i].dd_file_ap_inodo)+"</td>\n";
            grapho += "                </tr>\n";

        }
        else
        {
            grapho += "<tr><td bgcolor=\""+color+"\"> </td><td bgcolor=\""+color+"\"> </td></tr>\n";
        }
    }
    if(detalle.dd_ap_detalle_directorio!=-1){
        grapho += "                <tr>\n";
        grapho += "                    <td colspan=\"2\" bgcolor=\"greenyellow\">"+ QString::number(detalle.dd_ap_detalle_directorio) +"</td>\n";
        grapho += "                </tr>\n";
    }
    else
    {
        grapho += "<tr><td colspan=\"2\" bgcolor=\"greenyellow\"> </td></tr>\n";
    }
    grapho += "            </table>\n";
    grapho += "        >\n";
    grapho += "    ];\n\n";

    for (int i=0; i<5; i++) {
        if(detalle.dd_array_files[i].dd_file_ap_inodo!=-1)
        {
            INODO archivo = getInodo(path, start_inodes, detalle.dd_array_files[i].dd_file_ap_inodo);
            grapho += "DD"+QString::number(ap_dd)+"->INODO"+QString::number(detalle.dd_array_files[i].dd_file_ap_inodo)+";\n";
            grapho += getDotInodo(path, archivo, start_inodes,detalle.dd_array_files[i].dd_file_ap_inodo, start_bloques);
        }
    }

    if(detalle.dd_ap_detalle_directorio!=-1){
        grapho += "DD"+QString::number(ap_dd)+"->DD"+QString::number(detalle.dd_ap_detalle_directorio)+";\n";
        grapho += getDotDetalleTreeComplete(path, getDD(path, start_dd, detalle.dd_ap_detalle_directorio), detalle.dd_ap_detalle_directorio, start_dd, start_inodes, start_bloques);
    }
    return grapho;
}

bool Procedures::generateRepBm_Arbdir(QString path, QString id)
{
    createDirectory(path);

    MOUNTEDPARTITION mountedPartition = getMountedPartition(id);
    QString pathmountedPartition = getPathMountedPartition(id);

    SUPERBOOT sb = getSuperBoot(pathmountedPartition, mountedPartition.part_start);

    QString bitmap = getBitMap(pathmountedPartition, sb.sb_arbol_virtual_count, sb.sb_ap_bitmap_arbol_directorio);

    QFile qFile("repBM_DIRECTORIO.dot");
    if(qFile.open(QIODevice::WriteOnly))
    {
        QTextStream out(&qFile);
        out << getDotBitMap("Bit Map Arbol Directorio",bitmap);
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

    QString bitmap = getBitMap(pathmountedPartition, sb.sb_detalle_directory_count, sb.sb_ap_bitmap_detalle_directory);

    QFile qFile("repBM_DETALLE.dot");
    if(qFile.open(QIODevice::WriteOnly))
    {
        QTextStream out(&qFile);
        out << getDotBitMap("Bit Map Detalle de Directorio", bitmap);
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

    QString bitmap = getBitMap(pathmountedPartition, sb.sb_inodos_count, sb.sb_ap_bitmap_table_inodo);

    QFile qFile("repBM_INODO.dot");
    if(qFile.open(QIODevice::WriteOnly))
    {
        QTextStream out(&qFile);
        out << getDotBitMap("Bit Map de Inodos",bitmap);
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

    QString bitmap = getBitMap(pathmountedPartition, sb.sb_bloques_count, sb.sb_ap_bitmap_bloques);

    QFile qFile("repBM_BLOCK.dot");
    if(qFile.open(QIODevice::WriteOnly))
    {
        QTextStream out(&qFile);
        out << getDotBitMap("Bit Map de bloques",bitmap);
        qFile.close();
    }

    generateRep("repBM_BLOCK.dot",path);
    writeLine("Se genero el reporte correctamente");
    return true;
}
bool Procedures::generateRepBitacora(QString path, QString id)
{

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
    grapho += getDotAVD(pathmountedPartition,root,sb.sb_ap_arbol_directory,0,"white");
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
    createDirectory(path);
    QStringList carpetas = path.split('/', QString::SkipEmptyParts);

    MOUNTEDPARTITION mountedPartition = getMountedPartition(id);
    QString pathmountedPartition = getPathMountedPartition(id);

    SUPERBOOT sb = getSuperBoot(pathmountedPartition, mountedPartition.part_start);

    AVD root = getAVD(pathmountedPartition,sb.sb_ap_arbol_directory,0);

    QList<POINTER> directory = getCarpetasAVD(pathmountedPartition, sb.sb_ap_arbol_directory, root);

    QList<POINTER> directory2;
    bool salir = true;
    do {

        for (int i = 0; i<directory.length(); i++) {
            writeLine(QString::number(i+1)  + " " + directory[i].name);
        }
        writeLine("Ingrese una opción.");
        int opcion = IOConsole::readLine().toInt();

        if(opcion<directory.length()+1){
            writeLine("a. Abrir");
            writeLine("b. Generar Reporte");

            QString opcion2 = IOConsole::readLine();

            if(opcion2.toUpper()=="A"){
                root = getAVD(pathmountedPartition, sb.sb_ap_arbol_directory, directory[opcion-1].pointer);
                directory = getCarpetasAVD(pathmountedPartition, sb.sb_ap_arbol_directory, root);
            }else if(opcion2.toUpper()=="B"){

                root = getAVD(pathmountedPartition, sb.sb_ap_arbol_directory, directory[opcion-1].pointer);

                QString grapho = "digraph structs {\n";
                grapho += "splines = ortho\n";

                grapho += "    AVD"+QString::number(directory[opcion-1].pointer)+" [\n";
                grapho += "        shape = none;\n";
                grapho += "        label = <\n";
                grapho += "            <table border=\"0\" cellborder=\"2\" cellspacing=\"2\" color=\"cyan4\">\n";
                grapho += "                <tr><td colspan=\"8\" bgcolor=\"white\" >"+QString::fromLatin1(root.avd_nombre_directorio).remove('\000')+"</td></tr>\n";
                grapho += "                <tr>\n";
                grapho += "                    <td bgcolor = \"lightcyan\"> &nbsp; </td>\n";
                grapho += "                    <td bgcolor = \"lightcyan\"> &nbsp; </td>\n";
                grapho += "                    <td bgcolor = \"lightcyan\"> &nbsp; </td>\n";
                grapho += "                    <td bgcolor = \"lightcyan\"> &nbsp; </td>\n";
                grapho += "                    <td bgcolor = \"lightcyan\"> &nbsp; </td>\n";
                grapho += "                    <td bgcolor = \"lightcyan\"> &nbsp; </td>\n";
                grapho += "                    <td bgcolor = \"cyan3\"> &nbsp; </td>\n";

                if(root.avd_ap_detalle_directorio!=-1)
                    grapho += "                    <td bgcolor = \"greenyellow\">"+QString::number(root.avd_ap_detalle_directorio)+"</td>\n";
                else
                    grapho += "                    <td bgcolor = \"greenyellow\"> &nbsp; </td>\n";


                grapho += "                </tr>\n";
                grapho += "            </table>\n";
                grapho += "        >\n";
                grapho += "    ];\n\n";

                grapho += "AVD"+QString::number(directory[opcion-1].pointer)+"->"+"DD"+QString::number(root.avd_ap_detalle_directorio)+";\n";

                grapho += getDotTreeDirectory(pathmountedPartition,getDD(pathmountedPartition,sb.sb_ap_detalle_directory,root.avd_ap_detalle_directorio),root.avd_ap_detalle_directorio,sb.sb_ap_detalle_directory);
                grapho += "}\n";

                QFile qFile("repTREE_DIRECTORIO.dot");
                if(qFile.open(QIODevice::WriteOnly))
                {
                    QTextStream out(&qFile);
                    out << grapho;
                    qFile.close();
                }

                generateRep("repTREE_DIRECTORIO.dot",path);
                writeLine("Se genero el reporte correctamente");
                salir = false;
            }
        }

    } while(salir);


    return true;
}
bool Procedures::generateRepTreeComplete(QString path, QString id)
{
    createDirectory(path);
    QStringList carpetas = path.split('/', QString::SkipEmptyParts);

    MOUNTEDPARTITION mountedPartition = getMountedPartition(id);
    QString pathmountedPartition = getPathMountedPartition(id);

    SUPERBOOT sb = getSuperBoot(pathmountedPartition, mountedPartition.part_start);

    AVD root = getAVD(pathmountedPartition,sb.sb_ap_arbol_directory,0);

    QString grapho = "digraph structs {\n";
    grapho += "splines = ortho\n";
    grapho += getDotTreeComplete(pathmountedPartition,root,sb.sb_ap_arbol_directory,0,"white", sb.sb_ap_detalle_directory, sb.sb_ap_table_inodo, sb.sb_ap_bloques);
    grapho += "}\n";

    QFile qFile("repTREE_COMPLETE.dot");
    if(qFile.open(QIODevice::WriteOnly))
    {
        QTextStream out(&qFile);
        out << grapho;
        qFile.close();
    }

    generateRep("repTREE_COMPLETE.dot",path);
    writeLine("Se genero el reporte correctamente");
    return true;
}
bool Procedures::generateRepLs(QString path, QString id, QString ruta)
{

}

int Procedures::getN(int size)
{
    return ( size - static_cast<int>(2*sizeof(SUPERBOOT)))/static_cast<int>( 27 + sizeof(AVD) + sizeof(DD) + 5*sizeof(INODO) + 20*sizeof(BLOCK_DATA) + sizeof(BITACORA));
}

//Metodos para carpetas.
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
AVD Procedures::getCarpetaAVD(QString path, int start, AVD root, QString name, int usr)
{
    AVD nulo = createAVD("", -1, 0, 664);

    PERMISOS perm =  getPermisos(root.avd_perm);

    if(getPermisoLectura(root.avd_proper, usr, perm)){
        for (int i=0;i<6;i++)
            if(root.avd_ap_array_subdirectorios[i]!=-1)
                if( QString::fromLatin1(getAVD(path, start, root.avd_ap_array_subdirectorios[i]).avd_nombre_directorio).remove('\000') == name)
                    return getAVD(path, start, root.avd_ap_array_subdirectorios[i]);

        if(root.avd_ap_arbol_virtual_directorio!=-1)
            return getCarpetaAVD(path, start, getAVD(path, start, root.avd_ap_arbol_virtual_directorio), name, usr);
    }

    return nulo;
}
bool Procedures::insertarCarpetaAVD(QString path, SUPERBOOT sb, AVD root, int ap_root, QString name, int usr){
    PERMISOS perm =  getPermisos(root.avd_perm);

    if(getPermisoEscritura(root.avd_proper, usr, perm)){

        for (int i=0; i<6;i++)
            if(root.avd_ap_array_subdirectorios[i]==-1){
                QString BMDD = getBitMap(path, sb.sb_detalle_directory_count, sb.sb_ap_bitmap_detalle_directory);
                QString BMAVD = getBitMap(path, sb.sb_arbol_virtual_count, sb.sb_ap_bitmap_arbol_directorio);

                int bit_free_DD = getFirstFreeBM(BMDD);
                int bit_free_AVD = getFirstFreeBM(BMAVD);

                root.avd_ap_array_subdirectorios[i] = bit_free_AVD;

                sb.sb_detalle_directory_free--;
                sb.sb_arbol_virtual_free--;

                BMDD[bit_free_DD] = '1';
                BMAVD[bit_free_AVD] = '1';

                DD dd_nuevaCarpeta = createDD();
                AVD nuevaCarpeta = createAVD(name,bit_free_DD, usr, 664);

                setDD(path,dd_nuevaCarpeta,sb.sb_ap_detalle_directory,bit_free_DD);
                setAVD(path, nuevaCarpeta, sb.sb_ap_arbol_directory,bit_free_AVD);
                setAVD(path, root, sb.sb_ap_arbol_directory, ap_root);

                setData(path, sb.sb_ap_bitmap_arbol_directorio - static_cast<int>( sizeof (SUPERBOOT)), sb, BMAVD, BMDD, "", "");
                return true;
            }

        if(root.avd_ap_arbol_virtual_directorio!=-1)
            return insertarCarpetaAVD(path,sb,getAVD(path,sb.sb_ap_arbol_directory,root.avd_ap_arbol_virtual_directorio),root.avd_ap_arbol_virtual_directorio,name,usr);
        else{
            QString BMDD = getBitMap(path, sb.sb_detalle_directory_count, sb.sb_ap_bitmap_detalle_directory);
            QString BMAVD = getBitMap(path, sb.sb_arbol_virtual_count, sb.sb_ap_bitmap_arbol_directorio);

            int bit_free_AVD = getFirstFreeBM(BMAVD);

            sb.sb_arbol_virtual_free--;

            BMAVD[bit_free_AVD] = '1';

            root.avd_ap_arbol_virtual_directorio = bit_free_AVD;

            AVD indirectoAVD = createAVD(root.avd_nombre_directorio, -1, usr, 664);

            setAVD(path, indirectoAVD, sb.sb_ap_arbol_directory, bit_free_AVD);
            setAVD(path, root, sb.sb_ap_arbol_directory, ap_root);

            setData(path, sb.sb_ap_bitmap_arbol_directorio - static_cast<int>( sizeof (SUPERBOOT)), sb, BMAVD, BMDD, "", "");

            insertarCarpetaAVD(path, sb, indirectoAVD, bit_free_AVD, name,usr);
        }

    }
    return false;
}
bool Procedures::removerCarpetaAVD(QString path, SUPERBOOT sb, AVD root, int ap_root, int usr){
    bool retorno= true;
    PERMISOS perm =  getPermisos(root.avd_perm);

    if(getPermisoEscritura(root.avd_proper, usr, perm)){
        for (int i=0; i<6;i++) {
            if (root.avd_ap_array_subdirectorios[i]!=-1)
            {
                if(removerCarpetaAVD(path,sb,getAVD(path,sb.sb_ap_arbol_directory,root.avd_ap_array_subdirectorios[i]),root.avd_ap_array_subdirectorios[i],usr)){

                }
            }


        }
    }
    return retorno;
}

//Metodos para archivos.
bool Procedures::existArchivoDD(QString path, int start, DD root, QString name){
    for (int i = 0; i<5; i++) {
        if(root.dd_array_files[i].dd_file_ap_inodo!=-1){
            if(QString::fromLatin1(root.dd_array_files[i].dd_file_nombre).remove('\000')==name)
                return true;
        }
    }
    if(root.dd_ap_detalle_directorio!=-1){
        return existArchivoDD(path, start, getDD(path,start,root.dd_ap_detalle_directorio),name);
    }
    return false;
}
bool Procedures::insertFileDD(QString path, SUPERBOOT sb, int ap_sb, DD root, int ap_root, QString name, int size, QString cont, int usr, int perm){

    QString BMINODO = getBitMap(path, sb.sb_inodos_count, sb.sb_ap_bitmap_table_inodo);

    int bitfreeINODO = getFirstFreeBM(BMINODO);

    INODO archivo = createInodo(bitfreeINODO,size,usr,perm);

    for (int i = 0; i<5; i++) {
        if(root.dd_array_files[i].dd_file_ap_inodo==-1){
            BMINODO[bitfreeINODO] = '1';
            root.dd_array_files[i] = createBlockFile(name,bitfreeINODO);

            setDD(path,root,sb.sb_ap_detalle_directory,ap_root);
            setInodo(path,archivo,sb.sb_ap_table_inodo,bitfreeINODO);

            setData(path, ap_sb, sb,"","",BMINODO,"");

            if(cont!="")
                insertTextFile(path,sb,ap_sb,archivo,bitfreeINODO,cont);

            return true;
        }
    }
    if(root.dd_ap_detalle_directorio!=-1){
        return insertFileDD(path,sb,ap_sb, getDD(path,sb.sb_ap_detalle_directory,root.dd_ap_detalle_directorio), root.dd_ap_detalle_directorio,name,size,cont,usr,perm);
    }else{
        QString BMDD = getBitMap(path, sb.sb_detalle_directory_count, sb.sb_ap_bitmap_detalle_directory);
        int bitfreeDD = getFirstFreeBM(BMDD);
        BMDD[bitfreeDD] = '1';

        DD indirecto = createDD();
        setDD(path,indirecto,sb.sb_ap_detalle_directory,bitfreeDD);
        setData(path,ap_sb, sb,"",BMDD,"","");

        return insertFileDD(path,sb,ap_sb,indirecto, bitfreeDD,name,size,cont,usr,perm);

    }

}
INODO Procedures::getInodoDD(QString path, int start_inodes, int start_dd, DD root, QString name){
    //TODO verificar si tienes permisos de lectura.
    INODO nulo = createInodo(-1,0,0,0);
    for (int i = 0; i<5; i++) {
        if(root.dd_array_files[i].dd_file_ap_inodo!=-1){
            if(QString::fromLatin1(root.dd_array_files[i].dd_file_nombre).remove('\000')==name)
                return getInodo(path,start_inodes,root.dd_array_files[i].dd_file_ap_inodo);
        }
    }
    if(root.dd_ap_detalle_directorio!=-1){
        return getInodoDD(path, start_inodes, start_dd, getDD(path,start_dd,root.dd_ap_detalle_directorio),name);
    }
    return nulo;
}
bool Procedures::insertTextFile(QString path, SUPERBOOT sb, int ap_sb, INODO archivo, int ap_inodo, QString cont){
    //TODO verificar si tiene permisos de escritura.
    QString BMBLOCK = getBitMap(path, sb.sb_bloques_count, sb.sb_ap_bitmap_bloques);
    QString BMINODO = getBitMap(path, sb.sb_inodos_count, sb.sb_ap_bitmap_table_inodo);

    int bitfreeBLOCK=0;

    BLOCK_DATA BD;

    for(int i = 0; i<4; i++){
        if(cont.length()>25){
            if(archivo.i_array_bloques[i]==-1){
                bitfreeBLOCK = getFirstFreeBM(BMBLOCK);

                BMBLOCK[bitfreeBLOCK] = '1';

                archivo.i_array_bloques[i] = bitfreeBLOCK;

                BD = createBlockData(cont.mid(0,25));
                setBlockData(path,BD,sb.sb_ap_bloques,bitfreeBLOCK);

                cont = cont.mid(25);
            }else{
                BD = createBlockData(cont.mid(0,25));
                setBlockData(path,BD,sb.sb_ap_bloques,archivo.i_array_bloques[i]);

                cont = cont.mid(25);
            }

        }
        else{

            if(archivo.i_array_bloques[i]==-1){
                bitfreeBLOCK = getFirstFreeBM(BMBLOCK);

                BMBLOCK[bitfreeBLOCK] = '1';

                archivo.i_array_bloques[i] = bitfreeBLOCK;

                BD = createBlockData(cont.mid(0,cont.length()));

                setBlockData(path,BD,sb.sb_ap_bloques,bitfreeBLOCK);

                cont = "";

                setInodo(path,archivo,sb.sb_ap_table_inodo, ap_inodo);

                setData(path,ap_sb,sb,"","","",BMBLOCK);
                return true;
            }else{
                BD = createBlockData(cont.mid(0,25));
                setBlockData(path,BD,sb.sb_ap_bloques,archivo.i_array_bloques[i]);

                cont = "";

                setInodo(path,archivo,sb.sb_ap_table_inodo, ap_inodo);

                setData(path,ap_sb,sb,"","","",BMBLOCK);
                return true;
            }
        }
    }

    if(archivo.i_ap_indirecto ==-1){


        int freebitINODO = getFirstFreeBM(BMINODO);
        archivo.i_ap_indirecto = freebitINODO;

        setInodo(path,archivo,sb.sb_ap_table_inodo, ap_inodo);

        BMINODO[freebitINODO] = '1';

        INODO indirecto = createInodo(freebitINODO,archivo.i_size_archivo,archivo.i_id_proper,archivo.i_perm);
        setInodo(path,indirecto,sb.sb_ap_table_inodo,freebitINODO);

        setData(path,ap_sb,sb,"","",BMINODO,BMBLOCK);

        return insertTextFile(path, sb, ap_sb, indirecto ,freebitINODO,cont);
    }else{
        setInodo(path,archivo,sb.sb_ap_table_inodo, ap_inodo);
        setData(path,ap_sb,sb,"","",BMINODO,BMBLOCK);
        return insertTextFile(path, sb, ap_sb, getInodo(path,sb.sb_ap_table_inodo,archivo.i_ap_indirecto),archivo.i_ap_indirecto,cont);
    }

}
QString Procedures::getTextFile(QString path, SUPERBOOT sb, INODO archivo){
    QString text="";
    for (int i =0;i<4;i++)
        if(archivo.i_array_bloques[i]!=-1)
            text+= QString::fromLatin1(getBlockData(path,sb.sb_ap_bloques,archivo.i_array_bloques[i]).bd_data,25).remove('\000');

    if(archivo.i_ap_indirecto !=-1)
        text+=getTextFile(path,sb, getInodo(path, sb.sb_ap_table_inodo, archivo.i_ap_indirecto));

    return text;
}
bool Procedures::removeTextFile(QString path, SUPERBOOT sb, INODO archivo, int usr){

    QString BMBLOCK = getBitMap(path,sb.sb_bloques_count, sb.sb_ap_bitmap_bloques);
    QString BMINODO = getBitMap(path,sb.sb_inodos_count, sb.sb_ap_bitmap_table_inodo);

    PERMISOS perm =  getPermisos(archivo.i_perm);

    if(getPermisoEscritura(archivo.i_id_proper, usr, perm)){

        for (int i=0; i<4;i++) {
            if(archivo.i_array_bloques[i]!=-1){
                BMBLOCK[archivo.i_array_bloques[i]] = '0';
                archivo.i_array_bloques[i] = -1;
            }

        }

        if(archivo.i_ap_indirecto !=-1){
            removeTextFile(path,sb,getInodo(path,sb.sb_ap_table_inodo,archivo.i_ap_indirecto),usr);
            BMBLOCK[archivo.i_ap_indirecto] = '0';
        }

        setInodo(path,archivo,sb.sb_ap_table_inodo,archivo.i_count_inodo);

        setData(path,sb.sb_ap_arbol_directory-static_cast<int>(sizeof(SUPERBOOT)),sb,"","",BMINODO,BMBLOCK);

        return true;
    }
    return false;
}

//Metodos para mover.

//Metodos para copiar.

//Metodos para renombrar.

//Metodos para Loss.

//Metodos para Recovery.


void Procedures::setData(QString path , int startsb, SUPERBOOT sb, QString BMAVD, QString BMDD, QString BMINODO, QString BMBLOCK){

    setSuperBoot(path, sb, startsb);

    if(BMAVD!=""){
        setBitMap(path, BMAVD, sb.sb_ap_bitmap_arbol_directorio);
        sb.sb_first_free_bit_arbol_directorio = getFirstFreeBM(BMAVD);
    }
    if(BMDD!=""){
        setBitMap(path, BMDD, sb.sb_ap_bitmap_detalle_directory);
        sb.sb_first_free_bit_detalle_directorio = getFirstFreeBM(BMDD);
    }
    if(BMINODO!=""){
        setBitMap(path, BMINODO, sb.sb_ap_bitmap_table_inodo);
        sb.sb_first_free_bit_tabla_inodo =getFirstFreeBM(BMINODO);
    }
    if(BMBLOCK!=""){
        setBitMap(path, BMBLOCK, sb.sb_ap_bitmap_bloques);
        sb.sb_first_free_bit_bloques = getFirstFreeBM(BMBLOCK);
    }
    setSuperBoot(path,sb, sb.sb_ap_log + sb.sb_arbol_virtual_count * static_cast<int>(sizeof(BITACORA)));

}

void Procedures::recuperarUsuarios(QString textuser, QString id)
{
    users.clear();
    grps.clear();
    QStringList registros = textuser.split('\n', QString::SkipEmptyParts);
    QStringList registro;

    for (int i=0; i<registros.length();i++) {
        registro.clear();
        registro = registros[i].remove(' ').split(',', QString::SkipEmptyParts);
        if(registro[1]=="G")
            grps.append(createGrp(registro[0].toInt(),registro[2].toUpper()));
        else if(registro[1]=="U")
            for (int j=0;j<grps.length();j++)
                if(grps[j].name==registro[2])
                    users.append(createUser(registro[0].toInt(), grps[j].grp, registro[2].toUpper(), registro[3].toUpper(), registro[4], id.toUpper()));
    }

}
QString Procedures::getStringUserGrp(){
    QStringList registros;
    for (int i=0; i<grps.length();i++)
        registros.append(QString::number(grps[i].grp) + ",G," + grps[i].name);


    for (int i=0; i<users.length();i++)
        registros.append(QString::number(users[i].usr) + ",U," + users[i].namegrp + "," + users[i].name + "," + users[i].pwd);

    return registros.join("\n");

}

void Procedures::formatPartition(QString id, QString type)
{
    MOUNTEDPARTITION mountedPartition =  getMountedPartition(id);
    QString pathmountedPartition = getPathMountedPartition(id);

    if((mountedPartition.part_type == 'P')||(mountedPartition.part_type == 'L')){

        SUPERBOOT sb = createSuperBoot(mountedPartition);

        AVD avd = createAVD("/",0,1, 664);

        DD dd = createDD();
        dd.dd_array_files[0]= createBlockFile("user.txt",0);

        INODO usertxt = createInodo(0, 0, 1, 664);
        usertxt.i_array_bloques[0]=0;
        usertxt.i_array_bloques[1]=1;

        BLOCK_DATA bduser1 = createBlockData("1,G,ROOT\n1,U,ROOT,ROOT,2");
        BLOCK_DATA bduser2 = createBlockData("01113915\n");

        sb.sb_inodos_free--;
        sb.sb_arbol_virtual_free--;
        sb.sb_detalle_directory_free--;
        sb.sb_bloques_free--;
        sb.sb_bloques_free--;

        QString BMAVD = createBitMap(sb.sb_arbol_virtual_count);
        QString BMDD = createBitMap(sb.sb_detalle_directory_count);
        QString BMINODO = createBitMap(sb.sb_inodos_count);
        QString BMBLOCK = createBitMap(sb.sb_bloques_count);

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
    MOUNTEDPARTITION mountedPartition = getMountedPartition(id);
    QString pathmountedPartition = getPathMountedPartition(id);

    if(pathmountedPartition != ""){
        SUPERBOOT sb = getSuperBoot(pathmountedPartition, mountedPartition.part_start);
        recuperarUsuarios(getTextFile(pathmountedPartition,sb,getInodo(pathmountedPartition,sb.sb_ap_table_inodo,0)),id);
        for (int i=0; i<users.length(); i++){
            //writeLine(users[i].name + " - - - " + users[i].pwd);
            if(users[i].name==usr.toUpper() && users[i].pwd==pwd){
                userlogin = users[i];
                return true;
            }
        }
    }
    return false;
}
bool Procedures::cerrarSesion()
{
    if(userlogin.name != ""){
        userlogin = createUser(0,0,"","","","");
        return true;
    }
    else
        return false;

}

bool Procedures::crearGrupo(QString name, QString id){
    MOUNTEDPARTITION mountedPartition = getMountedPartition(id);
    QString pathmountedPartition = getPathMountedPartition(id);

    SUPERBOOT sb = getSuperBoot(pathmountedPartition, mountedPartition.part_start);
    recuperarUsuarios(getTextFile(pathmountedPartition,sb,getInodo(pathmountedPartition,sb.sb_ap_table_inodo,0)),id);

    QString txt = getStringUserGrp();

    bool encontrado = false;
    int idnuevo = 0;

    if(pathmountedPartition != ""){

        USER user = getUserLogin();

        if(user.usr == 1 && user.name.toUpper()=="ROOT"){
            for (int i=0;i<grps.length();i++) {
                if(grps[i].name == name.toUpper()){
                    encontrado = true;

                }
                if(grps[i].grp>idnuevo)
                    idnuevo=grps[i].grp;
            }

            if(!encontrado){
                grps.append(createGrp(idnuevo+1, name.toUpper()));
                removeTextFile(pathmountedPartition, sb, getInodo(pathmountedPartition,sb.sb_ap_table_inodo,0), user.usr);
                insertTextFile(pathmountedPartition,sb,mountedPartition.part_start, getInodo(pathmountedPartition,sb.sb_ap_table_inodo,0), 0, getStringUserGrp());
                return true;
            }
        }

    }
    return false;
}
bool Procedures::removerGrupo(QString name, QString id)
{
    MOUNTEDPARTITION mountedPartition = getMountedPartition(id);
    QString pathmountedPartition = getPathMountedPartition(id);

    SUPERBOOT sb = getSuperBoot(pathmountedPartition, mountedPartition.part_start);
    recuperarUsuarios(getTextFile(pathmountedPartition,sb,getInodo(pathmountedPartition,sb.sb_ap_table_inodo,0)),id);

    QString txt = getStringUserGrp();

    if(pathmountedPartition != ""){
        USER user = getUserLogin();

        if(user.usr == 1 && user.name.toUpper()=="ROOT"){
            for (int i=0; i<grps.length(); i++){
                if(grps[i].name == name.toUpper())
                {
                    for (int j=0; j<users.length(); j++)
                        if(users[j].grp==grps[i].grp)
                            users.removeAt(j);

                    grps.removeAt(i);
                    removeTextFile(pathmountedPartition, sb, getInodo(pathmountedPartition,sb.sb_ap_table_inodo,0), user.usr);
                    insertTextFile(pathmountedPartition,sb,mountedPartition.part_start, getInodo(pathmountedPartition,sb.sb_ap_table_inodo,0), 0, getStringUserGrp());
                    return true;
                }
            }

        }
    }
    return false;
}
bool Procedures::crearUsuario(QString usr, QString pwd, QString grp, QString id)
{
    MOUNTEDPARTITION mountedPartition = getMountedPartition(id);
    QString pathmountedPartition = getPathMountedPartition(id);

    SUPERBOOT sb = getSuperBoot(pathmountedPartition, mountedPartition.part_start);
    recuperarUsuarios(getTextFile(pathmountedPartition,sb,getInodo(pathmountedPartition,sb.sb_ap_table_inodo,0)),id);

    QString txt = getStringUserGrp();

    bool encontrado = false;
    bool encontrado2 = false;
    int idnuevo = 0;
    int idgrp = 0;

    if(pathmountedPartition != ""){

        USER user = getUserLogin();

        if(user.usr == 1 && user.name.toUpper()=="ROOT"){

            for (int i=0; i<users.length(); i++){
                if(users[i].name==usr){
                    encontrado = true;
                }
                if(users[i].usr>idnuevo)
                    idnuevo=users[i].usr;
            }

            for (int i=0;i<grps.length();i++) {
                if(grps[i].name == grp.toUpper()){
                    encontrado2 = true;
                    idgrp = grps[i].grp;
                }
            }

            if(!encontrado && encontrado2){
                users.append(createUser(idnuevo+1, idgrp, grp.toUpper(), usr.toUpper(), pwd, id));
                removeTextFile(pathmountedPartition, sb, getInodo(pathmountedPartition,sb.sb_ap_table_inodo,0), user.usr);
                insertTextFile(pathmountedPartition,sb,mountedPartition.part_start, getInodo(pathmountedPartition,sb.sb_ap_table_inodo,0), 0, getStringUserGrp());
                return true;
            }
        }

    }
    return false;
}
bool Procedures::removerUsuario(QString usr, QString id)
{
    MOUNTEDPARTITION mountedPartition = getMountedPartition(id);
    QString pathmountedPartition = getPathMountedPartition(id);

    SUPERBOOT sb = getSuperBoot(pathmountedPartition, mountedPartition.part_start);
    recuperarUsuarios(getTextFile(pathmountedPartition,sb,getInodo(pathmountedPartition,sb.sb_ap_table_inodo,0)),id);

    QString txt = getStringUserGrp();

    if(pathmountedPartition != ""){

        USER user = getUserLogin();

        if(user.usr == 1 && user.name.toUpper()=="ROOT"){

            for (int i=0; i<users.length(); i++){
                if(users[i].name==usr){
                    users.removeAt(i);
                    removeTextFile(pathmountedPartition, sb, getInodo(pathmountedPartition,sb.sb_ap_table_inodo,0), user.usr);
                    insertTextFile(pathmountedPartition,sb,mountedPartition.part_start, getInodo(pathmountedPartition,sb.sb_ap_table_inodo,0), 0, getStringUserGrp());
                    return true;
                }
            }

        }

    }
    return false;
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
                if(!(existCarpetaAVD(pathmountedPartition, sb.sb_ap_arbol_directory, root, carpetas[pos])!=-1)){
                    if(insertarCarpetaAVD(pathmountedPartition, sb, root, ap_root, carpetas[pos], userlogin.usr))
                        root = getAVD(pathmountedPartition, sb.sb_ap_arbol_directory, ap_root);
                    else
                        return SIN_PERMISOS_ESCRITURA;
                }
                ap_root = existCarpetaAVD(pathmountedPartition, sb.sb_ap_arbol_directory, root, carpetas[pos]);

                if(QString::fromLatin1(getCarpetaAVD(pathmountedPartition, sb.sb_ap_arbol_directory, root, carpetas[pos], userlogin.usr).avd_nombre_directorio).remove('\000')!="")
                    root = getCarpetaAVD(pathmountedPartition, sb.sb_ap_arbol_directory, root, carpetas[pos], userlogin.usr);
                else
                    return SIN_PERMISOS_LECTURA;
                pos++;
            }else if (pos == carpetas.length() -1){
                if(!existArchivoDD(pathmountedPartition, sb.sb_ap_arbol_directory, getDD(pathmountedPartition,sb.sb_ap_detalle_directory,root.avd_ap_detalle_directorio), carpetas[pos])){
                    insertFileDD(pathmountedPartition, sb, mountedPartition.part_start, getDD(pathmountedPartition,sb.sb_ap_detalle_directory,root.avd_ap_detalle_directorio), root.avd_ap_detalle_directorio, carpetas[pos], size, cont, 1, 664);
                    //TODO Validar usuario que inicia sesion
                    pos++;
                    return EXITO;
                }else
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
                if(QString::fromLatin1(getCarpetaAVD(pathmountedPartition, sb.sb_ap_arbol_directory, root, carpetas[pos], userlogin.usr).avd_nombre_directorio).remove('\000')!="")
                    root = getCarpetaAVD(pathmountedPartition, sb.sb_ap_arbol_directory, root, carpetas[pos], userlogin.usr);
                else
                    return SIN_PERMISOS_LECTURA;
                pos++;
            }else if (pos == carpetas.length() -1){
                if(!existArchivoDD(pathmountedPartition, sb.sb_ap_arbol_directory, getDD(pathmountedPartition,sb.sb_ap_detalle_directory,root.avd_ap_detalle_directorio), carpetas[pos])){
                    insertFileDD(pathmountedPartition, sb, mountedPartition.part_start, getDD(pathmountedPartition,sb.sb_ap_detalle_directory,root.avd_ap_detalle_directorio), root.avd_ap_detalle_directorio, carpetas[pos], size, cont, 1, 664);
                    //TODO Validar usuario que inicia sesion
                    pos++;
                    return EXITO;
                }else
                    return EXISTE;
            }
        }
    }
    return FALLO;


}
int Procedures::mostrarContenido(QString id, QString archive){

    QStringList carpetas = archive.split('/', QString::SkipEmptyParts);

    MOUNTEDPARTITION mountedPartition = getMountedPartition(id);
    QString pathmountedPartition = getPathMountedPartition(id);

    SUPERBOOT sb = getSuperBoot(pathmountedPartition, mountedPartition.part_start);

    int pos = 0;
    int ap_root = 0;

    AVD root = getAVD(pathmountedPartition, sb.sb_ap_arbol_directory, ap_root);

    while(pos<carpetas.length()){

        if(pos<carpetas.length()-1)
        {
            if(!(existCarpetaAVD(pathmountedPartition, sb.sb_ap_arbol_directory, root, carpetas[pos])!=-1))
                return FALLO;
            ap_root = existCarpetaAVD(pathmountedPartition, sb.sb_ap_arbol_directory, root, carpetas[pos]);
            root = getCarpetaAVD(pathmountedPartition, sb.sb_ap_arbol_directory, root, carpetas[pos], userlogin.usr);
            pos++;
        }else if (pos == carpetas.length() -1){
            if(existArchivoDD(pathmountedPartition, sb.sb_ap_arbol_directory, getDD(pathmountedPartition,sb.sb_ap_detalle_directory,root.avd_ap_detalle_directorio), carpetas[pos])){
                {
                    writeLine("Contenido: "+carpetas[pos]);
                    QString txt =getTextFile(pathmountedPartition,sb,getInodoDD(pathmountedPartition,sb.sb_ap_table_inodo,sb.sb_ap_detalle_directory,getDD(pathmountedPartition,sb.sb_ap_detalle_directory,root.avd_ap_detalle_directorio),carpetas[pos]));
                    if(txt!="")
                        writeLine(txt.toUtf8());
                    else
                        writeError("Archivo sin contenido");
                }
                pos++;
                return EXISTE;
            }else{
                return FALLO;
            }
        }
    }

    return FALLO;
}
void Procedures::mostrarContenido(QString id, QStringList archives)
{
    for (int i =0 ;i<archives.length();i++) {
        if (mostrarContenido(id,archives[i])==FALLO)
            writeError("No existe" + archives[i]);
    }
}
void Procedures::eliminar(QString id, QString path, bool recursividad)
{

}
void Procedures::editarArchivo(QString path, QString cont)
{

}

bool Procedures::renameFile(QString path, int start_DD, int pos_DD, DD detalle, QString name, QString newname)
{
    for (int i=0; i<5; i++) {
        if(QString::fromLatin1(detalle.dd_array_files[i].dd_file_nombre,20).remove('\000')==name){
            for (int j=0; j<20; j++)
                if(j<newname.length())

                    detalle.dd_array_files[i].dd_file_nombre[j] = newname[j].toLatin1();
                else
                    detalle.dd_array_files[i].dd_file_nombre[j] = '\000';
            //TODO verficar permisos
            setDD(path, detalle, start_DD, pos_DD);
            return true;
        }
    }
    if(detalle.dd_ap_detalle_directorio!=-1){
        renameFile(path, start_DD, detalle.dd_ap_detalle_directorio, getDD(path,start_DD, detalle.dd_ap_detalle_directorio),name, newname);
    }
    return false;
}

int Procedures::renombrar(QString path, QString name, QString id)
{
    QStringList carpetas = path.split('/', QString::SkipEmptyParts);

    MOUNTEDPARTITION mountedPartition = getMountedPartition(id);
    QString pathmountedPartition = getPathMountedPartition(id);

    SUPERBOOT sb = getSuperBoot(pathmountedPartition, mountedPartition.part_start);

    int pos = 0;
    int ap_root = 0;

    AVD root = getAVD(pathmountedPartition, sb.sb_ap_arbol_directory, ap_root);

    while(pos<carpetas.length()){

        if(pos<carpetas.length()-1)
        {
            if(!(existCarpetaAVD(pathmountedPartition, sb.sb_ap_arbol_directory, root, carpetas[pos])!=-1))
                return FALLO;
            ap_root = existCarpetaAVD(pathmountedPartition, sb.sb_ap_arbol_directory, root, carpetas[pos]);
            root = getCarpetaAVD(pathmountedPartition, sb.sb_ap_arbol_directory, root, carpetas[pos], userlogin.usr);
            pos++;
        }else if (pos == carpetas.length() -1){
            QStringList archivo = carpetas[pos].split('.',QString::SkipEmptyParts);

            if(archivo.length()>1){

                if(existArchivoDD(pathmountedPartition, sb.sb_ap_arbol_directory, getDD(pathmountedPartition,sb.sb_ap_detalle_directory,root.avd_ap_detalle_directorio), carpetas[pos]))
                {

                    if(renameFile(path,sb.sb_ap_detalle_directory,root.avd_ap_detalle_directorio, getDD(pathmountedPartition,sb.sb_ap_detalle_directory,root.avd_ap_detalle_directorio), carpetas[pos], name))
                    {
                        return EXITO;
                    }
                    else
                    {
                        pos++;
                        return FALLO;
                    }
                }else
                    return FALLO;

            }else{

                if((existCarpetaAVD(pathmountedPartition, sb.sb_ap_arbol_directory, root, carpetas[pos])!=-1))
                {
                    root = getCarpetaAVD(pathmountedPartition, sb.sb_ap_arbol_directory, root, carpetas[pos], userlogin.usr);

                    for (int i=0; i<20; i++)
                        if(i<name.length())
                            root.avd_nombre_directorio[i] = name[i].toLatin1();
                        else
                            root.avd_nombre_directorio[i] = '\000';
                    setAVD(pathmountedPartition, root, sb.sb_ap_arbol_directory,ap_root);
                }else
                    return FALLO;

            }

        }
    }

    return FALLO;
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
                if(!(existCarpetaAVD(pathmountedPartition, sb.sb_ap_arbol_directory, root, carpetas[pos])!=-1)){
                    if(insertarCarpetaAVD(pathmountedPartition, sb, root, ap_root, carpetas[pos], userlogin.usr))
                        root = getAVD(pathmountedPartition, sb.sb_ap_arbol_directory, ap_root);
                    else
                        return SIN_PERMISOS_ESCRITURA;
                }
                ap_root = existCarpetaAVD(pathmountedPartition, sb.sb_ap_arbol_directory, root, carpetas[pos]);

                if(QString::fromLatin1(getCarpetaAVD(pathmountedPartition, sb.sb_ap_arbol_directory, root, carpetas[pos], userlogin.usr).avd_nombre_directorio).remove('\000')!="")
                    root = getCarpetaAVD(pathmountedPartition, sb.sb_ap_arbol_directory, root, carpetas[pos], userlogin.usr);
                else
                    return SIN_PERMISOS_LECTURA;
                pos++;
            }else if (pos == carpetas.length() -1){
                if(!(existCarpetaAVD(pathmountedPartition, sb.sb_ap_arbol_directory, root, carpetas[pos])!=-1)){
                    insertarCarpetaAVD(pathmountedPartition, sb, root, ap_root, carpetas[pos], userlogin.usr);
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
                if(QString::fromLatin1(getCarpetaAVD(pathmountedPartition, sb.sb_ap_arbol_directory, root, carpetas[pos], userlogin.usr).avd_nombre_directorio).remove('\000')!="")
                    root = getCarpetaAVD(pathmountedPartition, sb.sb_ap_arbol_directory, root, carpetas[pos], userlogin.usr);
                else
                    return SIN_PERMISOS_LECTURA;
                pos++;
            }else if (pos == carpetas.length() -1){
                if(!(existCarpetaAVD(pathmountedPartition, sb.sb_ap_arbol_directory, root, carpetas[pos])!=-1)){
                    insertarCarpetaAVD(pathmountedPartition, sb, root, ap_root, carpetas[pos], userlogin.usr);
                    pos++;
                    return EXITO;
                }else
                    return EXISTE;
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
bool Procedures::cambiarGrupo(QString usr, QString grp)
{
    USER user = getUserLogin();
    MOUNTEDPARTITION mountedPartition = getMountedPartition(user.id.toLower());
    QString pathmountedPartition = getPathMountedPartition(user.id.toLower());

    SUPERBOOT sb = getSuperBoot(pathmountedPartition, mountedPartition.part_start);
    recuperarUsuarios(getTextFile(pathmountedPartition,sb,getInodo(pathmountedPartition,sb.sb_ap_table_inodo,0)),user.id);

    QString txt = getStringUserGrp();


    //TODO verificar ID de la particion sean iguales
    if(pathmountedPartition != ""){
        if(user.usr == 1 && user.name.toUpper()=="ROOT"){
            for (int i=0; i<grps.length(); i++){
                if(grps[i].name == grp.toUpper())
                {
                    for (int j=0; j<users.length(); j++)
                        if(users[j].name==usr.toUpper())
                        {
                            users[j].grp = grps[i].grp;
                            users[j].namegrp = grps[i].name;
                            removeTextFile(pathmountedPartition, sb, getInodo(pathmountedPartition,sb.sb_ap_table_inodo,0), user.usr);
                            insertTextFile(pathmountedPartition,sb,mountedPartition.part_start, getInodo(pathmountedPartition,sb.sb_ap_table_inodo,0), 0, getStringUserGrp());
                            return true;
                        }
                }
            }

        }
    }
    return false;
}
void Procedures::perdida(QString id)
{
    MOUNTEDPARTITION mountedPartition = getMountedPartition(id);
    QString pathmountedPartition = getPathMountedPartition(id);

    SUPERBOOT sb = getSuperBoot(pathmountedPartition, mountedPartition.part_start);

    char caracter = '\000';
    ifstream exist(pathmountedPartition.toUtf8(),ios::in);

    if(exist.good())
    {
        ofstream file( pathmountedPartition.toUtf8(), ios::in | ios::out | ios::binary);

        writeLine("Simulando perdida de datos...");

        for (int i=mountedPartition.part_start;i<sb.sb_ap_log;i++){
            file.seekp(i);
            caracter = '\000';
            file.write(reinterpret_cast<char*>(&caracter), sizeof (caracter));
        }
        file.close();
        exist.close();
        writeLine("Se termino de simular la perdida de datos");
    }
    else
        writeError("Disco no existe en la ubicación");

}
void Procedures::recuperacion(QString id)
{
    MOUNTEDPARTITION mountedPartition = getMountedPartition(id);
    QString pathmountedPartition = getPathMountedPartition(id);

    SUPERBOOT sb = getSuperBoot(pathmountedPartition, mountedPartition.part_start);

    for (int i=0; i<sb.sb_arbol_virtual_count; i++) {
        BITACORA log = getBitacora(pathmountedPartition, sb.sb_ap_log, i);
        if(QString::fromLatin1(log.log_nombre).remove('\000')!="")
        {
            switch (log.log_tipo) {

            case LOG_CARPETA:
                switch (log.log_tipo_operacion) {
                case ACTIONCREATE:
                    crearCarpetaNueva(log.id,pathmountedPartition,log.recursividad);
                    break;
                case ACTIONREMOVE:
                    eliminar(log.id, log.log_nombre, log.recursividad);
                    break;
                case ACTIONRENAME:
                    //renombrar(log.log_nombre, )
                    break;

                case ACTIONMOVE:
                    break;
                case ACTIONCOPY:
                    break;
                default:

                    break;
                }
                break;
            case LOG_ARCHIVO:
                switch (log.log_tipo_operacion) {

                case ACTIONCREATE:
                    crearArchivoNuevo(log.id,QString::fromLatin1(log.log_nombre).remove('\000'), log.recursividad, 0, QString::fromLatin1(log.log_contenido).remove('\000'));
                    break;
                case ACTIONREMOVE:
                    eliminar(log.id, log.log_nombre, log.recursividad);
                    break;
                case ACTIONRENAME:

                    break;

                case ACTIONMOVE:

                    break;
                case ACTIONCOPY:

                    break;
                case ACTIONEDIT:

                    break;
                case ACTIONCAT:

                    break;
                default:

                    break;
                }
                break;
            }

        }
        else{
            break;
        }
    }



}


void Procedures::crearRegistroLog(QString id, int action, int tipo, QString path, QString contenido, bool recursividad)
{
    MOUNTEDPARTITION mountedPartition = getMountedPartition(id);
    QString pathmountedPartition = getPathMountedPartition(id);

    SUPERBOOT sb = getSuperBoot(pathmountedPartition, mountedPartition.part_start);

    setBitacora(pathmountedPartition, Procedures::createBitacora(action, tipo, path, contenido,time(nullptr),id, recursividad),sb.sb_ap_log, sb.sb_arbol_virtual_count);

}
