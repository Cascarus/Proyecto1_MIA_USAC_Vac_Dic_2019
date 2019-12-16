#ifndef PROCEDURES_H
#define PROCEDURES_H

#include <NodeAST/nodeast.h>
#include "stdio.h"
#include "fstream"
#include "structs.h"
#include "dirent.h"
#include "QDebug"
#include "QFile"
#include <math.h>
#include "IOConsole/ioconsole.h"

class Procedures
{
public:
    static void clearProcedures();

    static void writeLine(QString texto);
    static void writeError(QString text);
    static void writeCommand(QString text);

    static void createFile(QString path, int size, QString unit);
    static void deleteFile(QString path);

    static MBR createMBR(int size, QString unit);
    static void setMBR(QString path, MBR mbr, int pos);
    static MBR getMBR(QString path,int pos);

    static void setEBR(QString path, EBR mbr, int pos);
    static EBR getEBR(QString path,int pos);

    static void createDirectory(QString path);
    static char* generate_mbr_fecha_creacion(time_t mbr_fecha_creacion);

    static void createPartition(int size, QString unit, QString path, QString type, QString fit, QString name);
    static bool addPartition(QString unit, QString path, QString name, int add);
    static bool deletePartition(QString path, QString del, QString name);
    static bool existPartition(QString name, QString path);

    static bool comprobateName(QString name, QString path);

    static bool putPartitionPrincipal(MBR mbr, PARTITION partition, QString path);
    static bool putPartitionLogical(MBR mbr,EBR ebr,QString path);

    static bool mountPartition(QString path, QString name);
    static void unmountPartition(QString id);
    static void writeMountPartition();
    static QString getId(QString path);

    static int comprobatePNGPDF(QString path);

    static void generateRep(QString dot, QString path);

    static QString getDotBM(QString titulo, char *bitmap);

    static bool generateRepMBR(QString path, QString id);
    static bool generateRepFile(QString path, QString id, QString ruta);
    static bool generateRepDisk(QString path, QString id);
    static bool generateRepInode(QString path, QString id);
    static bool generateRepSb(QString path, QString id);
    static bool generateRepBm_Arbdir(QString path, QString id);
    static bool generateRepBm_Detdir(QString path, QString id);
    static bool generateRepBm_Inode(QString path, QString id);
    static bool generateRepBm_Block(QString path, QString id);
    static bool generateRepBitacora(QString path, QString id);
    static bool generateRepDirectorio(QString path, QString id);
    static bool generateRepTreeFile(QString path, QString id);
    static bool generateRepTreeDirectorio(QString path, QString id);
    static bool generateRepTreeComplete(QString path, QString id);
    static bool generateRepLs(QString path, QString id, QString ruta);

    // Fase 2 Proyecto 1 - Get N Sistema de archivos LWH
    static int getN(int size);

    // Fase 2 Proyecto 1 - Constructor, Getter and Setter
    static QString getPathMountedPartition(QString id);

    static MOUNTEDPARTITION getMountedPartition(QString id);
    static MOUNTEDPARTITION toMountedPartition(PARTITION partition, QString hd);
    static MOUNTEDPARTITION toMountedPartition(EBR partition, QString hd);

    static char *createBM(int n);
    static void setBitMap(QString path, char *bitmap, int pos);
    static char *getBitMap(QString path, int n, int pos);
    static int getFirstFreeBM(char *bitmap);

    static SUPERBOOT createSuperBoot(MOUNTEDPARTITION mountedPartition);
    static void setSuperBoot(QString path, SUPERBOOT superblock, int pos);
    static SUPERBOOT getSuperBoot(QString path, int pos);

    static AVD createAVD(QString name, int det, int usr);
    static void setAVD(QString path, AVD avd, int start, int n);
    static AVD getAVD(QString path, int start, int n);

    static BLOCK_FILE createBlockFile(QString name, int ap_inodo);

    static DD createDD();
    static void setDD(QString path, DD dd, int start, int n);
    static DD getDD(QString path, int start, int n);

    static INODO createInodo(int inodo, int size, int proper);
    static void setInodo(QString path, INODO inodo, int start, int n);
    static INODO getInodo(QString path, int start, int n);

    static BLOCK_DATA createBlockData(QString block);
    static void setBlockData(QString path, BLOCK_DATA blockdata, int start, int n);
    static BLOCK_DATA getBlockData(QString path, int start, int n);

    static BITACORA createBitacora(MOUNTEDPARTITION mountedPartition);
    static void setBitacora(QString path, BITACORA bitacora, int start, int n);
    static BITACORA getBitacora(QString path, int start, int n);

    static int existCarpetaAVD(QString path, int start, AVD root, QString name);
    static AVD getCarpetaAVD(QString path, int start, AVD root, QString name);
    static bool insertarCarpetaAVD(QString path, SUPERBOOT sb, AVD root, int ap_root, QString name, int usr);

    static bool existArchivoDD(QString path, int start, DD root, QString name);
    static int insertarArchivoDD(QString path, SUPERBOOT sb, DD root, QString name, int size, QString cont);

    static void setData(QString path, int startsb, SUPERBOOT sb, char *BMAVD, char *BMDD, char *BMINODO, char *BMBLOCK);

    // Fase 2 Proyecto 1 -  Comandos    
    static void formatPartition(QString id, QString type);
    static bool inicioSesion(QString usr, QString pwd, QString id);
    static void cerrarSesion();
    static void crearGrupo(QString name);
    static void removerGrupo(QString name);
    static void crearUsuario(QString usr, QString pwd, QString grp);
    static void removerUsuario(QString usr);
    static void cambiarPermisos(QString path, QString ugo, bool r);
    static int crearArchivoNuevo(QString id, QString path, bool p, int size, QString cont);
    static void mostrarContenido(QString archive);
    static void eliminar(QString path);
    static void editarArchivo(QString path, QString cont);
    static void renombrar(QString path, QString name);
    static int crearCarpetaNueva(QString id, QString path, bool p);
    static void copiar(QString path, QString dest);
    static void mover(QString path, QString dest);
    static void buscar(QString path, QString name);
    static void cambiarPropietario(QString path, QString usr, bool r);
    static void cambiarGrupo(QString usr, QString grp);
    static void perdida(QString id);
    static void recuperacion(QString id);

    static QString getDotAVD(QString path, AVD root, int inicioAVD, int n);
    static QString getDotAVD2(QString path, AVD root, int inicioAVD, int n);
};


#endif // PROCEDURES_H
