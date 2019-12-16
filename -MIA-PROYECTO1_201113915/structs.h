#ifndef STRUCTS_H
#define STRUCTS_H

#include "ctime"
#include "QString"

using namespace std;

typedef struct PARTITION
{
    char        part_status;
    char        part_type;
    char        part_fit;
    int         part_start;
    int         part_size;
    char        part_name[16];
}PARTITION;

typedef struct MBR
{
    int         mbr_tamano;
    time_t      mbr_fecha_creacion;
    int         mbr_disk_signature;
    PARTITION   mbr_partition_1;
    PARTITION   mbr_partition_2;
    PARTITION   mbr_partition_3;
    PARTITION   mbr_partition_4;
}MBR;

typedef struct EBR
{
    char        part_status;
    char        part_fit;
    int         part_start;
    int         part_size;
    int         part_next;
    char        part_name[16];
}EBR;

typedef struct MOUNTEDPARTITION
{
    char        part_status;
    char        part_type;
    char        part_fit;
    int         part_start;
    int         part_size;
    char        hd[16];
}MOUNTEDPARTITION;



typedef struct SUPERBOOT
{
    char        sb_nombre_hd[16];
    int         sb_arbol_virtual_count;
    int         sb_detalle_directory_count;
    int         sb_inodos_count;
    int         sb_bloques_count;
    int         sb_arbol_virtual_free;
    int         sb_detalle_directory_free;
    int         sb_inodos_free;
    int         sb_bloques_free;
    time_t      sb_date_creacion;
    time_t      sb_date_ultimo_montaje;
    int         sb_montaje_count;
    int         sb_ap_bitmap_arbol_directorio;
    int         sb_ap_arbol_directory;
    int         sb_ap_bitmap_detalle_directory;
    int         sb_ap_detalle_directory;
    int         sb_ap_bitmap_table_inodo;
    int         sb_ap_table_inodo;
    int         sb_ap_bitmap_bloques;
    int         sb_ap_bloques;
    int         sb_ap_log;
    int         size_struct_arbol_directorio;
    int         size_struct_detalle_directorio;
    int         size_struct_inodo;
    int         size_struct_bloque;
    int         sb_first_free_bit_arbol_directorio;
    int         sb_first_free_bit_detalle_directorio;
    int         sb_first_free_bit_tabla_inodo;
    int         sb_first_free_bit_bloques;
    int         sb_magic_num;
}SUPERBOOT;

typedef struct AVD
{
    time_t      avd_fecha_creacion;
    char        avd_nombre_directorio[20];
    int         avd_ap_array_subdirectorios[6];
    int         avd_ap_detalle_directorio;
    int         avd_ap_arbol_virtual_directorio;
    int         avd_proper;
}AVD;

typedef struct BLOCK_FILE
{
    char        dd_file_nombre[20];
    int         dd_file_ap_inodo;
    time_t      dd_file_date_creation;
    time_t      dd_file_date_modificacion;
}BLOCK_FILE;

typedef struct DD
{
    BLOCK_FILE  dd_array_files[5];
    int         dd_ap_detalle_directorio;
}DD;

typedef struct BLOCK_DATA
{
    char        bd_data[25];
}BLOCK_DATA;

typedef struct INODO
{
    int         i_count_inodo;
    int         i_size_archivo;
    int         i_count_bloques_asignados;
    int         i_array_bloques[4];
    int         i_ap_indirecto;
    int         I_id_proper;
}INODO;

typedef struct BITACORA{
    int         log_tipo_operacion;
    char        log_tipo;
    char        log_nombre[256];
    char        log_contenido[256];
    time_t      log_fecha;
}BITACORA;

enum Choice
{
    ADD = 1,
    ARCHIVE = 2,
    CONT = 3,
    DELETE = 4,
    DESTINY = 5,
    FIT = 6,
    GRP = 7,
    ID = 8,
    IDDESTINY = 9,
    NAME = 10,
    NTCAT = 11,
    NTCHGRP = 12,
    NTCHMOD = 13,
    NTCHOWN = 14,
    NTCP = 15,
    NTEDIT = 16,
    NTEXEC = 17,
    NTFDISK = 18,
    NTFIND = 19,
    NTINSTRUCTION = 20,
    NTINSTRUCTIONS = 21,
    NTLOGIN = 22,
    NTLOGOUT = 23,
    NTLOSS = 24,
    NTMKDIR = 25,
    NTMKDISK = 26,
    NTMKFILE = 27,
    NTMKFS = 28,
    NTMKGRP = 29,
    NTMKUSR = 30,
    NTMOUNT = 31,
    NTMV = 32,
    NTPAUSE = 33,
    NTRECOVERY = 34,
    NTREN = 35,
    NTREP = 36,
    NTRM = 37,
    NTRMDISK = 38,
    NTRMGRP = 39,
    NTRMUSR = 40,
    NTUNMOUNT = 41,
    P = 42,
    PATH = 43,
    PWD = 44,
    R = 45,
    RF = 46,
    RUTA = 47,
    SIZE = 48,
    TYPE = 49,
    UGO = 50,
    UNIT = 51,
    USR = 52
};

enum RETURN
{
    FALLO = 0,
    EXITO = 1,
    EXISTE =2
};

enum JOURNALACTION {
    ACTIONNULL = 0,
};

#endif // STRUCTS_H
