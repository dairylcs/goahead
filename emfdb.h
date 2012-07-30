/*
  	emfdb.h -- EMF database compatability functions for GoAhead WebServer.

    Copyright (c) All Rights Reserved. See details at the end of the file.
 */

/********************************* Includes ***********************************/

#ifndef _h_EMFDB
#define _h_EMFDB 1

#include	"uemf.h"

/********************************* Defines ************************************/

#define		T_INT					0
#define		T_STRING				1

#define		DB_OK					0
#define		DB_ERR_GENERAL			-1
#define		DB_ERR_COL_NOT_FOUND	-2
#define		DB_ERR_COL_DELETED		-3
#define		DB_ERR_ROW_NOT_FOUND	-4
#define		DB_ERR_ROW_DELETED		-5
#define		DB_ERR_TABLE_NOT_FOUND	-6
#define		DB_ERR_TABLE_DELETED	-7
#define		DB_ERR_BAD_FORMAT		-8

#define     DB_CASE_INSENSITIVE  1

typedef struct dbTable_s {
	char_t	*name;
	int		nColumns;
	char_t	**columnNames;
	int		*columnTypes;
	int		nRows;
	int		**rows;
} dbTable_t;

/********************************** Prototypes ********************************/
/*
  	Add a schema to the module-internal schema database
 */
extern int		dbRegisterDBSchema(dbTable_t *sTable);
extern int		dbOpen(char_t *databasename, char_t *filename, int (*gettime)(int did), int flags);
extern void		dbClose(int did);
extern int		dbGetTableId(int did, char_t *tname);
extern char_t	*dbGetTableName(int did, int tid);
extern int		dbReadInt(int did, char_t *table, char_t *column, int row, int *returnValue);
extern int		dbReadStr(int did, char_t *table, char_t *column, int row, char_t **returnValue);
extern int		dbWriteInt(int did, char_t *table, char_t *column, int row, int idata);
extern int		dbWriteStr(int did, char_t *table, char_t *column, int row, char_t *s);
extern int		dbAddRow(int did, char_t *table);
extern int		dbDeleteRow(int did, char_t *table, int rid);
extern int		dbSetTableNrow(int did, char_t *table, int nNewRows);
extern int		dbGetTableNrow(int did, char_t *table);

/*
  	Dump the contents of a database to file
 */
extern int		dbSave(int did, char_t *filename, int flags);

/*
  	Load the contents of a database to file
 */
extern int		dbLoad(int did, char_t *filename, int flags);
extern int		dbSearchStr(int did, char_t *table, char_t *column, char_t *value, int flags);
extern void		dbZero(int did);
extern char_t	*basicGetProductDir();
extern void		basicSetProductDir(char_t *proddir);

#endif /* _h_EMFDB */

/*
    @copy   default

    Copyright (c) Embedthis Software LLC, 2003-2012. All Rights Reserved.

    This software is distributed under commercial and open source licenses.
    You may use the Embedthis GoAhead open source license or you may acquire 
    a commercial license from Embedthis Software. You agree to be fully bound
    by the terms of either license. Consult the LICENSE.md distributed with
    this software for full details and other copyrights.

    Local variables:
    tab-width: 4
    c-basic-offset: 4
    End:
    vim: sw=4 ts=4 expandtab

    @end
 */